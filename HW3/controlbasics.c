// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 3: C Control Statement Basics I
// Created by Cheng Fei in 12/18/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*----------------------------------------------------------------------*/

// printYourAge() displays whether you are a kid, a teenager, or an adult
// based on your age.
int printYourAge(void);
// computeNumber() takes three inputs from the user -- 
// the first and the last are operands, the second is an operator --
// and compute the result.
int computeNumber(void);
// computeMaxInThree() displays the maximum number in three inputs.
int computeMaxInThree(void);
/*----------------------------------------------------------------------*/

int main(void) 
{
  printYourAge();
  computeNumber();
  computeMaxInThree();
  return EXIT_SUCCESS;
}
/*----------------------------------------------------------------------*/

int printYourAge(void) 
{
  int yourAge;
  printf("How old are you? ");
  scanf("%d", &yourAge);

  if      (yourAge < 13) printf("You are a kid.     \n");
  else if (yourAge < 19) printf("You are a teenager.\n");
  else                   printf("You are an adult.  \n");

  return 0;
}
/*----------------------------------------------------------------------*/

int computeNumber(void)
{
  // contN is a boolean flag of whether the while loop continues.
  // contStr stores yes/no. 
  // (yes -- continue to run the program; no -- stop running the program)
  int contN = 1; char contStr[5];
  double firstN, secondN;
  char op;
  while (contN) {
    printf("Type a number, operator, number -- separated by a space: ");
    scanf("%lf %c %lf", &firstN, &op, &secondN);
    switch (op) {
      case '+': 
        printf("%lf + %lf = %lf", firstN, secondN, firstN+secondN);
        break;
      case '-':
        printf("%lf - %lf = %lf", firstN, secondN, firstN-secondN);
        break;
      case '*':
        printf("%lf * %lf = %lf", firstN, secondN, firstN*secondN);
        break;
      case '/':
        printf("%lf / %lf = %lf", firstN, secondN, firstN/secondN);
        break;
      case '%':
        printf("%lf %% %lf = %d", firstN, secondN, (int)firstN%(int)secondN);
        break;
      default: printf("Unknown operator.");
    }
    printf("\n\n");
    printf("Do you want to continue? (Please enter 'yes' or 'no')");
    scanf("%5s", contStr);
    if (!strcmp(contStr, "yes")) contN = 1;
    else contN = 0;
  }

  return 0;
}
/*----------------------------------------------------------------------*/

int computeMaxInThree(void) 
{
  int a, b, c;
  int dummy;
  char cont = 'y';
  while (cont == 'y') {
    printf("Enter three integers to find the max among them -- seperated by space:\n");
    scanf("%d %d %d", &a, &b, &c);
    dummy = (a > b) ? a : b;
    printf("The max is %d\n\n", (dummy > c) ? dummy : c);
    printf("Continue? Type 'y' for yes: ");
    scanf("%1s", &cont);
  }
  printf("Thank you for using my max program.\n");
  return 0;
}