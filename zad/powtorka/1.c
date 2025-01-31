#include <stdio.h>
#include <stdlib.h>

int main(){
FILE * file;
int najwieksza;
int number;
int najmniejsza = 1000;
file = fopen ("liczby.txt","r");
while (fscanf(file, "%d", &number) == 1){
    if (najwieksza < number){
        najwieksza = number;
    } else if (number < najmniejsza)
    {
        najmniejsza = number;
    }
    
}

    printf("Najwieksza: %d\nNajmniejsza: %d", najwieksza, najmniejsza);
fclose(file);
}