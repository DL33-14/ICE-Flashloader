/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TASK_MGR_H__
#define __TASK_MGR_H__

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/

/* Defines -------------------------------------------------------------------*/

/* Public Typedef -----------------------------------------------------------*/

/* Public Variable Declaration ----------------------------------------------*/

/* Public Function Declaration ----------------------------------------------*/
void taskMgr_initMcu( void );

void taskMgr_queueTask( void );

void taskMgr_startTask( void );

#ifdef __cplusplus
}
#endif

#endif /* __TASK_MGR_H__ */
