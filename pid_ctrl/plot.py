import matplotlib.pyplot as plt
import csv

x = []
y = []
def main():
    csvr = csv.reader(open("pts.csv"))
    for l in csvr:
        a,b = map(float, l)
        x.append(a)
        y.append(b)

    plt.plot(x,y)
    plt.grid('on')
    plt.show()




if __name__ == "__main__":
    main()

