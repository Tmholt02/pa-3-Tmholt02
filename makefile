OUTPUT := q1
GPP_FLAGS := -std=c++11 -Wall

.PHONY: all clean q1

all: q1

q1: q1.o openr.o
	g++ q1.o openr.o -o $(OUTPUT)
	rm -f q1.o openr.o

q1.o: q1.cpp
	g++ $(GPP_FLAGS) -c q1.cpp -o q1.o

openr.o: openr.s
	g++ -c openr.s -o openr.o

clean:
	rm -f q1.o openr.o $(OUTPUT)