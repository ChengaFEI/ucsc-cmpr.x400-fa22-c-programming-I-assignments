//C language does not allow you to have more than one main in one application
//So, when you are writing your midterm, you may run into situation that you have to
//create multiple project for each problem in the homework.
//That could get out of hand

//So, here is a solution which you can use.  This solution uses functions.  Though I use functions
//later, but, for now, just copy the methodlogies which should help you.  You will learn
//about writing functions in details in coming days

//Say, you are writing homework #1
//Name the file as homework_1.c

//now write the code like this
#include <stdio.h>

//this is problem_1.  Here you write the complete code for problem#1
void problem_1(){
    //your code goes here
    printf("Hello World and Student of C\n");
}

//this is problem_2.  Here you write the complete code for problem#1
void problem_2(){
    //your code goes here
    printf("More code for problem# 3\n");
}

//this is problem_3.  Here you write the complete code for problem#1
void problem_3(){
    //your code goes here
    printf("More code for problem# 3\n");
}

int main (void){
    
    problem_1();   //call the function problem_1, where you will write the code for problem#1
    problem_2();   //call the function problem_2, where you will write the code for problem#1
    problem_3();   //call the function problem_3, where you will write the code for problem#1
    
    return 0;
}