APP=vector_arr

all: clean comp run

comp:
	g++ -g -o ${APP}.exe ${APP}.cpp  -std=c++11

clean:
	rm -rf ./${APP}.exe

run:
	./${APP}.exe
