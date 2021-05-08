#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define barrier_elem 1000000000

typedef int Item;
typedef struct Node Node;

// элемент списка
struct Node {
	Item elem;
	Node *next;
};


// список
typedef struct {
    int size;
    Node *data;
} List;

// создание списка
List *list_create();
// вставка элемента по индексу в список
void list_insert(List*,Item,int);
// получение элемента из списка по индексу
Item list_get(List*,int);
// добавление в конец списка
void list_push(List*,Item);
// удаление элемента из списка по индексу
void list_remove(List*,int);
// удаление элемента из списка по значению
void list_delete(List*,Item);
// печать списка
void list_print(List*,char*[]);
// удаление всего списка из памяти
void list_destroy(List*);
// задание: развернуть список
void list_reverse(List*);

#endif

