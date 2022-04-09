
UNAME = $(shell uname)

ifeq ($(UNAME), Darwin)
# Definitions for Macbook compilation

#DEFINES = -D_LINUX_ -D$(RHEX_HARDWARE)

INC = -I../include $(AUXFLAGS) $(DEFINES) 

CXXFLAGS = -Wall -g -I../include   $(DEFINES) $(AUXFLAGS)

LDFLAGS  = -L/lib $(AUXFLAGS)
LDLIBS   = -lm

endif
