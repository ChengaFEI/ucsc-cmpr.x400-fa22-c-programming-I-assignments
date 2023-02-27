// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 5: C Pointer/Array Basics I
// Created by Cheng Fei in 12/18/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
/*---------------------------------------------------------------------------*/

// selectAnOption() prompts the user to select from 1 to 5 and alerts the error until the correct number is entered.
int selectAnOption(void);
// displayDoubles() prompts the user to enter two doubles and alerts the error until correct doubles are entered.
int displayDoubles(void);
// isDouble() takes a c-style string and checks whether it represents a double.
int isDouble(char []);
// printTempInfo() displays the internal temperature arrays' max, min, sum, and average.
int printTempInfo(void);
/*---------------------------------------------------------------------------*/

int main(void) {
  selectAnOption();
  displayDoubles();
  printTempInfo();

  printf("Thank you for using my homework#5 solution.\n\n");
  return EXIT_SUCCESS;
}
/*---------------------------------------------------------------------------*/

int selectAnOption(void) 
{
  printf("Welcome to sorting program.\n\n");
  printf("\t1. Title\n");
  printf("\t2. Rank \n");
  printf("\t3. Date \n");
  printf("\t4. Stars\n");
  printf("\t5. Likes\n");
  char choice[MAX_INPUT_SIZE];
  int number, isNumeric;
  while (1) {
    isNumeric = 1;
    printf("\nEnter your choice between 1 and 5 only: ");
    fflush(stdin);
    scanf("%s", choice);
    printf("\n");
    // Check whether choice is a number.
    for (int i = 0; i < strlen(choice); i++) {
      if (!isdigit(choice[i])) {
        printf("You have entered an invalid input. Try again.\n");
        isNumeric = 0;
        break;
      }
    }
    // Check choice is in the range of 1-5.
    if (isNumeric) {
      sscanf(choice, "%d", &number);
      if (number > 5 || number < 1) {
        printf("You have not entered a number between 1 and 5. Try again.\n");
      } else {
        printf("You entered valid choice %d\n", number);
        printf("Thank you for giving your choice.\n\n");
        break;
      }
    }
  }
  return 0;
}
/*---------------------------------------------------------------------------*/

int displayDoubles(void)
{
  char aStr[MAX_INPUT_SIZE], bStr[MAX_INPUT_SIZE];
  double aDou, bDou;
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
      printf("You entered %.10g and %.10g successfully\n\n", aDou, bDou);
      break;
    }
  } while (1);

  return 0;
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

int printTempInfo(void)
{
  int weeklyTemp[] = { 69, 70, 71, 68, 66, 71, 70 }; 
  int i, max, min, curr, number;
  float total = 0, average;
  max = min = weeklyTemp[0];
  number = sizeof(weeklyTemp)/sizeof(int);
  for (int i = 0; i < number; i++) {
    curr = weeklyTemp[i];
    printf("The temperature of day %d was %d\n", i+1, curr);
    max = (max > curr) ? max : curr;
    min = (min < curr) ? min : curr;
    total += curr; 
  }
  average = total / number;
  printf("\nThe minimum temperature is: %d\n", min);
  printf(  "The maximum temperature is: %d\n", max);
  printf(  "The average temperature for the week is: %f\n\n", average);

  return 0;
}