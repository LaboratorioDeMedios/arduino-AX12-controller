arduino-AX12-controller
=======================

Basic controller of AX-12+ motors with an Arduino

What to do before get this running on MAC OS:

1.	Install arduino.cc (this instructions are for version 1.0.5)
2.	Download AX-12+ library for arduino 2.3 at http://www.pablogindel.com/descargas/
3.	Install (copy) the library to ~/Documents/Arduino/Libraries
4.	Go to package contents of Arduino and locate the file: Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/HardwareSerial.cpp and comment lines 143 to 156 (#if defined(USART1_RX_vect) …… #endif)
5.	Edit ax12.cpp (~/Documents/Arduino/Libraries/ax12/ax12.cpp) and change "include wiring.h" by "include Arduino.h"
6.	Run arduino application and select Board 2560
