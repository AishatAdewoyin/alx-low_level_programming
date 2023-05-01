#!/bin/bash
gcc -c *.c
ar rc liball.a *.o
echo y | rm -I *.o
