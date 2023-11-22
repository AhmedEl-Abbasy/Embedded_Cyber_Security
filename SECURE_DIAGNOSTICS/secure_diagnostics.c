/******************************************************************************
 * Module:
 *
 * File Name:secure_diagnostics.c
 *
 * Description:
 *
 * Created on: Nov 20, 2023
 *
 * Author: Ahmed El-Abbasy
 *
 *******************************************************************************/

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include "secure_diagnostics.h"
#include "timer0.h"
/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Local Data Types and Structures                       *
 *******************************************************************************/
static u32 randValue;
security_stge_t security_stge = security_stge_L0;
static u8 GetValue_0[50];
static u32 Value = 0;
static u32 Valyy = 0;


/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function                             *
 *******************************************************************************/
void Cyber_lab_init()
{
	comM_init();
	lcd_vidInit();
	led_init();
	EXTI_EnableGlobalInt();
	Timer0_Init();
	Timer0_Start();

}

void Cyber_lab_loop()
{

	if(comM_isMssgReceived() ==TRUE)
	{
		comM_getMssg(GetValue_0);
		Value = StringToIntFun(GetValue_0);
		comM_sendMssg((u8*)"\r");

	}
	if(security_stge == security_stge_L0)
	{
		if(Value == 0x2701)
		{
			lcd_vidSendCmd(_LCD_CLEAR);
			security_stge = security_stge_L1;
			lcd_vidGotoRowColumn(0,0);
			lcd_vidDisplyStr((u8*)"6701 ");
			lcd_vidGotoRowColumn(1,0);
			randValue =TCNT0_Reg * 67368;
			DisplayResultt(randValue);
			Valyy =EncryptionFun((u32)randValue);
		}
		else if ((Value ==0) | (Value == 0xAA00 ))
		{}
		else
		{
			security_stge = security_stge_L0;
			lcd_vidSendCmd(_LCD_CLEAR);
			DisplayResultt(Value);
			lcd_vidGotoRowColumn(1,0);
			lcd_vidDisplyStr((u8*)"Wrong_0");
		}
	}
	else if(security_stge == security_stge_L1)
	{
		if(Value == 0x2701)
		{
			;
		}
		else if(Value == 0x2702)
		{
			security_stge = security_stge_L2;
		}
		else
		{
			security_stge = security_stge_L0;
			lcd_vidSendCmd(_LCD_CLEAR);
			DisplayResultt(Value);
			lcd_vidGotoRowColumn(1,0);
			lcd_vidDisplyStr((u8*)"Wrong_1");
		}
	}
	else if(security_stge == security_stge_L2)
	{
		if(Value == 0x2702)
		{
			;
		}
		else if(Value == Valyy)
		{
			security_stge = security_stge_L3;
			lcd_vidGotoRowColumn(2,0);
			lcd_vidDisplyStr((u8*)"6702 ");
			lcd_vidGotoRowColumn(3,0);
			lcd_vidDisplyStr((u8*)"7F2735 ");
		}
		else
		{
			lcd_vidSendCmd(_LCD_CLEAR);
			DisplayResultt(Value);
			lcd_vidGotoRowColumn(1,0);
			lcd_vidDisplyStr((u8*)"Wrong_2");
			security_stge = security_stge_L0;
		}
	}
	else if(security_stge == security_stge_L3)
	{
		if(Value == Valyy)
		{
			;
		}
		else if(Value ==  0x3101)
		{
			security_stge = security_stge_L4;
		}
		else
		{
			lcd_vidSendCmd(_LCD_CLEAR);
			DisplayResultt(Value);
			lcd_vidGotoRowColumn(1,0);
			lcd_vidDisplyStr((u8*)"Wrong_3");
			security_stge = security_stge_L0;
		}
	}
	else if(security_stge == security_stge_L4)
	{
		if(Value == 0x3101)
		{
			;
		}
		else if(Value == 0xAA00 )
		{
			security_stge = security_stge_L5;
			lcd_vidSendCmd(_LCD_CLEAR);
			lcd_vidGotoRowColumn(0,0);
			lcd_vidDisplyStr((u8*)"0x7101AA00");
			led_on(LED_YELLOW);
		}
		else
		{
			lcd_vidSendCmd(_LCD_CLEAR);
			lcd_vidDisplyStr((u8*)"NRC 7F 31 35");
		}
	}
	else if(security_stge == security_stge_L5)
	{
		if(Value == 0x2701)
		{
			security_stge = security_stge_L0;
		}

	}

}
/*******************************************************************************
 *                      End of File:  secure_diagnostics.c                                      *
 *******************************************************************************/
