/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CRC_H__
#define __CRC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Public Variable Declaration ----------------------------------------------*/
extern CRC_HandleTypeDef hcrc;

void MX_CRC_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __CRC_H__ */

