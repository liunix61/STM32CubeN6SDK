/**
  ******************************************************************************
  * @file    AppliSecure/Src/stm32n6xx_it.c
  * @author  GPM Application Team
  * @brief   Secure Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * COPYRIGHT(c) 2024 STMicroelectronics
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32n6xx_it.h"

extern funcptr_NS pSecureFault_Callback;
extern funcptr_NS pSecureError_Callback;
extern funcptr_NS pSecureIT_Callback;

#if defined(__ICCARM__)
typedef void (CMSE_NS_CALL *SecureFault_Callback)(void);
typedef void (CMSE_NS_CALL *SecureError_Callback)(void);
typedef void (CMSE_NS_CALL *SecureIT_Callback)(IRQn_Type IrqLine);
#else
typedef void CMSE_NS_CALL (*SecureFault_Callback)(void);
typedef void CMSE_NS_CALL (*SecureError_Callback)(void);
typedef void CMSE_NS_CALL (*SecureIT_Callback)(IRQn_Type IrqLine);
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M55 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Secure Fault exception.
  * @param  None
  * @retval None
  */
void SecureFault_Handler(void)
{
  funcptr_NS callback_NS; // non-secure callback function pointer

  if(pSecureFault_Callback != (funcptr_NS)NULL)
  {
   /* return function pointer with cleared LSB */
   callback_NS = (funcptr_NS)cmse_nsfptr_create(pSecureFault_Callback);

   callback_NS();
  }
  else
  {
    GPIO_InitTypeDef  gpio_init_structure;
    __HAL_RCC_GPIOG_CLK_ENABLE();

    /* configure the GPIOG13 pin */
    gpio_init_structure.Pin = GPIO_PIN_10;
    gpio_init_structure.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_structure.Pull = GPIO_NOPULL;
    gpio_init_structure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init (GPIOG, &gpio_init_structure);
  }

  while (1)
  {
    for(int i = 0; i<20000000; i++);
    HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_10);
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/******************************************************************************/
/*                 STM32N6xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32n6xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles IAC interrupt request.
  * @retval None
  */
void IAC_IRQHandler(void)
{
  funcptr_NS callback_NS; // non-secure callback function pointer

  if(pSecureError_Callback != (funcptr_NS)NULL)
  {
   /* return function pointer with cleared LSB */
   callback_NS = (funcptr_NS)cmse_nsfptr_create(pSecureError_Callback);

   callback_NS();
  }
  else
  {
    while(1);  /* Something went wrong */
  }
}

