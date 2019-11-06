APP=in_disk

all: clean comp

clean:
	rm -rf ${APP}

comp:
	g++ -Wall -g -Wunknown-pragmas -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe