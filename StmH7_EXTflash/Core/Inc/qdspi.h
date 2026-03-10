/*
 * qdspi.h
 *
 *  Created on: 03-Mar-2026
 *      Author: adin.n@acsiatech.com
 */

#ifndef INC_QDSPI_H_
#define INC_QDSPI_H_


/* USER CODE BEGIN Private defines */

uint8_t CSP_QUADSPI_Init(void);
uint8_t CSP_QSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress);
uint8_t CSP_QSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size);
uint8_t CSP_QSPI_EnableMemoryMappedMode(void);
uint8_t CSP_QSPI_Erase_Chip (void);
uint8_t CSP_QSPI_ReadMemory(uint8_t* pData, uint32_t ReadAddr, uint32_t Size);

/* USER CODE END Private defines */

/* USER CODE BEGIN Prototypes */

/*MT25QL128A memory parameters*/
#define MEMORY_FLASH_SIZE   					0x200000   /* 2MB (16 Mbits) */
#define MEMORY_SECTOR_SIZE  					0x10000    /* 64KB block */
#define MEMORY_PAGE_SIZE    					0x100      /* 256 bytes */


/*MT25QL128A commands */
#define WRITE_ENABLE_CMD 						0x06
#define READ_STATUS_REG_CMD 					0x05
#define QUAD_WRITE_VOL_CFG_REG_CMD 				0x50U
#define QUAD_WRITE_DISABLE_CMD 					0x04U

#define SECTOR_ERASE_CMD 						0x20
#define CHIP_ERASE_CMD 							0xC7
#define QUAD_IN_FAST_PROG_CMD 					0x32

#define READ_CONFIGURATION_REG_CMD 				0x5A

#define QUAD_OUT_FAST_READ_CMD 					0x6B
#define DUMMY_CLOCK_CYCLES_READ_QUAD 			8
#define RESET_ENABLE_CMD 						0x66
#define RESET_EXECUTE_CMD 						0x99
#define QUAD_FAST_READ_IO_CMD 					0xEBU
#define QUAD_RESET_ENABLE_CMD					0x66U
#define QUAD_RESET_EXECUTE_CMD					0x99U
#define QUAD_64KB_BLOCK_ERASE 					0xD8U

#define QUAD_READ_SR1_CMD						0x05U
#define QUAD_READ_SR2_CMD						0x35U
#define QUAD_READ_SR3_CMD						0x15U

#define QUAD_WRITE_SR1_CMD						0x01U
#define QUAD_WRITE_SR2_CMD						0x31U
#define QUAD_WRITE_SR3_CMD						0x11U
/*MT25QL128A timeouts*/
#define QUADSPI_MAX_ERASE_TIMEOUT 460000 /* 460s max */

/* USER CODE END Prototypes */

#endif /* INC_QDSPI_H_ */
