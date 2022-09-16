/*
 * LCD_Interface.h
 *
 *  Created on: Jul 29, 2022
 *      Author: OmarNagdy
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define LCD_CONTROL_PORT	PORTB
#define  LCD_DATA_PORT		PORTC




//macros for 8 bit intit func.
#define LCD_FUNCTION_SET        0b00111100
#define DISPLAY_ON_OR_OFF_CONTROL  0b00001100
#define DISPLAY_CLEAR 			0b00000001
#define ENTRY_MODE_SET 			0b00000110


//macros for go to pos. func.
//Address of 1st cell in the first row is 128 and that of the 1st cell of the 2nd row is 192
#define  ROW1_ADDRESS_START  128
#define  ROW2_ADDRESS_START  192

#define ROW1 0
#define ROW2 1



//macros for writeoncgram func.
#define PATTERN1_BASE_ADDRESS 		0x40
#define PATTERN2_BASE_ADDRESS 		0x48
#define PATTERN3_BASE_ADDRESS 		0x50
#define PATTERN4_BASE_ADDRESS 		0x58
#define PATTERN5_BASE_ADDRESS 		0x60
#define PATTERN6_BASE_ADDRESS 		0x68
#define PATTERN7_BASE_ADDRESS 		0x70
#define PATTERN8_BASE_ADDRESS 		0x78




void HLCD_voidSendCommand(u8 A_u8Command);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidInit(void);
void HLCD_voidClearDisplay(void);
void HLCD_voidSendString(u8 *A_PtrtoString);
void HLCD_voidGoToPosition(u8 A_u8RowNumber,u8 A_u8ColumnNumber);
void HLCD_voidDisplayNumber(s32 A_s32Number);
void HLCD_voidWriteOnCGRAM(u8 A_u8PatternIndex,u8 *A_u8PtrToPatternValue);


#endif /* LCD_INTERFACE_H_ */
