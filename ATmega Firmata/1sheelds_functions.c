﻿/*
 * _1sheelds_functions.c
 *
 * Created: 24/12/2013 08:53:17 م
 *  Author: HP
 */ 
#include "gpio.h"
#include "pwm.h"
#include "mapping162.h"


void pinMode(uint8 pin , uint8 pinMode)
{
	uint8 bit = digitalPinToBitMask(pin);
	uint8 port = digitalPinToPort(pin);
	t_SetPortCfg cfg;
	
	if(port == NOT_A_PIN)
	{
		return;
	}
	
	
	//cfg.initValue=0x00;
	//SET_BIT((cfg.initValue),bit);
	cfg.pID = portModeRegister(port);
	
	if(pinMode == INPUT)
	{
		//cfg.Portdir &= (~(1 << bit)); 
		CLR_BIT((cfg.Portdir),bit);
		//cfg.Portdir=0x00;
	}
	else
	{		
		SET_BIT((cfg.Portdir),bit);
		//cfg.Portdir =0xff;//|= (1 << bit);
		//cfg.Portdir=0xff;
	}
	
	GPIO_Cfg(&cfg);
}

uint8  digitalRead(uint8 pin)
{
	uint8 bit = digitalPinToBitMask(pin);
	uint8 port = digitalPinToPort(pin);
	t_SetPortCfg cfg;
	
	if(port == NOT_A_PIN)
	{
		return 0;
	}
	
	cfg.pID = portModeRegister(port);
	
	return GPIO_getPin(cfg.pID,bit);
			
}

void   digitalWrite(uint8 pin, uint8 value)
{
	uint8 bit = digitalPinToBitMask(pin);
	uint8 port = digitalPinToPort(pin);
	t_SetPortCfg cfg;
	
	if(port == NOT_A_PIN)
	{
		//return;
	}
	
	cfg.pID = portModeRegister(port);
	
	GPIO_setPin(value,cfg.pID,bit);
}


void analogWrite(uint8 pin, uint16 val)
{
	uint8 timer = 0xff;
	pinMode(pin, OUTPUT);
		
	timer = digitalPinToTimer(pin);	 
	pwm_Setup(timer);
	pwm_SetDutyCycle(val, timer);	
}

uint8 readPort(byte port, byte bitmask)
{
	unsigned char out=0, pin=port*8;
	if ((IS_PIN_DIGITAL(pin+0)) && (bitmask & 0x01) && ( digitalRead(pin+0))) out |= 0x01;
	if ((IS_PIN_DIGITAL(pin+1)) && (bitmask & 0x02) && ( digitalRead(pin+1))) out |= 0x02;
	if ((IS_PIN_DIGITAL(pin+2)) && (bitmask & 0x04) && ( digitalRead(pin+2))) out |= 0x04;
	if ((IS_PIN_DIGITAL(pin+3)) && (bitmask & 0x08) && ( digitalRead(pin+3))) out |= 0x08;
	if ((IS_PIN_DIGITAL(pin+4)) && (bitmask & 0x10) && ( digitalRead(pin+4))) out |= 0x10;
	if ((IS_PIN_DIGITAL(pin+5)) && (bitmask & 0x20) && ( digitalRead(pin+5))) out |= 0x20;
	if ((IS_PIN_DIGITAL(pin+6)) && (bitmask & 0x40) && ( digitalRead(pin+6))) out |= 0x40;
	if ((IS_PIN_DIGITAL(pin+7)) && (bitmask & 0x80) && ( digitalRead(pin+7))) out |= 0x80;
	return out;
}

void writePort(byte port, byte value, byte bitmask)
{
	byte pin=port*8;
	if ((bitmask & 0x01)) digitalWrite((pin+0), (value & 0x01));
	if ((bitmask & 0x02)) digitalWrite((pin+1), (value & 0x02));
	if ((bitmask & 0x04)) digitalWrite((pin+2), (value & 0x04));
	if ((bitmask & 0x08)) digitalWrite((pin+3), (value & 0x08));
	if ((bitmask & 0x10)) digitalWrite((pin+4), (value & 0x10));
	if ((bitmask & 0x20)) digitalWrite((pin+5), (value & 0x20));
	if ((bitmask & 0x40)) digitalWrite((pin+6), (value & 0x40));
	if ((bitmask & 0x80)) digitalWrite((pin+7), (value & 0x80));
}