/* Includes ------------------------------------------------------------------*/
#include "crc.h"
#include "utils.h"

/* Private Variable Declaration ---------------------------------------------*/
CRC_HandleTypeDef hcrc;

/* Public Function Definition ------------------------------------------------------------------*/
/* CRC init function */
void MX_CRC_Init(void)
{
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }

}

/* Private Function Definition ------------------------------------------------------------------*/
void HAL_CRC_MspInit(CRC_HandleTypeDef* crcHandle)
{

  if(crcHandle->Instance==CRC)
  {
    /* CRC clock enable */
    __HAL_RCC_CRC_CLK_ENABLE();
  }
}

void HAL_CRC_MspDeInit(CRC_HandleTypeDef* crcHandle)
{

  if(crcHandle->Instance==CRC)
  {
    /* Peripheral clock disable */
    __HAL_RCC_CRC_CLK_DISABLE();
  }
}
