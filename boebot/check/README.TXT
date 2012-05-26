
Sketch for BoeBot + Arduino
---------------------------

Connections:

  Right servo to 11
  Left servo to 10

  Right whisker to digital 11 using 220 ohm resistor
  Right whisker to +5V using 10k ohm resistor

  Left whisker to digital 10 using 220 ohm resistor
  Left whisker to +5V using 10k ohm resistor

Compiling
---------

You will need GNU make. Change the makefile ARDUINO_DIR, BOARD_TAG,
and ARDUINO_PORT to match your platform/environment. Useful build 
targets are:

  clean
  all
  upload

If using the Arduino IDE, then rename check.cpp to check.pde and 
set the board target and USB port from the IDE menus.








