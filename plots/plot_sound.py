#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
import scipy.signal as ss


def parse_data(fname):
    samples_l = []
    samples_r = []
    with open(fname) as sound:
        for line in sound:
            l,r = map(abs, map(float, line.split(',')))
            samples_l.append(l)
            samples_r.append(r)
        # 5 secs at 8k samples
    return (samples_l, samples_r)

def plot(channels):
    (ch_l, ch_r) = channels
    x = np.linspace(0,5, len(ch_l))
    plt.subplot(2,1,1)
    plt.plot(x,ch_l, '.-')

    plt.subplot(2,1,2)
    plt.plot(x,ch_r, '.-')
    plt.show()

"""
calculate the envelope of the signal
if the magnitude of the envelope crosses from lower->higher and higher->lower then is a hit.
The magnitude of the threshold needs to be updated wrt to the current median and some stddeviations
"""


def envelop(signal):
    """
    Using Hilbert  or scipy.find_peaks
    https://en.wikipedia.org/wiki/Analytic_signal
    """
    pass


def filter_median(samples):
    (samples_l, samples_r) = samples
    ch_r = np.abs(ss.hilbert(samples_r))
    ch_l = np.abs(ss.hilbert(samples_l))
    return (ch_l, ch_r)


if __name__ == "__main__":
    plot(filter_median(parse_data("sound.csv")))

