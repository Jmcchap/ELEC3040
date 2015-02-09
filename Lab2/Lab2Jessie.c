#include "STM32L1xx.h"

int count = 0;

/*----------------------------------------------------------*/
/* Pin setup - initialize GPIO pins used in program */
/* PA1 - Switch 1 connected to DIO0 on the EEBoard */
/* PA2 - Switch 2 connected to DIO1 on the EEBoard */
/*----------------------------------------------------------*/
 void PinSetup(){
 /*Configure PC() as output pins for LEDS*/
 RCC->AHBENR |= 0x04;             /*Enable GPIOC clock*/
 GPIOC->MODER &= (0xFFFFFF00);    /*Clear Pins 0-3 to be set as output*/
 GPIOC->MODER |= (0x00000055);    /*Sets Pins 0-3 in output mode*/

 /*Configure PA() as input pins for S1 and S2*/
 RCC->AHBENR |= 0x01;             /*Enable GPIOA clock*/
 GPIOA->MODER &= (0xFFFFFFC3);    /*Clears Pins 1 and 2 as inputs*/

 }

/*----------------------------------------------------------*/
/* Delay function - 0.5 second delay??? */
/*----------------------------------------------------------*/
void delay ()
{
 int a,b;
 for (a=0; a<100; a++) { //outer loop
 for (b=0; b<10000; b++) { //inner loop
 }
 }
}

/*----------------------------------------------------------*/
/* Counting function - reversible decade counter with LED display */
/*----------------------------------------------------------*/
void counting (unsigned char sw2)
{
  if (sw2 = 0) //count up
  {
    if (count>=9)
      count = 0; //if count=9 roll over to 0
      else
      count++; //increment counter by one
  }
    else //count down
  {
    if (count <= 0)
      count = 9; //if count=0 roll over to 9
      else
      count--; //decrement counter by one
  }
  //insert smart stuff about binary and LEDs here
}

/*----------------------------------------------------------*/
/* Main program */
/*----------------------------------------------------------*/
int main(void)
{
  unsigned char sw1 = 1; //state of SW1
  unsigned char sw2 = 0; //state of SW2
  unsigned char led1 = 0; //state of LED1
  unsigned char led2 = 0; //state of LED2
  unsigned char led3 = 0; //state of LED3
  unsigned char led4 = 0; //state of LED4
  PinSetup(); //Configure GPIO pins

  while(1) //Endless loop
  {
    //insert smart stuff about determining the values of sw1 and sw2 here
    if (sw1 = 1) //START - increment counter and delay 0.5 seconds
    {
      counting(sw2); //increment counter and display values with LED
      delay(); //0.5 second delay
    }
    else //STOP - do nothing
    {
    }
  }
}
