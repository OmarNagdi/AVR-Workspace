/*
 * ADC_Interface.h
 *
 *  Created on: Aug 12, 2022
 *      Author: OmarNagdy
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

//CHoose a  channel value among these values
#define CHANNEL_0	0
//..etc



void MADC_voidInit(void);
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo);



#endif /* ADC_INTERFACE_H_ */
