demo:demo.o tcp_handle.o
	gcc -g -o demo demo.o tcp_handle.o
demo.o:demo.c tcp_handle.h demo.h
	gcc -g -c demo.c 
tcp_handle.o: tcp_handle.c tcp_handle.h
	gcc -g -c tcp_handle.c
clean:
	rm -rf demo
	rm -rf *.o