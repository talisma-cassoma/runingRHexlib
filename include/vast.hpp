/************************************************************************
* Created       : Uluc Saranli, 01/05/2001
* Last Modified : Talisma Mnauel
* Note: The types vast and uvast are 64 bit signed and unsigned integer 
*       types respectively. In some platforms, these data types are 
*       implemented through C++ classes and may not provide all the 
*       standard operators for integers.
*************************************************************************
* This file is part of RHexLib, 
*
* Copyright (c) 2001 The University of Michigan, its Regents,
* Fellows, Employees and Agents. All rights reserved, and distributed as
* free software under the following license.
************************************************************************/

#ifndef _VAST_HH
#define _VAST_HH

// LINUX definitions 

//#ifdef _LINUX_
// In Linux, we have the long long data type

typedef long long vast;  //NOTE: Pour renommer  un  type donné, dans le but d’alléger son utilisation. on utilise en général, la déclaration typedef
typedef unsigned long long uvast;

#define VAST_TO_LONG(v) long(v)        
#define VAST_TO_DOUBLE(v) double(v)

//#endif // _LINUX_

// QNX4 definitions 

#endif
