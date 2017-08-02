FLAGS=-fopenmp -O2 # -g
FC=gfortran
CC=gcc -lm


c_src = $(wildcard *.c)
c_exe = $(patsubst %.c, %, $(c_src))

f_src = $(wildcard *.f90)
f_exe = $(patsubst %.f90, %, $(f_src))

all:
	@echo "Usage: make [f|c]_kernel, [f|c]_pi, etc."

% : %.c
	$(CC) $(FLAGS) $< -o $@

% : %.f90
	$(FC) $(FFLAGS) $(FLAGS) $< -o $@

clean:
	rm -rf *.o *~ *.dSYM $(c_exe) $(f_exe)

echo:
	@echo $(c_src)
	@echo $(c_exe)

.PHONY: clean echo
