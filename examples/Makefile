 ######################################################################
 # $Id: Makefile,v 1.5 2001/08/06 20:29:09 ulucs Exp $
 #
 # The Makefile for the RHexLib example executables
 #
 # Created       : Uluc Saranli, 11/16/2000
 # Last Modified : Uluc Saranli, 06/27/2001
 #
 ######################################################################


############################################
# Modify the following segment only.       #
############################################

# This line defines the name of the executables. Note that we assume
# the presence of an associated .cc file as well.
EXEC = \
	main
# This line specifies all the other source files that need to be
# compiled and linked together with the executable
SOURCES =  

# This line specifies any additional flags that you want to feed the
# compiler. It is usually used to specify additional include
# directories through -I and additional link directories through -L
AUXFLAGS = 

# This line specifies any additional libraries that you want to link
# your executable against. Note that you MUST specify the full path of
# the library in question.
AUXLIBS = 

# The following sections set the variable LIBS based on which hardware
# platform is currently being uised. The LIBS variable contains ONLY
# the names of the libraries, without the path. The Makefile tools
# append the path automatically.



LIBS = libbase.a #librhex.a libvirtualhw.a libsimsecthw.a libcommonhw.a 
#For SimSect, we will need some additional libraries
#AUXLIBS += $(SIMSECT_DIR)/lib/libhexapod.a $(SIMSECT_DIR)/lib/libengine.a 


#################################################
# The rest of this file should not be modified  #
#################################################

include ../tools/bintargets.mk

