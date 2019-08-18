/**************************************************************************************************/

/*
 * File: main.c
 * Author: Seth Sanasac
 * NetID: sjs4
 * Date: October 10 2014
 *
 * Description: Main functionality for simple C program that reads an input file,  counts the words in it, counts
 * how many times each word is used, then displays how many times each word is used.
 *
 */

/**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "dlist.h"
#include "wordcounting.h"
#include "trending.h"

/**************************************************************************************************/

int main(int argc, char *argv[])
{
	
	DList list;
	//creates a new list and puts it in a memory heap

   
	if( argc != 3 ) {
      printf("\nUsage: %s inputFile outputFile \n\n", argv[0]);  // message to help the user with the data
      return -1;
	}	
	DListInit(&list);
	if (!readDataFromFile(1, &list, argv[1])) // makes the input list
	{
		printf("Could not read from input file %s\n", argv[1]);
		return -1;
	}
	if (!readDataFromFile(2, &list, argv[2]))
	{
		printf("Could not read from input file %s\n", argv[2]);
		return -1;
	}

	DListSorting(&list);
	counting(&list); 
	return 0;
}

/**************************************************************************************************/
