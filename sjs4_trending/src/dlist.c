/**************************************************************************************************/

/*
* File: dlist.c
* Author: Seth Sanasac
* NetID: sjs4
* Date: October 10 2014
*
* Description: Doubly linked list functions
*
*/

/**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dlist.h"
#include "bool.h"

/**************************************************************************************************/


void DListInit(DList* list)  // Initializes the list to use
{
	if (list)
	{
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
}
/**************************************************************************************************/


DListNode* DListSearch(DList* list, char* key)  // Search through the list

// if the key is found, set start or end count to 1
// if not found, add a new node to the list
// returns a node
{  	
	DListNode *found;	
	found = (DListNode*)malloc(sizeof(DListNode));
		if (list->head == NULL)
		{	
			return list->head;
		}
		else
		{			
			found = list->head;
		}		
		while (found != NULL)
		{
			if (strcmp(found->word, key) != 0)
			{
				found = found->next;
			}
			else
			{
				return found;
			}		
		}		
	return 0;
}
/**************************************************************************************************/
//frees list memory for the program
void DListDestroy(DList* list)
{
	free(list);
	return;
}

/**************************************************************************************************/


bool DListInsertAfter(DList* list, DListNode* currNode, DListNode* newNode) // insert new node
{
	bool result = false;
	if (list != NULL)
	{
		result = true;
		if (currNode == NULL)
		{
			return DListInsertBefore(list, list->head, newNode);
		}
		else
		{
			newNode->next = currNode->next;
			newNode->prev = currNode;
			if (currNode->next)
			{
				currNode->next->prev = newNode;
			}
			currNode->next = newNode;
		}
		DListUpdateHeadTail(list,newNode,currNode);
		list->size++;
	}
	return result;}

/**************************************************************************************************/

bool DListInsertBefore(DList* list, DListNode* currNode, DListNode* newNode) // insert new node
{
	bool result = false;
	if (list != NULL)
	{
		result = true;
		if (currNode == NULL)
		{
			newNode->next = list->head;
			newNode->prev = NULL;
			if (list->head != NULL)
			{
				list->head->prev = newNode;
			}
		}
		else
		{
			if (newNode)
			{
				newNode->prev = currNode->prev;
				newNode->next = currNode;
				if (currNode->prev != NULL)
				{
					currNode->prev->next = newNode;
				}
				currNode->prev = newNode;
			}			
		}
		DListUpdateHeadTail(list, currNode, newNode);
		list->size++;
	}
	return result;
}

/**************************************************************************************************/

void DListUpdateHeadTail(DList* list, DListNode* currNode, DListNode* newNode)  // update list after inserting new node
{
	if (list)
	{
		if (currNode)
		{
			if (currNode->next == NULL)
			{
				list->tail = currNode;
			}
			if (currNode->prev == NULL)
			{
				list->head = NULL;
			}
		}
		if (newNode)
		{
			if (newNode->next == NULL)
			{
				list->tail = newNode;
			}
			if (newNode->prev == NULL)
			{
				list->head = newNode;
			}
		}
		if (currNode && newNode)
		{
			if (currNode->next == newNode->next || currNode->prev == newNode->prev)
			{
				printf("you have failed update the list\n");
			}
		}
	}
	return;
}

/**************************************************************************************************/

bool DListRemove(DList* list, DListNode* currNode)  // removes the node from the list
{
	
	return true; 
}

void DListSorting(DList* list)   // sorts the list
{	
	int i=0, j=0;
	DListNode *current = NULL;
	DListNode *right = NULL;
	DListNode *temp = NULL;
	temp = (DListNode*)malloc(sizeof(DListNode));
	temp->startCount = 0;
	temp->endCount = 0;
	temp->word = (char*)malloc(sizeof(char)* 1024);	
	current = list->head;
	for (i = 0; i < list->size - 1 ; i++)
	{
		right = current->next;
		for (j = i + 1; j < list->size; j++)
		{			
			if (((int)(current->endCount - current->startCount)) >((int)(right->endCount - right->startCount)))
			{
				//swap the data
				strcpy(temp->word, current->word);
				temp->startCount = current->startCount;
				temp->endCount = current->endCount;

				strcpy(current->word, right->word);
				current->startCount = right->startCount;
				current->endCount = right->endCount;

				strcpy(right->word, temp->word);
				right->startCount = temp->startCount;
				right->endCount = temp->endCount;
			}
			right = right->next;
		}
		current = current->next;

		// end of last part
	}
}

// end of all parts
