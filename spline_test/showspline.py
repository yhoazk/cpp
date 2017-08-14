import matplotlib.pyplot as plt
import sys



if __name__ == "__main__":
    fd= open(sys.argv[1])
    x_l = []
    y_l = []
    for l in fd:
        x,y = map(float, l.split(','))
        x_l.append(x)
        y_l.append(y)

    plt.plot(x_l,y_l)
    plt.grid('on');
    plt.show()
