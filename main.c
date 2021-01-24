/************************************************************
*** Title: rEsIsToЯ_bAnD_сОl0ur_CoDe__CaLcUlAt0Я ************
*** Author: cold_summer aka Elizabeth Maslennikova **********
*** Date: ~01/12/2019 *************************************** yes, it was written in 2019
************************************************************/

#include <stdio.h>
#include <stdlib.h> // for func
#include <ctype.h>  // for func toupper()
#include <math.h>   // for func pow()

// #define NUMBER_OF_TOTAL_COLOURS 13
#define NUMBER_OF_COLOURS 11
#define NUMBER_OF_TOLERANCE 3 

char *interface [] = 
{
"\n      Colours               Multiplier values          Tolerance        Select",
"\n*-----------------*      *--------------------*      *-----------*",    
"\n|0 value     BLACK| 10^0 |1                   |      |           |     tap [B]"
"\n|1 value    COFFEE| 10^1 |10                  |      |     1%    |     tap [C]",
"\n|2 value       RED| 10^2 |100                 |      |     2%    |     tap [R]",
"\n|3 value    ORANGE| 10^3 |1000                |      |           |     tap [O]", 
"\n|4 value    YELLOW| 10^4 |10000               |      |           |     tap [Y]", 
"\n|5 value   EMERALD| 10^5 |100000              |      |           |     tap [E]",
"\n|6 value     AZURE| 10^6 |1000000             |      |           |     tap [A]",
"\n|7 value    VIOLET| 10^7 |____________________|      |           |     tap [V] ",
"\n|8 value      GRAY| 10^8 |0.1<--->GOLD  tap[G]<------>     5%    |     tap [G]",
"\n|9 value     WHITE| 10^9 |0.01<->SILVER tap[S]<------>    10%    |     tap [W]",
"\n|    NO COLOUR    |      |        NONE  tap[N]------->    20%    ----> tap [N]"
"\n*-----------------*      *--------------------*      *-----------*",
};// ascii interface

// funcs
char users_input(int index);
int gold_or_gray(char band_colour, int index);
unsigned long long int_converter(char band_colour, int digit_order_number);
float float_converter(char band_colour);


int main ()// START of MAIN 
{
//___data_segment

 char first_colour, second_colour;// first two or three colours values
 char third_colour = '0';// if (number == 4) means the resistor is 4-band. So, we need two colours. 
 char multiplier_colour, tolerance_colour;// colours of multiplier and tolerance 
 int  number, index, digit_order_number, g0ld_or_gray = -1, ENTER, tolerance_int = 5;
 unsigned long hundreds, tens, ones, multiplier_int;
 unsigned long long result_int;
 float multiplier_float, result_float;

//___code_segment

  printf("\nHello, user!\nThis program is here to help you to find out the value (Ohms) of your resistor.\n\n"); 
  printf("All you need is to know the colours of your resistor.\n\nGive the desired number of bands (4 or 5 only)\n"); 
   scanf("%d",&number);

 while(number!= 4 && number!= 5)
 {// checks if there are other numbers than 4 and 5
  printf("4 or 5 only. Try again!\n");
   scanf("%d", &number);
    scanf("%d",&ENTER);  
 }

  printf("\nNow look at the table\nAND\nChoose colour which matches to the value.");
  printf("\n\n\n\t\t\t\t     <<Table of colours and their values>>\n\n");
  for(int i = 0; i < 12; i++)// prints ascii interface with colours values
  printf("%s", interface[i]); 
  printf("\n\nChoose the colours");

//___1rd_band_(colour)_segment
 index = 1, digit_order_number = 2;
 first_colour = users_input(index);
 g0ld_or_gray = gold_or_gray(first_colour, index);
 hundreds = int_converter(first_colour, digit_order_number);

//___2nd_band_(colour)_segment
 index = 2, digit_order_number = 1; 
 second_colour = users_input(index);
 g0ld_or_gray = gold_or_gray(second_colour, index);
 tens = int_converter(second_colour, digit_order_number);

//___3rd_band_(colour)_segment
 if(number == 5)
 {
  index = 3, digit_order_number = 0;
  third_colour = users_input(index);
  g0ld_or_gray = gold_or_gray(third_colour, index);
  ones = int_converter(third_colour, digit_order_number);
 }
 else
 ones = 0;

//___4th_band_(multiplier)_segment
 index = 4, digit_order_number = -1;
 multiplier_colour = users_input(index);
 g0ld_or_gray = gold_or_gray(multiplier_colour, index);
  if(g0ld_or_gray == 0 || g0ld_or_gray == -1)
   multiplier_int = int_converter(multiplier_colour, digit_order_number);
  else
   multiplier_float = float_converter(multiplier_colour);

//___5th_band_(tolerance)_segment
 do
 {
  printf("\n\nThe TOLERANCE has the colour of\n(only [C]OFFEE, [R]ED, [G]OLD, [S]ILVER & [N]ONE): ");
    scanf("%d", &ENTER);
   scanf("%c",&tolerance_colour);
   tolerance_colour = toupper(tolerance_colour);
   switch(tolerance_colour)
   { 
    case 'C':
     tolerance_int = tolerance_int/tolerance_int;
     break;
    case 'R':
     tolerance_int = 2;
     break;
    case 'G':
     tolerance_int *= 1;
     break;
    case 'S':
     tolerance_int *= 2;
     break;
    case 'N':
     tolerance_int *= 4;
     break;
   
   }
 }while(tolerance_colour!='C' && tolerance_colour!='R' && tolerance_colour!='G' && tolerance_colour!='S' && tolerance_colour!='N');

//___total_value_segment
// if the result is int type
if(g0ld_or_gray == 0 || g0ld_or_gray == -1)
 {
 result_int = (hundreds + tens + ones)*multiplier_int;

  printf("\nThe value of your resistor is: "); 
  if(result_int >= 1000000000)
  printf("%.llu Giga Ohms +- %d%%", (result_int/1000000000), tolerance_int);
  if(result_int >= 1000000 && result_int < 1000000000)
  printf("%.2llu Mega Ohms +- %d%%",(result_int/1000000), tolerance_int);
  if(result_int >= 1000 && result_int < 1000000)
  printf("%.2llu kilo Ohms +- %d%%",(result_int/1000), tolerance_int);
  if(result_int < 1000)
  printf("%.llu Ohms +- %d%%", result_int, tolerance_int);
 }
// if the result is float type
 if(g0ld_or_gray == 1)
  {
 result_float = ((hundreds + tens + ones)*multiplier_float);

  printf("\nThe value of your resistor is: "); 
  printf("%.2f Ohms +- %d%%", result_float, tolerance_int);
  }
 
return 0;
}// END of MAIN


char users_input(int index)// START of func
{ 
 char band_colour;
 char ENTER;// input for user's ENTER (buffer overflow, thanks to scanf())
 
 if(index != 4)
 printf("\n\nThe %d band has the colour of \n(tap [COLOUR] ): ", index);
 else
 printf("\n\nThe MULTIPLIER band has the colour of \n(tap [COLOUR] ): ");
   scanf("%c",&ENTER);
  scanf("%c",&band_colour); 
 band_colour = toupper(band_colour); 
  
  if(index != 4)
  while(band_colour!='B' && band_colour!='C' && band_colour!='R' && band_colour!='O' && band_colour!='Y' &&  band_colour!='E' && band_colour!='A' && band_colour!='V' && band_colour!='G' && band_colour!='W')
  {// checks if the user's input is out of the range
   printf("Oops...! There is no such a colour! Please, try again: ");// if not, then it prints that message
     scanf("%c", &ENTER);
    scanf("%c",&band_colour);// asks for input again
   band_colour = toupper(band_colour);
  }

  else
  while(band_colour!='B' && band_colour!='C' && band_colour!='R' && band_colour!='O' && band_colour!='Y' &&  band_colour!='E' && band_colour!='A' && band_colour!='V' && band_colour!='G' && band_colour!='W' && band_colour!='S' && band_colour!='N')
  {
   printf("Oops...! There is no such a colour! Please, try again: ");
     scanf("%c", &ENTER);
    scanf("%c",&band_colour);
   band_colour = toupper(band_colour);
  }
 printf("\nOK!");  
return band_colour;
}// END of func


int gold_or_gray(char band_colour, int index)// START of func
{// there's two colours (gold and gray) which have the same symbol [G]
 // need somehow to solve this conflict 
 int boolean = -1;  
  if(band_colour == 'G' && index == 4)
  {
    do
    {
     printf("[G] is for both [G]old and [G]gray\n");
     printf("What is your choice?\nTap 1 is [G]old or 0 if [G]ray: ");
      scanf("%d", &boolean);
    }while(boolean != 0 && boolean != 1);
  }
  if(band_colour == 'S')
   boolean = 1;
return boolean;
}// END of func



 unsigned long long int_converter(char band_colour, int digit_order_number)// START of func
{// array of letters which represent colours
  char colours [NUMBER_OF_COLOURS] = {'B','C','R','O','Y','E','A','V','G','W'};

//___first_two_or_three_colours_segment
  // integer version of character (char band_colour) == (int band_value), for exp.: 'B' == 0, atoi() equivalent
  unsigned long long band_value;
  // converts first three colours to int type
  for (int i = 0; i < NUMBER_OF_COLOURS; i++)
  if(band_colour == colours[i])
   band_value = i;   
  // is it hundreds? tens? ones?
  for(int i = 1; i <= 3; i++)
   if(digit_order_number == i)
    band_value = band_value*(pow(10,i));// pow() -> power of 10 in i
  // if there's no a 3rd colour (4-band resistor)
  if (band_colour == '0')
   band_value = 0;

//___multiplier_segment_for_rainbow_colours
  if(digit_order_number == -1)// if [G] is for Gray
  {
   for(int i = 0; i < NUMBER_OF_COLOURS; i++)
    if(band_colour == colours[i])
     band_value = pow(10,i);
   }  

return band_value;  
}// END of func


float float_converter(char band_colour)// START of func
{//___multiplier_segment_for_Gold_&_Silver_colours
 float band_value;
 char tolerance [NUMBER_OF_TOLERANCE] = {'G','S'}; 
   for(int i = 0; i < NUMBER_OF_TOLERANCE - 1; i++)
    if(band_colour == tolerance[i])
     band_value = pow(10,-i-1);// for 0,001 or 0,01 values 

return band_value;
}// END of func
