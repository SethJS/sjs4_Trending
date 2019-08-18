

/**************************************************************************************************/

/*
* File: dlist.h
* Author: Seth Sanasac
* NetID: sjs4
* Date: October 10 2014
*
*                  old file from sprinkles class.
*           
*/


#include <stdlib.h>
#include <stdio.h>
#include "bool.h"

#ifndef DLIST_H
#define DLIST_H

/**************************************************************************************************/
//define struct
typedef struct DListNode_struct {
	char *word;
	unsigned long startCount;
	unsigned long endCount;
	struct DListNode_struct *next;
	struct DListNode_struct *prev;
} DListNode;

/**************************************************************************************************/
//define list
typedef struct DList_struct
{
	int size;
	DListNode *head;
	DListNode *tail;
}DList;

//Doubly linked list functions requirement for this assignment
/**************************************************************************************************/
void DListInit(DList* list);

/**************************************************************************************************/

void DListDestroy(DList* list);

/**************************************************************************************************/

void DListSorting(DList* list);

/**************************************************************************************************/

bool DListInsertAfter(DList* list, DListNode* currNode, DListNode* newNode);

/**************************************************************************************************/

bool DListInsertBefore(DList* list, DListNode* currNode, DListNode* newNode);

/**************************************************************************************************/

void DListUpdateHeadTail(DList* list, DListNode* currNode, DListNode* newNode);

/**************************************************************************************************/

DListNode* DListSearch(DList* list, char* key);

/**************************************************************************************************/

bool DListRemove(DList* list, DListNode* currNode);

/**************************************************************************************************/

#endif