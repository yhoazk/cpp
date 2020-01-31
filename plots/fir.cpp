#include "fir.h"

static float filter_taps[SAMPLEFILTER_TAP_NUM] = {
  -810465886355.1636,
  -469131008187.29614,
  -241288006341.87198,
  -35153900783.07125,
  21319416523.075787,
  193983051536.34766,
  609082455094.6571,
  807028671932.3047,
  820165518395.129,
  544887708882.5558,
  153376533657.15417,
  145026489444.22772,
  -24359262286.560947,
  -337915867571.7054,
  -735618620364.0421,
  -1281874587150.669,
  -735618620364.0421,
  -337915867571.7054,
  -24359262286.560947,
  145026489444.22772,
  153376533657.15417,
  544887708882.5558,
  820165518395.129,
  807028671932.3047,
  609082455094.6571,
  193983051536.34766,
  21319416523.075787,
  -35153900783.07125,
  -241288006341.87198,
  -469131008187.29614,
  -810465886355.1636
};

void SampleFilter_init(SampleFilter* f) {
  int i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM; ++i)
    f->history[i] = 0;
  f->last_index = 0;
}

void SampleFilter_put(SampleFilter* f, float input) {
  f->history[f->last_index++] = input;
  if(f->last_index == SAMPLEFILTER_TAP_NUM)
    f->last_index = 0;
}

float SampleFilter_get(SampleFilter* f) {
  float acc = 0;
  int index = f->last_index, i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM; ++i) {
    index = index != 0 ? index-1 : SAMPLEFILTER_TAP_NUM-1;
    acc += f->history[index] * filter_taps[i];
  };
  return acc;
}
