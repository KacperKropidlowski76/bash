#include <stdio.h>
#include <stdlib.h>

int main(){
    int jd;
    printf("Podaj liczbe:");
    scanf("%d", &jd);
    FILE * fileDod;
    FILE * fileUje;
    int number;
    fileDod = fopen("dodatnie.txt","a");
    fileUje = fopen("ujemne.txt", "a");

    for (size_t i = 0; i < jd; i++)
    {
        scanf("%d", &number);
        if (number > 0)
        {
            fprintf(fileDod, "%d\n", number);
        } else if (number < 0)
        {
            fprintf(fileUje, "%d\n", number);
        } else {
            printf(stderr, "Blad");
        }
        
        
    }
    fclose(fileDod);
    fclose(fileUje);
}