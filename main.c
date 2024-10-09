/* Includes ------------------------------------------------------------------*/
#include "task_mgr.h"
#include "SEGGER_RTT.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private function definitions -----------------------------------------------*/


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/
  SEGGER_RTT_printf(0, "main()\n");

  taskMgr_initMcu();
  taskMgr_queueTask();

  taskMgr_startTask();

  /* Infinite loop */
  while (1)
  {

  }
}

