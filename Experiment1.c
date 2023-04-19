# include <xc.h>

void main(void) {
  
  DDRC = 16; // will make pin 5 an output 0B 00010000
  
  while(1)
  {
    if((PINC & 00000001) == 00000001)
    {
      //PORTC = 16;
      PORTC = 0;
    }
    else
    {
      PORTC = 16;
      PORTC = 0;
    }
    return;
  }
