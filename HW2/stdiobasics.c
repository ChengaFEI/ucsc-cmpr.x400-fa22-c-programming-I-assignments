// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 2: C Syntax Basics II
// Created by Cheng Fei in 12/17/2022

#include <stdio.h>
#include <stdlib.h>
/*----------------------------------*/

void computeCircleArea1(void);
void computeCircleArea2(void);
void printPersonInfo(void);
void selectAnOperator(void);
/*----------------------------------*/

int main(void) {
  computeCircleArea1();
  computeCircleArea2();
  printPersonInfo();
  selectAnOperator();
  return EXIT_SUCCESS;
}
/*----------------------------------*/

void computeCircleArea1(void) {
  int radius = 2;
  double area;
  const double pi = 3.142;
  area = pi * radius * radius; 
  printf("The area is: %5.2f\n", area);
}
/*----------------------------------*/

void computeCircleArea2(void) {
  int radius;
  double pi, area;  
  printf("\n");
  printf("Enter the radius: "); 
  scanf("%d", &radius);
  printf("Enter the pi: ");
  scanf("%lf", &pi);
  area= pi * radius * radius; 
  printf("The area is: %5.2f\n", area);
}
/*----------------------------------*/

void printPersonInfo(void) {
  char firstName[20];
  char lastName[20];
  char city[20];
  char zip[10];

  printf("\n"); 
  printf("5185 is fun course.\n\n");
  printf("First Name\tLast Name\tCity  \tZip  \n"); 
  printf("----------\t---------\t------\t-----\n"); 
  printf("Bill      \tClinton  \tHarlem\t10026\n");
  printf("\n");
  printf("How do you print double quotes?         \n"); 
  printf("Who said\"Test Scores Can Be Used ....\"\n"); 

  printf("Please enter your first name: ");
  scanf("%19s", firstName);
  printf("Please enter your last name: ");
  scanf("%19s", lastName);
  printf("Please enter your city: ");
  scanf("%19s", city);
  printf("Please enter your zip code: ");
  scanf("%9s", zip);
  printf("First Name\tLast Name\tCity  \tZip  \n"); 
  printf("----------\t---------\t------\t-----\n"); 
  printf("%s        \t%s       \t%s    \t%s   \n\n", 
          firstName,  lastName,  city,   zip     );
}
/*----------------------------------*/

void selectAnOperator(void) {
  printf("1. Addition      \n");
  printf("2. Subtraction   \n");
  printf("3. Multiplication\n");
  printf("4. Division      \n");
  printf("5. Exit          \n");

  int option;
  printf("\nWhat would you like to do?");
  scanf("%d", &option);
  printf("You selected ");
  switch (option) {
    case 1: printf("Addition      \n"); break;
    case 2: printf("Subtraction   \n"); break;
    case 3: printf("Multiplication\n"); break;
    case 4: printf("Division      \n"); break;
  }
  printf("\nThank you for using my program.\n");
}