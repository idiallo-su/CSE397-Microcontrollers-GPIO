#include <xc.h>

volatile int oneCount = 0;
volatile int tenCount = 0;
volatile int direction = 0;
void main(void) 
{  
    PORT_REGS->GROUP[0].PORT_DIRSET = 0b00000000000000000000101111111100;  // sets pins to an output 00 000 000 000 000 000 000 111 111 101 100
    //PORT_REGS->GROUP[0].PORT_DIRCLR = 0b00000000000000010000000000000000;  // Pushbutton  for increment set as input on PA16, physical pin 17
    PORT_REGS->GROUP[0].PORT_DIRCLR = 0b00000000000001000000000000000000;  // Pushbutton  for direction set as input on PA18, physical pin 19
    PORT_REGS->GROUP[0].PORT_DIRCLR = 0b00000000010000000000000000000000;  // Pushbutton  for reset     set as input on PA22, physical pin 21
    //PORT_REGS->GROUP[0].PORT_PINCFG[16] = 0b00000010;                      // Input enable for PA16, physical pin 17
    PORT_REGS->GROUP[0].PORT_PINCFG[18] = 0b00000010;                      // Input enable for PA18, physical pin 19
    PORT_REGS->GROUP[0].PORT_PINCFG[22] = 0b00000010;                      // Input enable for PA22, physical pin 21
    
    setUP();
    //int tenCount = 0;
    //int oneCount = 0;
    //int flagInc = 1;
    int flagDirection = 1;
    int flagReset = 1;
    //int direction = 0; //0 for forward, 1 for reverse
    
    while(1)
    {
        
        //Code for changing direction
        if((PORT_REGS->GROUP[0].PORT_IN & 0b00000000000001000000000000000000) == 0b00000000000001000000000000000000)
        {
            if(flagDirection == 1)
            {
                if(direction == 1)
                {
                    direction = 0;
                    flagDirection = 0;
                }
                else if(direction == 0)
                {
                    direction = 1;
                    flagDirection = 0;
                }
            }
        }
        else
        {
            flagDirection = 1;
        }
        
        //Code for reset button
        if((PORT_REGS->GROUP[0].PORT_IN & 0b00000000010000000000000000000000) == 0b00000000010000000000000000000000)
        {
            if(flagReset == 1)
            {
                    tenCount = 0;
                    oneCount = 0;
                    flagReset = 0;
            }
        }
        else
        {
            flagReset = 1;
        }
        
        /*
        //Code for increment or decrementing the count
        if ((PORT_REGS->GROUP[0].PORT_IN & 0b00000000000000010000000000000000) == 0b00000000000000010000000000000000)
        {
           if (flagInc == 1)
           {
               if(direction == 0) // forward/counting up
               {
                   if (oneCount < 9)
                   {
                       oneCount = oneCount + 1;
                       flagInc = 0;
                   }
                   else if ((tenCount == 9)&&(oneCount == 9))
                   {
                       tenCount = 0;
                       oneCount = 0;
                       flagInc = 0;
                   }
                   else if (oneCount == 9)
                   {
                       oneCount = 0;
                       tenCount = tenCount + 1;
                       flagInc = 0;
                   }
               }
               else if(direction == 1) // backwards/counting down
               {
                   if (oneCount > 0)
                   {
                       oneCount = oneCount - 1;
                       flagInc = 0;
                   }
                   else if ((tenCount == 0)&&(oneCount == 0))
                   {
                       tenCount = 9;
                       oneCount = 9;
                       flagInc = 0;
                   }
                   else if (oneCount == 0)
                   {
                       oneCount = 9;
                       tenCount = tenCount - 1;
                       flagInc = 0;
                   }
               }
           }
        }   
        else
        {
            flagInc = 1;
        }   
        */
                
        //Switch case for the ones digit (second display)
        switch(oneCount) 
        {
            case 0:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000011111100; //  Output the number 0 
                micros(1000);
                break;

            case 1:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000000011000; //  Output the number 1
                micros(1000);
                break;

            case 2:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001001101100; //  Output the number 2 
                micros(1000);
                break;

            case 3:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001000111100; //  Output the number 3 
                micros(1000);
                break;

            case 4:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001010011000; //  Output the number 4 
                micros(1000);        
                break;

            case 5:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001010110100; //  Output the number 5 
                micros(1000);        
                break;

            case 6:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001011110100; //  Output the number 6 
                micros(1000);        
                break;

            case 7:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000000011100; //  Output the number 7 
                micros(1000);        
                break;

            case 8:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001011111100; //  Output the number 8 
                micros(1000);        
                break;

            case 9:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000100000000; //turn off first display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000100000000000; //turn on second display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001010111100; //  Output the number 9 
                micros(1000);        
                break;
        }   

        //Switch case for the tens digit (first display)
        switch(tenCount) 
        {
            case 0:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000011111100; //  Output the number 0 
                micros(1000);        
                break;

            case 1:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000000011000; //  Output the number 1
                micros(1000);        
                break;

            case 2:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001001101100; //  Output the number 2 
                micros(1000);        
                break;

            case 3:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001000111100; //  Output the number 3 
                micros(1000);        
                break;

            case 4:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001010011000; //  Output the number 4 
                micros(1000);        
                break;

            case 5:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001010110100; //  Output the number 5 
                micros(1000);        
                break;

            case 6:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001011110100; //  Output the number 6 
                micros(1000);        
                break;

            case 7:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000000011100; //  Output the number 7 
                micros(1000);        
                break;

            case 8:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001011111100; //  Output the number 8 
                micros(1000);        
                break;

            case 9:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001010111100; //  Output the number 9 
                micros(1000);        
                break;
                
            default:
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000100000000000; //turn off second display
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //global clear
                PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000000100000000; //turns on first display
                PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000011111100; //  Output the number 0 
                micros(1000); 
        }   
    }
    return;
}

//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000011111100; //  Output the number 0 
//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000000011000; //  Output the number 1 
//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001001101100; //  Output the number 2 
//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001000111100; //  Output the number 3 
//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001010011000; //  Output the number 4 
//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001010110100; //  Output the number 5 
//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001011110100; //  Output the number 6 
//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000000000011100; //  Output the number 7 
//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001011111100; //  Output the number 8 
//PORT_REGS->GROUP[0].PORT_OUTSET = 0b00000000000000000000001010111100; //  Output the number 9 
//PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //clear first display
//PORT_REGS->GROUP[0].PORT_OUTCLR = 0b00000000000000000000001011111100; //clear second display
    
void micros(unsigned int x)
{
    TC5_REGS -> COUNT16.TC_COUNT = 0;
    TC5_REGS -> COUNT16.TC_INTFLAG = 0b00010000;
    TC5_REGS -> COUNT16.TC_CC[0] = x;
    while ((TC5_REGS ->COUNT16.TC_INTFLAG & 0b00010000) == 0b00000000);
}

void setUP (void)
{
    //hardware delay
    PM_REGS->PM_APBCMASK |= 0b00000000000000000010000000000000;
    GCLK_REGS->GCLK_CLKCTRL = 0b0100000000011100;
    TC5_REGS->COUNT16.TC_CTRLA = 0b0000000000100000;
    TC5_REGS->COUNT16.TC_CC[0] = 1000;
    TC5_REGS->COUNT16.TC_CTRLA |= 0b0000000000000010;
    
    //interrupt
    PORT_REGS->GROUP[0].PORT_PINCFG[16] = 0x07;
    PM_REGS->PM_APBAMASK |= 0x00000040;
    GCLK_REGS->GCLK_CLKCTRL = 0x4005;
    EIC_REGS->EIC_INTENSET = 0x00000001;
    EIC_REGS->EIC_CONFIG[0] = 0x00000009;
    EIC_REGS->EIC_CTRL = 0x02;
    NVIC_EnableIRQ(EIC_IRQn);
}

void EIC_Handler(void)
{   
   //PORT_REGS->GROUP[0].PORT_OUTTGL = 0b00000000000000000000000000000001;

   if(direction == 0) // forward/counting up
   {
       if (oneCount < 9)
       {
           oneCount = oneCount + 1;
       }
       else if ((tenCount == 9)&&(oneCount == 9))
       {
           tenCount = 0;
           oneCount = 0;
       }
       else if (oneCount == 9)
       {
           oneCount = 0;
           tenCount = tenCount + 1;
       }
   }
   else if(direction == 1) // backwards/counting down
   {
       if (oneCount > 0)
       {
           oneCount = oneCount - 1;
       }
       else if ((tenCount == 0)&&(oneCount == 0))
       {
           tenCount = 9;
           oneCount = 9;
       }
       else if (oneCount == 0)
       {
           oneCount = 9;
           tenCount = tenCount - 1;
       }
   }   
    //Clear the external interrupt 0 flag
    EIC_REGS->EIC_INTFLAG = 0x00000001;
}
