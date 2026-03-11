/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    octospi.c
 * @brief   This file provides code for the configuration
 *          of the OCTOSPI instances.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "octospi.h"

/* USER CODE BEGIN 0 */
OSPI_HandleTypeDef hqspi;

/* USER CODE END 0 */

OSPI_HandleTypeDef hospi1;

/* OCTOSPI1 init function */
void MX_OCTOSPI1_Init(void)
{

  /* USER CODE BEGIN OCTOSPI1_Init 0 */

  /* USER CODE END OCTOSPI1_Init 0 */

  OSPIM_CfgTypeDef sOspiManagerCfg = {0};

  /* USER CODE BEGIN OCTOSPI1_Init 1 */

  /* USER CODE END OCTOSPI1_Init 1 */
  hqspi.Instance = OCTOSPI1;
  hqspi.Init.FifoThreshold = 1;
  hqspi.Init.DualQuad = HAL_OSPI_DUALQUAD_DISABLE;
  hqspi.Init.MemoryType = HAL_OSPI_MEMTYPE_MICRON;
  hqspi.Init.DeviceSize = 20;
  hqspi.Init.ChipSelectHighTime = 1;
  hqspi.Init.FreeRunningClock = HAL_OSPI_FREERUNCLK_DISABLE;
  hqspi.Init.ClockMode = HAL_OSPI_CLOCK_MODE_0;
  hqspi.Init.WrapSize = HAL_OSPI_WRAP_NOT_SUPPORTED;
  hqspi.Init.ClockPrescaler = 2;
  hqspi.Init.SampleShifting = HAL_OSPI_SAMPLE_SHIFTING_NONE;
  hqspi.Init.DelayHoldQuarterCycle = HAL_OSPI_DHQC_DISABLE;
  hqspi.Init.ChipSelectBoundary = 0;
  hqspi.Init.DelayBlockBypass = HAL_OSPI_DELAY_BLOCK_BYPASSED;
  hqspi.Init.MaxTran = 0;
  hqspi.Init.Refresh = 0;
  if (HAL_OSPI_Init(&hqspi) != HAL_OK)
  {
    Error_Handler();
  }
  sOspiManagerCfg.ClkPort = 1;
  sOspiManagerCfg.NCSPort = 1;
  sOspiManagerCfg.IOLowPort = HAL_OSPIM_IOPORT_1_LOW;
  if (HAL_OSPIM_Config(&hqspi, &sOspiManagerCfg, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN OCTOSPI1_Init 2 */

  /* USER CODE END OCTOSPI1_Init 2 */

}

void HAL_OSPI_MspInit(OSPI_HandleTypeDef* ospiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(ospiHandle->Instance==OCTOSPI1)
  {
  /* USER CODE BEGIN OCTOSPI1_MspInit 0 */

  /* USER CODE END OCTOSPI1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_OSPI;
    PeriphClkInitStruct.OspiClockSelection = RCC_OSPICLKSOURCE_D1HCLK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* OCTOSPI1 clock enable */
    __HAL_RCC_OCTOSPIM_CLK_ENABLE();
    __HAL_RCC_OSPI1_CLK_ENABLE();

    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**OCTOSPI1 GPIO Configuration
    PE2     ------> OCTOSPIM_P1_IO2
    PA1     ------> OCTOSPIM_P1_IO3
    PB2     ------> OCTOSPIM_P1_CLK
    PD11     ------> OCTOSPIM_P1_IO0
    PD12     ------> OCTOSPIM_P1_IO1
    PB6     ------> OCTOSPIM_P1_NCS
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPIM_P1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN OCTOSPI1_MspInit 1 */

  /* USER CODE END OCTOSPI1_MspInit 1 */
  }
}

void HAL_OSPI_MspDeInit(OSPI_HandleTypeDef* ospiHandle)
{

  if(ospiHandle->Instance==OCTOSPI1)
  {
  /* USER CODE BEGIN OCTOSPI1_MspDeInit 0 */

  /* USER CODE END OCTOSPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_OCTOSPIM_CLK_DISABLE();
    __HAL_RCC_OSPI1_CLK_DISABLE();

    /**OCTOSPI1 GPIO Configuration
    PE2     ------> OCTOSPIM_P1_IO2
    PA1     ------> OCTOSPIM_P1_IO3
    PB2     ------> OCTOSPIM_P1_CLK
    PD11     ------> OCTOSPIM_P1_IO0
    PD12     ------> OCTOSPIM_P1_IO1
    PB6     ------> OCTOSPIM_P1_NCS
    */
    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_2);

    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_1);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_2|GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_11|GPIO_PIN_12);

  /* USER CODE BEGIN OCTOSPI1_MspDeInit 1 */

  /* USER CODE END OCTOSPI1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

static uint8_t QSPI_WriteEnable(void);
static uint8_t QSPI_AutoPollingMemReady(uint32_t Timeout);
static uint8_t QSPI_Configuration(void);
static uint8_t QSPI_ResetChip(void);
/* USER CODE END 0 */

/* USER CODE BEGIN 1 */

/* QUADSPI init function */
uint8_t CSP_QUADSPI_Init(void)
{

    // prepare QSPI peripheral for ST-Link Utility operations
    // hqspi.Instance = QUADSPI;
    if (HAL_OSPI_DeInit(&hqspi) != HAL_OK)
    {
        return HAL_ERROR;
    }

    MX_OCTOSPI1_Init();

    if (QSPI_ResetChip() != HAL_OK)
    {
        return HAL_ERROR;
    }

    HAL_Delay(1);

    if (QSPI_AutoPollingMemReady(HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    if (QSPI_WriteEnable() != HAL_OK)
    {

        return HAL_ERROR;
    }

    if (QSPI_Configuration() != HAL_OK)
    {
        return HAL_ERROR;
    }

    if (QSPI_AutoPollingMemReady(HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

uint8_t
CSP_QSPI_Erase_Chip(void)
{

    OSPI_RegularCmdTypeDef sCommand;

    /* Erasing Sequence --------------------------------- */
    sCommand.OperationType = 			HAL_OSPI_OPTYPE_COMMON_CFG;                   /* Common configuration (indirect or auto-polling mode) */
    sCommand.FlashId = 					HAL_OSPI_FLASH_ID_1;                                /* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode =		HAL_OSPI_INSTRUCTION_DTR_DISABLE;        /* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode = 			HAL_OSPI_ADDRESS_DTR_DISABLE;                /* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode = 				HAL_OSPI_DATA_DTR_DISABLE;                      /* Disable Data DDR/DTR Mode */
    sCommand.DQSMode = 					HAL_OSPI_DQS_DISABLE;                               /* Disable Data Strobe */
    sCommand.SIOOMode = 				HAL_OSPI_SIOO_INST_EVERY_CMD;                      /* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode = 		HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes = 			HAL_OSPI_ALTERNATE_BYTES_NONE;               /* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize = 		HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode = 	HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; /* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode = 			HAL_OSPI_INSTRUCTION_1_LINE;                /* Instruction on a single line */
    sCommand.InstructionSize = 			HAL_OSPI_INSTRUCTION_8_BITS;                /* 8-bit Instruction */
    sCommand.AddressSize = 				HAL_OSPI_ADDRESS_24_BITS;                       /* 24-bit Address */
    /* Instruction */
    sCommand.Instruction = 				CHIP_ERASE_CMD; /* What We Do? */
    /* Address */
    sCommand.AddressMode 				= HAL_OSPI_ADDRESS_NONE; /* Define Address Lines: No Address */
    sCommand.Address 					= 0;                         /* Byte Address */
    /* Data */
    sCommand.DataMode 					= HAL_OSPI_DATA_NONE; /* Define Data Lines: No Data */
    sCommand.DummyCycles 				= 0;               /* Bytes Send With No Data */
    sCommand.NbData						= 1;
    if (QSPI_WriteEnable() != HAL_OK)
    {
        return HAL_ERROR;
    }
    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    if (QSPI_AutoPollingMemReady(QUADSPI_MAX_ERASE_TIMEOUT) != HAL_OK)
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

static uint8_t QSPI_AutoPollingMemReady(uint32_t Timeout)
{

    OSPI_RegularCmdTypeDef sCommand;
    OSPI_AutoPollingTypeDef sConfig;

    /* Configure automatic polling mode to wait for memory ready ------ */

    sCommand.OperationType 			= HAL_OSPI_OPTYPE_COMMON_CFG;                   /* Common configuration (indirect or auto-polling mode) */
    sCommand.FlashId				= HAL_OSPI_FLASH_ID_1;                                /* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode 	= HAL_OSPI_INSTRUCTION_DTR_DISABLE;        /* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode 		= HAL_OSPI_ADDRESS_DTR_DISABLE;                /* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode 			= HAL_OSPI_DATA_DTR_DISABLE;                      /* Disable Data DDR/DTR Mode */
    sCommand.DQSMode 				= HAL_OSPI_DQS_DISABLE;                               /* Disable Data Strobe */
    sCommand.SIOOMode 				= HAL_OSPI_SIOO_INST_EVERY_CMD;                      /* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes 		= HAL_OSPI_ALTERNATE_BYTES_NONE;               /* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode  = HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; /* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode 		= HAL_OSPI_INSTRUCTION_1_LINE;                /* Instruction on a single line */
    sCommand.InstructionSize 		= HAL_OSPI_INSTRUCTION_8_BITS;                /* 8-bit Instruction */
    sCommand.AddressSize 			= HAL_OSPI_ADDRESS_24_BITS;                       /* 24-bit Address */
    /* Instruction */
    sCommand.Instruction 			= READ_STATUS_REG_CMD; /* What We Do? */
    /* Address */
    sCommand.AddressMode 			= HAL_OSPI_ADDRESS_NONE; /* Define Address Lines: No Address */
    sCommand.Address = 0;                         /* Byte Address */
    /* Data */
    sCommand.DataMode 				= HAL_OSPI_DATA_1_LINE; /* Define Data Lines: Data On a Single Line */
    sCommand.DummyCycles 			= 0;                 /* Bytes Send With No Data */
    sCommand.NbData 				= 1;

    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }
    sConfig.Match 				= 0x00U;
    sConfig.Mask 				= 0x01U;
    sConfig.MatchMode 			= HAL_OSPI_MATCH_MODE_AND;
    sConfig.Interval 			= 0x10;
    sConfig.AutomaticStop 		= HAL_OSPI_AUTOMATIC_STOP_ENABLE;

    if (HAL_OSPI_AutoPolling(&hqspi, &sConfig, Timeout) != HAL_OK)
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

static uint8_t QSPI_WriteEnable(void)
{

    OSPI_RegularCmdTypeDef sCommand;
    OSPI_AutoPollingTypeDef sConfig;

    /* Enable write operations ------------------------------------------ */
    sCommand.OperationType 			= HAL_OSPI_OPTYPE_COMMON_CFG;
    sCommand.FlashId 				= HAL_OSPI_FLASH_ID_1;
    sCommand.InstructionDtrMode 	= HAL_OSPI_INSTRUCTION_DTR_DISABLE;
    sCommand.DataDtrMode 			= HAL_OSPI_DATA_DTR_DISABLE;
    sCommand.DQSMode 				= HAL_OSPI_DQS_DISABLE;
    sCommand.SIOOMode 				= HAL_OSPI_SIOO_INST_EVERY_CMD;
    sCommand.AlternateBytesMode 	= HAL_OSPI_ALTERNATE_BYTES_NONE;
    sCommand.AlternateBytes 		= HAL_OSPI_ALTERNATE_BYTES_NONE;
    sCommand.AlternateBytesSize 	= HAL_OSPI_ALTERNATE_BYTES_NONE;
    sCommand.AlternateBytesDtrMode  = HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE;
    sCommand.InstructionMode 		= HAL_OSPI_INSTRUCTION_1_LINE;
    sCommand.InstructionMode 		= HAL_OSPI_INSTRUCTION_1_LINE; /* Instruction on a single line */
    sCommand.InstructionSize 		= HAL_OSPI_INSTRUCTION_8_BITS; /* 8-bit Instruction */
    sCommand.AddressSize 			= HAL_OSPI_ADDRESS_24_BITS;
    sCommand.Instruction 			= WRITE_ENABLE_CMD;
    sCommand.AddressMode 			= HAL_OSPI_ADDRESS_NONE;
    sCommand.DataMode 				= HAL_OSPI_DATA_NONE;
    sCommand.DummyCycles 			= 0;
    sCommand.NbData 				= 0;

    // sCommand.DataDtrMode = HAL_OSPI_DDR_MODE_DISABLE;
    // sCommand.DdrHoldHalfCycle = HAL_OSPI_DDR_HHC_ANALOG_DELAY;

    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    /* Configure automatic polling mode to wait for write enabling ---- */

    sCommand.OperationType 			= HAL_OSPI_OPTYPE_COMMON_CFG;                   /* Common configuration (indirect or auto-polling mode) */
    sCommand.FlashId 				= HAL_OSPI_FLASH_ID_1;                                /* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode 	= HAL_OSPI_INSTRUCTION_DTR_DISABLE;        /* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode 		= HAL_OSPI_ADDRESS_DTR_DISABLE;                /* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode 			= HAL_OSPI_DATA_DTR_DISABLE;                      /* Disable Data DDR/DTR Mode */
    sCommand.DQSMode 				= HAL_OSPI_DQS_DISABLE;                               /* Disable Data Strobe */
    sCommand.SIOOMode 				= HAL_OSPI_SIOO_INST_EVERY_CMD;                      /* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes 		= HAL_OSPI_ALTERNATE_BYTES_NONE;               /* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode  = HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; /* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode 		= HAL_OSPI_INSTRUCTION_1_LINE;                /* Instruction on a single line */
    sCommand.InstructionSize 		= HAL_OSPI_INSTRUCTION_8_BITS;                /* 8-bit Instruction */
    sCommand.AddressSize 			= HAL_OSPI_ADDRESS_24_BITS;                       /* 24-bit Address */
    /* Instruction */
    sCommand.Instruction 			= READ_STATUS_REG_CMD; /* What We Do? */
    /* Address */
    sCommand.AddressMode 			= HAL_OSPI_ADDRESS_NONE; /* Define Address Lines: No Address */
    sCommand.Address = 0;                         /* Byte Address */
    /* Data */
    sCommand.DataMode 				= HAL_OSPI_DATA_1_LINE; /* Define Data Lines: Data On a Single Line */
    sCommand.DummyCycles 			= 0;                 /* Bytes Send With No Data */
    sCommand.NbData 				= 1;

    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }
    sConfig.Match 					= 0x02;
    sConfig.Mask 					= 0x02;
    sConfig.MatchMode 				= HAL_OSPI_MATCH_MODE_AND;
    // sConfig.StatusBytesSize = 1;
    sConfig.Interval 				= 0x10;
    sConfig.AutomaticStop 			= HAL_OSPI_AUTOMATIC_STOP_ENABLE;
    if (HAL_OSPI_AutoPolling(&hqspi, &sConfig,
                             HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

/*Enable quad mode and set dummy cycles count*/
static uint8_t
QSPI_Configuration(void)
{

    OSPI_RegularCmdTypeDef sCommand;
    uint16_t reg;

    sCommand.InstructionMode 		= HAL_OSPI_INSTRUCTION_1_LINE;
    sCommand.Instruction 			= READ_CONFIGURATION_REG_CMD;
    sCommand.AddressMode 			= HAL_OSPI_ADDRESS_NONE;
    sCommand.AlternateBytesMode 	= HAL_OSPI_ALTERNATE_BYTES_NONE;
    sCommand.DataMode 				= HAL_OSPI_DATA_1_LINE;
    sCommand.DummyCycles 			= 0;
    // sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    // sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode 				= HAL_OSPI_SIOO_INST_EVERY_CMD;
    sCommand.NbData 				= 2;

    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    if (HAL_OSPI_Receive(&hqspi, (uint8_t *)(&reg),
                         HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    if (QSPI_WriteEnable() != HAL_OK)
    {

        return HAL_ERROR;
    }

    /*set dummy cycles*/
    MODIFY_REG(reg, 0xF0F0, ((DUMMY_CLOCK_CYCLES_READ_QUAD << 4) | (DUMMY_CLOCK_CYCLES_READ_QUAD << 12)));

    sCommand.Instruction = QUAD_WRITE_VOL_CFG_REG_CMD;

    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    if (HAL_OSPI_Transmit(&hqspi, (uint8_t *)(&reg),
                          HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }
    return HAL_OK;
}

uint8_t
CSP_QSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress)
{

    OSPI_RegularCmdTypeDef sCommand;
    uint32_t StartAddress=0;

       StartAddress = EraseStartAddress - (EraseStartAddress % MEMORY_SECTOR_SIZE);

       while (EraseEndAddress >= StartAddress)
       {
       	/* Erasing Sequence -------------------------------------------------- */
       	/* Common Commands*/
       	sCommand.OperationType      		= HAL_OSPI_OPTYPE_COMMON_CFG; 				/* Common configuration (indirect or auto-polling mode) */
       	sCommand.FlashId            		= HAL_OSPI_FLASH_ID_1; 						/* Set The OCTO SPI Flash ID */
       	sCommand.InstructionDtrMode 		= HAL_OSPI_INSTRUCTION_DTR_DISABLE; 		/* Disable Instruction DDR/DTR Mode */
       	sCommand.AddressDtrMode     		= HAL_OSPI_ADDRESS_DTR_DISABLE; 			/* Disable Address DDR/DTR Mode */
       	sCommand.DataDtrMode				= HAL_OSPI_DATA_DTR_DISABLE; 				/* Disable Data DDR/DTR Mode */
       	sCommand.DQSMode            		= HAL_OSPI_DQS_DISABLE; 					/* Disable Data Strobe */
       	sCommand.SIOOMode          			= HAL_OSPI_SIOO_INST_EVERY_CMD; 			/* SIOO Mode: Send instruction on every transaction */
       	sCommand.AlternateBytesMode 		= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Disable Alternate Bytes Mode */
       	sCommand.AlternateBytes				= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes = 0 */
       	sCommand.AlternateBytesSize			= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes Size = 0 */
       	sCommand.AlternateBytesDtrMode		= HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; 	/* Disable Alternate Bytes DDR/DTR Mode */
       	sCommand.InstructionMode   			= HAL_OSPI_INSTRUCTION_1_LINE;				/* Instruction on a single line */
       	sCommand.InstructionSize    		= HAL_OSPI_INSTRUCTION_8_BITS;				/* 8-bit Instruction */
       	sCommand.AddressSize 				= HAL_OSPI_ADDRESS_24_BITS;					/* 24-bit Address */
       	/* Instruction */
       	sCommand.Instruction 				= QUAD_64KB_BLOCK_ERASE;				/* What We Do? */
       	/* Address */
       	sCommand.AddressMode       			= HAL_OSPI_ADDRESS_1_LINE;					/* Define Address Lines: Address On a Single Line */
       	sCommand.Address					= (StartAddress & 0xFFFFFF);				/* Byte Address */
       	/* Data */
       	sCommand.DataMode          			= HAL_OSPI_DATA_NONE;						/* Define Data Lines: No Data */
       	sCommand.DummyCycles       			= 0;										/* Bytes Send With No Data */
       	sCommand.NbData            			= 0;										/* Bytes Send With Data */

           if( QSPI_WriteEnable() != HAL_OK) {
               return HAL_ERROR;
           }

           if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
               return HAL_ERROR;
           }

           if (QSPI_AutoPollingMemReady(HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
               return HAL_ERROR;
           }

           StartAddress += MEMORY_SECTOR_SIZE;
       }

       return HAL_OK;
}

uint8_t
CSP_QSPI_WriteMemory(uint8_t *buffer, uint32_t address, uint32_t buffer_size)
{

    OSPI_RegularCmdTypeDef sCommand;
    uint32_t end_addr, current_size, current_addr;

    /* Calculation of the size between the write address and the end of the page */
    current_addr = 0;

    while (current_addr <= address)
    {
        current_addr += MEMORY_PAGE_SIZE;
    }
    current_size = current_addr - address;

    /* Check if the size of the data is less than the remaining place in the page */
    if (current_size > buffer_size)
    {
        current_size = buffer_size;
    }

    /* Initialize the adress variables */
    current_addr = address;
    end_addr = address + buffer_size;

    /* Perform the write page by page */
    do
    {
        sCommand.OperationType 			= HAL_OSPI_OPTYPE_COMMON_CFG;                   /* Common configuration (indirect or auto-polling mode) */
        sCommand.FlashId 				= HAL_OSPI_FLASH_ID_1;                                /* Set The OCTO SPI Flash ID */
        sCommand.InstructionDtrMode 	= HAL_OSPI_INSTRUCTION_DTR_DISABLE;        /* Disable Instruction DDR/DTR Mode */
        sCommand.AddressDtrMode 		= HAL_OSPI_ADDRESS_DTR_DISABLE;                /* Disable Address DDR/DTR Mode */
        sCommand.DataDtrMode 			= HAL_OSPI_DATA_DTR_DISABLE;                      /* Disable Data DDR/DTR Mode */
        sCommand.DQSMode				= HAL_OSPI_DQS_DISABLE;                               /* Disable Data Strobe */
        sCommand.SIOOMode 				= HAL_OSPI_SIOO_INST_EVERY_CMD;                      /* SIOO Mode: Send instruction on every transaction */
        sCommand.AlternateBytesMode 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Disable Alternate Bytes Mode */
        sCommand.AlternateBytes 		= HAL_OSPI_ALTERNATE_BYTES_NONE;               /* Alternate Bytes = 0 */
        sCommand.AlternateBytesSize 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Alternate Bytes Size = 0 */
        sCommand.AlternateBytesDtrMode 	= HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; /* Disable Alternate Bytes DDR/DTR Mode */
        sCommand.InstructionMode 		= HAL_OSPI_INSTRUCTION_1_LINE;                /* Instruction on a single line */
        sCommand.InstructionSize 		= HAL_OSPI_INSTRUCTION_8_BITS;                /* 8-bit Instruction */
        sCommand.AddressSize 			= HAL_OSPI_ADDRESS_24_BITS;
        sCommand.AddressMode 			= HAL_OSPI_ADDRESS_1_LINE; /* 24-bit Address */
                                                        /* Instruction */
        sCommand.Instruction 			= QUAD_IN_FAST_PROG_CMD;
        sCommand.DataMode 				= HAL_OSPI_DATA_4_LINES;
        sCommand.Address 				= current_addr;
        sCommand.DummyCycles 			= 0;
        sCommand.NbData 				= current_size;

        if (current_size == 0)
        {
            return HAL_OK;
        }

        /* Enable write operations */
        if (QSPI_WriteEnable() != HAL_OK)
        {
            return HAL_ERROR;
        }

        /* Configure the command */
        if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
        {
            return HAL_ERROR;
        }

        /* Transmission of the data */
        if (HAL_OSPI_Transmit(&hqspi, buffer, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
        {
            return HAL_ERROR;
        }

        /* Configure automatic polling mode to wait for end of program */
        if (QSPI_AutoPollingMemReady(HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
        {
            return HAL_ERROR;
        }

        /* Update the address and size variables for next page programming */
        current_addr += current_size;
        buffer += current_size;
        current_size = ((current_addr + MEMORY_PAGE_SIZE) > end_addr) ? (end_addr - current_addr) : MEMORY_PAGE_SIZE;
    } while (current_addr <= end_addr);

    return HAL_OK;
}

uint8_t CSP_QSPI_EnableMemoryMappedMode(void)
{

    OSPI_RegularCmdTypeDef sCommand;
    OSPI_MemoryMappedTypeDef sMemMappedCfg;

    /* Enable Memory-Mapped mode-------------------------------------------------- */

    sCommand.OperationType 			= HAL_OSPI_OPTYPE_READ_CFG;                     /* Read Configuration (Memory-Mapped Mode) */
    sCommand.FlashId 				= HAL_OSPI_FLASH_ID_1;                                /* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode 	= HAL_OSPI_INSTRUCTION_DTR_DISABLE;        /* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode 		= HAL_OSPI_ADDRESS_DTR_DISABLE;                /* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode 			= HAL_OSPI_DATA_DTR_DISABLE;                      /* Disable Data DDR/DTR Mode */
    sCommand.DQSMode 				= HAL_OSPI_DQS_DISABLE;                               /* Disable Data Strobe */
    sCommand.SIOOMode 				= HAL_OSPI_SIOO_INST_EVERY_CMD;                      /* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes 		= HAL_OSPI_ALTERNATE_BYTES_NONE;               /* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode  = HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; /* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode 		= HAL_OSPI_INSTRUCTION_1_LINE;                /* Instruction on a single line */
    sCommand.InstructionSize 		= HAL_OSPI_INSTRUCTION_8_BITS;                /* 8-bit Instruction */
    sCommand.AddressSize 			= HAL_OSPI_ADDRESS_24_BITS;                       /* 24-bit Address */
    /* Instruction */
    sCommand.Instruction 			= QUAD_FAST_READ_IO_CMD; /* What We Do? */
    /* Address */
    sCommand.AddressMode 			= HAL_OSPI_ADDRESS_4_LINES; /* Define Address Lines: Address On Four Lines */
    sCommand.Address 				= 0;                            /* Byte Address */
    /* Data */
    sCommand.DataMode 				= HAL_OSPI_DATA_4_LINES; /* Define Data Lines: Data On Four Lines */
    sCommand.DummyCycles 			= 4;                  /* Bytes Send With No Data */
    sCommand.NbData 				= 0;
    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    sCommand.OperationType 			= HAL_OSPI_OPTYPE_WRITE_CFG;                    /* Write Configuration (Memory-Mapped Mode)) */
    sCommand.FlashId 				= HAL_OSPI_FLASH_ID_1;                                /* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode 	= HAL_OSPI_INSTRUCTION_DTR_DISABLE;        /* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode 		= HAL_OSPI_ADDRESS_DTR_DISABLE;                /* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode 			= HAL_OSPI_DATA_DTR_DISABLE;                      /* Disable Data DDR/DTR Mode */
    sCommand.DQSMode 				= HAL_OSPI_DQS_DISABLE;                               /* Disable Data Strobe */
    sCommand.SIOOMode 				= HAL_OSPI_SIOO_INST_EVERY_CMD;                      /* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes 		= HAL_OSPI_ALTERNATE_BYTES_NONE;               /* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize 	= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode  = HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; /* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode 		= HAL_OSPI_INSTRUCTION_1_LINE;                /* Instruction on a single line */
    sCommand.InstructionSize 		= HAL_OSPI_INSTRUCTION_8_BITS;                /* 8-bit Instruction */
    sCommand.AddressSize 			= HAL_OSPI_ADDRESS_24_BITS;                       /* 24-bit Address */
    /* Instruction */
    sCommand.Instruction 			= QUAD_IN_FAST_PROG_CMD; /* What We Do? */
    /* Address */
    sCommand.AddressMode 			= HAL_OSPI_ADDRESS_1_LINE; /* Define Address Lines: Address On a Single Line */
    sCommand.Address 				= 0;                           /* Byte Address */
    /* Data */
    sCommand.DataMode 				= HAL_OSPI_DATA_4_LINES; /* Define Data Lines: Data On Four Lines */
    sCommand.DummyCycles 			= 0;                  /* Bytes Send With No Data */
    sCommand.NbData 				= 0;                       /* Bytes Send With Data */

    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }
    sMemMappedCfg.TimeOutActivation = HAL_OSPI_TIMEOUT_COUNTER_DISABLE;

    if (HAL_OSPI_MemoryMapped(&hqspi, &sMemMappedCfg) != HAL_OK)
    {
        return HAL_ERROR;
    }
    return HAL_OK;
}

static uint8_t QSPI_ResetChip()
{
    OSPI_RegularCmdTypeDef sCommand;

    /* Erasing Sequence -------------------------------------------------- */
    sCommand.OperationType      		= HAL_OSPI_OPTYPE_COMMON_CFG; 				/* Common configuration (indirect or auto-polling mode) */
    sCommand.FlashId            		= HAL_OSPI_FLASH_ID_1; 						/* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode 		= HAL_OSPI_INSTRUCTION_DTR_DISABLE; 		/* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode     		= HAL_OSPI_ADDRESS_DTR_DISABLE; 			/* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode				= HAL_OSPI_DATA_DTR_DISABLE; 				/* Disable Data DDR/DTR Mode */
    sCommand.DQSMode            		= HAL_OSPI_DQS_DISABLE; 					/* Disable Data Strobe */
    sCommand.SIOOMode          			= HAL_OSPI_SIOO_INST_EVERY_CMD; 			/* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode 		= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes				= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize			= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode		= HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; 	/* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode   			= HAL_OSPI_INSTRUCTION_1_LINE;				/* Instruction on a single line */
    sCommand.InstructionSize    		= HAL_OSPI_INSTRUCTION_8_BITS;				/* 8-bit Instruction */
    sCommand.AddressSize 				= HAL_OSPI_ADDRESS_24_BITS;					/* 24-bit Address */
    	/* Instruction */
    sCommand.Instruction 				= QUAD_RESET_ENABLE_CMD;						/* What We Do? */
    	/* Address */
    sCommand.AddressMode       			= HAL_OSPI_ADDRESS_NONE;					/* Define Address Lines: No Address */
    sCommand.Address					= 0;										/* Byte Address */
    	/* Data */
    sCommand.DataMode          			= HAL_OSPI_DATA_NONE;						/* Define Data Lines: No Data */
    sCommand.DummyCycles       			= 0;										/* Bytes Send With No Data */
    sCommand.NbData            			= 0;										/* Bytes Send With Data */

    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
            return HAL_ERROR;
     }

        /* Reset Device --------------------------- */
    	/* Common Commands*/
    sCommand.OperationType      		= HAL_OSPI_OPTYPE_COMMON_CFG; 				/* Common configuration (indirect or auto-polling mode) */
    sCommand.FlashId            		= HAL_OSPI_FLASH_ID_1; 						/* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode 		= HAL_OSPI_INSTRUCTION_DTR_DISABLE; 		/* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode     		= HAL_OSPI_ADDRESS_DTR_DISABLE; 			/* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode				= HAL_OSPI_DATA_DTR_DISABLE; 				/* Disable Data DDR/DTR Mode */
    sCommand.DQSMode            		= HAL_OSPI_DQS_DISABLE; 					/* Disable Data Strobe */
    sCommand.SIOOMode          			= HAL_OSPI_SIOO_INST_EVERY_CMD; 			/* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode 		= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes				= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize			= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode		= HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; 	/* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode   			= HAL_OSPI_INSTRUCTION_1_LINE;				/* Instruction on a single line */
    sCommand.InstructionSize    		= HAL_OSPI_INSTRUCTION_8_BITS;				/* 8-bit Instruction */
    sCommand.AddressSize 				= HAL_OSPI_ADDRESS_24_BITS;					/* 24-bit Address */
    /* Instruction */
    sCommand.Instruction 				= QUAD_RESET_EXECUTE_CMD;							/* What We Do? */
    /* Address */
   	sCommand.AddressMode       			= HAL_OSPI_ADDRESS_NONE;					/* Define Address Lines: No Address */
    sCommand.Address					= 0;										/* Byte Address */
    /* Data */
    sCommand.DataMode          			= HAL_OSPI_DATA_NONE;						/* Define Data Lines: No Data */
    sCommand.DummyCycles       			= 0;										/* Bytes Send With No Data */
    sCommand.NbData            			= 0;										/* Bytes Send With Data */

    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
            return HAL_ERROR;
    }
   return HAL_OK;
}

uint8_t CSP_QSPI_ReadMemory(uint8_t *pData, uint32_t ReadAddr, uint32_t Size)
{
    OSPI_RegularCmdTypeDef sCommand = {0};
    /* Initialize the read command */
    /* Common Commands*/
    sCommand.OperationType 				= HAL_OSPI_OPTYPE_COMMON_CFG;                   /* Common configuration (indirect or auto-polling mode) */
    sCommand.FlashId 					= HAL_OSPI_FLASH_ID_1;                                /* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode 		= HAL_OSPI_INSTRUCTION_DTR_DISABLE;        /* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode 			= HAL_OSPI_ADDRESS_DTR_DISABLE;                /* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode 				= HAL_OSPI_DATA_DTR_DISABLE;                      /* Disable Data DDR/DTR Mode */
    sCommand.DQSMode 					= HAL_OSPI_DQS_DISABLE;                               /* Disable Data Strobe */
    sCommand.SIOOMode 					= HAL_OSPI_SIOO_INST_EVERY_CMD;                      /* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode 		= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes 			= HAL_OSPI_ALTERNATE_BYTES_NONE;               /* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize 		= HAL_OSPI_ALTERNATE_BYTES_NONE;           /* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode 		= HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; /* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode 			= HAL_OSPI_INSTRUCTION_1_LINE;                /* Instruction on a single line */
    sCommand.InstructionSize 			= HAL_OSPI_INSTRUCTION_8_BITS;                /* 8-bit Instruction */
    sCommand.AddressSize 				= HAL_OSPI_ADDRESS_24_BITS;                       /* 24-bit Address */
    /* Instruction */
    sCommand.Instruction 				= QUAD_FAST_READ_IO_CMD; /* What We Do? */
    /* Address */
    sCommand.AddressMode 				= HAL_OSPI_ADDRESS_4_LINES; /* Define Address Lines: Address On Four Line */
    sCommand.Address 					= ReadAddr;                     /* Byte Address */
    /* Data */
    sCommand.DataMode 					= HAL_OSPI_DATA_4_LINES; /* Define Data Lines: Data On Four Lines */
    sCommand.DummyCycles				= 4;                  /* Bytes Send With No Data */
    sCommand.NbData 					= Size;                    /* Bytes Send With Data */

    /* Configure the command */
    if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    /* Reception of the data */
    if (HAL_OSPI_Receive(&hqspi, pData, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}
HAL_StatusTypeDef W25Q128_Read_Status_Registers(OSPI_HandleTypeDef* hospi, uint8_t* register_data, uint8_t register_num)
{
	OSPI_RegularCmdTypeDef sCommand={0};

	/* Common Commands*/
    sCommand.OperationType      	= HAL_OSPI_OPTYPE_COMMON_CFG; 				/* Common configuration (indirect or auto-polling mode) */
    sCommand.FlashId            	= HAL_OSPI_FLASH_ID_1; 						/* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode 	= HAL_OSPI_INSTRUCTION_DTR_DISABLE; 		/* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode     	= HAL_OSPI_ADDRESS_DTR_DISABLE; 			/* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode			= HAL_OSPI_DATA_DTR_DISABLE; 				/* Disable Data DDR/DTR Mode */
    sCommand.DQSMode            	= HAL_OSPI_DQS_DISABLE; 					/* Disable Data Strobe */
    sCommand.SIOOMode          		= HAL_OSPI_SIOO_INST_EVERY_CMD; 			/* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode 	= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes			= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize		= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode	= HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; 	/* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode   		= HAL_OSPI_INSTRUCTION_1_LINE;				/* Instruction on a single line */
    sCommand.InstructionSize    	= HAL_OSPI_INSTRUCTION_8_BITS;				/* 8-bit Instruction */
    sCommand.AddressSize 			= HAL_OSPI_ADDRESS_24_BITS;					/* 24-bit Address */
    /* Instruction */
    sCommand.Instruction 			= 0;										/* What We Do? */
    /* Address */
    sCommand.AddressMode       		= HAL_OSPI_ADDRESS_NONE;					/* Define Address Lines: No Address */
    sCommand.Address				= 0;										/* Byte Address */
    /* Data */
    sCommand.DataMode          		= HAL_OSPI_DATA_1_LINE;						/* Define Data Lines: Data On a Single Line */
    sCommand.DummyCycles       		= 0;										/* Bytes Send With No Data */
    sCommand.NbData            		= 1;										/* Bytes Send With Data */

	if (register_num == 1)
		sCommand.Instruction = QUAD_READ_SR1_CMD;
	else if (register_num == 2)
		sCommand.Instruction = QUAD_READ_SR2_CMD;
	else if (register_num == 3)
		sCommand.Instruction = QUAD_READ_SR3_CMD;
	else
		return HAL_ERROR;

    if (HAL_OSPI_Command(hospi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    if (HAL_OSPI_Receive(hospi, register_data, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

	return HAL_OK;
}

/* Write Status Registers Function */
HAL_StatusTypeDef W25Q128_Write_Status_Registers(OSPI_HandleTypeDef* hospi, uint8_t reg_data, uint8_t reg_num)
{
	OSPI_RegularCmdTypeDef sCommand;

	/* Common Commands*/
    sCommand.OperationType      	= HAL_OSPI_OPTYPE_COMMON_CFG; 				/* Common configuration (indirect or auto-polling mode) */
    sCommand.FlashId            	= HAL_OSPI_FLASH_ID_1; 						/* Set The OCTO SPI Flash ID */
    sCommand.InstructionDtrMode 	= HAL_OSPI_INSTRUCTION_DTR_DISABLE; 		/* Disable Instruction DDR/DTR Mode */
    sCommand.AddressDtrMode     	= HAL_OSPI_ADDRESS_DTR_DISABLE; 			/* Disable Address DDR/DTR Mode */
    sCommand.DataDtrMode			= HAL_OSPI_DATA_DTR_DISABLE; 				/* Disable Data DDR/DTR Mode */
    sCommand.DQSMode            	= HAL_OSPI_DQS_DISABLE; 					/* Disable Data Strobe */
    sCommand.SIOOMode          		= HAL_OSPI_SIOO_INST_EVERY_CMD; 			/* SIOO Mode: Send instruction on every transaction */
    sCommand.AlternateBytesMode 	= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Disable Alternate Bytes Mode */
    sCommand.AlternateBytes			= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes = 0 */
    sCommand.AlternateBytesSize		= HAL_OSPI_ALTERNATE_BYTES_NONE; 			/* Alternate Bytes Size = 0 */
    sCommand.AlternateBytesDtrMode	= HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE; 	/* Disable Alternate Bytes DDR/DTR Mode */
    sCommand.InstructionMode   		= HAL_OSPI_INSTRUCTION_1_LINE;				/* Instruction on a single line */
    sCommand.InstructionSize    	= HAL_OSPI_INSTRUCTION_8_BITS;				/* 8-bit Instruction */
    sCommand.AddressSize 			= HAL_OSPI_ADDRESS_24_BITS;					/* 24-bit Address */
    /* Instruction */
    sCommand.Instruction 			= QUAD_WRITE_DISABLE_CMD;					/* What We Do? */
    /* Address */
    sCommand.AddressMode       		= HAL_OSPI_ADDRESS_NONE;					/* Define Address Lines: No Address */
    sCommand.Address				= 0;										/* Byte Address */
    /* Data */
    sCommand.DataMode          		= HAL_OSPI_DATA_NONE;						/* Define Data Lines: No Data */
    sCommand.DummyCycles       		= 0;										/* Bytes Send With No Data */
    sCommand.NbData            		= 0;										/* Bytes Send With Data */

	if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
		return HAL_ERROR;
	}
	if (QSPI_AutoPollingMemReady(HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
        return HAL_ERROR;
    }

	sCommand.Instruction 			= QUAD_WRITE_VOL_CFG_REG_CMD;				/* What We Do? */
	if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
		return HAL_ERROR;
	}
	if (QSPI_AutoPollingMemReady(HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
        return HAL_ERROR;
    }

	if (reg_num == 1)
		sCommand.Instruction = QUAD_WRITE_SR1_CMD;
	else if (reg_num == 2)
		sCommand.Instruction = QUAD_WRITE_SR2_CMD;
	else if (reg_num == 3)
		sCommand.Instruction = QUAD_WRITE_SR3_CMD;
	else
		return HAL_ERROR;

	sCommand.DataMode          		= HAL_OSPI_DATA_1_LINE;
	sCommand.NbData            		= 1;

	if (QSPI_WriteEnable() != HAL_OK) {
		return HAL_ERROR;
	}

	if (HAL_OSPI_Command(&hqspi, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
		return HAL_ERROR;
	}
	if (HAL_OSPI_Transmit(&hqspi, &reg_data, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
		return HAL_ERROR;
	}
	if (QSPI_AutoPollingMemReady(HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
        return HAL_ERROR;
    }

	return HAL_OK;
}
/* USER CODE END 1 */
