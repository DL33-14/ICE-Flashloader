/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_MGR_H__
#define __USB_MGR_H__

#ifdef __cplusplus
extern "C"
{
#endif
/* Includes ------------------------------------------------------------------*/
#include "usbd_cdc.h"

    /* Defines -------------------------------------------------------------------*/

    /* Public Typedef -----------------------------------------------------------*/

    /* Public Variable Declaration ----------------------------------------------*/

    /* Public Function Declaration ----------------------------------------------*/
    void usbMgr_queueTask(void);

#ifdef __cplusplus
}
#endif

#endif /* __USB_MGR_H__ */