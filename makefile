demo:demo.o byte_process.o
	gcc -g -o demo demo.o byte_process.o
demo.o:demo.c byte_process.h demo.h
	gcc -g -c demo.c 
byte_process.o: byte_process.c byte_process.h
	gcc -g -c byte_process.c
clean:
	rm -rf demo
	rm -rf *.o