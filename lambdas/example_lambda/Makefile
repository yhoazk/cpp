APP=example_lambda

all: clean comp run

clean:
	rm -rf ./${APP}.exe
comp:
	g++ -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe
