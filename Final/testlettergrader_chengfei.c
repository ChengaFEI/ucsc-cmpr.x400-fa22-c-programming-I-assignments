// UCSC CMPR.X400.(831)
// C Programming I
//
// Final Programming Assignment
// letter-grader
// 
// Function: Take in a text file with students' names and their scores, display statistics of each quiz/exam, calculate students' letter grades, and store students' names and letter grades in a sorted order in the output file. 
//
// Created by Cheng Fei in 12/25/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "quicksort.h" // Quick-sort algorithm on the singly linked list.

#define MAX_LINE_LENGTH 200
/*----------------------------------------------------------------------------*/

// Step functions:
// Functions in this group are in charge of the sub-tasks of the main function.
int parseArguments(int argc, char **argv);
int readStudentsInfo(char *inputFileName, student *firstStu);
int displayStatistics(student *firstStu);
int writeStudentsGrades(char *outputFileName, student *firstStu);

// Helper functions:
// Functions in this group are in charge of the auxiliary tasks.
int calculateLetterGrade(student *stu);
int freeStudents(student *stu);
/*----------------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
  printf("\n");
  // Step 1: Parse the program arguments.
  if ( parseArguments(argc, argv) != 0 ) 
    return EXIT_FAILURE;
  printf("\n");

  // Step 2: Read data from the input file to the student list.
  char *inputFileName = argv[1];
  student *firstStu; // The first student object in the list.
  if ( (firstStu = (student *) malloc(sizeof(student))) == NULL ) {
    printf("Out of memory!\n");
    return EXIT_FAILURE;
  }
  if ( readStudentsInfo(inputFileName, firstStu) != 0 )
    return EXIT_FAILURE;

  // Step 3: Calculate statistics of each quiz/exam, including the average, minimum, and the maximum.
  if ( displayStatistics(firstStu) != 0 )
    return EXIT_FAILURE;
  printf("\n");

  // Step 4: Store students' names and letter grades in the output file.
  char *outputFileName = argv[2];
  if ( (writeStudentsGrades(outputFileName, firstStu)) != 0 )
    return EXIT_FAILURE;

  // Step X: Release dynamically allocated memories.
  freeStudents(firstStu);
  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// parseArguments() parses input arguments.
// @Params:  argc (function input)
//           -- the number of arguments.
// @Params:  argv (function input) 
//           -- input arguments in a c-style string format.
// @Returns: a binary flag
//           -- 0 indicates success.
//           -- 1 indicates failure.
int parseArguments(int argc, char **argv)
{
  // If number of arguments is not correct.
  if (argc != 3) {
    printf("Usage: student-list-parser inputFile.txt outputFile.txt\n");
    return 1;
  }
  // If 3 arguments are entered.
  else {
    printf("Input will be read from: %s\n", argv[1]);
    printf("Output will be written into: %s\n", argv[2]);
  }
  return 0; // Success.
}
/*-----------------------------------------------------------------------------*/

// readStudentsInfo() reads the name/scores of students into the student list.
// @Params:  inputFileName (function input)
//           -- the input file with students' data to read.
// @Params:  firstStudent (function output) 
//           -- a pointer to the first student in the list.
// @Returns: a binary flag
//           -- 0 indicates success.
//           -- 1 indicates failure.
int readStudentsInfo(char *inputFileName, student *stu)
{
  student *firstStu = stu;
  student *lastStu = stu;
  char line[MAX_LINE_LENGTH]; // Current line.
  char *word;                 // Current word.
  FILE *inFile;
  if ( (inFile = fopen(inputFileName, "r")) == NULL ) {
    perror("Error opening the input file.\n");
    return 1;
  }
  while ( fgets(line, sizeof(line), inFile) != NULL ) {
    word = strtok(line, ",");
    strcpy(stu->name, word);
    word = strtok(NULL, ",");
    stu->q1 = atoi(word);
    word = strtok(NULL, ",");
    stu->q2 = atoi(word);
    word = strtok(NULL, ",");
    stu->q3 = atoi(word);
    word = strtok(NULL, ",");
    stu->q4 = atoi(word);
    word = strtok(NULL, ",");
    stu->mid1 = atoi(word);
    word = strtok(NULL, ",");
    stu->mid2 = atoi(word);
    word = strtok(NULL, ",");
    stu->final = atoi(word);
    // Calculate student's letter grade.
    if ( calculateLetterGrade(stu) != 0 ) {
      freeStudents(firstStu);
      printf("Error loading students' scores.\n");
      return 1;
    }
    // Malloc a new student object.
    if ( (stu->next = (student *) malloc(sizeof(student))) == NULL ) {
      freeStudents(firstStu);
      printf("Out of memory.\n");
      return 1;
    }
    lastStu = stu;
    stu = stu->next;
  }
  lastStu->next = NULL;
  free(stu); // Free the memory occupied by the last student object in the list.
  fclose(inFile);
  return 0; // Success.
}
/*-----------------------------------------------------------------------------*/

// displayStatistics() calculates the average, minimum, maximum of each quiz/exam and displays the results on the console.
// @Params:  firstStu (function input) 
//           -- a pointer to the first student in the list.
// @Returns: a binary flag
//           -- 0 indicates success.
//           -- 1 indicates failure.
int displayStatistics(student *firstStu)
{
  if (firstStu == NULL) return 1;
  // The first element in each array is the sum,
  // The second element in each array is the minimum,
  // The third element in each array is the maximum.
  float Q1[3], Q2[3], Q3[3], Q4[3], Mid1[3], Mid2[3], Final[3];
  float q1, q2, q3, q4, mid1, mid2, final;
  int stuCount = 0;
  // Initialize statistics.
  Q1[0]    = Q1[1]    = Q1[2]    = firstStu->q1;
  Q2[0]    = Q2[1]    = Q2[2]    = firstStu->q2;
  Q3[0]    = Q3[1]    = Q3[2]    = firstStu->q3;
  Q4[0]    = Q4[1]    = Q4[2]    = firstStu->q4;
  Mid1[0]  = Mid1[1]  = Mid1[2]  = firstStu->mid1;
  Mid2[0]  = Mid2[1]  = Mid2[2]  = firstStu->mid2;
  Final[0] = Final[1] = Final[2] = firstStu->final;

  student *stu = firstStu->next;
  stuCount++;
  // Loop over all student objects in the list.
  while (stu != NULL) {
    stuCount++;
    q1 = stu->q1;
    Q1[0] += q1;
    Q1[1] = q1 < Q1[1] ? q1 : Q1[1];
    Q1[2] = q1 > Q1[2] ? q1 : Q1[2];
    q2 = stu->q2;
    Q2[0] += q2;
    Q2[1] = q2 < Q2[1] ? q2 : Q2[1];
    Q2[2] = q2 > Q2[2] ? q2 : Q2[2];
    q3 = stu->q3;
    Q3[0] += q3;
    Q3[1] = q3 < Q3[1] ? q3 : Q3[1];
    Q3[2] = q3 > Q3[2] ? q3 : Q3[2];
    q4 = stu->q4;
    Q4[0] += q4;
    Q4[1] = q4 < Q4[1] ? q4 : Q4[1];
    Q4[2] = q4 > Q4[2] ? q4 : Q4[2];
    mid1 = stu->mid1;
    Mid1[0] += mid1;
    Mid1[1] = mid1 < Mid1[1] ? mid1 : Mid1[1];
    Mid1[2] = mid1 > Mid1[2] ? mid1 : Mid1[2];
    mid2 = stu->mid2;
    Mid2[0] += mid2;
    Mid2[1] = mid2 < Mid2[1] ? mid2 : Mid2[1];
    Mid2[2] = mid2 > Mid2[2] ? mid2 : Mid2[2];
    final = stu->final;
    Final[0] += final;
    Final[1] = final < Final[1] ? final : Final[1];
    Final[2] = final > Final[2] ? final : Final[2];
    // Update the current student object with the next one in the list.
    stu = stu->next;
  }
  // Update the first element in each array from sum to average by dividing them with the student count.
  Q1[0]    /= stuCount;
  Q2[0]    /= stuCount;
  Q3[0]    /= stuCount;
  Q4[0]    /= stuCount;
  Mid1[0]  /= stuCount;
  Mid2[0]  /= stuCount;
  Final[0] /= stuCount;
  // Display the quiz/exam statistics on the console.
  printf("\t\tQ1\tQ2\tQ3\tQ4\tMid1\tMid2\tFinal\n");
  printf("Average:\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
          Q1[0], Q2[0], Q3[0], Q4[0], Mid1[0], Mid2[0], Final[0]);
  printf("Minimum:\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
          (int) Q1[1], (int) Q2[1], (int) Q3[1], (int) Q4[1], (int) Mid1[1], (int) Mid2[1], (int) Final[1]);
  printf("Maximum:\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
          (int) Q1[2], (int) Q2[2], (int) Q3[2], (int) Q4[2], (int) Mid1[2], (int) Mid2[2], (int) Final[2]);
  return 0; // Success.
}
/*-----------------------------------------------------------------------------*/

// writeStudentsGrades() writes the students' names and letter grades into the output file in a sorted order.
// @Params:  outputFileName (function input) 
//           -- the name of the output file.
// @Params:  firstStu (function input) 
//           -- a pointer to the first student in the list.
// @Returns: a binary flag
//           -- 0 indicates success.
//           -- 1 indicates failure.
int writeStudentsGrades(char *outputFileName, student *firstStu)
{
  // Sort the student linked list in an ascending order.
  student *lastStu = firstStu;
  lastStudent(firstStu, &lastStu);
  if ( quickSort(firstStu, lastStu) != 0 ) {
    printf("Error sorting the student linked list.\n");
    freeStudents(firstStu);
    return 1;
  }
  FILE *outFile;
  if ( (outFile = fopen(outputFileName, "w")) == NULL ) {
    printf("Error opening the output file.\n");
    return 1;
  }
  student *stu = firstStu;
  while (stu != NULL) {
    fputs(stu->name, outFile);
    fputs("\t\t", outFile);
    fputs(&stu->grade, outFile);
    fputs("\n", outFile);
    stu = stu->next;
  }
  fclose(outFile);
  return 0; // Success.
}
/*-----------------------------------------------------------------------------*/

// calculateLetterGrade() computes the letter grade by the student's scores in each quiz/exam. 
// Equation:Letter grade equation: 
// Final Score = quiz1 * .10 + quiz2 * .10 + quiz3 * .10 + quiz4 * .10 + midi * .20 + midii * .15 + final * .25 
// Determination of letter grade is according to the following logic:
// Final Score >= 90% then letter grade is A, 80%-89% B, 70%-79% C, 60-69% D, <= 59% F))
// @Params:   stu (function input/output) 
//            -- a pointer to the student.
// @Returns:  a binary flag
//            -- 0 indicates success.
//            -- 1 indicates failure.
// @Requires: the memory of the student object must be allocated and scores property must not be NULL.
int calculateLetterGrade(student *stu)
{
  if (stu == NULL) return 1;
  float q1 = stu->q1;
  float q2 = stu->q2;
  float q3 = stu->q3;
  float q4 = stu->q4;
  float mid1 = stu->mid1;
  float mid2 = stu->mid2;
  float final = stu->final;
  // Calculate the final score.
  float score = .1*q1 + .1*q2 + .1*q3 + .1*q4 + .2*mid1 + .15*mid2 + .25*final;
  if (score >= 90) stu->grade = 'A';
  else if (score >= 80) stu->grade = 'B';
  else if (score >= 70) stu->grade = 'C';
  else if (score >= 60) stu->grade = 'D';
  else stu->grade = 'F';
  return 0; // Success.
}
/*-----------------------------------------------------------------------------*/

// freeStudents() cleans up all the dynamic memory occupied by student objects.
// @Params:  firstStu (function output) 
//           -- a pointer to the first student in the list.
// @Returns: a binary flag
//           -- 0 indicates success.
//           -- 1 indicates failure.
int freeStudents(student *firstStu)
{
  if (firstStu == NULL) return 0;
  if (firstStu->next != NULL) freeStudents(firstStu->next);
  free(firstStu);
  return 0; // Success.
}
/*-----------------------------------------------------------------------------*/
