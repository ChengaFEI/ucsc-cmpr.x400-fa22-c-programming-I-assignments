// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 1: C Syntax Basics I
// Created by Cheng Fei in 10/05/2022

#include <stdio.h>

void problem_1();
void problem_2();
void problem_3();
void problem_4();

int main (void) {
    problem_1();
    printf("--------------------------------------\n");   
    problem_2();   
    printf("--------------------------------------\n");   
    problem_3(); 
    printf("--------------------------------------\n");
    problem_4();
    printf("--------------------------------------\n");
    return 0;
}

/*
    Solution of problem 1.1
*/
void problem_1() {
    printf("Welcome to the class of C Beginners\n");
}

/*
    Solution of problem 1.2
*/
void problem_2() {
    printf("Welcome\nto the class of C Beginners\n");
}

/*
    Solution of problem 1.3
*/
void problem_3() {
    printf("***       ***    ********    ***         ***            ***\n");
    printf("***       ***    ***         ***         ***         ***   ***\n");
    printf("***       ***    ***         ***         ***         ***   ***\n");
    printf("*************    ********    ***         ***         ***   ***\n");
    printf("***       ***    ***         ***         ***         ***   ***\n");
    printf("***       ***    ***         ***         ***         ***   ***\n");
    printf("***       ***    ********    ********    ********       ***\n");
}

/*
    Solution of problem 1.4
*/
void problem_4() {
    printf("|       |    --------    |           |         --------\n");
    printf("|       |    |           |           |         |      |\n");
    printf("|       |    |           |           |         |      |\n");
    printf("---------    --------    |           |         |      |\n");
    printf("|       |    |           |           |         |      |\n");
    printf("|       |    |           |           |         |      |\n");
    printf("|       |    --------    --------    --------  --------\n");}