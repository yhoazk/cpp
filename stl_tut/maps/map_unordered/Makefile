APP=map_unordred_map
all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -g --std=c++14 -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe
