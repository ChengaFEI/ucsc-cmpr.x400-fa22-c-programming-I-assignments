// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 8: Modular Programming Basics I
// Part     2: diybox.c
// Created by Cheng Fei in 12/18/2022

#include <stdlib.h>
#include <stdio.h>
/*--------------------------------------------------------------------------*/

int drawHorizontalLine(char, int);
int drawVerticalLine  (char, int, int);
int drawBox           (void);
/*--------------------------------------------------------------------------*/

int main(void) 
{
  char answer = 'y';
  printf("\nUsing for-loop and user values, continuously:\n");
  while (answer == 'y') {
    drawBox();
    printf("Continue? Type 'y' for yes: ");
    scanf("%c", &answer);
  }

  return EXIT_SUCCESS;
}
/*--------------------------------------------------------------------------*/

// Draw the horizontal line of the diy box.
// @Params:  hori  -- character for the horizontal line.
// @Params:  width -- the width of the box.
// @Returns: a binary flag.
//           0 indicates success.
//           1 indicates failure.
int drawHorizontalLine(char hori, int width)
{
  for (int i = 0; i < width; i++) printf("%c", hori);
  printf("\n");
  return 0;
}
/*--------------------------------------------------------------------------*/

// Draw vertical lines of the diy box.
// @Params:  verti  -- character for the vertical line.
// @Params:  width  -- the width of the box.
// @Params:  height -- the height of the box.
// @Returns: a binary flag.
//           0 indicates success.
//           1 indicates failure.
int drawVerticalLine(char verti, int width, int height)
{
  for (int i = 0; i < height - 2; i++) {
    printf("%c", verti);
    for (int j = 0; j < width - 2; j++) printf(" ");
    printf("%c\n", verti);
  }
  return 0;
}
/*--------------------------------------------------------------------------*/

// Draw a box with both horizontal lines and vertical lines.
// @Returns: a binary flag.
//           0 indicates success.
//           1 indicates failure.
int drawBox(void)
{
  char hori, verti;
  int width, height;

  printf("\nPlease enter height of a box: ");
  scanf("%d", &height);
  printf("\nPlease enter width of a box: ");
  scanf("%d", &width);
  //you first need to flush the buffer, which still has
  //'\n' character due to pressing enter
  while (getchar() != '\n');
  printf("\nPlease enter the vertical charcters to draw box: ");
  scanf("%c", &verti);
  //don't forget to remove the newline character after
  //reading just a charcter in above code
  while (getchar() != '\n');
  printf("\nPlease enter the horizontal charcters to draw box: ");
  scanf("%c", &hori);
  printf("\n");

  drawHorizontalLine(hori, width);
  drawVerticalLine(verti, width, height);
  drawHorizontalLine(hori, width);

  //clean up the newline after last character read
  while (getchar() != '\n');

  return 0;
}