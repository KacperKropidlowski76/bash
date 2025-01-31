#include <stdio.h>
#include <stdlib.h>

int main(){
FILE * file;
int number;
int najwieksza;
//int tab[] = {9, 3, 324, 12, 1, 123, 99, 125, 323, 420, 133, 371};
int najmniejsza = 1000;
//int dlg = sizeof(tab) / sizeof(tab[0]);

  file = fopen ("liczby.txt","r");
  if (file!=NULL)
  {
    
    while (fscanf(file, "%d", &number) == 1)
    {
    
        if (number > najwieksza)
        {
            najwieksza = number;
        }

        if (number < najmniejsza)
        {
            najmniejsza = number;
        }
    }
    
    
    printf("Najwieksza: %d\nNajmniejsza: %d", najwieksza, najmniejsza);
    fclose (file);
  //} else {
    //printf("Problem");
    return 0;
  } else {
    printf(stderr, "Blad", file);
  }
}
  
