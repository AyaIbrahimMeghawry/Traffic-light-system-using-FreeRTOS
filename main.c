/*
 * main.c
 *
 *  Author:Aya Meghawry
 *  Created on: 12/9/2023
 *
 */


#include "TYPES.h"
#include "BIT_MATH.h"
#include"DIO_interface.h"
#include "Sevev_Seg_Interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


void Task1(void* pvParameters);
void Task2(void* pvParameters);
void Task3(void* pvParameters);


xSemaphoreHandle LEDSem;
int main ()
{
	Sev_Seg_Intialize();
	MDIO_voidSetPinDirect(DIO_PORTD , PIN3,PIN_OUTPUT); //Yellow Led
	MDIO_voidSetPinDirect(DIO_PORTD , PIN4,PIN_OUTPUT); //Red Led
	MDIO_voidSetPinDirect(DIO_PORTD , PIN5,PIN_OUTPUT); //Green Led


	xTaskCreate(Task1,"Task1",200,NULL,3,NULL);
	xTaskCreate(Task2,"Task2",200,NULL,2,NULL);
	xTaskCreate(Task3,"Task3",200,NULL,1,NULL);

	LEDSem =xSemaphoreCreateCounting(3,1);
	vTaskStartScheduler();
	while (1)
	{
	}

	return 0;
}


void Task1(void* pvParameters)
{
	u8 Local_u8Semstate;
	u8 Local_U8Counter1;
	u8 Local_U8Counter2;
	while (1)
	{
		Local_u8Semstate =xSemaphoreTake(LEDSem,0);
		if (Local_u8Semstate == pdPASS)
		{
			MDIO_voidSetPinValue(DIO_PORTD, PIN5, PIN_HIGH);
			for (Local_U8Counter1 = 0; Local_U8Counter1 <=5;Local_U8Counter1++)
			{
				Sev_Seg2_WriteNumber(Local_U8Counter1);
				for (Local_U8Counter2 = 0; Local_U8Counter2 <= 9;Local_U8Counter2++)
				{
					Sev_Seg1_WriteNumber(Local_U8Counter2);
					vTaskDelay((200));
				}
			}
			MDIO_voidSetPinValue(DIO_PORTD, PIN5, PIN_LOW);
			xSemaphoreGive(LEDSem);
		}
		vTaskDelay(1000);
	}
}


void Task2(void* pvParameters)
{
	u8 Local_u8Semstate;
	u8 Local_U8Counter1;
	u8 Local_U8Counter2;
	while (1)
	{
		Local_u8Semstate =xSemaphoreTake(LEDSem,0);
		if (Local_u8Semstate == pdPASS)
		{
			MDIO_voidSetPinValue(DIO_PORTD, PIN4, PIN_HIGH);
			for (Local_U8Counter1 = 0; Local_U8Counter1 <=5;Local_U8Counter1++)
			{
				Sev_Seg2_WriteNumber(Local_U8Counter1);
				for (Local_U8Counter2 =0; Local_U8Counter2 <= 9;Local_U8Counter2++)
				{
					Sev_Seg1_WriteNumber(Local_U8Counter2);
					vTaskDelay((200));
				}
			}
			MDIO_voidSetPinValue(DIO_PORTD, PIN4, PIN_LOW);
			xSemaphoreGive(LEDSem);
		}
		vTaskDelay(1000);
	}
}

void Task3(void* pvParameters)
{
	u8 Local_u8Semstate;
	u8 Local_U8Counter1;
	u8 Local_U8Counter2;

	while (1)
	{
		Local_u8Semstate =xSemaphoreTake(LEDSem,0);
		if (Local_u8Semstate == pdPASS)
		{
			MDIO_voidSetPinValue(DIO_PORTD, PIN3, PIN_HIGH);
			for (Local_U8Counter1 = 0; Local_U8Counter1 <=5;Local_U8Counter1++)
			{
				Sev_Seg2_WriteNumber(Local_U8Counter1);
				for (Local_U8Counter2 =0; Local_U8Counter2 <= 9;Local_U8Counter2++)
				{
					Sev_Seg1_WriteNumber(Local_U8Counter2);
					vTaskDelay((200));
				}
			}
			MDIO_voidSetPinValue(DIO_PORTD, PIN3, PIN_LOW);
			xSemaphoreGive(LEDSem);
		}
		vTaskDelay(1000);
	}
}


