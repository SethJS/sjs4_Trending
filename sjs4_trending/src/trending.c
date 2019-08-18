/**************************************************************************************************/

/*
* File: tempdata.c
* Author: Seth Sanasac
* NetID: sjs4
* Date: October 10 2014
*
* Description: reads the text from each file then inserts them into the list
*
*/

/**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "dlist.h"
#include <ctype.h>
#include <string.h>
#include "trending.h"

bool readDataFromFile(int k, DList *list, char *fileName)
  //  this reads file data and copies it to the list
{
	FILE *input;
	input = NULL;
	input = fopen(fileName, "r");
		//makes a variable for the file
	int i = 0;
	char *word;
	word= NULL;	
	word = (char*)malloc(sizeof(char)* 1024);
	while (!feof(input))
		{				
			if (word == NULL)
			{
				printf("System out of memory.\n");
			}
			else
			{
				fscanf(input, " %s ", word);
				i = 0;
				while (word[i])
				{ 
					word[i] = (tolower(word[i]));	
					i++; 
				}				
				DListNode *key=NULL;
				key= DListSearch(list, word);
				if (key != NULL)
					// if the node is found
				{
					if (k == 2)
					{
						key->endCount = key->endCount + 1;
						
					}
					else if (k == 1)
					{
						key->startCount = key->startCount + 1;
					}					
				}
				else
				{
					key = (DListNode*)malloc(sizeof(DListNode));
					key->startCount = 0;
					key->endCount = 0;
					key->word = (char *)malloc(sizeof(char)*(1024));					
					strcpy(key->word, word);
					if (k == 2)
					{						
						key->endCount = 1;
					}
					else if (k == 1)
					{
						key->startCount = 1;
					}					
					DListInsertAfter(list, NULL, key);
				}			
			}
		}				
	fclose(input);
	free(word);
	return 1;
}

