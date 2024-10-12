/**
  ******************************************************************************
  * @file           : usb_mgr.c
  * @version        : v0.1
  * @brief          : Main USB app
  ******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "task.h"

#include "utils.h"

#include "usb_ctrl.h"

/* Defines -------------------------------------------------------------------*/

/* Private Typedef -----------------------------------------------------------*/
typedef enum
{
    INIT,

}tUsbMgr_state;

/* Private Variable Declaration ----------------------------------------------*/
osThreadId_t mUsbMgr_taskHandle;

const osThreadAttr_t usbMgr_taskAttributes = {
  .name = "USB Manager",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private Function Declaration ----------------------------------------------*/
static void usbMgr_mainThread(void *argument);
static void usbMgr_init(void);

/* Public Function Defnition -------------------------------------------------*/
void usbMgr_queueTask( void )
{
    mUsbMgr_taskHandle = osThreadNew(usbMgr_mainThread, NULL, &usbMgr_taskAttributes);
}

/* Private Function Definition -----------------------------------------------*/
static void usbMgr_mainThread(void *argument)
{
    MX_USB_DEVICE_Init();

    for(;;)
    {
        osDelay(1);
    }
}

static void usbMgr_fsm( void )
{
}