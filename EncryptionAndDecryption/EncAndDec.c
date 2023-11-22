/*******************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * Module: 
 *
 * File Name: EncAndDec.c
 *
 * Created on: Nov 20, 2023 
 *
 * Description: Source file 
 *
 * Author: Ahmed El-Abbasy
 *
 *******************************************************************************/

/*******************************************************************************
 *                      Includes                                               *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 *                      Local Data                                             *
 *******************************************************************************/


/*******************************************************************************
 *                      Global Data                                            *
 *******************************************************************************/


 /*******************************************************************************
 *                      ISR's Definitions                                      *
 *******************************************************************************/


/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/


/*******************************************************************************
 *                      Private Functions Definitions                          *
 *******************************************************************************/
  

/*******************************************************************************
 *                      Global Functions Definitions                           *
 *******************************************************************************/


/*******************************************************************************
 *                               Main Functions                           *
 *******************************************************************************/
int main()
{
	int i =0;
	char message2[50];
	int flag1 =0;
	int key =0;
	char* message="Choose from list!\n";

	while(1)
	{
		printf("\n=========================\n");
		for(int i =0; i< strlen(message);i++)
		{
			printf("%c",message[i]);
		}
		printf("1-Encryption \n2-Decryption \n3-Exit\n");
		scanf("%d",&i);
		getchar();
		printf("\n");
		if(i == 3)
        {
            break;
        }
		printf("Please enter your message\n");

		gets(message2);

		printf("Please enter your Key\n");
		scanf("%d",&key);
		getchar();
		printf("\n");
		key = key % 26;

		for(int c =0; c<strlen(message2);c++)
		{
			if((message2[c] >='a' & message2[c] <='z')|( message2[c] >='A' & message2[c] <='Z')|message2[c] ==' ')
			{
			}
			else
			{
				flag1 = 1;
				break;
			}
		}

		int flag2 =0;
		if(flag1 == 1)
		{
			printf("Your message is invalid\n");
		}
		else
		{
			for(int c =0; c<strlen(message2);c++)
			{
				if(i == 1)
				{
					if((message2[c] >='a' & message2[c] <='z') )
					{
						if ((message2[c]+key) > 'z')
						{
							flag2 = (message2[c]+key) - 'z'-1;
							message2[c] = 'a'+flag2;
							printf("%c",message2[c]);
						}
						else
						{
							printf("%c",message2[c]+key);
						}
					}
					else if ((message2[c] >='A' & message2[c] <='Z') )
					{
						if ((message2[c]+key) > 'Z')
						{
							flag2 = (message2[c]+key) - 'Z'-1;
							message2[c] = 'A'+flag2;
							printf("%c",message2[c]);
						}
						else
						{
							printf("%c",message2[c]+key);
						}
					}
					else if(message2[c] >=' ')
					{
						printf("%c",message2[c]);
					}
				}
				else if(i = 2)
				{
					if((message2[c] >='a' & message2[c] <='z') )
					{
						if ((message2[c]-key) < 'a')
						{
							flag2 = 'a' -(message2[c]-key) -1;
							message2[c] = 'z'-flag2;
							printf("%c",message2[c]);
						}
						else
						{
							printf("%c",message2[c]-key);
						}
					}
					else if ((message2[c] >='A' & message2[c] <='Z') )
					{
						if ((message2[c]-key) < 'A')
						{
							flag2 = 'A' -(message2[c]-key) -1;
							message2[c] = 'Z'-flag2;
							printf("%c",message2[c]);
						}
						else
						{
							printf("%c",message2[c]-key);
						}
					}
					else if(message2[c] >=' ')
					{
						printf("%c",message2[c]);
					}
				}
				else
				{
					flag1 = 2;
					break;
				}
			}
			printf("\n");
		}
		if(flag1 == 2)
		{
			break;
		}
	}

	return 0;
}


/*******************************************************************************
 *                      End of File: EncAndDec.c                                        *
 *******************************************************************************/



























