#include <stdio.h>
#include "printer.h"
#include <stdlib.h>

void printActualState(information * info){

    printf("Prozesse:  %d / Betriebsmittel:  %d\n\n",info->processNumber,info->betriebsMitellNumber);

    printf("Gesamtanforderungen:\n");
    for(int x = 0; x< info->processNumber ; x++)
    {
        int y;
        for( y = 0 ; y<info->betriebsMitellNumber - 1 ; y++)
        {
            printf(" %d ",info->gesamtAnforderungenMatrix[x][y]);
        }
        printf(" %d",info->gesamtAnforderungenMatrix[x][y]);
        printf("\n");
    }

    printf("\n");

    printf("Belegungen:\n");
    for(int x = 0; x< info->processNumber ; x++)
    {
        int y;
        for( y = 0 ; y<info->betriebsMitellNumber - 1 ; y++)
        {
            printf(" %d ",info->aktuelleBelegungenMatrix[x][y]);
        }
        printf(" %d",info->aktuelleBelegungenMatrix[x][y]);
        printf("\n");
    }

    printf("\n");

    printf("verfügbar: ");
    int n = 0;
    for( n = 0; n< info->betriebsMitellNumber - 1; n++)
    {
        printf(" %d ",info->memoryAvalible[0][n]);
    }
    printf(" %d",info->memoryAvalible[0][n]);
    printf("\n\n");

    printf("Restanforderungen:\n");
    for(int x = 0; x< info->processNumber ; x++)
    {
        int y;
        for( y = 0 ; y<info->betriebsMitellNumber - 1 ; y++)
        {
            printf(" %d ",info->restAnforderung[x][y]);
        }
        printf(" %d",info->restAnforderung[x][y]);
        printf("\n");
    }

    printf("\n");

    printf("frei: ");
    n = 0;
    for( n = 0; n< info->betriebsMitellNumber - 1; n++)
    {
        printf(" %d ",info->freeMemoryAfter[0][n]);
    }
    printf(" %d",info->freeMemoryAfter[0][n]);
    printf("\n\n");
    

}