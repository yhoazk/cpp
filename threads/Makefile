APP = threads_test

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -Wall -std=c++11 -pthread ${APP}.cpp -o ${APP}.exe

run:
	./${APP}.exe

	
