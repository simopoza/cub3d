// C program to set precision in floating point numbers
#include<stdio.h>
#include<math.h>
int main()
{
float num = 0.000000301991598195684455997864;

// 4 digits after the decimal point
num = floor(1000000*num)/1000000;

printf("%f", num);
return 0;
}
