/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
#include "stm32f4xx_hal.h"

/* Public Function Defnition -------------------------------------------------*/
void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}
