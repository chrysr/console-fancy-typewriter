CC = g++
CFLAGS  =-w #-g -pg
DEPS= functions.h

type:  main.o functions.o 
	$(CC) $(CFLAGS) -o type main.o functions.o 

main.o:  main.cpp functions.h 
	$(CC) $(CFLAGS) -c main.cpp

functions.o:  functions.cpp functions.h 
	$(CC) $(CFLAGS) -c functions.cpp

clean: 
	$(RM) type *.o

