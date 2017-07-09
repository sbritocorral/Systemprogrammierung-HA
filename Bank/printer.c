#include <stdio.h>
#include "printer.h"
#include <stdlib.h>

void printActualState(information * info, int sicher, FILE * fp){

    fprintf(fp,"Prozesse:  %d / Betriebsmittel:  %d\n\n",info->processNumber,info->betriebsMitellNumber);

    fprintf(fp,"Gesamtanforderungen:\n");
    for(int x = 0; x< info->processNumber ; x++)
    {
        int y;
        for( y = 0 ; y<info->betriebsMitellNumber - 1 ; y++)
        {
            fprintf(fp," %d ",info->gesamtAnforderungenMatrix[x][y]);
        }
        fprintf(fp," %d",info->gesamtAnforderungenMatrix[x][y]);
        fprintf(fp,"\n");
    }

    fprintf(fp,"\n");

    fprintf(fp,"Belegungen:\n");
    for(int x = 0; x< info->processNumber ; x++)
    {
        int y;
        for( y = 0 ; y<info->betriebsMitellNumber - 1 ; y++)
        {
            fprintf(fp," %d ",info->aktuelleBelegungenMatrix[x][y]);
        }
        fprintf(fp," %d",info->aktuelleBelegungenMatrix[x][y]);
        fprintf(fp,"\n");
    }

    fprintf(fp,"\n");

    fprintf(fp,"verfügbar: ");
    int n = 0;
    for( n = 0; n< info->betriebsMitellNumber - 1; n++)
    {
        fprintf(fp," %d ",info->memoryAvalible[0][n]);
    }
    fprintf(fp," %d",info->memoryAvalible[0][n]);
    fprintf(fp,"\n\n");

    fprintf(fp,"Restanforderungen:\n");
    for(int x = 0; x< info->processNumber ; x++)
    {
        int y;
        for( y = 0 ; y<info->betriebsMitellNumber - 1 ; y++)
        {
            fprintf(fp," %d ",info->restAnforderung[x][y]);
        }
        fprintf(fp," %d",info->restAnforderung[x][y]);
        fprintf(fp,"\n");
    }

    fprintf(fp,"\n");

    fprintf(fp,"frei: ");
    n = 0;
    for( n = 0; n< info->betriebsMitellNumber - 1; n++)
    {
        fprintf(fp," %d ",info->freeMemoryAfter[0][n]);
    }
    fprintf(fp," %d",info->freeMemoryAfter[0][n]);
    fprintf(fp,"\n\n");

    if(sicher)
    {
        fprintf(fp,"SICHER\n");
    }
    else{
        fprintf(fp,"UNSICHER\n");
    }
    

}

void printActualOperationState(information * info , int * operation,FILE * fp)
{

    fprintf(fp,"Operation: %c %d %d %d\n\n",operation[0],operation[1],operation[2],operation[3]);

     fprintf(fp,"Restanforderungen:\n");
    for(int x = 0; x< info->processNumber ; x++)
    {
        int y;
        for( y = 0 ; y<info->betriebsMitellNumber - 1 ; y++)
        {
            fprintf(fp," %d ",info->restAnforderung[x][y]);
        }
        fprintf(fp," %d",info->restAnforderung[x][y]);
        fprintf(fp,"\n");
    }
    fprintf(fp,"\n");

    int n = 0;
    fprintf(fp,"f: ");
    for(n = 0; n< info->betriebsMitellNumber - 1; n++)
    {
        fprintf(fp," %d ",info->freeMemoryAfter[0][n]);
    }
    fprintf(fp," %d",info->freeMemoryAfter[0][n]);
    fprintf(fp,"\n\n");



}