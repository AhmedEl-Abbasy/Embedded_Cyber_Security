/******************************************************************************
 * Module:
 *
 * File Name:functions.c
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
#include "cyper_p.h"

/*******************************************************************************
 *                      Global Constant Macros                                 *
 *******************************************************************************/
/*******************************************************************************
 *                      Global Function Macros                                 *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data Types and Structures                       *
 *******************************************************************************/
/*******************************************************************************
 *                      Global Data Prototypes                                 *
 *******************************************************************************/

/*******************************************************************************
 *                      Global Function                             *
 *******************************************************************************/

u32 StringToIntFun(u8* GetValue_0)
{
	u32 retvalue =0;
	u8 number = 0;
	//lcd_vidDisplyStr(GetValue_0);
	for(u8 i =0;i<100;i++)
	{
		if(GetValue_0[i] != '\0')
		{
			if((GetValue_0[i]>='0')&(GetValue_0[i]<='9'))
			{
				number = GetValue_0[i] - 48;
				retvalue = retvalue * 16;
				retvalue = retvalue +number;
				number =0;
			}
			else if((GetValue_0[i]>='a')&(GetValue_0[i]<='f'))
			{
				number = GetValue_0[i] - 87;
				retvalue = retvalue * 16;
				retvalue = retvalue +number;
				number =0;
			}
			else if((GetValue_0[i]>='A')&(GetValue_0[i]<='F'))
			{
				number = GetValue_0[i] - 55;
				retvalue = retvalue * 16;
				retvalue = retvalue +number;
				number =0;
			}
		}
		else
		{
			break;
		}
	}
	return retvalue;
}

void DisplayResultt(u32 result)
{
	u32 result1 =0;
	int i;
	for(i =0;i<100;i++)
	{
		result1 =result1 *10;
		result1 = result1 +(result % 10);
		result = result/10;
		if(result == 0)
			break;
	}
	for(;i>=0;i--)
	{
		lcd_vidDisplyChar((result1%10)+48);
		result1 = result1 /10;
//		for(u32 i1=0;i1<10000;i1++);
	}

}

u32 EncryptionFun(u32 xx)
{
	u32 yy =0;
	//yy = xx + 0x11001201;	285217281
	yy = xx + 285217281;
	return yy;
}

/*******************************************************************************
 *                      End of File:  functions.c                                      *
 *******************************************************************************/










