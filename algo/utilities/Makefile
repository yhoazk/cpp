
#APP = <STH> Pass app as inArg

CC = g++ -g -std=c++11
#CC = gcc -g



all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	${CC} -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe


debug:
	gdb ./${APP}.exe
