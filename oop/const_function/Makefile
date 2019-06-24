APP=const_function

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -std=c++11 -g -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe
