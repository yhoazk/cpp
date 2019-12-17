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
    x = np.linspace(0,5, 5120)
    plt.plot(x,left)
    plt.show()