/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UTILS_H__
#define __UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/

/* Defines -------------------------------------------------------------------*/

/* Public Typedef -----------------------------------------------------------*/

/* Public Variable Declaration ----------------------------------------------*/

/* Public Function Declaration ----------------------------------------------*/

void utils_printLog(char* message);

void Error_Handler(void);

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line);
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif

#endif /* __UTILS_H__ */
