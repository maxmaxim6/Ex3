CC=gcc
CFLAG=-Wall -g

all: txtfind isort

isort: isort.o main.o
	$(CC) $(CFLAG) -o isort main.o isort.o

txtfind: txtfind.o main2.o
	$(CC) $(CFLAG) -o txtfind main2.o txtfind.o 

main2.o:main2.c txtfind.h
	$(CC) $(CFLAG) -c main2.c

main.o:main.c isort.h 
	$(CC) $(CFLAG) -c main.c

txtfind.o:txtfind.c txtfind.h
	$(CC) $(CFLAG) -c txtfind.c -o $@

isort.o: isort.c isort.h
	$(CC) $(CFLAG) -c isort.c -o $@


.PHONY:clean all

clean:
	rm -f *.o txtfind isort


