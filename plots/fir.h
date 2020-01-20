#ifndef SAMPLEFILTER_H_
#define SAMPLEFILTER_H_

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 44100 Hz

* 0 Hz - 400 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = 3.5780710342581137 dB

* 500 Hz - 1000 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = -41.298681852902575 dB

*/

#define SAMPLEFILTER_TAP_NUM 31

typedef struct {
  float history[SAMPLEFILTER_TAP_NUM];
  unsigned int last_index;
} SampleFilter;

void SampleFilter_init(SampleFilter* f);
void SampleFilter_put(SampleFilter* f, float input);
float SampleFilter_get(SampleFilter* f);

#endif
