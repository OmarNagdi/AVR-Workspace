/*
 * SevenSeg_Interface.h
 *
 *  Created on: Jul 17, 2022
 *      Author: OmarNagdy
 */

#ifndef SEVENSEG_INTERFACE_H_
#define SEVENSEG_INTERFACE_H_





#define SEVEN_SEG_PORT PORTB



#define SEVEN_SEGMENT_PORT1 PORTB
#define SEVEN_SEGMENT_PORT2 PORTA





//FOR MY COMMON ANODE 7SEGMENT
#define ZERO     0b01000000
#define ONE	     0b01111001
#define TWO      0b00100100
#define THREE    0b00110000
#define FOUR     0b00011001
#define FIVE     0b00010010
#define SIX      0b00000010
#define SEVEN    0b01111000
#define EIGHT    0b00000000
#define NINE     0b00010000




void HSEVENSEG_voidDisplayNumber(u8 A_u8Number);

void HSEVENSEG_voidDisplayNumberOnOneSegmentOfAnInputPort(u8 A_u8PortNo,u8 A_u8Number);


#endif /* SEVENSEG_INTERFACE_H_ */
