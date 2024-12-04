#ifndef _SYSTEM_SYSTEM_INIT_H_
#define _SYSTEM_SYSTEM_INIT_H_

#ifdef __cplusplus
extern "C" {
#endif

// initializes the libraries and configured peripherals
void System_Init(void);

// initializes OS and starts the scheduler - this function never returns
void System_StartOS(void);

#ifdef __cplusplus
}
#endif

#endif