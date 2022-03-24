/************************************************************************
* Created       : Uluc Saranli, 11/16/2000
* Last Modified : Talisma Manuel
* Note: basic data types used in RHexLib
*************************************************************************
* This file is part of RHexLib, 
*
* Copyright (c) 2001 The University of Michigan, its Regents,
* Fellows, Employees and Agents. All rights reserved, and distributed as
* free software under the following license.
************************************************************************/

#ifndef TYPES_HPP
#define TYPES_HPP

// Local includes
#include "vast.hpp" // Defines a 64 bit integer data type 


// Type definitions 
// A Boolean type
#ifdef _LINUX_

typedef bool BOOL;

#endif

#ifdef _QNX4_

typedef enum{ false = 0, true = 1 } bool;
typedef bool BOOL;

#endif

// Shortcut types
typedef char int8;
typedef unsigned char uint8;
typedef short int int16;
typedef unsigned short int uint16;
typedef int int32;
typedef unsigned int uint32;
typedef vast int64;
typedef uvast uint64;
typedef unsigned int uint;  //desnecessario 

// The CLOCK datatype. Holds the clock value in us.
typedef int64 CLOCK;
#define CLOCK_TO_LONG(c) VAST_TO_LONG(c)
#define CLOCK_TO_DOUBLE(c) VAST_TO_DOUBLE(c)
#define SEC_TO_CLOCK( _num_ ) ( CLOCK ) ( 1000000.0 * (_num_) )
#define MIN_TO_CLOCK( _num_ ) ( CLOCK ) ( 60000000.0 * (_num_) )
#define HOUR_TO_CLOCK( _num_ ) ( CLOCK ) ( 360000000.0 * (_num_) )
#define CLOCK_TO_SEC( _num_ ) ( CLOCK_TO_DOUBLE( _num_ ) / 1000000.0 )
#define CLOCK_TO_MIN( _num_ ) ( CLOCK_TO_DOUBLE( _num_ ) / 60000000.0 )
#define CLOCK_TO_HOUR( _num_ ) ( CLOCK_TO_DOUBLE( _num_ ) / 360000000.0 )

#define MM_CLOCKS_PER_SEC 1000000L

// Some useful definitions
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#endif
