#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = (void *)data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}
//EJERCICIO 1
List * createList() {
  List* list=(List*) malloc (sizeof(List));
  list->head = NULL;
  list->current = NULL;
  list->tail = NULL;
  return list;
}

//EJERCICIO 2
void * firstList(List * list) {
  if (list->head && list->head->data){
    list->current = list->head;
    return list->head->data;
  }
  return NULL;
}

void * nextList(List * list) {
  if (list->current && list->current->next && list->current->next->data){
    list->current = list->current->next;
    return list->current->data;
  }
  return NULL;
}

//EJERCICIO 3
void * lastList(List * list) {
  if (list->tail && list->tail->data){
    list->current = list->tail;
    return list->tail->data;
  }
  return NULL;  
  
}

void * prevList(List * list) {
  if (list->current && list->current->prev && list->current->prev->data){
    list->current = list->current->prev;
    return list->current->data;
  }
  return NULL;
}

//EJERCICIO 4
void pushFront(List * list, const void * data){
  Node* nuevoNodo = createNode(data);
  nuevoNodo->next = list->head;

  if(list->head)
    list->head->prev = nuevoNodo;
  else
    list->tail = nuevoNodo;  
  
  list->head = nuevoNodo;
  nuevoNodo->prev = NULL;
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

//EJERCICIO 5
void pushCurrent(List * list, const void * data) {
  Node* nuevoNodo = createNode(data);
  nuevoNodo->prev = list->current;
  if (!list->current->next){
    printf("ENTRÓ\n");
    list->tail = nuevoNodo;
    nuevoNodo->next = NULL;
  }
  else{
    nuevoNodo->next = list->current->next;
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

//EJERCICIO 6
void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}