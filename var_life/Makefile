APP=var_life

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -std=c++11 -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe
