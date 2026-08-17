#ifndef PCM3010_H
#define PCM3010_H

#include <stdint.h>
#include "stm32l4xx_hal.h"
#include <stdio.h>

#define BUFFER_SIZE 512

typedef struct {

	uint16_t pdwn_pin;
	GPIO_TypeDef *pwd_port;
	SAI_HandleTypeDef *transmit_hsai;
	SAI_HandleTypeDef *receive_hsai;
} pcm3010_config_t;

typedef struct {
	uint32_t tx_buffer[BUFFER_SIZE];
	uint32_t rx_buffer[BUFFER_SIZE];
	volatile uint32_t *input_p;
	volatile uint32_t *output_p;
} i2s_buffers_t;

extern pcm3010_config_t pcm3010_config;
extern i2s_buffers_t pcm3010_buffers;

extern volatile uint8_t output_ready;
extern volatile uint8_t input_ready;

void reset_pcm3010();
void init_pcm3010_dma();
void init_pcm3010();

#endif /* PCM3010_H */
