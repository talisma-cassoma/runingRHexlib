##teste 

LIBS = base/libbase.a 

include tools/tooldefs.mk ./tools/flagdefs.mk

### Standard targets.
all: libs clean

libs: $(LIBS)

$(LIBS): FORCE
	@$(ECHO)
	@$(CD) $(@D) ; $(MAKE) $(@F)
	@$(LN) ../$(@) lib 

FORCE:
clean:
	$(RM) -rf ./*/*.o ./*/*~ ./*/*.err

.PHONY: all clean 
