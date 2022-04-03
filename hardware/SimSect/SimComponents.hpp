/*********************************************************************
 * $Id: SimComponents.hh,v 1.3 2001/07/18 21:33:08 ulucs Exp $
 *
 * Internal data type definitions and function prototypes for the
 * SimSect hardware components
 *
 * Created       : Uluc Saranli, 03/11/2001
 * Last Modified : Uluc Saranli, 06/27/2001
 *
 ********************************************************************/

#ifndef _SIMCOMPONENTS_HPP
#define _SIMCOMPONENTS_HPP

//#ifdef _LINUX_      // Only compile this file for Linux

// Local includes
#include "Hardware.hpp"
#include "SimSectHW.hpp"

// SimSect hardware specific constants --------------------------------------

#define SIMSECT_TORQUE_CONST 0.0161          // Torque constant ( Nm / A )
#define SIMSECT_RA           1.34            // Armature resistance (in ohm )
#define SIMSECT_SPEED_CONST  55.3685         // Speed constant ( rad/s / V )
#define SIMSECT_ENC_RATIO    2000            // Encoder ratio ( count/rev )
#define SIMSECT_GEAR_RATIO   (1.0 / 33.0625) // Gear ratio (output rev / shaft rev)

#define SIMSECT_DRIVE_OFFSET 5.7         // drive offset for the "motors" ( V )
#define SIMSECT_DRIVE_DROP   0.0         // Motor drive voltage drop coefficient ( V/A )
#define SIMSECT_DRIVE_SCALE  (2.0 / 4.0) // Motor drive PWM output scaling ([-1,1]/V)
#define SIMSECT_DRIVE_SUPPLY 24          // Motor drive voltage suppy value (V)
#define SIMSECT_AOUT_MIN     0.0         // Analog Output limits (V)
#define SIMSECT_AOUT_MAX     10.0

// The SiMSectHW component classes ------------------------------------------

class SimEncoder : public EncoderHW {
public:
  ~SimEncoder( ) { };

  void   enable( uint index );
  void   disable( uint index );

  uint16 read( uint index );
  void   reset( uint index );

};

class SimAnalog : public AnalogHW {
public:
  ~SimAnalog( ) { };

  float read( uint index );
  void  write( uint index, float value );

  void  outputRange( uint index, float *min, float *max ) {
    *min = SIMSECT_AOUT_MIN;
    *max = SIMSECT_AOUT_MAX;
  };

};

// SimSect digital channels. Not implemented yet!.
class SimDigital : public DigitalHW {
public:

  uint   getByte( uint byte ) { return 0; };
  void   setByte( uint byte, uint8 value ) { };
  bool   getBit( uint byte, uint bit ) { return false; };
  void   setBit( uint byte, uint bit, bool value ) { };

};

// SimSect timers. Not implemented yet!.
class SimTimer : public TimerHW {
public:

  void   setup( uint timer, uint mode, uint32 hertz ) { };
  uint16 read( uint timer ) { return 0; };
  void   getInfo( uint timer, uint *initial, uint *clockFreq ) {
    *initial = 0; *clockFreq = 0; 
  };

};

// SimSect accelerometers. Not implemented yet!.
class SimAccel : public AccelHW {
public:

  float read( Axis a );
  void getInfo( Axis axis, float *resolution, float *limit );
};

// SimSect gyros. 
class SimGyro : public GyroHW {
public:

  float readRate( Axis a );
  float readAngle( Axis a );

  void resetAngle( Axis a, float val ) { };
  void setOffset( Axis a, float val ) { };
    
  void getInfo( Axis axis, float *resolution, float *limit );
};


// Interface class to the system power (battery etc. )
class SimPower : public PowerHW {
public:

  float voltage( void ) { return 24.0; };
  float current( void ) { return 0.0; };
};

class SimSwitch : public SwitchHW {
public:

  bool read( uint index );
};

class SimDial : public DialHW {
public:

  float read( uint index );
};

// Interface class to the DC motors.
class SimMotor : public DCMotorHW {

public:

  SimMotor( void );

  void  getParams( uint index, MotorParam_t *param );

  float getVoltage( uint index );
  float getCurrent( uint index );
  float getBackEMF( uint index );
  float getTemperature( uint index ) { return 0.0; };

  ControlMode getControlMode( uint index ) { return controlMode; };
  void setCommand( uint index, float cmd );
  float getCommand( uint index );

  void getCalibration( uint index, MotorCalib_t *calib ) {
    // SimSect's calibration is static, so we can just return constants here.

    calib->driveOffset = SIMSECT_DRIVE_OFFSET;
    calib->drivePolarity = +1;

  };

  void setCalibration( uint index, MotorCalib_t *calib ) { };

private:

  ControlMode  controlMode;

};

//#endif

#endif // #ifndef _SIMCOMPONENTS_HH

