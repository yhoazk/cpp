APP = early_bind

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -Wall -std=c++11 ${APP}.cpp -o ${APP}.exe

run:
	./${APP}.exe
