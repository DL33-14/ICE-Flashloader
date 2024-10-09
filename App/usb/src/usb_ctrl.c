/**
  ******************************************************************************
  * @file           : usb_ctrl.c
  * @version        : v0.1
  * @brief          : USB HAL interface
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "usbd_cdc.h"
#include "usbd_desc.h"
#include "usbd_core.h"
#include "usb_ctrl.h"
#include "utils.h"

/* Defines -------------------------------------------------------------------*/
#define APP_RX_DATA_SIZE  2048
#define APP_TX_DATA_SIZE  2048

/* Private Typedef -----------------------------------------------------------*/

/* Private Function Declaration ----------------------------------------------*/
static int8_t usb_init(void);
static int8_t usb_deInit(void);
static int8_t usb_control(uint8_t cmd, uint8_t* pbuf, uint16_t length);
static int8_t usb_receive(uint8_t* pbuf, uint32_t *Len);
static int8_t usb_transmitCplt(uint8_t *pbuf, uint32_t *Len, uint8_t epnum);

/* Private Variable Declaration ----------------------------------------------*/
static uint8_t UserRxBufferFS[APP_RX_DATA_SIZE];
static uint8_t UserTxBufferFS[APP_TX_DATA_SIZE];
USBD_HandleTypeDef hUsbDeviceFS;

/* Public Variable Declaration -----------------------------------------------*/
USBD_CDC_ItfTypeDef USBD_Interface_fops_FS =
{
  usb_init,
  usb_deInit,
  usb_control,
  usb_receive,
  usb_transmitCplt
};

/* Public Function Defnition -------------------------------------------------*/
void usbCtrl_init(void)
{
    utils_printLog("Usb ctrl init");
    if (USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS) != USBD_OK)
    {
      utils_printLog("USBD_Init");
      Error_Handler();
    }
    if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_CDC) != USBD_OK)
    {
      utils_printLog("USBD_RegisterClass");
      Error_Handler();
    }
    if (USBD_CDC_RegisterInterface(&hUsbDeviceFS, &USBD_Interface_fops_FS) != USBD_OK)
    {
      utils_printLog("USBD_CDC_RegisterInterface");
      Error_Handler();
    }
    if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
    {
      utils_printLog("USBD_Start");
      Error_Handler();
    }
    utils_printLog("Usb ctrl init done");
}

/* Private Function Definition ----------------------------------------------*/
static int8_t usb_init(void)
{
  /* Set Application Buffers */
  USBD_CDC_SetTxBuffer(&hUsbDeviceFS, UserTxBufferFS, 0);
  USBD_CDC_SetRxBuffer(&hUsbDeviceFS, UserRxBufferFS);
  return (USBD_OK);
}

static int8_t usb_deInit(void)
{
  return (USBD_OK);
}

static int8_t usb_control(uint8_t cmd, uint8_t* pbuf, uint16_t length)
{
    UNUSED(cmd);
    UNUSED(pbuf);
    UNUSED(length);

  return (USBD_OK);
}

static int8_t usb_receive(uint8_t* Buf, uint32_t *Len)
{
  USBD_CDC_SetRxBuffer(&hUsbDeviceFS, &Buf[0]);
  USBD_CDC_ReceivePacket(&hUsbDeviceFS);
  return (USBD_OK);
}

int8_t usb_Transmit(uint8_t* Buf, uint16_t Len)
{
  uint8_t result = USBD_OK;
  USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;
  if (hcdc->TxState != 0){
    return USBD_BUSY;
  }
  USBD_CDC_SetTxBuffer(&hUsbDeviceFS, Buf, Len);
  result = USBD_CDC_TransmitPacket(&hUsbDeviceFS);
  return result;
}

static int8_t usb_transmitCplt(uint8_t *Buf, uint32_t *Len, uint8_t epnum)
{
  uint8_t result = USBD_OK;
  UNUSED(Buf);
  UNUSED(Len);
  UNUSED(epnum);
  return result;
}