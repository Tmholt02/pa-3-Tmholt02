OUTPUT := q1
GPP_FLAGS := -std=c++11 -Wall

.PHONY: all clean q1 q2

all: q1 q2

q1: q1.o openr.o
	g++ q1.o openr.o -o q1
	rm -f q1.o openr.o

q1.o: q1.cpp
	g++ $(GPP_FLAGS) -c q1.cpp -o q1.o

openr.o: openr.s
	g++ -c openr.s -o openr.o

q2: q2.cpp
	g++ $(GPP_FLAGS) q2.cpp -o q2

clean:
	rm -f q1.o openr.o q1 q2
