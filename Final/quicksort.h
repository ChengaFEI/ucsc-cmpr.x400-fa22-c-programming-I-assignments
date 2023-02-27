// UCSC CMPR.X400.(831)
// C Programming I
//
// Final Programming Assignment
// quicksort.h
// 
// Function: Prototypes of the quick-sort algorithm on the singly-linked-list. 
//
// Created by Cheng Fei in 12/25/2022

#include "student.h"
/*----------------------------------------------------------------------------*/

// Quick sort the student linked list by the name in the ascending order.
int quickSort(student *firstStu, student *lastStu);
// Partition the linked list from firstStu to lastStu and return the pivot student object.
int partition(student *firstStu, student *lastStu, student **pivStu);
// Swap all properties in student1 and student2, except their next student.
int swap(student *stu1, student *stu2);
// Find the last student in the linked list whose head is firstStu.
int lastStudent(student *firstStu, student **lastStu);

// Helper function.
// Swap two c-style strings.
void swapStr(char *s1, char *s2);