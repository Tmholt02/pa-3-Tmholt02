OUTPUT := q1
GPP_FLAGS := -std=c++11 -Wall

.PHONY: all clean q1 q2

all: q1 q2

q1: q1.cpp openr.s
	g++ $(GPP_FLAGS) q1.cpp openr.s -o q1

q2: q2.cpp
	g++ $(GPP_FLAGS) q2.cpp -o q2

clean:
	rm -f q1.o openr.o q1 q2
