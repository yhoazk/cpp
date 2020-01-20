#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np



with open("sound.csv") as sound:
    left = []
    rigth = []
    for line in sound:
        l,r = map(float, line.split(','))
        left.append(l)
        rigth.append(r)
    # 5 secs at 8k samples    
    
    x = np.linspace(0,5, len(rigth))
    plt.subplot(2,1,1)
    plt.plot(x,left, '.-')

    plt.subplot(2,1,2)
    plt.plot(x,rigth, '.-')

    plt.show()