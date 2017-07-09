#include<stdio.h>
#include <stdlib.h>
#include "calculation.h"
#include "printer.h"

int main(int argc, char *argv[] )
{

   
    if(argc <= 2)
    {
        printf("You have to give the input file as first parameter and output file as second parameter\n");
        return 1;
    }


   FILE * outFile = fopen(argv[2],"w");

   file * workFile = openFile(argv[1]);


    information * info = getParsedInformation(workFile);


   calculateRestAnforderung(info->gesamtAnforderungenMatrix,info->aktuelleBelegungenMatrix,info->restAnforderung,info->processNumber,info->betriebsMitellNumber);
   calculateFreeMatrix(info->memoryAvalible,info->aktuelleBelegungenMatrix,info->freeMemoryAfter,info->processNumber,info->betriebsMitellNumber);
   int sicher = calculateBankAlgo(info->freeMemoryAfter,info->restAnforderung,info->aktuelleBelegungenMatrix,info->bankProof,info->processNumber,info->betriebsMitellNumber);
   
   printActualState(info,sicher,outFile);

   if(sicher)
   {



    for(int x =0 ; x< info->countOperation - 1 ; x++)
   {



    int allow = calculateOperation(info->operationen[x],info->freeMemoryAfter,info->gesamtAnforderungenMatrix,info->aktuelleBelegungenMatrix, 0);
    
    


    if(allow == 1)
    {

        if(info->operationen[x][0] == 65)
        {
            calculateRestAnforderung(info->gesamtAnforderungenMatrix,info->aktuelleBelegungenMatrix,info->restAnforderung,info->processNumber,info->betriebsMitellNumber);
        }
        
        calculateFreeMatrix(info->memoryAvalible,info->aktuelleBelegungenMatrix,info->freeMemoryAfter,info->processNumber,info->betriebsMitellNumber);
        int sicher = calculateBankAlgo(info->freeMemoryAfter,info->restAnforderung,info->aktuelleBelegungenMatrix,info->bankProof,info->processNumber,info->betriebsMitellNumber);
        printf("Esto es operation : %c %d %d %d \n", info->operationen[x][0],info->operationen[x][1],info->operationen[x][2],info->operationen[x][3] );
        printf("Esto es sicher : %d\n",sicher);

        if(sicher)
        {

            printActualOperationState(info,info->operationen[x],outFile);

        }
        else{

            calculateOperation(info->operationen[x],info->freeMemoryAfter,info->gesamtAnforderungenMatrix,info->aktuelleBelegungenMatrix, 1);
            calculateRestAnforderung(info->gesamtAnforderungenMatrix,info->aktuelleBelegungenMatrix,info->restAnforderung,info->processNumber,info->betriebsMitellNumber);
            calculateFreeMatrix(info->memoryAvalible,info->aktuelleBelegungenMatrix,info->freeMemoryAfter,info->processNumber,info->betriebsMitellNumber);
            
        }

    }

   }


   }

   fclose(outFile);

    freeInfo(info);
    freeFile(workFile);


    return 0;


}


