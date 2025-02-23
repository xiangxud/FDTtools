/*
 *######################################################################
 *                                RAppIDJDP
 *           Rapid Application Initialization and Documentation Tool
 *                         Freescale Semiconductor Inc.
 *
 *######################################################################
 *
 * Project Name           : detc_ecu
 *
 * Project File           : detc_ecu.rsp
 *
 * Revision Number        : 1.0
 *
 * Tool Version           : 1.0.0.3
 *
 * file                   : sys_init.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : MPC5606S
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 04-Sep-2014 15:25:01
 *
 * Created on Date        : 04-Sep-2014 15:25:02
 *
 * Brief Description      : This file contains system initialization code
 *
 ******************************************************************************** 
 *
 * Detail Description     : This file contains function which calls respective peripheral
 *                          initialization functions
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "rappid_ref.h"
#include "sys_init.h"
#include "intc_init.h"
#include "rgm_init.h"
#include "siu_init.h"
#include "sysclk_init.h"
#include "swt_init.h"
#include "msr_init.h"
#include "pit_init.h"
#include "stm_init.h"
#include "emios_init.h"
#include "adc_init.h"
#include "rtc_init.h"
#include "smc_init.h"
#include "lcd_init.h"

extern void siu_init_fnc(void);

/*********************  Initialization Function(s) ************************/

void sys_init_fnc (void)
{

/* -----------------------------------------------------------------------------*/
/*	               System Initialization Functions                            */
/* -----------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------*/
/*                  Reset Determination Goes Here                               */
/* -----------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------*/
/*   Initialize the Interrupt Controller (INTC)                                 */
/* -----------------------------------------------------------------------------*/
    intc_init_fnc();
    IVPRInitialize();

/* -----------------------------------------------------------------------------*/
/*   Initialize the Reset Generation Module(RGM)                                */
/* -----------------------------------------------------------------------------*/
    rgm_init_fnc();

/* -----------------------------------------------------------------------------*/
/*   Initialize the Software Watchdog (SWT)                                     */
/* -----------------------------------------------------------------------------*/
    //swt_init_fnc();

/* -----------------------------------------------------------------------------*/
/*   Initialize the Main Status Register (MSR)                                  */
/* -----------------------------------------------------------------------------*/
    msr_init_fnc();

/* -----------------------------------------------------------------------------*/
/*   Initialize the System Clock, Mode Entry (ME) & CMU                         */
/* -----------------------------------------------------------------------------*/
    sysclk_module_init_fnc();

/* -----------------------------------------------------------------------------*/
/*   Initialize the Real Time Clock(RTC)                                        */
/* -----------------------------------------------------------------------------*/
    rtc_init_fnc();

/* -----------------------------------------------------------------------------*/
/*   Initialize the System Timer Module (STM)                                   */
/* -----------------------------------------------------------------------------*/
    /* stm_init_fnc(); */
    
    emios_init_fnc();
    
/* -----------------------------------------------------------------------------*/
/*   Initialize the segment display (LCD)                                       */
/* -----------------------------------------------------------------------------*/  
	lcd_init_fnc();

/* -----------------------------------------------------------------------------*/
/*   Initialize the Periodic Interrupt Timer (PIT)                              */
/* -----------------------------------------------------------------------------*/
    pit_init_fnc();

/* -----------------------------------------------------------------------------*/
/*   Initialize the Mode Entry Post Configuration                               */
/* -----------------------------------------------------------------------------*/
    mode_entry_post_config_fnc();

/* -----------------------------------------------------------------------------*/
/*   Initialize the Analogue-to-Digital converter (ADC)                         */
/* -----------------------------------------------------------------------------*/
    adc_init_fnc();

/* -----------------------------------------------------------------------------*/
/*   Initialize the System Integration Unit (SIU)                               */
/* -----------------------------------------------------------------------------*/
    siu_init_fnc();
    
/* -----------------------------------------------------------------------------*/
/*   Initialize the Stepper motor control Unit (SMC)                            */
/* -----------------------------------------------------------------------------*/    
    smc_init_fnc();
}

 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

