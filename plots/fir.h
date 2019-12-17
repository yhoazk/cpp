#ifndef SAMPLEFILTER_H_
#define SAMPLEFILTER_H_

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 2000 Hz

* 0 Hz - 100 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = 2.8871673830932423 dB

* 300 Hz - 1000 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = -43.12005635377503 dB

*/

#define SAMPLEFILTER_TAP_NUM 13

typedef struct {
  double history[SAMPLEFILTER_TAP_NUM];
  unsigned int last_index;
} SampleFilter;

void SampleFilter_init(SampleFilter* f);
void SampleFilter_put(SampleFilter* f, double input);
double SampleFilter_get(SampleFilter* f);

#endif
