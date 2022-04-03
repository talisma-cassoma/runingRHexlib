/*********************************************************************
 * $Id: SimMotor.cc,v 1.3 2001/07/18 21:33:08 ulucs Exp $
 *
 * Low level hardware interface to the DC motors in the SimSect interface
 *
 * Created       : Uluc Saranli, 03/22/2001
 * Last Modified : Talisma Manuel, 
 *
 ********************************************************************/

//#ifdef _LINUX_      // Only compile this file for Linux

#include <math.h>
#include "ModuleManager.hpp"
#include "SimSectHW.hpp"
#include "SimComponents.hpp"
#include "SimSectDriver.hh"


// SimMotor::SimMotor : Class constructor
SimMotor::SimMotor( void ) {

  MMMessage( "Initializing DC motor interfaces..." );

  // Determine the mode of operation
  controlMode = VOLTAGE_MODE;

  MMMessage( "done.\n" );

}

// SimMotor::getParams : Returns hardware specific constant parameters
void SimMotor::getParams( uint index, MotorParam_t *params ) {

  params->torqueConstant = SIMSECT_TORQUE_CONST;
  params->speedConstant = SIMSECT_SPEED_CONST;
  params->terminalResistance = SIMSECT_RA;

  params->encRatio = SIMSECT_ENC_RATIO;
  params->gearRatio = SIMSECT_GEAR_RATIO;

}

float SimMotor::getVoltage( uint index ) {

  // Read the motor terminal voltage from the SimSectDriver class
  return driver->motorVoltage( index );

};

float SimMotor::getCurrent( uint index ) {

  // Read the motor armature current from the SimSectDriver class
  return driver->motorCurrent( index ); 

};

float SimMotor::getBackEMF( uint index ) {

  // Read the motor back EMF from the SimSectDriver class
  return driver->motorBackEMF( index ); 

};

//
// Sets the command to the motor based on the control mode and the
// calibration parameters.
//
void SimMotor::setCommand( uint index, float cmd ) {

  // Set the command through the SimSect interface class.
  // Note that the control mode will be determined by SimSectDriver and the
  // command will be appropriately clipped.
  driver->setCommand( index, cmd );

};

float SimMotor::getCommand( uint index ) {

  // Get the latest command from SimSectDriver.
  return driver->getCommand( index );
}

//#endif
