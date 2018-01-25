APP=example_0

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:

	g++ -pthread -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe
