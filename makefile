CC=gcc
AR=ar
FLAGS= -g -Wall

mains: main.o libmyBank.a  
	$(CC) $(FLAGS) -o mains main.o libmyBank.a

libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o  *.a mains 

