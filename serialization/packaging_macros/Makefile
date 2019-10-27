APP=pragma_demo

all: clean comp run

clean:
	rm -rf ${APP}

comp:
	gcc -Wall -Wunknown-pragmas -o ${APP}.exe ${APP}.c

run:
	./${APP}.exe