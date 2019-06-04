CXX=tcc

CLIENT_LIBS= -lreadline
CFLAGS= -g -Wall -std=c99 -pedantic
OUTFILE= -o bin/mlsp

default: all

all:
	$(CXX) main.c hash.c sds.c $(CFLAGS) $(OUTFILE) $(CLIENT_LIBS)
