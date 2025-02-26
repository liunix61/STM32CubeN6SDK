
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_filex.h
  * @author  MCD Application Team
  * @brief   FileX applicative header file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_FILEX_H__
#define __APP_FILEX_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "fx_api.h"
#include "fx_stm32_sd_driver.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
UINT VENC_FileX_Init(void);
/* USER CODE BEGIN EFP */
UINT VENC_FileX_write(CHAR * data, LONG size);
UINT VENC_FileX_close(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* Main thread Name */
#ifndef FX_APP_THREAD_NAME
  #define FX_APP_THREAD_NAME "FileX app thread"
#endif

/* Main thread time slice */
#ifndef FX_APP_THREAD_TIME_SLICE
  #define FX_APP_THREAD_TIME_SLICE TX_NO_TIME_SLICE
#endif

/* Main thread auto start */
#ifndef FX_APP_THREAD_AUTO_START
  #define FX_APP_THREAD_AUTO_START TX_AUTO_START
#endif

/* Main thread preemption threshold */
#ifndef FX_APP_PREEMPTION_THRESHOLD
  #define FX_APP_PREEMPTION_THRESHOLD FX_APP_THREAD_PRIO
#endif

/* fx sd volume name */
#ifndef FX_SD_VOLUME_NAME
  #define FX_SD_VOLUME_NAME "STM32_SDIO_DISK"
#endif

/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
#ifdef __cplusplus
}
#endif
#endif /* __APP_FILEX_H__ */
