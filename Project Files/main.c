/*
Interfacing HC-SR04 Ultrasonic Distance sensor with LPC2148 - Example Source Code for KEIL ARM.
www.tmisystems.in
*/

//#include <lpc214x.h>
#include <stdio.h> 
#include "lib_funcs.h"
#include <lpc21xx.h>
#include<lpc213x.h>
#include<string.h>
//#include<lpc21xx.h>


#define TRIG (1<<5) //P0.5
#define ECHO (1<<4) //P0.4


//lcd define functions

#define SLAVE_ADDR 78    
#define MAX        12
#define AA         2
#define SI         3
#define STO        4
#define STA        5
#define I2EN       6


///1212dc
void delay22( long int x)
{
unsigned int i;
for(i=0;i<x;i++);

}


///1212dc



// lcd functions calls



//         Delay Function
//
void wait(int count)
	{
      while(count-- );
}
//////////////////////////
//        Initialize I2c
//
//
//
void I2C_Init (void)
{
   VPBDIV    =   0x02;        // sets FOSC =  60MHHZ
   PINSEL0   =   0x00000050;  // set po.2,p0.3 to sda scl
   I2C0SCLH   =   150;        //50%duty,I2CFreq->100KHz,PCLK=30MHz
   I2C0SCLL   =   150;
   I2C0CONSET  =  (1<<I2EN);  //Enable I2C module
	 //PINSEL1 = 0x00000000 ;		// Configure P0.16 to P0.31 as GPIO
	// IO0DIR  = 0x000F0000 ;
	// IO0CLR = 0x000F0000;
}
//////////////////////////
//     Enter Master 
//     transmitter Mode
//
int I2C_Start ()
{
   I2C0CONCLR   =   1 << STO; 
   I2C0CONCLR = 1 << SI;   
   I2C0CONSET   =   1 << STA; 
   return 0;
}


void delay_ms(int count)
{
  int j=0,i=0;
 
  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 10 us */
    for(i=0;i<35;i++);
  }
}







void senddata(char data){ 
     while(!(I2C0CONSET & 0x08)); 		 
		 I2C0DAT      =   data; 
		 I2C0CONCLR   =   1 << SI;
		 delay_ms(200);
} 
void LCD_Command (char cmnd)	/* LCD16x2 command funtion */
{
	char data;
	data = (cmnd & 0xF0)|0x04|0x08;/* Send upper nibble */     // 0X08 NEED TO CHK
	//rs=0;	rw=0;	en=1; 0100 = 0x04 LSB
	senddata(data);
	delay_ms(100);
	//en=0;
	data = (cmnd & 0xF0)|0x08;
	senddata(data);
	delay_ms(100);
	
	data = (cmnd << 4)|0x04|0x08;/* Send lower nibble */
	senddata(data);
	delay_ms(100);
	//en=0;
	data = (cmnd << 4)|0x08;
	senddata(data);
	delay_ms(100);
}
void LCD_Char (char char_data)	/* LCD data write function */
{
	char data;
	//rs=1;		rw=0;		en=1;
	data =(char_data & 0xF0)|0x08|0x05;/* Send upper nibble */
	senddata(data);
	delay_ms(1);
	//rs=1; rw =0 ; en=0;
	data =(char_data & 0xF0)|0x08|0x01;
	senddata(data);
	delay_ms(2);

	////rs=1; rw =0 ; en=1;
	data = (char_data << 4)|0x08|0x05;/* Send lower nibble */
	senddata(data);
	delay_ms(1);
	////rs=1; rw =0 ; en=0;
	data = (char_data << 4)|0x08|0x01;
	senddata(data);
	delay_ms(5);
	senddata(0x08);
}
void LCD_String (char *str)	/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);  /* Call LCD data write */
	}
}

//void LCD_String_xy (char row, char pos, char *str)  /* Send string to LCD function */
//{
	//if (row == 0)
	//LCD_Command((pos & 0x0F)|0x80);
	//else if (row == 1)
	//LCD_Command((pos & 0x0F)|0xC0);
//	LCD_String(str);  	/* Call LCD string function */
//}




//end lcd function calls


void delay(unsigned int x)
{
	unsigned int i;
	for(i=0;i<x;i++);
}

int main(void)
{
	
	
//dc motor start
	
	
////DC Motor old P0.8 P0.9



//dc main code start
	
{
	//delay(10);//
	printf("1");
	IODIR0=0x00000300;
	{
	//delay(10);//
		printf("2");
	IOSET0=0x00000300;
	//delay(10);//
		printf("3");
	delay22(100);
	//delay(10);//
		printf("4");
  IOCLR0=0x00000300;
  //delay(10);//
		printf("5");
	}
}


//dc motor stop

	


	initClocks(); //Set PCLK = CCLK = 60Mhz - used by: UART, Timer and ADC
	initUART0();  //Initialize UART0 for retargeted printf()
	initTimer0(); //Init Timer for delay functions
	int echoTime=0;
	int distance=0;

	IO0DIR |= TRIG;    //Set P0.2(TRIG) as output
	IO0DIR &= ~(ECHO); //Set P0.3(ECHO) as input (explicitly)
	IO0CLR |= TRIG;    //Set P0.2 LOW initially

	printf("Ultrasonic sensor\n");
	delayMS(2000);//Wait for GPIO to be stable

	//while(1)
	{
		//Output 10us HIGH on TRIG pin
		IO0SET |= TRIG;
		delayUS(10);
		IO0CLR |= TRIG;

		while(!(IO0PIN & ECHO)); //Wait for a HIGH on ECHO pin
		startTimer0(); //Start counting
		while(IO0PIN & ECHO); //Wait for a LOW on ECHO pin
		echoTime = stopTimer0(); //Stop counting and save value(us) in echoTime

		distance = (0.0343 * echoTime)/2; //Find the distance

		printf("Distance = %dcm\n",distance);
		
		delayMS(500); //wait 1 second for next update
	
		//start
		
if(distance>5)			
{
 {
	//unsigned int x;
	 //int i;
	PINSEL2=0x00000000;
	IO0DIR=0x0000F000;
	//while(distance>5)
	{	
		
		
			IO0SET=0x00001000;
			delay(80000);
			IO0CLR=0x00001000;
			delay(80000);
			IO0SET=0x00002000;
			delay(80000);
			IO0CLR=0x00002000;
			delay(80000);
			IO0SET=0x00004000;
			delay(80000);
			IO0CLR=0x00004000;
			delay(80000);
			IO0SET=0x00008000;
			delay(80000);
			IO0CLR=0x00008000;
			delay(80000);
		IO0SET=0x00001000;
			delay(80000);
			IO0CLR=0x00001000;
			delay(80000);
			IO0SET=0x00002000;
			delay(80000);
			IO0CLR=0x00002000;
			delay(80000);
			IO0SET=0x00004000;
			delay(80000);
			IO0CLR=0x00004000;
			delay(80000);
			IO0SET=0x00008000;
			delay(80000);
			IO0CLR=0x00008000;
			delay(80000);
			IO0SET=0x00001000;
			delay(80000);
			IO0CLR=0x00001000;
			delay(80000);
			IO0SET=0x00002000;
			delay(80000);
			IO0CLR=0x00002000;
			delay(80000);
			IO0SET=0x00004000;
			delay(80000);
			IO0CLR=0x00004000;
			delay(80000);
			IO0SET=0x00008000;
			delay(80000);
			IO0CLR=0x00008000;
			delay(80000);
			IO0SET=0x00001000;
			delay(80000);
			IO0CLR=0x00001000;
			delay(80000);
			IO0SET=0x00002000;
			delay(80000);
			IO0CLR=0x00002000;
			delay(80000);
			IO0SET=0x00004000;
			delay(80000);
			IO0CLR=0x00004000;
			delay(80000);
			IO0SET=0x00008000;
			delay(80000);
			IO0CLR=0x00008000;
			delay(80000);
			IO0SET=0x00001000;
			delay(80000);
			IO0CLR=0x00001000;
			delay(80000);
			IO0SET=0x00002000;
			delay(80000);
			IO0CLR=0x00002000;
			delay(80000);
			IO0SET=0x00004000;
			delay(80000);
			IO0CLR=0x00004000;
			delay(80000);
			IO0SET=0x00008000;
			delay(80000);
			IO0CLR=0x00008000;
			delay(80000);
		  IO0SET=0x00001000;
			delay(80000);
			IO0CLR=0x00001000;
			delay(80000);
			IO0SET=0x00002000;
			delay(80000);
			IO0CLR=0x00002000;
			delay(80000);
			IO0SET=0x00004000;
			delay(80000);
			IO0CLR=0x00004000;
			delay(80000);
			IO0SET=0x00008000;
			delay(80000);
			IO0CLR=0x00008000;
			delay(80000);
			IO0SET=0x00001000;
			delay(80000);
			IO0CLR=0x00001000;
			delay(80000);
			IO0SET=0x00002000;
			delay(80000);
			IO0CLR=0x00002000;
			delay(80000);
			IO0SET=0x00004000;
			delay(80000);
			IO0CLR=0x00004000;
			delay(80000);
			IO0SET=0x00008000;
			delay(80000);
			IO0CLR=0x00008000;
			delay(80000);
			IO0SET=0x00001000;
			delay(80000);
			IO0CLR=0x00001000;
			delay(80000);
			IO0SET=0x00002000;
			delay(80000);
			IO0CLR=0x00002000;
			delay(80000);
			IO0SET=0x00004000;
			delay(80000);
			IO0CLR=0x00004000;
			delay(80000);
			IO0SET=0x00008000;
			delay(80000);
			IO0CLR=0x00008000;
			delay(80000);
		}
	}
 
	
	{
		
	
		  char code =  SLAVE_ADDR;// 0x6e;
		  
		  char str[] = "cart is empty";
		  int i =0;
		  I2C_Init();                  //Initialize I2C moodule		
		I2C_Start();                 //start I2C module 
     	wait(4000);

			while(!(I2C0CONSET & 0x08)); //wait till SI bit set
			//IO0SET = (1<<21);
      I2C0CONCLR	 =	 1 << STO;
			I2C0CONCLR	 =	 1 << STA;				
			I2C0CONSET   =   1 << AA;
			I2C0DAT      =  code;
			
			I2C0CONCLR   =   1 << SI; 
			//wait(4000);	
			while(!(I2C0CONSET & 0x08));
			//IO0SET = 0x00010000;	
			
			
			if(I2C0STAT == 0x18)                     //SLA+W has been transmitted; ACK has been received
			{	  
					// IO0SET = (1<<23);	  	   	 
				   I2C0CONSET   =   1 << AA;
					 I2C0DAT      =   0x00;//x00;//Buff[index]; 
				   I2C0CONCLR   =   1 << SI; 
				//	 IO0SET = 0x00020000;
				   while(!(I2C0CONSET & 0x08));
					 for(i=0; i < 2000;i++)wait(800);
				   if(I2C0STAT == 0x28)   //Data byte in I2DAT has been transmitted; ACK has been received
					 {	
						// IO0SET = 0x00030000;           						
															
						LCD_Command(0x02);
						LCD_Command (0x28);	/* Initialization of 16X2 LCD in 4bit mode */
						LCD_Command (0x0C);	/* Display ON Cursor OFF */
						LCD_Command (0x06);	/* Auto Increment cursor */
						LCD_Command (0x01);	/* Clear display */
						LCD_Command (0x80);	/* Cursor at home position */
						 
						LCD_String(str);
						 //LCD_String_xy(1,0,"HELLO WORLD");
					
					//  while(1){
					//			IO0CLR = 0x000F0000;
					//			for(i=0; i < 2000;i++)wait(800);
					//			IO0SET = 0x000F0000;
					//			for(i=0; i < 2000;i++)wait(800);
					//		}	;

			    }		
			}
			
}//END OF MAIN lcd
	
	
	
}
 //stop

else
{

	{
		
	
		  char code =  SLAVE_ADDR;// 0x6e;
		  
		  char str[] = "cart is full";
		  int i =0;
		  I2C_Init();                  //Initialize I2C moodule		
		I2C_Start();                 //start I2C module 
     	wait(4000);

			while(!(I2C0CONSET & 0x08)); //wait till SI bit set
			//IO0SET = (1<<21);
      I2C0CONCLR	 =	 1 << STO;
			I2C0CONCLR	 =	 1 << STA;				
			I2C0CONSET   =   1 << AA;
			I2C0DAT      =  code;
			
			I2C0CONCLR   =   1 << SI; 
			//wait(4000);	
			while(!(I2C0CONSET & 0x08));
			//IO0SET = 0x00010000;	
			
			
			if(I2C0STAT == 0x18)                     //SLA+W has been transmitted; ACK has been received
			{	  
					// IO0SET = (1<<23);	  	   	 
				   I2C0CONSET   =   1 << AA;
					 I2C0DAT      =   0x00;//x00;//Buff[index]; 
				   I2C0CONCLR   =   1 << SI; 
				//	 IO0SET = 0x00020000;
				   while(!(I2C0CONSET & 0x08));
					 for(i=0; i < 2000;i++)wait(800);
				   if(I2C0STAT == 0x28)   //Data byte in I2DAT has been transmitted; ACK has been received
					 {	
						// IO0SET = 0x00030000;           						
															
						LCD_Command(0x02);
						LCD_Command (0x28);	/* Initialization of 16X2 LCD in 4bit mode */
						LCD_Command (0x0C);	/* Display ON Cursor OFF */
						LCD_Command (0x06);	/* Auto Increment cursor */
						LCD_Command (0x01);	/* Clear display */
						LCD_Command (0x80);	/* Cursor at home position */
						 
						LCD_String(str);
						 //LCD_String_xy(1,0,"HELLO WORLD");
					
					//  while(1){
					//			IO0CLR = 0x000F0000;
					//			for(i=0; i < 2000;i++)wait(800);
					//			IO0SET = 0x000F0000;
					//			for(i=0; i < 2000;i++)wait(800);
					//		}	;

			    }		
			}
			
}//END OF MAIN lcd
	
	
}
///12

 

 
















///34
		
		
main();
}}
	
	//return 0; //This won't execute normally

