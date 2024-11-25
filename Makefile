libsort.a: bubble.o q.o show.o
	ar -rc libsort.a bubble.o q.o show.o
bubble.o:bubble.c
	gcc -c bubble.c -o bubble.o
q.o:q.c
	gcc -c q.c -o q.o
show.o:show.c
	gcc -c show.c -o show.o
 
.PHONY:install
install:	
	
	mkdir -p sort/lib
	mkdir -p sort/include
	cp -rf *.h sort/include
	cp -rf *.a sort/lib
	cp -r sort test
	cp -r main.c test

