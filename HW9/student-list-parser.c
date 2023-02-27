// UCSC CMPR.X400.(831)
// C Programming I
//
// Homework 9: Stuctures
//
// Function: This program reads in contents of the input file, display information on the console, and writes contents to the output file.
// 
// Created by Cheng Fei in 12/20/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_NUM 100
#define MAX_CHAR_NUM 100
/*-----------------------------------------------------------------------------*/

// Step functions:
// Functions in this group are in charge of the sub-tasks of the main function.
int parseArguments( int argc, char **argv);
int displayInputs( char *inputFileName );
int writeNames( char *inputFileName, char *outputFileName );
/*-----------------------------------------------------------------------------*/

int main( int argc, char *argv[] ) 
{
  // Input file's name and output file's name.
  char *inputFileName, *outputFileName;
  printf("\n");

  // Step 1: Parse input arguments.
  if ( parseArguments(argc, argv) != 0 ) 
    return EXIT_FAILURE;
  printf("\n");

  // Step 2: Display contents of the input file.
  inputFileName = argv[1];
  if ( displayInputs(inputFileName) != 0 )
    return EXIT_FAILURE;
  printf("\n");

  // Step 3: Store contents from the input file to the output file.
  outputFileName = argv[2];
  if ( writeNames(inputFileName, outputFileName) != 0 )
    return EXIT_FAILURE;

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
int parseArguments( int argc, char **argv )
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

// displayInputs() displays contents in the input file.
// @Params:   inputFileName (function input)
//            -- the name of the input file.
// @Returns:  a binary flag
//            -- 0 indicates success.
//            -- 1 indicates failure.
int displayInputs( char *inputFileName )
{
  FILE *fp;
  fp = fopen(inputFileName, "r");
  // Open the input file stream.
  if ( fp == NULL ) {
    perror("Error opening the input file.\n"); // Display specific error causes.
    fclose(fp);
    return 1;
  } else {
    char curr;
    // Read characters in the input file.
    while ( ( curr = fgetc(fp) ) != EOF ) printf("%c", curr);
    printf("\n");
  }
  fclose(fp); // Close the input file stream.
  return 0;   // Success.
}
/*-----------------------------------------------------------------------------*/

// writeNames() writes names in the input file into the output file.
// @Params:   inputFileName (function input)
//            -- the name of the input file.
//            outputFileName (function output)
//            -- the name of the output file.
// @Returns:  a binary flag
//            -- 0 indicates success.
//            -- 1 indicates failure.
int writeNames( char *inputFileName, char *outputFileName )
{
  FILE *inFile = fopen(inputFileName, "r");
  FILE *outFile = fopen(outputFileName, "w");

  if ( inFile == NULL || outFile == NULL ) {
    perror("Error opening the input/output file.\n");
    fclose(inFile);
    fclose(outFile);
    return 1;
  } else {
    fputs("This is what was read from the input file: ", outFile);
    fputs(inputFileName, outFile);
    fputs("\n\n", outFile);
    char curr;
    while ( ( curr = fgetc(inFile) ) != EOF ) {
      // Discard all characters after the first comma.
      if (curr == ',') {
        fputc('\n', outFile);
        do {
          curr = fgetc(inFile);
        } while (curr != '\n' && curr != EOF);
      } else {
        fputc(curr, outFile);
      }
    }
  }
  fclose(inFile);
  fclose(outFile);
  return 0;
}