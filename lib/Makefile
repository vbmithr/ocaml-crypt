include ../Makefile.common

ifeq ($(UNAME),Linux)
	CLIBS += crypt
endif

NO_CUSTOM = y
SOURCES = crypt_stubs.c crypt.mli crypt.ml
RESULT = crypt

all:	native-code-library byte-code-library

include $(OCAMLMAKEFILE)

