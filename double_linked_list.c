/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>
#include "sokoban.h"
#include "double_linked_list.h"

//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(SOKOBAN x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(SOKOBAN x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
  printf("inserted at head\n");
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(SOKOBAN x) {
	struct Node* newNode = GetNewNode(x);
	if(tail == NULL) {
		tail = newNode;
		return;
	}
	tail->next = newNode;
	newNode->prev = tail;
  tail=newNode;
  printf("inserted at tail \n");
}

SOKOBAN send_head(){
  SOKOBAN H;
  struct Node* temp = head;
  printf("suiv\n");
  H = temp->data;
  temp=temp->next;
  return H;
}

SOKOBAN send_tail(){
  SOKOBAN T;
  struct Node* temp = tail;
  printf("suiv\n");
  T = temp->data;
  temp=temp->next;
  return T;
}
