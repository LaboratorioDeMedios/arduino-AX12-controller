//
//  Arduino.h
//  ax12OSCServer
//
//  Created by german on 4/24/14.
//
//

#ifndef __ax12OSCServer__Arduino__
#define __ax12OSCServer__Arduino__

#include <math.h>
#include <map>
#include <ofMath.h>
#include <ofxOsc.h>

#include "ofSerial.h"

#define		ID_MOTOR_1			1
#define		ID_MOTOR_2			2
#define		ID_MOTOR_4			4
#define		ID_MOTOR_8			8

	class Arduino: public ofxOscReceiver{
        
	public:
		virtual ~Arduino();
		Arduino();
        
		virtual bool		setup();
		virtual void		exit();
		virtual void		update();
		virtual void		draw();
        
		virtual void		keyPressed(int key);
        
		void				reset(bool forceReset);
        
		int				moveMotor(int motorId, signed int degrees);
		ofVec3f				lookAt(const ofVec3f& point);

		char*				read();
		
		signed int*			motorAngles() const;
        
	private:
		void				sendMotor(int value, int id);
		ofSerial			serial;
		signed int			angleMotor1;
		signed int			angleMotor2;
		signed int			angleMotor4;
	};

#endif /* defined(__ax12OSCServer__Arduino__) */
