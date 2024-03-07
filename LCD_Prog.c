/*
 * LCD_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "LCD_Interface.h"
#include "LCD_Private.h"

void H_LCD_Void_LCDInit(void)
{
#if   LCD_MODE   ==   LCD_8_BIT_MODE
	M_DIO_Void_SetPinDirection(LCD_D0_PORT,LCD_D0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D1_PORT,LCD_D1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D2_PORT,LCD_D2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D3_PORT,LCD_D3_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D4_PORT,LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PORT,LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PORT,LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PORT,LCD_D7_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	H_LCD_Void_LCDWriteCommand(LCD_8_BIT_MODE_COMMAND);
	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);
#elif LCD_MODE   ==   LCD_4_BIT_MODE
	M_DIO_Void_SetPinDirection(LCD_D4_PORT,LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PORT,LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PORT,LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PORT,LCD_D7_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_1);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_2);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_3);
	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_COMMAND);
	H_LCD_Void_LCDWriteCommand(LCD_RETURN_HOME_COMMAND);
#endif
}
void H_LCD_Void_LCDWriteCharacter(u8 Copy_U8_Character)
{
#if LCD_MODE   ==   LCD_8_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	M_DIO_Void_SetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(Copy_U8_Character,0));
	M_DIO_Void_SetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(Copy_U8_Character,1));
	M_DIO_Void_SetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(Copy_U8_Character,2));
	M_DIO_Void_SetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(Copy_U8_Character,3));
	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Character,4));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Character,5));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Character,6));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Character,7));
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
#elif LCD_MODE   ==   LCD_4_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);

	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Character,4));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Character,5));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Character,6));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Character,7));

	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);

	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Character,0));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Character,1));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Character,2));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Character,3));

	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
#endif
}
void H_LCD_Void_LCDWriteCommand(u8 Copy_U8_Command)
{
#if LCD_MODE   ==   LCD_8_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
	M_DIO_Void_SetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(Copy_U8_Command,0));
	M_DIO_Void_SetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(Copy_U8_Command,1));
	M_DIO_Void_SetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(Copy_U8_Command,2));
	M_DIO_Void_SetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(Copy_U8_Command,3));
	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
#elif LCD_MODE   ==   LCD_4_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);

	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));

	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);

	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Command,0));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Command,1));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Command,2));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Command,3));

	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
#endif
}
void H_LCD_Void_LCDWriteString(u8*Copy_U8_Ptr)
{
	u8 Local_U8_Counter = 0;
	while(Copy_U8_Ptr[Local_U8_Counter] != '\0')
	{
		H_LCD_Void_LCDWriteCharacter(Copy_U8_Ptr[Local_U8_Counter]);
		Local_U8_Counter++;
	}
}
void H_LCD_Void_LCDWriteNumber(s32 Copy_S32_Num)
{
	if(Copy_S32_Num < 0)
	{
		Copy_S32_Num = Copy_S32_Num * -1;
		H_LCD_Void_LCDWriteCharacter('-');
	}
	u8 Local_U8_Arr[10] = {0};
	s8 Local_S8_Counter = -1;
	while(Copy_S32_Num != 0)
	{
		Local_S8_Counter++;
		Local_U8_Arr[Local_S8_Counter] = Copy_S32_Num % 10;
		Copy_S32_Num = Copy_S32_Num / 10;
	}
	while(Local_S8_Counter >= 0)
	{
		H_LCD_Void_LCDWriteCharacter( Local_U8_Arr[Local_S8_Counter] + LCD_ASCII_OF_0);
		Local_S8_Counter--;
	}
}

void H_LCD_Void_LCDClear(void)
{
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_COMMAND);
}

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col)
{
	switch(copy_u8Row)
	{
		case 0:
			H_LCD_Void_LCDWriteCommand(0x80+copy_u8Col);
			break;
		case 1:
			H_LCD_Void_LCDWriteCommand(0xC0+copy_u8Col);
			break;
		case 2:
			H_LCD_Void_LCDWriteCommand(0x94+copy_u8Col);
			break;
		case 3:
			H_LCD_Void_LCDWriteCommand(0xD4+copy_u8Col);
			break;
		default:
			break;
	}
	_delay_ms(1);
}



void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum )
{
	copy_u8ByteNum &= 0x7; // we only have 8 locations 0-7
	H_LCD_Void_LCDWriteCommand(0x40 | (copy_u8ByteNum << 3)); // Set CGRAM address
	for (int i = 0; i < 8; i++)
	{
		H_LCD_Void_LCDWriteCharacter(copy_u8data[i]); // Write character pattern
	}
}

void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum )
{
	H_LCD_Void_LCDWriteCommand(0x80); // Move cursor to the beginning of the first line
	H_LCD_Void_LCDWriteCharacter(copy_u8ByteNum);
}


