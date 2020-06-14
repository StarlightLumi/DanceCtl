# DanceCtl
This a custom software written for the Arduino, meant to replace the PCB inside an L-tek Dance Pad.

This mod will increase the polling rate from 125hz to 1000hz, enabling you to get them sweet sweet quads.

### Windows and Linux (DanceCtl2)
First, download the Arduino Joystick Library. Instructions are at the github below.
 - https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-2.0/Joystick

To download the .ino:
 - Click "Clone or Download" in the top right.
 - Download the ZIP
 - Open up the zip, and run "DanceCtl2.ino"
 - Arduino will ask you to copy it to a new path, hit "OK"
 - Set your Arduino IDE for your specific Arduino model (this is written for a Micro/Leonardo, so likely one of those two).
 - Upload, and you're done!
 - Good luck with the soldering!

### Linux-only (DanceCtl)
To download the .ino:
 - Click "Clone or Download" in the top right.
 - Download the ZIP
 - Open up the zip, and run "DanceCtl.ino"
 - Arduino will ask you to copy it to a new path, hit "OK"
 - Set your Arduino IDE for your specific Arduino model (this is written for a Micro/Leonardo, so likely one of those two).
 - Upload, and you're done!
 - Good luck with the soldering!
 
 ### Current Issues
 - Possible debounce issue on DanceCtl2.  I'm getting roughly 1-2 decents on really difficult charts, but still able to star the easier ones.  Needs more data to diagnose, as it could entirely be me sucking at ITG.
 - DanceCtl2 seems to add ~0.5ms delay.  Some optimization may decrease it to ~0.2ms, but I don't think it's entirely fixable.  Still better than the 8ms delay of the original Ltek board tho!
 - I'm not the best programmer in the world, but it's better than nothing! (which is what we had before)
