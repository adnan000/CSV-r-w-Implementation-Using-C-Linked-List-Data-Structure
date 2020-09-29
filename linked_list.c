/* 	EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 
* 	Modul 				: 6
* 	Percobaan 			: 1 
* 	Hari dan Tanggal 	: Rabu, 29 April 2020
*	Nama (NIM) 			: Muhammad Adnan (13218019) 
* 	Asisten (NIM) 		: Wuri Utami (13217024) 
* 	Nama File 			: 13218019_6_1.c 
* 	Deskripsi 			: Linked List
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int node_type;

typedef struct node {

 node_type element;
 struct node *prev;
 struct node *next;
} node_t;

typedef struct double_linked_list {
 node_t *head;
 node_t *tail;
 int size;
} double_linked_list_t;

void createDoubleList(double_linked_list_t **ppList);
void deleteDoubleList(double_linked_list_t **ppList);
void addFrontDoubleList(double_linked_list_t **ppList);
void addBackDoubleList(double_linked_list_t **ppList);
void removeFrontDoubleList(double_linked_list_t **ppList);
void removeBackDoubleList(double_linked_list_t *ppList);
void printDoubleList(double_linked_list_t *ppList);
int isListNotEmpty(double_linked_list_t *ppList);



void createDoubleList(double_linked_list_t **ppList){
    (*ppList)->head = (node_t*)malloc(sizeof(node_t));
    (*ppList)->tail = (node_t*)malloc(sizeof(node_t));

    (*ppList)->head->element = 0;
    (*ppList)->head->prev = NULL;
    (*ppList)->head->next = (*ppList)->tail;
    (*ppList)->tail->element = 1;
    (*ppList)->tail->prev = (*ppList)->head;
    (*ppList)->tail->next = NULL;
    (*ppList)->size = 2;
}

void deleteDoubleList(double_linked_list_t **ppList){
    (*ppList)->size = 0;
    (*ppList)->head = NULL;
    (*ppList)->tail = NULL;
}

void addFrontDoubleList(double_linked_list_t **ppList){
    node_t * add_node;
    add_node = (node_t*)malloc(sizeof(node_t));

    add_node->element = 3;
    add_node->next = (*ppList)->head;
    add_node->prev = NULL;
    (*ppList)->head = add_node;
    (*ppList)->size++;
}
void addBackDoubleList(double_linked_list_t **ppList){
    node_t * add_node;
    add_node = (node_t*)malloc(sizeof(node_t));

    add_node->element = 4;
    add_node->next = NULL;
    (*ppList)->tail->next = add_node;
    (*ppList)->tail = add_node;
    (*ppList)->size++;
}

void removeFrontDoubleList(double_linked_list_t **ppList){
    (*ppList)->head = (*ppList)->head->next;
    free((*ppList)->head->prev);
    (*ppList)->size--;
}

void removeBackDoubleList(double_linked_list_t *ppList){
    node_t * current = ppList->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    current->next = NULL;
    (ppList)->size--;
}

void printDoubleList(double_linked_list_t *ppList){
    node_t *current = ppList->head;
    int i = 0;
    printf("Total size : %d\n", ppList->size);
    while (current != NULL){
        printf("indeks ke -%d = %d\n",i, current->element);
        current = current->next;
        i++;
    }
    printf("\n");
}

int isListNotEmpty(double_linked_list_t *ppList){
    if (ppList->head == NULL){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    double_linked_list_t *ppList;
    ppList = (double_linked_list_t*) malloc(sizeof(double_linked_list_t));
    printf("Fungsi createDoubleList: \n");
    createDoubleList(&ppList);
    printDoubleList(ppList);

    printf("Fungsi addFrontDoubleList: \n");
    addFrontDoubleList(&ppList);
    printDoubleList(ppList);

    printf("Fungsi addBackDoubleList: \n");
    addBackDoubleList(&ppList);
    printDoubleList(ppList);

    printf("Fungsi removeFrontDoubleList: \n");
    removeFrontDoubleList(&ppList);
    printDoubleList(ppList);

    printf("Fungsi removeBackDoubleList: \n");
    removeBackDoubleList(ppList);
    printDoubleList(ppList);

    printf("Apakah list tidak kosong ? (0/1) : %d\n", isListNotEmpty(ppList));

    printf("Fungsi deleteDoubleList: \n");
    deleteDoubleList(&ppList);
    printDoubleList(ppList);

    printf("Apakah list tidak kosong ? (0/1) : %d\n", isListNotEmpty(ppList));
    return 0;
}