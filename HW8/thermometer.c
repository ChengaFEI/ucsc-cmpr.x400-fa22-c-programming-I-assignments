// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 8: Modular Programming Basics I
// Part     1: themometer.c
// Created by Cheng Fei in 12/18/2022

#include <stdlib.h>
#include <stdio.h>
/*--------------------------------------------------------------------------*/

int   getTemperatures   (int *);
int   printTemperatures (int *, int);
int   getMax            (int *, int);
int   getMin            (int *, int);
float getAverage        (int *, int);
int   printStatistics   (int *, int);
/*--------------------------------------------------------------------------*/

int main(void) 
{
  // Prompt the user to enter weekly temperatures.
  int weeklyTemp[7];
  getTemperatures(weeklyTemp);
  // Display weekly temperatures.
  printTemperatures(weeklyTemp, 7);
  printf("\n");
  // Display the minimum, maximum, and average of weekly temperatures.
  printStatistics(weeklyTemp, 7);
  printf("\n");
  return EXIT_SUCCESS;
}
/*--------------------------------------------------------------------------*/

// Prompt the user to enter temperatures for seven days in a week.
// @Params:  weeklyTemp -- pointer to int (int array) variable to store the input temperatures.
// @Returns: a binary flag.
//           0 indicates success.
//           1 indicates failure.
int getTemperatures(int *weeklyTemp)
{
  printf("Please enter temperatures for seven days in a week:\n");
  for (int i = 0; i < 7; i++) scanf("%d", &weeklyTemp[i]);
  return 0;
}
/*--------------------------------------------------------------------------*/

// Display the weekly temperatures.
// @Params:  weeklyTemp -- seven temperatures in a week.
// @Params:  size       -- the actual number of integers in the array.
// @Returns: a binary flag.
//           0 indicates success.
//           1 indicates failure.
int printTemperatures(int *weeklyTemp, int size) 
{
  for (int i = 0; i < size; i++) printf("%d ", weeklyTemp[i]);
  return 0;
}
/*--------------------------------------------------------------------------*/

// Find the maximum temperature in weekly temperatures.
// @Params:  weeklyTemp -- seven temperatures in a week.
// @Params:  size       -- the actual number of integers in the array.
// @Returns: the maximum value of temperature.
int getMax(int *weeklyTemp, int size) 
{
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (i == 0) max = weeklyTemp[i];
    else max = (max > weeklyTemp[i]) ? max : weeklyTemp[i];
  }
  return max;
}
/*--------------------------------------------------------------------------*/

// Find the minimum temperature in weekly temperatures.
// @Params:  weeklyTemp -- seven temperatures in a week.
// @Params:  size       -- the actual number of integers in the array.
// @Returns: the minimum value of temperature.
int getMin(int *weeklyTemp, int size) 
{
  int min = 0;
  for (int i = 0; i < size; i++) {
    if (i == 0) min = weeklyTemp[i];
    else min = (min < weeklyTemp[i]) ? min : weeklyTemp[i];
  }
  return min;
}
/*--------------------------------------------------------------------------*/

// Find the average temperature in weekly temperatures.
// @Params:  weeklyTemp -- seven temperatures in a week.
// @Params:  size       -- the actual number of integers in the array.
// @Returns: the average value of temperature.
float getAverage(int *weeklyTemp, int size) 
{
  float sum = 0;
  for (int i = 0; i < size; i++) sum += weeklyTemp[i];
  return sum / size;
}
/*--------------------------------------------------------------------------*/

// Display the minimum, the maximum, and the average of weekly temperatures.
// @Params:  weeklyTemp -- seven temperatures in a week.
// @Params:  size       -- the actual number of integers in the array.
// @Returns: a binary flag.
//           0 indicates success.
//           1 indicates failure.
int printStatistics(int *weeklyTemp, int size)
{
  printf("The minimum temperature in the week is %d.\n", 
    getMin(weeklyTemp, size));
  printf("The maximum temperature in the week is %d.\n", 
    getMax(weeklyTemp, size));
  printf("The average temperature in the week is %5.2f.\n", 
    getAverage(weeklyTemp, size));
  return 0;
}
/*--------------------------------------------------------------------------*/