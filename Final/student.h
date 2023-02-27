// UCSC CMPR.X400.(831)
// C Programming I
//
// Final Programming Assignment
// student.h
// 
// Function: Definition of the student structure.
//
// Created by Cheng Fei in 12/25/2022

#define MAX_NAME_LENGTH 50
/*----------------------------------------------------------------------------*/

// Student structure with the name and all the scores in each test.
typedef struct student_t {
  char name[MAX_NAME_LENGTH]; // Current student's name.
  float q1;                   // Quiz1's score.
  float q2;                   // Quiz2's score.
  float q3;                   // Quiz3's score.
  float q4;                   // Quiz4's score.
  float mid1;                 // First midterm's score.
  float mid2;                 // Second midterm's score.
  float final;                // Final exam's score.
  char grade;                 // Letter grade.
  struct student_t *next;     // Next linked student.
} student;
/*----------------------------------------------------------------------------*/
