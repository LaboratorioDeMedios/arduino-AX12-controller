Como mover la DollHead por OSC
================================

Formato OSC:
    ofxOscMessage m;
    m.setAddress("/head/orientationAngles/");
    m.addFloatArg(PITCH);
    m.addFloatArg(YAW);
    m.addFloatArg(ROLL);


Movimientos por motor
Pitch = (movimiento SI) = MOTOR 1
Yaw = (movimiento NO) = MOTOR 2
Roll = (movimiento MASO)  = MOTOR 4

Rangos y signos:

Pitch
-50 ---------------------------- 0 ---------------------------- +50
Arriba                      Frente                          Abajo

Yaw
-90 ---------------------------- 0 ---------------------------- +90
Derecha                    Frente                        Izquierda


Roll
-65 ---------------------------- 0 ---------------------------- +65
Derecha                    Frente                        Izquierda


Cuando dice Izquierda/Derecha se refiere a la izquierda/derecha desde la cabeza (se asume como obvio darse cuenta para dónde está mirando la cabeza)

Si se pasan valores fuera de rango, se interpreta como si se hubiera pasado el extremo correspondiente. Si se envía (70,120,-400) interpreta (50,90,-65).








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
