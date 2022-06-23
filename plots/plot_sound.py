#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np

samples_l = []
samples_r = []

def plot(fname):
    with open(fname) as sound:
        for line in sound:
            l,r = map(float, line.split(','))
            samples_l.append(l)
            samples_r.append(r)
        # 5 secs at 8k samples

        x = np.linspace(0,5, len(rigth))
        plt.subplot(2,1,1)
        plt.plot(x,left, '.-')

        plt.subplot(2,1,2)
        plt.plot(x,rigth, '.-')
        plt.show()

if __name__ == "__main__":
    plot("sound.csv")
