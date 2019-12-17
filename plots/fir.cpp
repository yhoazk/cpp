#include "fir.h"

static double filter_taps[SAMPLEFILTER_TAP_NUM] = {
  0.012026765746421812,
  0.03261684037369995,
  0.06122441295592891,
  0.09888486427087445,
  0.13308596524836538,
  0.16020764381252148,
  0.1685922024209116,
  0.16020764381252148,
  0.13308596524836538,
  0.09888486427087445,
  0.06122441295592891,
  0.03261684037369995,
  0.012026765746421812
};

void SampleFilter_init(SampleFilter* f) {
  int i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM; ++i)
    f->history[i] = 0;
  f->last_index = 0;
}

void SampleFilter_put(SampleFilter* f, double input) {
  f->history[f->last_index++] = input;
  if(f->last_index == SAMPLEFILTER_TAP_NUM)
    f->last_index = 0;
}

double SampleFilter_get(SampleFilter* f) {
  double acc = 0;
  int index = f->last_index, i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM; ++i) {
    index = index != 0 ? index-1 : SAMPLEFILTER_TAP_NUM-1;
    acc += f->history[index] * filter_taps[i];
  };
  return acc;
}