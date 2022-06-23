
import matplotlib.pyplot as plt
from numpy.lib.function_base import sort_complex
import pandas as pd
import seaborn as sns
from pandas.plotting import register_matplotlib_converters
import random
import csv
from statsmodels.tsa.seasonal import STL
import numpy as np
from scipy.stats import trim_mean

register_matplotlib_converters()
sns.set_style("darkgrid")

timestamps = []

# with open("data.csv", "r") as data_fd:
#   data_points = csv.reader(data_fd)
#   for row in data_points:
#     timestamps.append(float(row[0]))

def drift(t2_last, t2, t1_last, t1):
  t1_diff = t1_last - t1
  return ((t2_last - t2) - (t1_diff)) / (t1_diff)


def clock(slope=1.0, noise_mag=1.0):
  result_data = []
  for value in np.linspace(0,100*slope, 100):
    result_data.append(value  + random.gauss(noise_mag, 1))
  return result_data


def push(t0, t1):
  pass

def diff(l):
  return [j-i for i, j in zip(l[:-1], l[1:])]

# https://stackoverflow.com/questions/2400840/python-finding-differences-between-elements-of-a-list
def abs_diff(l):
  return [abs(j-i) for i, j in zip(l, l[1:])]


def faproach(samples):
  avg = sum(samples) / len(samples)
  avg_dist = [abs(avg - n) for n in samples ]
  selected = sorted(avg_dist)[:8]
  return sum(selected) / 8.0



# ts_diff = diff(timestamps)
# print(ts_diff)
# plt.plot(ts_diff)
# plt.show()
sample_idx = range(0,100)
clk1 = clock(0.9)
print(f"Clk1 Max{max(clk1)}")
clk2 = clock(1.1, 1.5)

diff_clk = [ c2 - c1 for c1, c2 in zip(clk1, clk2) ]

sample_16 = abs_diff(diff_clk[:16])
print(sample_16)
print(faproach(sample_16))
print(trim_mean(sample_16, 0.25))


print(f"Clk1 Max{max(clk2)}")
plt.plot(sample_idx, diff_clk)
plt.twiny()
plt.plot(sample_idx, clk1)
plt.twiny()
plt.plot(sample_idx, clk2)
plt.show()