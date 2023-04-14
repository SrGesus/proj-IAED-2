/*
  File: list.c
  Author: Gabriel ist1107030
  Description: Functions that provide abstraction to the DLList struct
*/

#include "./proj.h"

/*  
  Inserts node after given node, or as head if given node is NULL
*/
void *DLLISTinsert(
  DLList *list, DLNode *previous, void *value, Data *db, Args *args
) {
  DLNode *node = wrap_calloc(1, sizeof(DLNode), db, args);
  node->value = value;
  node->prev = previous;
  if (list->tail == previous) {
    list->tail = node;
  }
  if (previous != NULL) {
    node->next = previous->next;
    previous->next = node;
  } else {
    node->next = list->head;
    list->head = node;
  }
  if (node->next != NULL) {
    node->next->prev = node;
  }
  list->length++;
  return node;
}

/*
  Removes given node from a doubly linked list
*/
void DLLISTremove(DLList *list, DLNode *node) {
  if (node == NULL) {
    return;
  }
  if (list->head == node) {
    list->head = node->next;
  }
  if (list->tail == node) {
    list->tail = node->prev;
  }
  if (node->next != NULL) {
    node->next->prev = node->prev;
  }
  if (node->prev != NULL) {
    node->prev->next = node->next;
  }
  list->length--;
  free(node);
  return;
}

/*
  Frees every node on the LinkedList and uses 
  a function it receives as an argument to free its values
*/
void DLLISTdestroy(DLList *list, void (*free_node)(DLNode *)) {
  int i = 0;
  DLNode *node = NULL;
  DLNode *prev = NULL;

  while (DLLISTiter(list, &i, &node)) {
    (*free_node)(prev);
    prev = node;
  }
  (*free_node)(prev);
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
}

/*
  Iterates through the Linked List
*/
int DLLISTiter(DLList *list, int *i, DLNode **node) {
  if (*i >= list->length) {
    return false;
  }
  if (*i == 0) {
    *node = list->head;
  } else if ((*node)->next == NULL) {
    printf("Error: list length mismatch.\n");
    return false;
  } else {
    *node = (*node)->next;
  }
  (*i)++;
  return true;
}

/*
  Iterates through the Linked List in the reverse order
*/
int DLLISTiter_rev(DLList *list, int *i, DLNode **node) {
  if (*i >= list->length) {
    return false;
  }
  if (*i == 0) {
    *node = list->tail;
  } else if ((*node)->prev == NULL) {
    printf("Error: list length mismatch.\n");
    return false;
  } else {
    *node = (*node)->prev;
  }
  (*i)++;
  return true;
}
