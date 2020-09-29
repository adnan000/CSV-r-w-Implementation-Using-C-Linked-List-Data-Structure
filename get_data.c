/* 	EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 
* 	Modul 				: 2
* 	Percobaan 			: 3 
* 	Hari dan Tanggal 	: Rabu, 12 Februari 2020
*	Nama (NIM) 			: Muhammad Adnan (13218019) 
* 	Asisten (NIM) 		: Rizki Ardi M (13217054) 
* 	Nama File 			: 13218019_2_3.c 
* 	Deskripsi 			: Strings and External Files
*/
#include <stdio.h>
#include <string.h>
FILE *data;
FILE *data2;
char buff[1], *token , nama[12];
int i , n , kolom;
double a, b;

int main() {
	printf("Masukkan nama file csv : ");
	scanf("%s", &nama);
	data=fopen(nama,"r");
	while (fscanf(data, "%s", buff) != EOF){
		n++;
	}
	fclose(data);
	n--;
	int x[50], y[50];
	data2=fopen(nama,"r");
	for (i=0; i<50; i++){
		fscanf(data2, "%s", buff);
		token = strtok(buff, ",");
		kolom=1;
		while (token != NULL){
			printf("%c", *token);
			if (token!="x" && token!="y"){
				if (kolom%2!=0){
					x[i-1]=atoi(token);
				}else
					y[i-1]=atoi(token);
			}
			token = strtok(NULL, ",");
			kolom++;
		}		
	}
	fclose(data2);
	double e=0, f=0 ,g=0 ,h=0;
	for (i=0 ; i<n ; i++){
		e += x[i]*y[i];
		f += x[i];
		g += y[i];
		h += x[i]*x[i];
	}
	printf("%lf\n%lf\n%lf\n%lf\n", e,f,g,h);
	b = (n*e - f*g)/(n*h - f*f);
	a = (g - b*f)/n;
	printf("%lf\n", b);
	printf("Persamaan regresi adalah y = %.2lfx + %.2lf", b, a);
	
	return 0;
}
