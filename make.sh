#!/bin/bash

FLAGS="-Wall -Wextra -Wpedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -Wjump-misses-init -Wlogical-op -g"

# Compile
gcc -c frac.c -o frac.o 
gcc -c frac_test.c -o frac_test.o 

# Linking
gcc ${FLAGS} frac.o frac_test.o -lcunit -o out

# Running
./out
