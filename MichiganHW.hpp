/*********************************************************************
 * $Id: MichiganHW.hh,v 1.4 2001/07/19 16:35:56 ulucs Exp $
 *
 * Internal data type definitions and function prototypes for the
 * hardware components of the University of Michigan version of 
 * RHex.
 *
 * Created       : Uluc Saranli, 12/20/2000
 * Last Modified : Talisma 
 *
 ********************************************************************/

#ifndef _MICHIGANHW_HH
#define _MICHIGANHW_HH

// Local includes
#include "Hardware.hpp"

// MichiganHW Class ----

class MichiganHW : public Hardware {
public:
  MichiganHW( void );
  ~MichiganHW( );

  void initialize( void );
  void cleanup( void );

  CLOCK readClock( void );
  CLOCK readUClock( void );
  void driveEnable( uint ind, bool enable );

private:
  void driveEnable( bool enable );
  void initClock( void );

  static bool initStatus;
  static bool clockStatus;
  uint driveStatus;

};

#endif // #ifndef _MICHIGANHW_HH
