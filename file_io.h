/* 	FILE IO */
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#ifndef FILE_IO
#define FILE_IO

int menu();
// int menuChange();
void getData(char *nama, double_linked_list_t **ppList);
void writeData(char *nama_f, double_linked_list_t *ppList);
void create(char *nama_f, double_linked_list_t **ppList);

int menu(){
    int menu;
    // printf(" ___           _                             _       ___           _                        \n");
    // printf(" ___           _                             _       ___           _                        \n");
    // printf("(  _`\        (_ )                          ( )_    (  _`\        ( )_                      \n");
    // printf("| (_(_)   __   | |    _ _   ___ ___     _ _ | ,_)   | | ) |   _ _ | ,_)   _ _   ___     __  \n");
    // printf("`\__ \  /'__`\ | |  /'_` )/' _ ` _ `\ /'_` )| |     | | | ) /'_` )| |   /'_` )/' _ `\ /'_ `\\n");
    // printf("( )_) |(  ___/ | | ( (_| || ( ) ( ) |( (_| || |_    | |_) |( (_| || |_ ( (_| || ( ) |( (_) |\n");
    // printf("`\____)`\____)(___)`\__,_)(_) (_) (_)`\__,_)`\__)   (____/'`\__,_)`\__)`\__,_)(_) (_)`\__  |\n");
    // printf("                                                                                     ( )_) |\n");
    // printf("                                                                                      \___/'\n\n\n");
    
    system("@cls||clear");
    printf("Silahkan pilih aksi : \n\n");
    printf("1. Membuat file csv baru \n");
    printf("2. Mengubah isi file csv \n");
    printf("3. Menghapus isi file csv \n"); 
    printf("4. Membaca isi file csv \n");
    printf("Pilihan : ");
	scanf("%d", &menu);
    system("@cls||clear");
    return menu;
}

void getData(char *nama, double_linked_list_t **ppList) {
    char buff[255], *token ;
    int row = 0, column;
    FILE * fp;
    node_t *temp;
	fp=fopen(nama,"r");
	while (fgets(buff, 255, (FILE*)fp) != NULL){
		token = strtok(buff, ";");
		column=0;
        if (row == 0) {
            temp = (*ppList)->head;
        }else if (row == 1) {
            temp = (*ppList)->tail;
        }else{
            addBackDoubleList(ppList);
            temp = (*ppList)->tail;
        }
		while (token != NULL){
			if (row != 0){
				fillDoubleList(&temp, token, column);
			}
			token = strtok(NULL, ";");
			column++;
		}	
        row++;	
	}
	fclose(fp);
}

void writeData(char *nama_f, double_linked_list_t *ppList){
    FILE *fp;
    fp = fopen(nama_f, "w");
    node_t *current = ppList->head;

    fputs("No;NIK;NamaLengkap;TempatLahir;TanggalLahir;Umur;JenisKelamin;GolonganDarah;Status;Pekerjaan\n", fp);
    while (current != NULL){
    char buff1[1], buff2[12], buff3[10], buff4[3];
            fprintf(fp, "%d;%d;%s;%s;%d;%d;%s;%s;%s;%s\n", current->No, current->NIK, current->Nama, current->Tempat, 
                    current->Tanggal, current->Umur, current->Jenis, current->Gol, current->Status, current->Pekerjaan);
            current = current->next;
    }
    fclose(fp);
}

void create(char *nama_f, double_linked_list_t **ppList){
    char quit = 'y', num;
    node_t *new_data;
    new_data = (*ppList)->head;
    new_data->No = 1;
    while(quit != 'n'){
        printf("Masukkan jumlah data yang ingin dimasukkan : ");
        scanf("%d", &num);
        for (int i=0; i<num; i++){
            if (i == 0){
                new_data = (*ppList)->head;
            }else if (i ==1) {
                new_data = (*ppList)->tail;
                new_data->No = 2;
            }else{
                addBackDoubleList(ppList);
                new_data = (*ppList)->tail;
                new_data->No = i+1;
            }
            printf("Data ke - %d :\n", new_data->No);
            printf("Masukkan NIK :"); scanf(" %d", &new_data->NIK);
            printf("Masukkan Nama Lengkap :");
            scanf (" %[^\n]%*c",  &new_data->Nama);;
            printf("Masukkan Tempat Lahir :");
            scanf (" %[^\n]%*c", &new_data->Tempat);;
            printf("Masukkan Tanggal Lahir :");
            scanf(" %d", &new_data->Tanggal);
            printf("Masukkan Umur :");
            scanf(" %d", &new_data->Umur);
            printf("Masukkan Jenis Kelamin :");
            scanf (" %[^\n]%*c", &new_data->Jenis);;
            printf("Masukkan Golongan Darah :");
            scanf (" %[^\n]%*c", &new_data->Gol);;
            printf("Masukkan Status :");
            scanf (" %[^\n]%*c", &new_data->Status);;
            printf("Masukkan Pekerjaan :");
            scanf (" %[^\n]%*c", &new_data->Pekerjaan);;
        }
        printf("Apakah masih ingin memasukan data ? (y/n) : ");
        scanf("%c", &quit);
    }
}

void eraseFile(char *nama){
    FILE *fp;
    fp = fopen(nama, "w");
    fclose(fp);
}

#endif