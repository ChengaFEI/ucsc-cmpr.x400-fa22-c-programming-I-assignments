// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 6: String/Multi-array
// Created by Cheng Fei in 12/18/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
/*---------------------------------------------------------------------------*/

double aDou, bDou;
/*---------------------------------------------------------------------------*/

// getMenuChoice() prompts the user to select from 1 to 5 and alerts the error until the correct number is entered.
int getMenuChoice(char []);
// displayDoubles() prompts the user to enter two doubles and alerts the error until correct doubles are entered.
double *getTwoFloats(void);
// isDouble() takes a c-style string and checks whether it represents a double.
int isDouble(char []);
/*---------------------------------------------------------------------------*/

int main(void) {
  // Get a menu choice.
  printf("Welcome to sorting program.\n\n");
  printf("\t1. Title\n");
  printf("\t2. Rank \n");
  printf("\t3. Date \n");
  printf("\t4. Stars\n");
  printf("\t5. Likes\n");
  char choice[MAX_INPUT_SIZE];
  int number;
  do {
    printf("\nEnter your choice between 1 and 5 only: ");
    fflush(stdin);
    scanf("%s", choice);
    printf("\n");
    number = getMenuChoice(choice);
  } while (number == 0);

  // Get two double numbers.
  double *dous = getTwoFloats();
  printf("You entered %.10g and %.10g successfully\n\n", dous[0], dous[1]);

  return EXIT_SUCCESS;
}
/*---------------------------------------------------------------------------*/

// Check whether the input string is a valid number (from 1 to 5).
// @Params:  str -- a c-style string to check.
// @Returns: a flag
//           non-zero indicates a valid input and the value is the input number.
//           0 indicates an invalid input.
int getMenuChoice(char str[]) 
{
  int length = strlen(str);
  if (length == 0) return 0;

  // Check all digits are numeric.
  for (int i = 0; i < length; i++) {
    if (!isdigit(str[i])) {
      printf("You have entered an invalid input. Try again.\n");
      return 0;
    }
  }
  // Check the number is in the range from 1 to 5.
  int number;
  sscanf(str, "%d", &number);
  if (number < 1 || number > 5) {
    printf("You have not entered a number between 1 and 5. Try again.\n");
    return 0;
  }
  return number;
}
/*---------------------------------------------------------------------------*/

double *getTwoFloats(void)
{
  char aStr[MAX_INPUT_SIZE], bStr[MAX_INPUT_SIZE];
  printf("Please enter float numbers separated by space and press enter: ");
  fflush(stdin);
  scanf("%s %s", aStr, bStr);

  int isDou= 1;
  do {
    // Check whether aStr and bStr are doubles.
    if (!isDouble(aStr) || !isDouble(bStr)) {
      printf("Error reading your input. Please try again: ");
      fflush(stdin);
      scanf("%s %s", aStr, bStr);
    } else {
      sscanf(aStr, "%lf", &aDou);
      sscanf(bStr, "%lf", &bDou);
      double *dous = {&aDou, &bDou};
      return dous;
    }
  } while (1);

  return NULL;
}
/*---------------------------------------------------------------------------*/

int isDouble(char str[])
{
  int isDou = 1, length = strlen(str);
  int dotCount = 0;
  for (int i = 0; i < length; i++) {
    if (!isdigit(str[i])) {
      // The first character being '-' is acceptable.
      if (str[i] == '-' && i == 0 && length > 1) continue;
      // The character '.' in any digit is acceptable.
      else if (str[i] == '.' && ++dotCount == 1) continue;
      // All other characters are unacceptable.
      else {
        isDou = 0;
        break;
      }
    }
  }
  return isDou;
}
/*---------------------------------------------------------------------------*/