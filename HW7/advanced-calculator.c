// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 7: Advanced Calculator
// Function: Perform '+', '-', '*', '/' with two numbers (integers/decimals).
// 
// Created by Cheng Fei in 12/18/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_NUMBER 100
#define MAX_INPUT_SIZE   100
/*---------------------------------------------------------------------------*/

// Step functions:
// Functions in this group are in charge of the sub-tasks of the main function.
int getValidDouble(char [], double *, int *);
int getValidOperator(char [], char *);
int printCalResult(const double *, const double *, const char *);
/*---------------------------------------------------------------------------*/

int main(void) 
{
  // Step 1: Welcome and input prompt.
  printf("Welcome to Cheng Fei's Advanced Calculator, please enter a valid equation followed by enter:\n");

  // Step 2: Read and verify the input string.
  // Don't check operand1's DBZ error, check operand2's DBZ error.
  int aCheck = 1, bCheck = -1, aStatus, bStatus, operStatus;
  double aDouble, bDouble;
  char oper;
  // Loop until get valid inputs.
  while (1) {
    // Clear unused characters.
    fflush(stdin); 
    char input[MAX_INPUT_NUMBER][MAX_INPUT_SIZE];
    char curr;
    int numberi = 0, chari = 0, charCount = 0, strCount = 0;
    // Read the input.
    while ( (curr = fgetc(stdin)) != '\n' ) {
      if (curr != ' ') input[numberi][chari++] = curr;
      else if (chari != 0) {
        input[numberi++][chari] = '\0'; 
        chari = 0;
        strCount++;
      }
      charCount++;
    }
    input[numberi][chari] = '\0';
    strCount++;
    // Exit the program if enter no commands.
    if (charCount == 0) break;
    // Only 3 parts are needed (2 operands + 1 operator).
    if (strCount != 3) printf("Not a valid equation.\n");
    else {
      aStatus    = getValidDouble  (input[0], &aDouble, &aCheck);
      bStatus    = getValidDouble  (input[2], &bDouble, &bCheck);
      operStatus = getValidOperator(input[1], &oper);
      if (!aStatus && !operStatus && !bStatus) {
        // If all inputs are valid.
        printCalResult(&aDouble, &bDouble, &oper);
      } else if (1 == aStatus || 1 == operStatus || 1 == bStatus) {
        // If inputs' formats are invalid.
        printf("Not a valid equation.\n");
      } else {
        // If the operand2 is 0.
        printf("Can not divide by zero.\n");
      }
    }
    printf("Please enter a valid equation and press enter or press enter to exit.\n");
  }

  // Step 3: Exit.
  printf("Thank you for using Cheng Fei’s Advance Calculator, good bye!\n");
  printf("\n");

  return EXIT_SUCCESS;
}
/*---------------------------------------------------------------------------*/

// Check whether the input string is a valid double/integer.
// @Params:  str       --  a c-style string to check.
//           number    --  a variable to store the correct number.
//           checkType --  1 indicates not to check divide-by-zero error.
//                     -- -1 indicates to check divide-by-zero error.
// @Returns: a tertiary flag
//           0 indicates valid.
//           1 indicates invalid (non-numeric).
//          -1 indicates invalid (divide by zero).
int getValidDouble(char str[], double *number, int *checkType)
{
  int length = strlen(str);
  if (length == 0) return 1;

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
      return 1;
    }
  }

  // Read the string as the double number.
  fflush(stdin);
  sscanf(str, "%lf", number);

  // Check whether the number is 0.
  if (-1 == *checkType && *number == 0) return -1;

  return 0;
}
/*---------------------------------------------------------------------------*/

// Check whether the input string is a valid operator ('+', '-', '*', '/').
// @Params:  str      -- a c-style string to check.
//           operator -- a variable to store the correct operator.
// @Returns: a binary flag
//           0 indicates a valid input.
//           1 indicates an invalid input.
int getValidOperator(char str[], char *operator) {
  int length = strlen(str);
  if (length != 1) return 1;
  char ch = str[0];
  if (ch!='+' && ch!='-' && ch!='*' && ch!= '/') return 1;
  *operator = ch;
  return 0;
}
/*---------------------------------------------------------------------------*/

// Compute and display the calculation result.
// @Params:  number1  -- the first double number.
//           number2  -- the second double number.
//           operator -- the operator (one of '+', '-', '*', '/').
// @Returns: a binary flag
//           0 indicates success.
//           1 indicates failure.
int printCalResult(const double *number1, const double *number2, const char *operator)
{
  switch (*operator) {
    case '+': 
      printf("%.2lf + %.2lf = %.2lf\n", *number1, *number2, *number1 + *number2);
      break;
    case '-': 
      printf("%.2lf - %.2lf = %.2lf\n", *number1, *number2, *number1 - *number2);
      break;
    case '*': 
      printf("%.2lf * %.2lf = %.2lf\n", *number1, *number2, *number1 * *number2);
      break;
    case '/': 
      printf("%.2lf / %.2lf = %.2lf\n", *number1, *number2, *number1 / *number2);
      break;
  }
  return 0;
}
