// UCSC CMPR.X400.(831)
// C Programming I
//
// Final Programming Assignment
// quicksort.c
// 
// Function: Implementations of the quick-sort algorithm on the singly-linked-list. 
//
// Created by Cheng Fei in 12/25/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "quicksort.h"
/*----------------------------------------------------------------------------*/

// quickSort() sorts the student linked list from the firstStu to the lastStu in an ascending order.
// @Params:  firstStu (function input/ouput) 
//           -- the pointer to the first student object in the linked list.
//           -- the function will update the firstStu after sorting.
// @Params:  lastStu (function input)
//           -- the pointer to the last student object in the linked list.
// @Returns: a binary flag
//           -- 0 indicates success.
//           -- 1 indicates failure.
int quickSort(student *firstStu, student *lastStu)
{
  if (firstStu == lastStu) return 0; // No need to sort only one student.
  student *pivStu;
  if ( partition(firstStu, lastStu, &pivStu) != 0 ) return 1;
  // Quick sort the last half of the list.
  if (pivStu != NULL && pivStu->next != NULL) {
    if ( quickSort(pivStu->next, lastStu) != 0 ) return 1;
  }
  // Quick sort the first half of the list.
  if (pivStu != NULL && pivStu != firstStu) {
    if ( quickSort(firstStu, pivStu) != 0 ) return 1;
  }
  return 0; // Success.
}
/*----------------------------------------------------------------------------*/

// partition() partitions the linked list from firstStu to lastStu and returns the pivot student object.
// @Params:  firstStu (function input) 
//           -- the pointer to the first student object in the linked list.
// @Params:  lastStu (function input)
//           -- the pointer to the last student object in the linked list.
// @Params:  pivStu (function output)
//           -- the pointer to the pivot student object found in the list.
// @Returns: a binary flag
//           -- 0 indicates success.
//           -- 1 indicates failure.
int partition(student *firstStu, student *lastStu, student **pivStu)
{
  // Initialize the pivot student as the first student.
  *pivStu = firstStu;
  // The moving pointer.
  student *frontStu = firstStu;
  while (frontStu != NULL && frontStu != lastStu) {
    // If find a student whose name should precede the last student's name.
    if ( strcmp(frontStu->name, lastStu->name) < 0 ) {
      // Update the pivot student.
      *pivStu = firstStu;
      swap(firstStu, frontStu);
      firstStu = firstStu->next;
    }
    frontStu = frontStu->next;
  }
  swap(firstStu, lastStu);
  return 0; // Success.
}
/*----------------------------------------------------------------------------*/

// swap() swaps all properties in student1 and student2, except their next student.
// @Params:  stu1 (function input/ouput) 
//           -- the pointer to the student1 in the linked list.
//           -- the function will update the student1 after sorting.
// @Params:  stu2 (function input/output)
//           -- the pointer to the student2 in the linked list.
//           -- the function will update the student2 after sorting.
// @Returns: a binary flag
//           -- 0 indicates success.
//           -- 1 indicates failure.
int swap(student *stu1, student *stu2)
{
  // Swap name.
  swapStr(stu1->name, stu2->name);
  // Swap q1.
  float tempQ1 = stu1->q1;
  stu1->q1 = stu2->q1;
  stu2->q1 = tempQ1;
  // Swap q2.
  float tempQ2 = stu1->q2;
  stu1->q2 = stu2->q2;
  stu2->q2 = tempQ2;
  // Swap q3.
  float tempQ3 = stu1->q3;
  stu1->q3 = stu2->q3;
  stu2->q3 = tempQ3;
  // Swap q4.
  float tempQ4 = stu1->q4;
  stu1->q4 = stu2->q4;
  stu2->q4 = tempQ4;
  // Swap mid1.
  float tempMid1 = stu1->mid1;
  stu1->mid1 = stu2->mid1;
  stu2->mid1 = tempMid1;
  // Swap mid2.
  float tempMid2 = stu1->mid2;
  stu1->mid2 = stu2->mid2;
  stu2->mid2 = tempMid2;
  // Swap final.
  float tempFinal = stu1->final;
  stu1->final = stu2->final;
  stu2->final = tempFinal;
  // Swap grade.
  char tempGrade = stu1->grade;
  stu1->grade = stu2->grade;
  stu2->grade = tempGrade;
  return 0; // Success.
}
/*----------------------------------------------------------------------------*/

// lastStudent() finds the last student in the linked list whose head is firstStu.
// @Params:  firstStu (function input) 
//           -- the pointer to the first student object in the linked list.
// @Params:  lastStu (function output)
//           -- the pointer to the last student object in the linked list.
// @Returns: a binary flag
//           -- 0 indicates success.
//           -- 1 indicates failure.
int lastStudent(student *firstStu, student **lastStu)
{
  if (firstStu == NULL) return 1;
  student *stu = firstStu;
  while (stu != NULL && stu->next != NULL) stu = stu->next;
  *lastStu = stu;
  return 0; // Success.
}
/*----------------------------------------------------------------------------*/

// swapStr() swaps two c-style strings.
// @Params:  s1 (function input) 
//           -- the pointer to the first c-style string.
// @Params:  s2 (function output)
//           -- the pointer to the second c-style string.
// @Returns: None
void swapStr(char *s1, char *s2) 
{
  int length1 = strlen(s1);
  int length2 = strlen(s2);
  int length = (length1 < length2) ? length1 : length2;
  int i = 0;
  while (s1[i] != '\0' && s2[i] != '\0') {
    char temp = s1[i];
    s1[i] = s2[i];
    s2[i] = temp;
    i++;
  }
  if (s1[i] == '\0') {
    s1[i] = s2[i];
    s2[i++] = '\0';
    do {
      s1[i] = s2[i];
      i++;
    } while (s2[i] != '\0');
    s2[i] = 0;
    s1[i] = '\0';
  }
  if (s2[i] == '\0') {
    s2[i] = s1[i];
    s1[i++] = '\0';
    do {
      s2[i] = s1[i];
      i++;
    } while (s1[i] != '\0');
    s1[i] = 0;
    s2[i] = '\0';
  } 
}
/*----------------------------------------------------------------------------*/
