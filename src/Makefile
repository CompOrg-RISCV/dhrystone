# Path to clang inside Codasip package
CLANG=../../../sdk/bin/bk3-32IMC-UIDpid-ia-clang

# Benchmark settings
CFLAGS=-D__INT32 -DNOSTRUCTASSIGN -DHAS_PRINTF=1 -O3
LDFLAGS=-O3 -Xlinker --defsym=_STACK_SIZE=0x4000 -Xlinker --defsym=_HEAP_SIZE=0x4000 -stdlib=newlib
DEPS=codasip/portme.h dhry.h
OBJ=dhry_1.o dhry_2.o
LIBS=-lcomp -lm -lsim

# Build object files
%.o: %.c $(DEPS)
	$(CLANG) -c -o $@ $< $(CFLAGS)

# Link benchmark application
dhrystone.xexe: $(OBJ)
	$(CLANG) -o $@ $^ $(LDFLAGS) $(LIBS)

# All target
all: dhrystone.xexe

# Clean target
clean:
	rm -f $(OBJ) dhrystone.xexe
