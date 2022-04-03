/*********************************************************************
 * $Id: SimSectHW.hh,v 1.3 2001/07/18 21:33:08 ulucs Exp $
 *
 * Internal data type definitions and function prototypes for the
 * SimSect hardware configuration
 *
 * Created       : Uluc Saranli, 03/11/2001
 * Last Modified : Uluc Saranli, 03/11/2001
 *
 ********************************************************************/

#ifndef _SIMSECTHW_HPP
#define _SIMSECTHW_HPP

// Local includes
#include "Hardware.hh"
#include "ModuleManager.hh"

// SimSectHW Class -------

class SimSectHW : public Hardware {

private:
  static bool   initStatus;

public:
  ~SimSectHW( );

  void initialize( void );
  void cleanup( void );

  CLOCK readClock( void );
  CLOCK readUClock( void ) { return readClock(); };

  void driveEnable( uint index, bool enable ) { };

};

// This global variable can be used to access SimSect states for
// logging purposes.  Note that SimSectDriver.hh must be included
// before using this variable
extern class SimSectDriver *driver;

#endif // #ifndef _SIMSECTHW_HH
