// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 4: C Function Basics I
// Created by Cheng Fei in 12/18/2022

#include <stdlib.h>
#include <stdio.h>
/*---------------------------------------------------------------------------*/

void drawWithWhileLoop(void);
void drawWithDoWhileLoop(void);
void drawWithForLoop(void);
void drawWithUserDefinedParams(void);
void drawWithUserDefinedParamsRepeatly(void);
/*---------------------------------------------------------------------------*/

int main(void)
{
  drawWithWhileLoop();
  drawWithDoWhileLoop();
  drawWithForLoop();
  drawWithUserDefinedParams();
  drawWithUserDefinedParamsRepeatly();
  return EXIT_SUCCESS;
}
/*---------------------------------------------------------------------------*/

void drawWithWhileLoop(void)
{
  int i = 0, j = 0;
  printf("Using while loop:   \n");
  while (j++ < 20) printf("-");
  printf("\n");
  while (i++ < 8) {
    int k = 0;
    printf("|");
    while (k++ < 18) printf(" ");
    printf("|\n");
  }
  j = 0;
  while (j++ < 20) printf("-");
  printf("\n");
  }
/*---------------------------------------------------------------------------*/

void drawWithDoWhileLoop(void)
{
  int i = 0, j = 0;
  printf("Using do-while loop:   \n");
  while (j++ < 20) printf("-");
  printf("\n");
  do {
    int k = 0;
    printf("|");
    while (k++ < 18) printf(" ");
    printf("|\n");
  } while (++i < 8);
  j = 0;
  while (j++ < 20) printf("-");
  printf("\n");
}
/*---------------------------------------------------------------------------*/

void drawWithForLoop(void)
{
  int i = 0, j = 0;
  printf("Using for loop:   \n");
  printf("Using do-while loop:   \n");
  while (j++ < 20) printf("-");
  printf("\n");
  for (i = 0; i < 8; i++) {
    int k = 0;
    printf("|");
    while (k++ < 18) printf(" ");
    printf("|\n");
  }
  j = 0;
  while (j++ < 20) printf("-");
  printf("\n");
}
/*---------------------------------------------------------------------------*/

void drawWithUserDefinedParams(void)
{
  // Ask the user to enter variables.
  int width, height;
  char hori, verti;
  printf("Please enter the width and height of the big box: (integer) ");
  scanf("%d %d", &width, &height);
  printf("Please enter the character for the horizontal and vertical lines: (no whitespace)");
  fflush(stdin);
  scanf("%c %c", &hori, &verti);
  // Draw the big box.
  int i = 0, j = 0;
  printf("Using for loop:   \n");
  while (j++ < width) printf("%1c", hori);
  printf("\n");
  for (i = 0; i < height; i++) {
    int k = 0;
    printf("%1c", verti);
    while (k++ < width - 2) printf(" ");
    printf("%1c\n", verti);
  }
  j = 0;
  while (j++ < width) printf("%1c", hori);
  printf("\n");
}
/*---------------------------------------------------------------------------*/

void drawWithUserDefinedParamsRepeatly(void)
{
  char cont = 'y';
  while (cont == 'y') {
    // Ask the user to enter variables.
    int width, height;
    char hori, verti;
    printf("Please enter the width and height of the big box: (integer) ");
    scanf("%d %d", &width, &height);
    printf("Please enter the character for the horizontal and vertical lines: (no whitespace)");
    fflush(stdin);
    scanf("%c %c", &hori, &verti);
    // Draw the big box.
    int i = 0, j = 0;
    printf("Using for loop:   \n");
    while (j++ < width) printf("%1c", hori);
    printf("\n");
    for (i = 0; i < height; i++) {
      int k = 0;
      printf("%1c", verti);
      while (k++ < width - 2) printf(" ");
      printf("%1c\n", verti);
    }
    j = 0;
    while (j++ < width) printf("%1c", hori);
    printf("\n");
    // Ask whether to continue the program.
    printf("Do you want to print more boxes? ('y'--yes, 'n'--no) ");
    fflush(stdin);
    scanf("%c", &cont);
  }
}