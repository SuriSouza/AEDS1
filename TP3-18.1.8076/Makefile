all: tp3
tp3: TConj.o main.o
	gcc -lm -o tp3 TConj.o main.o
conj.o: TConj.c Tconj.h
	gcc -lm -o TConj.o -c TConj.c
main.o: main.c TConj.h
	gcc -lm -o main.o -c main.c

clean:
	rm -rf *.o
