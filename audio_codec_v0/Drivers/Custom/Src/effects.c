#include "effects.h"

//unity gain block. Output mirrors input
void unity_gain(uint32_t *output, uint32_t *input, uint16_t sample_size) {
	memcpy(output, input, sample_size * sizeof(*output));
}
