include ../tools/tooldefs.mk
include ../tools/flagdefs.mk

# Derived parameters.

OBJECTS = $(SOURCES:.cpp=.o)

# Standard targets.

depend: 
	$(ECHO) > Makefile.dep
	$(MAKEDEP) -fMakefile.dep -Y -- $(INC) -- `find . -name '*.cpp'` >& /dev/null
# esse comando faz e   	

$(LIBRARY) : $(OBJECTS)
	$(AR) rv $@ $?
	$(RANLIB) $@


### Dependencies

