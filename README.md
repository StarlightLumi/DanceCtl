# DanceCtl
This a custom software written for the Arduino, meant to replace the PCB inside an L-tek Dance Pad.

This mod will increase the polling rate from 125hz to 1000hz, enabling you to get them sweet sweet quads.

For the full guide, visit https://www.instructables.com/id/Modifying-an-L-tek-Dance-Pad-to-Poll-at-1000hz-on-/

Credit goes to Martin Natano for making the original guide and code this project was based on - https://www.natano.net/blog/2019-12-14-usb-polling-adventure/

### Which version should I get?
- If you're planning on using this with Linux, use DanceCtl.
- If you're planning on using this with Windows, use DanceCtl2.
- DanceCtl is hard coded and has much better debounce implemention.

### Windows and Linux (DanceCtl2)
First, download the Arduino Joystick Library. Instructions are at the github below.
 - https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-2.0/Joystick

To download the .ino:
 - Click "Clone or Download" in the top right.
 - Download the ZIP
 - Open up the zip, and run "DanceCtl2.ino"
 - Return to the instructables guide (https://www.instructables.com/id/Modifying-an-L-tek-Dance-Pad-to-Poll-at-1000hz-on-/)

### Linux-only (DanceCtl)
To download the .ino:
 - Click "Clone or Download" in the top right.
 - Download the ZIP
 - Open up the zip, and run "DanceCtl.ino"
 - Return to the instructables guide (https://www.instructables.com/id/Modifying-an-L-tek-Dance-Pad-to-Poll-at-1000hz-on-/)
 
 ### Current Issues
 - Possible debounce issue on DanceCtl2.  I'm getting roughly 1-2 decents on really difficult charts, but still able to star the easier ones.  Needs more data to diagnose, as it could entirely be me sucking at ITG.
 - DanceCtl2 seems to add ~0.5ms delay.  Some optimization may decrease it to ~0.2ms, but I don't think it's entirely fixable.  Still better than the 8ms delay of the original Ltek board tho!
 - I'm not the best programmer in the world, but it's better than nothing! (which is what we had before)
