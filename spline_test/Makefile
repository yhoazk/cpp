APP=demo_spline

all: clean comp run

clean: 
	rm -rf ./${APP}.exe

comp:
	g++ -o ${APP}.exe ${APP}.cpp

run:
	./${APP}.exe > data_pts.log
	python showspline.py data_pts.log

