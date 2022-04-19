##teste 
BINDIR = examples #examples/quickstart examples/esp examples/exprunner

LIBS = base/libbase.a 

HWLIBS = hardware/virtual/libvirtualhw.a \
	hardware/common/libcommonhw.a \
	hardware/SimSect/libsimsecthw.a

OBJECTS = $(SOURCES:.cpp=.o)
EXECOBJ = $(patsubst %,%.o,$(EXEC))
DEPLIBS = $(patsubst %,$(RHEX_DIR)/lib/%,$(LIBS)) $(AUXLIBS)
AUXLIBFILES = $(notdir $(AUXLIBS))
LINKLIBS = $(patsubst lib%.a,-l%,$(LIBS)) $(patsubst lib%.a,-l%,$(AUXLIBFILES))

include tools/tooldefs.mk ./tools/flagdefs.mk

### Standard targets.
 
main: main.o base/libbase.a 
	g++ -o $@ $@.o $(LINKLIBS) $(LDFLAGS) $(LDLIBS) 

main.o: examples/main.cpp
	g++ -o $@ -c $< $(CXXFLAGS)

#libs: $(LIBS) $(HWLIBS)
#
#$(LIBS) : FORCE
#	@$(ECHO)
#	@$(CD) $(@D) ; $(MAKE) $(@F)
#	@$(LN) ../$(@) lib 
 

#FORCE:
clean:
	$(RM) -rf ./*/*.o ./*/*~ ./*/*.err

.PHONY: main clean

