.DEFUALT_GOAL := makefile.mk

CC = gcc
CFLAGS = -g -fopenmp
RM = rm -f
EX = ./

default: all

all: Integral

Integral: integral.c
	$(CC) $(CFLAGS) -o integral integral.c

run: integral
	$(EX)integral


clean veryclean:
	$(RM) integral

