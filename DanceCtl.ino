#include "HID.h"

static const uint8_t hidReportDescriptor[] PROGMEM = {
    0x05, 0x01,   // USAGE_PAGE (Generic Desktop)
    0x09, 0x05,   // USAGE (Game Pad)
    0xa1, 0x01,   // COLLECTION (Application)
    0xa1, 0x00,   //  COLLECTION (Physical)
    0x85, 0x03,   //    REPORT_ID (3)

    // Buttons
    0x05, 0x09,   //    USAGE_PAGE (Button)
    0x19, 0x01,   //    USAGE_MINIMUM (Button 1)
    0x29, 0x06,   //    USAGE_MAXIMUM (Button 6)
    0x15, 0x00,   //    LOGICAL_MINIMUM (0)
    0x25, 0x01,   //    LOGICAL_MAXIMUM (1)
    0x75, 0x01,   //    REPORT_SIZE (1)
    0x95, 0x06,   //    REPORT_COUNT (6)
    0x81, 0x02,   //    INPUT (Data, Var, Abs)

    // Padding
    0x75, 0x01,   //    REPORT_SIZE (1)
    0x95, 0x02,   //    REPORT_COUNT (2)
    0x01, 0x01,   //    INPUT (Constant)

    0xc0,         //  END_COLLECTION
    0xc0,         // END_COLLECTION
};

#define DEBOUNCE_DELAY 2
#define NBUTTONS 6
static const int buttonPins[NBUTTONS] = {4, 5, 6, 7, 8, 9};

void setup() {
    int i;
    
    pinMode(LED_BUILTIN, OUTPUT);
    for (i = 0; i < NBUTTONS; i++)
        pinMode(buttonPins[i], INPUT_PULLUP);

    static HIDSubDescriptor node(hidReportDescriptor, sizeof(hidReportDescriptor));
    HID().AppendDescriptor(&node);
}

void loop() {
    static uint8_t reportData;
    static uint8_t buttonStates;
    static unsigned long lastButtonChange[NBUTTONS];
    unsigned long now;
    int sendReport, i;

    now = millis();
    sendReport = 0;

    for (i = 0; i < NBUTTONS; i++) {
        int pressed = !digitalRead(buttonPins[i]);
        if (pressed != bitRead(buttonStates, i)) {
            bitWrite(buttonStates, i, pressed);
            lastButtonChange[i] = now;
        }

        if (pressed != bitRead(reportData, i) && lastButtonChange[i] + DEBOUNCE_DELAY < now) {
            bitWrite(reportData, i, pressed);
            sendReport = 1;
        }
    }

    if (sendReport) {
        HID().SendReport(0x03, &reportData, sizeof(reportData));
        digitalWrite(LED_BUILTIN, reportData ? HIGH : LOW);
    }
}
