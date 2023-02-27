// UCSC CMPR.X400.(831)
// C Programming I
//
// Midterm Programming Assignment
// calculator
// Function: A console program (character based) to do simple calculation (addition, subtraction, multiplication and division) of two numbers.
//
// Created by Cheng Fei in 12/18/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
/*---------------------------------------------------------------------------*/

// Step functions:
// Functions in this group are in charge of the sub-tasks of the main function.
int printMenu(void);
int printResult(int, double *, double *);

// Check functions:
// Functions in this group are in charge of the input checking.
int isValidChoice(char []);
double isValidDouble(char [], int *);
/*---------------------------------------------------------------------------*/

int main(void) 
{
  while (1) {
    // Step 1: print the main menu.
    printMenu();
    printf("\n");
    
    // Step 2: prompt the user to select an operator.
    char choice[MAX_INPUT_SIZE];
    int choiceNumber;
    printf("What would you like to do? ");
    while (1) {
      fflush(stdin);
      scanf("%s", choice);
      if ( (choiceNumber = isValidChoice(choice)) ) break;
      printf("This is not a valid choice, please re-enter: ");
    }
    printf("\n");
    
    // Step 3: prompt the user to select two decimal numbers.
    if (choiceNumber == 5) {
      printf("Thank you for using Cheng Fei's Handy Calculator\n");
      return EXIT_SUCCESS;
    }
    printf("Please enter two numbers to ");
    switch (choiceNumber) {
      case 1: printf("add, "     ); break;
      case 2: printf("subtract, "); break;
      case 3: printf("multiply, "); break;
      case 4: printf("divide, "  ); break;
    }
    printf("separated by a space: ");
    char aStr[MAX_INPUT_SIZE], bStr[MAX_INPUT_SIZE];
    double aDouble, bDouble;
    int aError = 1, bError = 1;
    if (choiceNumber == 4) bError = -1;
    while (1) {
      fflush(stdin);
      scanf("%s %s", aStr, bStr);
      aDouble = isValidDouble(aStr, &aError);
      bDouble = isValidDouble(bStr, &bError); 
      // Check whether a and b are valid double numbers.
      if (aError == 1 && bError == 1) break; // Both numbers are valid.
      if (aError == 0 || bError == 0)
        printf("Error reading your numbers, please re-enter both numbers: ");
      if (bError == -1) 
        printf("You can’t divide by zero, please re-enter both numbers: ");
    }
    printf("\n");

    // Step 4: compute and display the result.
    printResult(choiceNumber, &aDouble, &bDouble);
    printf("\n");

    // Step X: reload the loop.
    printf("Press enter key to continue ....");
    char cmd;
    fflush(stdin);
    scanf("%c", &cmd);
    printf("\n");
  }
  
  return EXIT_SUCCESS;
}
/*---------------------------------------------------------------------------*/

// Display the main menu.
int printMenu(void)
{
  printf("Welcome to Cheng Fei's Handy Calculator\n\n");
  printf("\t1. Addition\n");
  printf("\t2. Subtraction\n");
  printf("\t3. Multiplication\n");
  printf("\t4. Division\n");
  printf("\t5. Exit\n");
  return 0;
}
/*---------------------------------------------------------------------------*/

// Compute and display the result by the instruction of the choiceNumber.
// @Params:   choiceNumber -- option code, ranging from 1 to 4.
// @Params:   aDouble      -- the first double number to compute.
// @Params:   bDouble      -- the second double number to compute.
// @Returns:  a binary flag
//            1 indicates success.
//            0 indicates failure.
// @Requires: choiceNumber -- taken from 1, 2, 3, 4
// @Requires: bDouble      -- when choiceNumber==4("Division"), bDouble!=0.
int printResult(int choiceNumber, double *aDouble, double *bDouble)
{
  switch (choiceNumber) {
    case 1: 
      printf("Result of adding %.2lf to %.2lf is %.2lf\n", 
        *aDouble, *bDouble, *aDouble + *bDouble);
      break;
    case 2:
      printf("Result of subtracting %.2lf by %.2lf is %.2lf\n",
        *aDouble, *bDouble, *aDouble - *bDouble);
      break;
    case 3:
      printf("Result of multiplying %.2lf by %.2lf is %.2lf\n",
        *aDouble, *bDouble, *aDouble * *bDouble);
      break;
    case 4:
      printf("Result of dividing %.2lf by %.2lf is %.2lf\n",
        *aDouble, *bDouble, *aDouble / *bDouble);
      break;
  }
  return 0;
}
/*---------------------------------------------------------------------------*/

// Check whether the input string is a valid number (from 1 to 5).
// @Params:  str -- a c-style string to check.
// @Returns: a flag
//           non-zero indicates a valid input and the value is the input number.
//           0 indicates an invalid input.
int isValidChoice(char str[]) 
{
  int length = strlen(str);
  if (length == 0) return 0;

  // Check all digits are numeric.
  for (int i = 0; i < length; i++) {
    if (!isdigit(str[i])) return 0;
  }
  // Check the number is in the range from 1 to 5.
  int number;
  sscanf(str, "%d", &number);
  if (number < 1 || number > 5) return 0;
  return number;
}
/*---------------------------------------------------------------------------*/

// Check whether the input string is a valid double.
// @Params:  str       -- a  c-style string to check.
//           errorFlag As an input:
//                     -- 1  indicates not to check divide-by-zero error.
//                     -- -1 indicates to check divide-by-zero error.
//                     As an output:
//                     -- 1  indicates valid.
//                     -- 0  indicates invalid (non-numeric).
//                     -- -1 indicates invalid (divide by zero).
// @Returns: a double number
//           non-zero indicates a valid input and the value is the input number.
//           0 indicates an invalid input.
double isValidDouble(char str[], int *errorFlag)
{
  int length = strlen(str);
  if (length == 0) {
    *errorFlag = 0;
    return (double) 0;
  }

  // Check all digits are numeric.
  char curr;
  int dotCount = 0; // Total number of the dot character ('.').
  for (int i = 0; i < length; i++) {
    curr = str[i];
    if (!isdigit(curr)) {
      // The first character being '-' (minus sign) is acceptable.
      if (curr == '-' && i == 0 && length > 1) continue;
      // Any character being '.' is acceptable.
      if (curr == '.' && ++dotCount == 1) continue;
      // All other non-numeric characters are unacceptable.
      *errorFlag = 0;
      return (double) 0;
    }
  }

  // Read the string as the double number.
  double number;
  fflush(stdin);
  sscanf(str, "%lf", &number);

  // Check whether the number is 0.
  if (-1 == *errorFlag && number == 0) {
    *errorFlag = -1;
    return (double) 0;
  }

  *errorFlag = 1;
  return number;
}