######################################################################
 # $Id: bintargets.mk,v 1.3 2001/07/18 21:33:08 ulucs Exp $
 #
 # Makefile utility to specify source files for a binary target.
 #
 # Created       : Uluc Saranli, 11/16/2000
 # Last Modified : Uluc Saranli, 06/27/2001
 #
 ######################################################################

include ../tools/tooldefs.mk
include ../tools/flagdefs.mk

# Derived parameters.

OBJECTS = $(SOURCES:.cpp=.o)
EXECOBJ = $(patsubst %,%.o,$(EXEC))
DEPLIBS = $(patsubst %,$(RHEX_DIR)/lib/%,$(LIBS)) $(AUXLIBS)
AUXLIBFILES = $(notdir $(AUXLIBS))
LINKLIBS = $(patsubst lib%.a,-l%,$(LIBS)) $(patsubst lib%.a,-l%,$(AUXLIBFILES))

# Standard targets.

all: $(EXEC) $(EXECOBJ)

$(EXEC) : $(EXECOBJ) $(OBJECTS) $(DEPLIBS)
	$(CXX) -o $@ $@.o $(OBJECTS) $(LDFLAGS) $(LINKLIBS) $(LDLIBS)

depend dep:
	$(ECHO) > Makefile.dep
	$(MAKEDEP) -fMakefile.dep -Y -- $(INC) -- `find . -name '*.cpp'` >& /dev/null
#	for i in *.cc; do $(CMM) $(INC) $$i; done > Makefile.dep

wc :
	@$(WC) -l *.cc *.hh Makefile | $(SORT) -r -n

clean:
	$(RM) -rf $(OBJECTS) $(EXECOBJ) $(EXEC) *~ *.err
	$(RM) -rf Makefile.dep.bak

cleanobj:
	$(RM) -rf $(OBJECTS) $(EXECOBJ) *~ *.err
	$(RM) -rf Makefile.dep.bak


### Dependencies
#ignore a makefile which does not exist or cannot be remade, with no error message
-include Makefile.dep

endif
