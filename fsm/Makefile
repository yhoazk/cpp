APP=fsm

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -Wall -Wextra -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe

