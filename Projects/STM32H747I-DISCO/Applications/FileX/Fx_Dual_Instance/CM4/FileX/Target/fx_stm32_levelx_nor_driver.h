/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FX_STM32_LX_NOR_DRIVER_H
#define FX_STM32_LX_NOR_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "fx_api.h"
#include "lx_api.h"

/* enable the driver to be used */
#define LX_NOR_QSPI_DRIVER

#ifdef LX_NOR_SIMULATOR_DRIVER
#include "lx_stm32_nor_simulator_driver.h"

#define LX_NOR_SIMULATOR_DRIVER_ID        0x01
#define LX_NOR_SIMULATOR_DRIVER_NAME      "FX Levelx NOR flash Simulator"
#endif

#ifdef LX_NOR_OSPI_DRIVER
#include "lx_stm32_ospi_driver.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
#define LX_NOR_OSPI_DRIVER_ID            0x02
#define LX_NOR_OSPI_DRIVER_NAME          "FX Levelx OctoSPI driver"
#endif

#ifdef LX_NOR_QSPI_DRIVER
#include "lx_stm32_qspi_driver.h"

#define LX_NOR_QSPI_DRIVER_ID           0x03
#define LX_NOR_QSPI_DRIVER_NAME         "FX Levelx QuadSPI driver"
#endif

#ifdef LX_NOR_CUSTOM_DRIVER
/*
 * define the Custom levelx nor drivers to be supported by the filex
 *  for example:

#define CUSTOM_DRIVER_ID          0xABCDEF
#define NOR_CUSTOM_DRIVER_NAME    "NOR CUSTOM DRIVER"
#include "lx_nor_custom_driver.h"
#define NOR_CUSTOM_DRIVERS   {"NOR CUSTOM DRIVER", CUSTOM_DRIVER_ID, lx_nor_customer_driver_initialize}
 */

#endif

#define MAX_LX_NOR_DRIVERS     8
#define UNKNOWN_DRIVER_ID      0xFFFFFFFF

/* USER CODE BEGIN DEFAULT_DRIVER */

/* uncomment the define below to define the default driver
   to use.
*/
/* #define LX_NOR_DEFAULT_DRIVER */

#ifdef LX_NOR_DEFAULT_DRIVER
#define NOR_DEFAULT_DRIVER    /* add Driver ID from the defines above (for example LX_NOR_SIMULATOR_DRIVER_ID) */
#endif
/* USER CODE END DEFAULT_DRIVER */

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

#if !defined(NOR_DEFAULT_DRIVER) && !defined(NOR_CUSTOM_DRIVERS) && !defined(LX_NOR_SIMULATOR_DRIVER) && !defined(LX_NOR_QSPI_DRIVER)  && !defined(LX_NOR_OSPI_DRIVER)
#error "[This error was thrown on purpose] : No NOR low -level driver defined"
#endif
/* Exported functions prototypes ---------------------------------------------*/
VOID  fx_stm32_levelx_nor_driver(FX_MEDIA *media_ptr);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

#ifdef __cplusplus
}
#endif

#endif /*FX_STM32_LX_NOR_DRIVER_H*/
