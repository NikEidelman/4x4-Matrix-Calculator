matmain: matmain.o mymat.o input.o
	gcc -g -Wall -ansi -pedantic matmain.o mymat.o input.o -o matmain
matmain.o: matmain.c
	gcc -c -Wall -ansi -pedantic matmain.c -o matmain.o
mymat.o: mymat.c
	gcc -c -Wall -ansi -pedantic mymat.c -o mymat.o
input.o: input.c
	gcc -c -Wall -ansi -pedantic input.c -o input.o
