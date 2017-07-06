#include<stdio.h>
#include <stdlib.h>
#include "calculation.h"
#include "printer.h"

int main()
{

    file * workFile = openFile("inputs/a_b_in.txt");

 

    information * info = getParsedInformation(workFile);


    calculateRestAnforderung(info->gesamtAnforderungenMatrix,info->aktuelleBelegungenMatrix,info->restAnforderung,info->processNumber,info->betriebsMitellNumber);
    calculateFreeMatrix(info->memoryAvalible,info->aktuelleBelegungenMatrix,info->freeMemoryAfter,info->processNumber,info->betriebsMitellNumber);
    
    printActualState(info);
    


    freeInfo(info);
    freeFile(workFile);


    return 0;


}