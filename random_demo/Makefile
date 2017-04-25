APP = random_demo

all: clean comp run

clean:
	rm -rf ./${APP}.exe *.py *.log


comp:
	g++ -std=c++11 -o ${APP}.exe ${APP}.cpp


run:
	echo 900 | ./${APP}.exe > dist.py
	python dist.py
