/* Includes ------------------------------------------------------------------*/
#include "crc.h"
#include "spi.h"
#include "gpio.h"
#include "clock.h"
#include "cmsis_os.h"

#include "utils.h"

#include "usb_mgr.h"

/* Defines -------------------------------------------------------------------*/

/* Private Typedef -----------------------------------------------------------*/

/* Private Variable Declaration ----------------------------------------------*/

/* Private Function Declaration ----------------------------------------------*/

/* Public Function Defnition -------------------------------------------------*/
void taskMgr_initMcu(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_CRC_Init();
}

void taskMgr_queueTask(void)
{
  usbMgr_queueTask();
}

void taskMgr_startTask(void)
{
  osKernelInitialize();
  osKernelStart();
}
