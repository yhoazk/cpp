APP=pid

all: clean comp run

clean:
	rm -rf ./${APP}.exe

comp:
	g++ -g -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe > pts.csv
	python plot.py
