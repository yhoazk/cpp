APP=main

all: clean comp run

clean:
	rm -rf ${APP}.exe

comp:
	g++ -Wall -o ${APP}.exe ${APP}.cpp impl_class.cpp model_class.cpp

run:
	./${APP}.exe
