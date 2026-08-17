#include "pcm3010.h"

pcm3010_config_t pcm3010_config = { 0 };

i2s_buffers_t pcm3010_buffers = { 0 };

volatile uint8_t output_ready = 0;
volatile uint8_t input_ready = 0;
void init_pcm3010_dma() {

//	HAL_StatusTypeDef HAL_SAI_Transmit_DMA(SAI_HandleTypeDef *hsai, uint8_t *pData, uint16_t Size)
	HAL_SAI_Receive_DMA(pcm3010_config.receive_hsai, (uint8_t*) pcm3010_buffers.rx_buffer,
			sizeof(pcm3010_buffers.rx_buffer) / sizeof(pcm3010_buffers.rx_buffer[0]));
	HAL_SAI_Transmit_DMA(pcm3010_config.transmit_hsai, (uint8_t*) pcm3010_buffers.tx_buffer,
			sizeof(pcm3010_buffers.tx_buffer) / sizeof(pcm3010_buffers.tx_buffer[0]));
}

void reset_pcm3010() {
	HAL_GPIO_WritePin(pcm3010_config.pwd_port, pcm3010_config.pdwn_pin, GPIO_PIN_RESET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(pcm3010_config.pwd_port, pcm3010_config.pdwn_pin, GPIO_PIN_SET);
}

void init_pcm3010() {
	reset_pcm3010();
	//start each buffer on rightmost segment
	pcm3010_buffers.output_p = &pcm3010_buffers.tx_buffer[BUFFER_SIZE / 2];
	pcm3010_buffers.input_p = &pcm3010_buffers.rx_buffer[BUFFER_SIZE / 2];
	init_pcm3010_dma();
}

//tx half completed callback
void HAL_SAI_TxHalfCpltCallback(SAI_HandleTypeDef *hsai) {
	pcm3010_buffers.output_p = &pcm3010_buffers.tx_buffer[0];
	output_ready = 1;

}

//Tx complete callback
void HAL_SAI_TxCpltCallback(SAI_HandleTypeDef *hsai) {
	pcm3010_buffers.output_p = &pcm3010_buffers.tx_buffer[BUFFER_SIZE / 2];
	output_ready = 1;
}

//rx half completed callback
void HAL_SAI_RxHalfCpltCallback(SAI_HandleTypeDef *hsai) {
	pcm3010_buffers.input_p = &pcm3010_buffers.rx_buffer[0];
	input_ready = 1;
}

//Rx complete callback
void HAL_SAI_RxCpltCallback(SAI_HandleTypeDef *hsai) {
	pcm3010_buffers.input_p = &pcm3010_buffers.rx_buffer[BUFFER_SIZE / 2];
	input_ready = 1;
}

