/**************************************************************************************************/

/*
 * File: worldcounting.c
 * Author: Seth Sanasac
 * NetID: sjs4
 * Date: October 10 2014
 *
 * Description: trending of each word then outputs them onto the screen
 *
 */

/**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "dlist.h"
#include "wordcounting.h"
//find the trending of the words and output them on the screen
void counting(DList *list)
{
	DListNode* ptr;
	ptr= NULL;
	int count = 0;
	if (list)
	{
		printf("Trending up:\n");
		ptr = list->tail;
		while (count < 5)
		{			
			printf("%s (+%d)\n", ptr->word, (int)(ptr->endCount) - (int)(ptr->startCount));
			ptr = ptr->prev;
			count=count+1;
		}
		printf("Trending down:\n"); 
		count = 0;
		ptr = list->head;
		while (count < 5)
		{
			printf("%s (%d)\n", ptr->word, (int)(ptr->endCount) - (int)(ptr->startCount));
			ptr = ptr->next;
			count = count + 1;
		}
	}
	return;
}