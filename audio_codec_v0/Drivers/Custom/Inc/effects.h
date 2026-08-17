#ifndef EFFECTS_H
#define EFFECTS_H

#include "pcm3010.h"
#include "string.h"


void unity_gain(uint32_t *output, uint32_t *input, uint16_t sample_size);

#endif /* EFFECTS_H */
