#include <stdio.h>
#include <stdlib.h>

struct masina{

    char marca[30];
    char culoare[30];
    int nr_inmatriculare;
    int nr_loc_parcare;

}lista[50], aux;

void citire (int n){

    int i;
    for(i=1; i<=n; i++)
    {
        printf("Masina %d: \n", i);
        printf("Marca masinii:");
        scanf("%s", &lista[i].marca);
        printf("Culoare masinii:");
        scanf("%s", &lista[i].culoare);
        printf("Numarul de inmatriculare:");
        scanf("%d", &lista[i].nr_inmatriculare);
        printf("Numarul locului de parcare din intervalul 1-30:");
        scanf("%d", &lista[i].nr_loc_parcare);
    }
}

void ordonare_marca(int n){

    int i, c;
    for (i=1; i<=n; i++)
    {

            c=strcmp(lista[i].marca,lista[i+1].marca);
            if (c>0){
                aux=lista[i];
                lista[i]=lista[i+1];
                lista[i+1]=aux;
            }
    }

    printf("\n Afisara tuturor masinilor dupa marca:\n");
    for (i=1; i<=n; i++)
         printf("Numarul masinii:%d Marca:%s Culoarea:%s \n", lista[i].nr_inmatriculare, lista[i].marca, lista[i].culoare);
}

void locuri_parcare(int n){

    int i;
    do{
        for(i=0;i<n-1;i++)
            if(lista[i].nr_loc_parcare){
            aux=lista[i];
            lista[i]=lista[i+1];
            lista[i+1]=aux;
            printf("%d", aux);
        }
    }while();
}

void cautare(int n){

    int i, nr;
    printf("Introduceti numarul de inmatriculare al masinii pe care vreti sa o gasiti: ");
    scanf("%d", &nr);
    for(i=0;i<n;i++){
        if(lista[i].nr_inmatriculare == nr)
            printf("Numarul masinii:%d Marca:%s Culoarea:%s \n", lista[i].nr_inmatriculare, lista[i].marca, lista[i].culoare);
        else
            printf("Nu exista masina cu acel numar in parcare.");
    }
}

int main()
{
    FILE *f;
    int n;
    cautare(n);
    printf("Locuri de parcare din intervalul 1-30:");
    scanf("%d", &n);
    if(n>=1 || n<=30)
        citire(n);
        if((f=fopen("fisier.dat", "wb"))==NULL){
            printf("eroare la deschidere\n");
            exit(1);
        }
        fwrite(&n,sizeof(int), 1,f);
        for(int i=0;i<n;i++){
        printf("Numarul masinii:%d Marca:%s Culoarea:%s \n", lista[i].nr_inmatriculare, lista[i].marca, lista[i].culoare);
        }
        fwrite(&lista,sizeof(aux), n,f);
        fclose(f);
        if((f=fopen("fisier.dat", "rb"))==NULL)
        {
            printf("eroare la deschidere\n");
            exit(1);
        }
        fclose(f);
        getch();
        cautare(n);
    return 0;
}
