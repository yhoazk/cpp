APP=inputWoIntro

CC=g++


all: clean comp run

clean:
	rm -rf ${APP}.exe

comp:
	${CC} -std=c++11 -o ${APP}.exe ${APP}.cpp

run:
	,/${APP}.exe
