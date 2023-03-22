make: all

all: compile run

compile:
	g++ -Wall -std=c++11 -o a.out main.cpp reading.cpp Shape.cpp Sphere.cpp Cylinder.cpp Torus.cpp Box.cpp

run: 
	./a.out shapes.dat

clean:
	rm a.out
	rm -f *.o