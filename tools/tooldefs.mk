#UNAME = $(shell uname)

# Definitions for Linux
#ifeq ($(UNAME), Darwin)

#CC = gcc
CXX = g++
#CPP = gcc -E
CMM = g++ -MM
AR = ar
RANLIB = ranlib
MAKE = make
MAKEDEP = makedepend
LN = ln -sf
#STRIP = strip
#RM = rm
#SED = sed
#MV = mv
CD = cd
#WC = wc
#TAR = tar
#GZIP = gzip
#SORT = sort
ECHO = echo
SHELL=/bin/bash

#endif