
UNAME = $(shell uname)

ifeq ($(UNAME), Darwin)
# Definitions for Macbook compilation

#DEFINES = -D_LINUX_ -D$(RHEX_HARDWARE)

INC = -I../include $(AUXFLAGS) $(DEFINES) 

CXXFLAGS = -Wall -g -Iinclude $(DEFINES) $(AUXFLAGS)

LDFLAGS  = -L./ $(AUXFLAGS) # -L. is used to tell that the static library is in current folder 
LDLIBS   = -lm

endif
