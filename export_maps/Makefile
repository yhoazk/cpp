APP=test_flight
LIB=spaceship
##
all: clean comp run

clean:
	rm -rf ./${APP}.exe

getlib:
	g++ -shared -fPIC ${LIB}.cpp -o lib${LIB}.so.1 -W1,-soname=lib${LIB}.so.1
	ln -s lib${LIB}.so.1 lib${LIB}.so

comp:
	g++ -Wall -l${LIB} -o ${APP}.exe ${APP}.cpp
	export LD_DEBUG=symbols
	export LD_LIBRARY_PATH=.

run:
	./${APP}.exe 
