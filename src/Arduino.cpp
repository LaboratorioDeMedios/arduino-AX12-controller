//
//  Arduino.cpp
//  ax12OSCServer
//
//  Created by german on 4/24/14.
//
//

#include "Arduino.h"

#define		ANGLE_UNDEFINED		MAXCHAR
#define		ANGLE_DEFAULT		0
#define		KEY_UNDEFINED		""
    
	// required
	static string	COM_PORT						= "COM3";
    
	static char		ANGLE_DEFAULT_1					= 0;
	static char		ANGLE_DEFAULT_2					= 0;
	static char		ANGLE_DEFAULT_4					= 0;
	static char		ANGLE_DEFAULT_8					= 0;
    
	static int		ANGLE_MAX_1						= 127;
	static int		ANGLE_MIN_1						= -127;
	static int		ANGLE_MAX_2						= 127;
	static int		ANGLE_MIN_2						= -127;
	static int		ANGLE_MAX_4						= 127;
	static int		ANGLE_MIN_4						= -127;
    
	// optional - for debug
	static char		KEY_RESET						= 0;
	static char		KEY_PRINT_STATUS				= ' ';
    
	static int		ANGLE_STEP_FOR_KEY				= 24;
	static char		KEY_ANGLE_1INC					= 'a';
	static char		KEY_ANGLE_1DEC					= 'z';
	static char		KEY_ANGLE_2INC					= 's';
	static char		KEY_ANGLE_2DEC					= 'x';
	static char		KEY_ANGLE_4INC					= 'd';
	static char		KEY_ANGLE_4DEC					= 'c';
    
	static unsigned long startTime;
    
	Arduino::Arduino()
	{
		angleMotor1 = 0;
		angleMotor2 = 0;
		angleMotor4 = 0;
	}
    
	Arduino::~Arduino()
	{
		if (serial.available()){
			serial.close();
		}
	}
    
	bool Arduino::setup()
	{
		angleMotor1 = ANGLE_DEFAULT_1;
		angleMotor2 = ANGLE_DEFAULT_2;
		angleMotor4 = ANGLE_DEFAULT_4;
        
        vector< ofSerialDeviceInfo > lista = serial.getDeviceList();
        
		if (!serial.setup(1, 9600)) {
			cout << "Error en setup del Serial, puerto COM: " << COM_PORT << endl;
			//return false;
		}

		sendMotor((char) angleMotor1, ID_MOTOR_1);
		sendMotor((char) angleMotor2, ID_MOTOR_2);
		sendMotor((char) angleMotor4, ID_MOTOR_4);

		return true;
	}
    
	void Arduino::exit() {
		if (serial.available()){
			serial.close();
		}
	}
    
	void Arduino::update() {
        

	}
    
	void Arduino::draw() {

	}
    
	void Arduino::keyPressed (int key) {
        
		bool debug = true;
        
		if (debug) {
			switch (key)
			{
				case '0':
					reset(true);
					break;
			}
            
            // TODO change this to switch case
            
			if (key == KEY_ANGLE_1INC) {
				moveMotor(1, angleMotor1 + ANGLE_STEP_FOR_KEY);
			} else if (key == KEY_ANGLE_1DEC) {
				moveMotor(1, angleMotor1 - ANGLE_STEP_FOR_KEY);
			} else if (key == KEY_ANGLE_2INC) {
				moveMotor(2, angleMotor2 + ANGLE_STEP_FOR_KEY);
			} else if (key == KEY_ANGLE_2DEC) {
				moveMotor(2, angleMotor2 - ANGLE_STEP_FOR_KEY);
			} else if (key == KEY_ANGLE_4INC) {
				moveMotor(4, angleMotor4 + ANGLE_STEP_FOR_KEY);
			} else if (key == KEY_ANGLE_4DEC) {
				moveMotor(4, angleMotor4 - ANGLE_STEP_FOR_KEY);
			}
			else if (key == KEY_RESET) {
				reset(false);
			}
			else if (key == KEY_PRINT_STATUS) {
				cout << read() << endl;
				cout << "motor 1: " << angleMotor1 << endl;
				cout << "motor 2: " << angleMotor2 << endl;
				cout << "motor 4: " << angleMotor4 << endl;
			}
		}
	}
    
    
	void Arduino::reset(bool forceReset)
	{
	}
    
	void Arduino::sendMotor(int value, int id)
	{
		if (value < 0){
			value = -value;
			value |= 1 << 7; //MAGIC!
		}
		char id_char = (char) id;
		serial.writeByte(id_char);
		serial.writeByte(value);
	}
    
	char* Arduino::read()
	{
		char* result;
		int byteCount = serial.available();
		if (byteCount > 0) {
			result = new char[byteCount];
			unsigned char byteRead = 0;
			int i = 0;
			while(serial.readBytes(&byteRead, 1) > 0) {
				result[i] = byteRead;
				i++;
			}
			result[i] = 0;
		}
		else
		{
			result = new char[1];
			result[0] = '\0';
		}
		return result;
	}
    
	int Arduino::moveMotor(int motorId, signed int degrees)
	{
		int error = 1;
        
		if (motorId == ID_MOTOR_1)
		{
			if (!ofInRange(degrees, ANGLE_MIN_1, ANGLE_MAX_1))
			{
				return error;
			}
			else
			{
				angleMotor1 = degrees;
			}
		}
		if (motorId == ID_MOTOR_2)
		{
			if (!ofInRange(degrees, ANGLE_MIN_2, ANGLE_MAX_2))
			{
				return error;
			}
			else
			{
				angleMotor2 = degrees;
			}
		}
		if (motorId == ID_MOTOR_4)
		{
			if (!ofInRange(degrees, ANGLE_MIN_4, ANGLE_MAX_4))
			{
				return error;
			}
			else
			{
				angleMotor4 = degrees;
			}
		}
        
		sendMotor(angleMotor1, ID_MOTOR_1);
		sendMotor(angleMotor2, ID_MOTOR_2);
		sendMotor(angleMotor4, ID_MOTOR_4);
        cout << this->read() << endl;
	}