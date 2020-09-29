/* 	LINKED LIST */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "file_io.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
 int No, NIK, Tanggal ,Umur;
 char Nama[30] ,Tempat[20], Jenis[2], Gol[3], Status[13], Pekerjaan[14];
 struct node *prev;
 struct node *next;
} node_t;

typedef struct double_linked_list {
 node_t *head;
 node_t *tail;
 int size;
} double_linked_list_t;

int menuChange();
void createDoubleList(double_linked_list_t **ppList);
void deleteDoubleList(double_linked_list_t **ppList);
void changeDoubleList(double_linked_list_t **ppList);
void searchDoubleList(double_linked_list_t *ppList);
void sortDoubleList(double_linked_list_t *ppList);
void addFrontDoubleList(double_linked_list_t **ppList);
void addBackDoubleList(double_linked_list_t **ppList);
void fillDoubleList(node_t **current, char *filler, int column);
void printDoubleList(double_linked_list_t *ppList);


int menuChange(){
    int menu_c;
    printf("1. Nomor Urut \n");
    printf("2. Nomor Induk Kependudukan (NIK) \n");
    printf("3. Nama Lengkap \n");
    printf("4. Tempat Lahir \n"); 
    printf("5. Tanggal Lahir \n");
    printf("6. Umur \n");
    printf("7. Jenis Kelamin \n");
    printf("8. Golongan Darah \n");
    printf("9. Status Perkawinan \n");
    printf("10. Pekerjaan \n");
    printf("Masukkan pilihan : ");
	scanf("%d", &menu_c);
    return menu_c;
}

void createDoubleList(double_linked_list_t **ppList){
    (*ppList)->head = (node_t*)malloc(sizeof(node_t));
    (*ppList)->tail = (node_t*)malloc(sizeof(node_t));

    (*ppList)->head->No = 0;
    (*ppList)->head->NIK = 0;
    (*ppList)->head->Tanggal = 0;
    (*ppList)->head->Umur = 0;
    (*ppList)->head->prev = NULL;
    strcpy((*ppList)->head->Gol , "");
    strcpy((*ppList)->head->Jenis , "");
    strcpy((*ppList)->head->Nama , "");
    strcpy((*ppList)->head->Pekerjaan , "");
    strcpy((*ppList)->head->Tempat , "");
    strcpy((*ppList)->head->Status , "");
    (*ppList)->head->next = (*ppList)->tail;

    (*ppList)->tail->No = 1;
    (*ppList)->tail->NIK = 0;
    (*ppList)->tail->Tanggal = 0;
    (*ppList)->tail->Umur = 0;
    (*ppList)->tail->prev = (*ppList)->head;
    strcpy((*ppList)->tail->Gol , "");
    strcpy((*ppList)->tail->Jenis , "");
    strcpy((*ppList)->tail->Nama , "");
    strcpy((*ppList)->tail->Pekerjaan , "");
    strcpy((*ppList)->tail->Tempat , "");
    strcpy((*ppList)->tail->Status , "");
    (*ppList)->tail->next = NULL;
    (*ppList)->size = 2;
}

void deleteDoubleList(double_linked_list_t **ppList){
    (*ppList)->size = 0;
    (*ppList)->head = NULL;
    (*ppList)->tail = NULL;
}

void changeDoubleList(double_linked_list_t **ppList){

}

void searchDoubleList(double_linked_list_t *ppList){
    char val[30];
    int var,a;
    node_t * current = ppList->head->next;
    printf("%d || %d || %s || %s || %d || %d || %s || %s || %s || %s\n", current->No, current->NIK, current->Nama,
    current->Tempat,current->Tanggal, current->Umur, current->Jenis, current->Gol, current->Status, current->Pekerjaan);
    printf("\nApa yang ingin Anda cari ? \n\n");
    var = menuChange();
    printf("Masukkan yang ingin Anda cari : ");
    if (var == 1 || var == 2 || var == 5 || var == 6){
        scanf("%d", &a);
    }else{scanf("%s", &val);}
    switch (var){
    case 1:
        while (a != current->No && current->next != NULL){
            current = current->next;
        }
        break;

    case 2:
        while (a != current->No && current->next != NULL) {
            current = current->next;
        }
        break;

    case 3:
        while (strcmp(current->Nama, val) != 0 && current->next != NULL) {
            current = current->next;
        }
        break;

    // case 4:
    //     while (strcmp(current->Tempat, val) != 0 && current->next != NULL) {
    //         current = current->next;
    //     }
    //     break;
    
    // case 5:
    //     while ((a < current->Tanggal) && (current->next != NULL)) {
    //         current = current->next;
    //     }
    //     break;
    
    // case 6:
    //     while ((a < current->Umur) && (current->next != NULL)) {
    //         current = current->next;
    //     }
    //     break;

    // case 7:
    //     while (strcmp(current->Jenis, val) != 0 && current->next != NULL) {
    //         current = current->next;
    //     }
    //     break;

    // case 8:
    //     while (strcmp(current->Gol, val) != 0 && current->next != NULL) {
    //         current = current->next;
    //     }
    //     break;

    // case 9:
    //     while (strcmp(current->Status, val) != 0 && current->next != NULL) {
    //         current = current->next;
    //     }
    //     break;

    // case 10:
    //     while (strcmp(current->Pekerjaan, val) != 0 && current->next != NULL) {
    //         current = current->next;
    //     }
    //     break;
    
    default:
        break;
    }
    if (current->next != NULL){printf("%d || %d || %s || %s || %d || %d || %s || %s || %s || %s\n", current->No, current->NIK, current->Nama,
    current->Tempat,current->Tanggal, current->Umur, current->Jenis, current->Gol, current->Status, current->Pekerjaan);}
    else{printf("Data tidak ditemukan\n");}
    
}

void sortDoubleList(double_linked_list_t *ppList){
    int a,var;
    char val[30];
    node_t * current = ppList->head;
    printf("Apa yang ingin Anda urutkan ? \n\n");
    var = menuChange();
    switch (var){
    case 1:
        while ((current->No < current->next->No) && (current->next != NULL)) {
            current = current->next;
        }
        break;

    case 2:
        while ((a < current->NIK) && (current->next != NULL)) {
            current = current->next;
        }
        break;

    case 3:
        while (strcmp(current->Nama, val) != 0 && current->next != NULL) {
            current = current->next;
        }
        break;

    case 4:
        while (strcmp(current->Tempat, val) != 0 && current->next != NULL) {
            current = current->next;
        }
        break;
    
    case 5:
        while ((a < current->Tanggal) && (current->next != NULL)) {
            current = current->next;
        }
        break;
    
    case 6:
        while ((a < current->Umur) && (current->next != NULL)) {
            current = current->next;
        }
        break;

    case 7:
        while (strcmp(current->Jenis, val) != 0 && current->next != NULL) {
            current = current->next;
        }
        break;

    case 8:
        while (strcmp(current->Gol, val) != 0 && current->next != NULL) {
            current = current->next;
        }
        break;

    case 9:
        while (strcmp(current->Status, val) != 0 && current->next != NULL) {
            current = current->next;
        }
        break;

    case 10:
        while (strcmp(current->Pekerjaan, val) != 0 && current->next != NULL) {
            current = current->next;
        }
        break;
    
    default:
        break;
    } 
    printDoubleList(ppList);
}

void addFrontDoubleList(double_linked_list_t **ppList){
    node_t * add_node;
    add_node = (node_t*)malloc(sizeof(node_t));

    add_node->No = 0;
    add_node->NIK = 0;
    add_node->Tanggal = 0;
    add_node->Umur = 0;
    strcpy(add_node->Gol , "");
    strcpy(add_node->Jenis , "");
    strcpy(add_node->Nama , "");
    strcpy(add_node->Pekerjaan , "");
    strcpy(add_node->Tempat , "");
    strcpy(add_node->Status , "");
    add_node->next = (*ppList)->head;
    add_node->prev = NULL;
    (*ppList)->head = add_node;
    (*ppList)->size++;
}

void addBackDoubleList(double_linked_list_t **ppList){
    node_t * add_node;
    add_node = (node_t*)malloc(sizeof(node_t));

    add_node->next = NULL;
    add_node->No = 0;
    add_node->NIK = 0;
    add_node->Tanggal = 0;
    add_node->Umur = 0;
    strcpy(add_node->Gol , "");
    strcpy(add_node->Jenis , "");
    strcpy(add_node->Nama , "");
    strcpy(add_node->Pekerjaan , "");
    strcpy(add_node->Tempat , "");
    strcpy(add_node->Status , "");

    add_node->prev = (*ppList)->tail;
    (*ppList)->tail->next = add_node;
    (*ppList)->tail = add_node;
    (*ppList)->size++;
}

void fillDoubleList(node_t **current, char *filler, int column){
    if (column == 0){
		(*current)->No = atoi(filler);
	}else if (column == 1){
	    (*current)->NIK = atoi(filler);
    }else if (column == 2){
	    strcpy((*current)->Nama , filler);
    }else if (column == 3){
	    strcpy((*current)->Tempat , filler);
    }else if (column == 4){
	    (*current)->Tanggal = atoi(filler);
    }else if (column == 5){
	    (*current)->Umur = atoi(filler);
    }else if (column == 6){
	    strcpy((*current)->Jenis ,filler);
    }else if (column == 7){
	    strcpy((*current)->Gol ,filler);
    }else if (column == 8){
	    strcpy((*current)->Status ,filler);
    }else if (column == 9){
	    strcpy((*current)->Pekerjaan ,filler);
    }
}

void printDoubleList(double_linked_list_t *ppList){
    node_t *current = ppList->head;
    printf("// MENCETAK DATA // \n\nTotal size : %d\n", ppList->size);
    if (current == NULL){printf("Data Kosong\n");}
    while (current != NULL){
        printf("%d;%d;%s;%s;%d;%d;%s;%s;%s;%s\n", current->No, current->NIK, current->Nama, current->Tempat, 
                    current->Tanggal, current->Umur, current->Jenis, current->Gol, current->Status, current->Pekerjaan);
        current = current->next;
    }
    printf("\n");
}


#endif