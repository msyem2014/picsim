
#include "../../include/picsim.h"
#include <string.h>

void
PIC16F648A_map(void)
{
 memset(&pic->P16map,0,sizeof(P16map_t));
#ifdef ICSPDBG  
 pic->P16map.ICKBUG = &pic->ram[0x18E];
 pic->P16map.BIGBUG = &pic->ram[0x18F];
#endif 
 pic->P16map.TMR1L = &pic->ram[0xE];
 pic->P16map.TMR1H = &pic->ram[0xF];
 pic->P16map.CCPR1L = &pic->ram[0x15];
 pic->P16map.CCPR1H = &pic->ram[0x16];
 pic->P16map.INDF = &pic->ram[0x0];
 pic->P16map.TMR0 = &pic->ram[0x1];
 pic->P16map.PCL = &pic->ram[0x2];
 pic->P16map.STATUS = &pic->ram[0x3];
 pic->P16map.FSR = &pic->ram[0x4];
 pic->P16map.PORTA = &pic->ram[0x5];
 pic->P16map.PORTB = &pic->ram[0x6];
 pic->P16map.PCLATH = &pic->ram[0xA];
 pic->P16map.INTCON = &pic->ram[0xB];
 pic->P16map.PIR1 = &pic->ram[0xC];
 pic->P16map.T1CON = &pic->ram[0x10];
 pic->P16map.TMR2 = &pic->ram[0x11];
 pic->P16map.T2CON = &pic->ram[0x12];
 pic->P16map.CCP1CON = &pic->ram[0x17];
 pic->P16map.RCSTA = &pic->ram[0x18];
 pic->P16map.TXREG = &pic->ram[0x19];
 pic->P16map.RCREG = &pic->ram[0x1A];
 //pic->P16map.CMCON = &pic->ram[0x1F];
 pic->P16map.OPTION_REG = &pic->ram[0x81];
 pic->P16map.TRISA = &pic->ram[0x85];
 pic->P16map.TRISB = &pic->ram[0x86];
 pic->P16map.PIE1 = &pic->ram[0x8C];
 //pic->P16map.PCON = &pic->ram[0x8E];
 pic->P16map.PR2 = &pic->ram[0x92];
 pic->P16map.TXSTA = &pic->ram[0x98];
 pic->P16map.SPBRG = &pic->ram[0x99];
 pic->P16map.EEDATA = &pic->ram[0x9A];
 pic->P16map.EEADR = &pic->ram[0x9B];
 pic->P16map.EECON1 = &pic->ram[0x9C];
 pic->P16map.EECON2 = &pic->ram[0x9D];
 //pic->P16map.VRCON = &pic->ram[0x9F];
}

/*PINS 

01 - RA2 AN2 Vref 
02 - RA3 AN3 CMP1 
03 - RA4 T0CKI CMP2 
04 - RA5 MCLR Vpp 
05 - Vss 
06 - RB0 INT 
07 - RB1 RX DT 
08 - RB2 TX CK 
09 - RB3 CCP1 
10 - RB4 PGM 
11 - RB5 
12 - RB6 T1OSO T1CKI PGC 
13 - RB7 T1OSI PGD 
14 - Vdd 
15 - RA6 OSC2 CLKOUT 
16 - RA7 OSC1 CLKIN 
17 - RA0 AN0 
18 - RA1 AN1 
 */

/*
======================
Family=P16 
processor=PIC16F648A
deviceid=0x1100
 */

void
PIC16F648A_reset(void)
{
 
 pic->pins[ 0].port = pic->P16map.PORTA;pic->pins[ 0].pord = 2;
 pic->pins[ 1].port = pic->P16map.PORTA;pic->pins[ 1].pord = 3;
 pic->pins[ 2].port = pic->P16map.PORTA;pic->pins[ 2].pord = 4;
 pic->pins[ 3].port = pic->P16map.PORTA;pic->pins[ 3].pord = 5;
 pic->pins[ 4].port = P_VSS    ;pic->pins[ 4].pord = -1;
 pic->pins[ 5].port = pic->P16map.PORTB;pic->pins[ 5].pord = 0;
 pic->pins[ 6].port = pic->P16map.PORTB;pic->pins[ 6].pord = 1;
 pic->pins[ 7].port = pic->P16map.PORTB;pic->pins[ 7].pord = 2;
 pic->pins[ 8].port = pic->P16map.PORTB;pic->pins[ 8].pord = 3;
 pic->pins[ 9].port = pic->P16map.PORTB;pic->pins[ 9].pord = 4;
 pic->pins[10].port = pic->P16map.PORTB;pic->pins[10].pord = 5;
 pic->pins[11].port = pic->P16map.PORTB;pic->pins[11].pord = 6;
 pic->pins[12].port = pic->P16map.PORTB;pic->pins[12].pord = 7;
 pic->pins[13].port = P_VDD    ;pic->pins[13].pord = -1;pic->pins[13].value = 1;
 pic->pins[14].port = pic->P16map.PORTA;pic->pins[14].pord = 6;
 pic->pins[15].port = pic->P16map.PORTA;pic->pins[15].pord = 7;
 pic->pins[16].port = pic->P16map.PORTA;pic->pins[16].pord = 0;
 pic->pins[17].port = pic->P16map.PORTA;pic->pins[17].pord = 1;

 pic->mclr = 4;

 pic->ccp[0] = 9;
/*
 pic->adc[0] = 17;
 pic->adc[1] = 18;
 pic->adc[2] = 1;
 pic->adc[3] = 2;
*/
 pic->usart[0] = 7;
 pic->usart[1] = 8;

 pic->pgc = 12;
 pic->pgd = 13;

 pic->sck = 0;
 pic->sdo = 0;
 pic->sdi = 0;

 pic->t0cki = 3;
 pic->t1cki = 12;

 pic->int0 = 6;
 pic->int1 = 0;
 pic->int2 = 0;
}

int
PIC16F648A_getconf(unsigned int cfg)
{
 switch (cfg)
  {
  case CFG_MCLR:
   return ((pic->config[0] & 0x0020) > 0);
   break;
  case CFG_WDT:
   return ((pic->config[0] & 0x04) > 0); 
   break;
  case CFG_DEBUG:
   return ((pic->config[0] & 0x0800) == 0);
   break;
  }
 return 0;
}

void
PIC16F648A_start(void)
{
 pic->ROMSIZE = 4096;
 pic->EEPROMSIZE = 256;
 pic->RAMSIZE = 512;
 pic->PINCOUNT = 18;
 pic->IDSIZE = 8;
 pic->CONFIGSIZE = 1;
 pic->STACKSIZE = 8;
 pic->CCPCOUNT = 1;
 pic->ADCCOUNT = 0;//4;
 pic->WDT_MS = 18;
 pic->reset = PIC16F648A_reset;
 pic->mmap = PIC16F648A_map;
 pic->getconf = PIC16F648A_getconf;
}
