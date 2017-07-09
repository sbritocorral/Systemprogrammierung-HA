#include "calculation.h"
#include <stdio.h>
#include <stdlib.h>

void calculateRestAnforderung(int ** gesamt, int ** belegungen, int ** rest,int processNumber , int betriebsMitellNumber){

    for(int x = 0; x< processNumber; x++)
    {
        for(int y = 0 ; y< betriebsMitellNumber ; y++)
        {
            rest[x][y] = gesamt[x][y] - belegungen[x][y];
        }
    }


}


void calculateFreeMatrix(int ** available, int ** belegungen,int ** freeMatrix,int processNumber , int betriebsMitellNumber){


    for(int y = 0; y<betriebsMitellNumber ; y++)
    {
        int temp = 0 ;
        for(int x = 0; x< processNumber ; x++)
        {
            temp = temp + belegungen[x][y];
        }
        freeMatrix[0][y] = available[0][y] - temp;   
    }


}


int calculateBankAlgo(int ** freeMatrixToCopy,int ** restMatrix,int ** belegtMatrix,int ** bankProof,int processNumber,int betriebsMitellNumber){

    int bo=0;

    int ** freeMatrix = malloc(sizeof(int * ) * 1);
    freeMatrix[0] = malloc(sizeof(int) * betriebsMitellNumber);

    for(int x = 0 ; x<betriebsMitellNumber ; x++)
    {
        freeMatrix[0][x] = freeMatrixToCopy[0][x];
    }

    int ** prevProof = malloc(sizeof(int * ) * (1));
        
    prevProof[0] =  malloc( processNumber * sizeof(int));
        



    
    
    initPrev(prevProof, betriebsMitellNumber, processNumber);

    //freePrev(prevProof,processNumber);
    

    //return 1 ; 
        
    while(1)
    {
        for(int x = 0 ; x<processNumber ; x++ )
        {
            int y = 0;

            if(bankProof[0][x] == 1)
            {

                continue;

            }


            //readFreeMatrix(freeMatrix,betriebsMitellNumber);
            //readRestMatrix(restMatrix,processNumber,betriebsMitellNumber);

            for(y = 0 ; y<betriebsMitellNumber ; y++)
            {
               if(restMatrix[x][y] > freeMatrix[0][y])
               {
                 bo=1; 
                 break;  
               } 
               
            }

            if(bo != 1){

               bankProof[0][x] = 1;

               //printf("Pude liberar uno !! : %d \n",x);

                for(int s =0; s<betriebsMitellNumber; s++){
                    freeMatrix[0][s] = freeMatrix[0][s] + belegtMatrix[x][s];
                }


                //readFreeMatrix(freeMatrix,betriebsMitellNumber);

                bo=0;
                break;
            }
            bo=0;
          
        }

        //readBankMatrix(bankProof,processNumber);

        if(test(bankProof, processNumber)){

            readRestMatrix(restMatrix,processNumber,betriebsMitellNumber);
            readFreeMatrix(freeMatrix,betriebsMitellNumber);
            
            freePrev(prevProof,processNumber);
            freeMatrixCopy(freeMatrix,betriebsMitellNumber);

            for(int x = 0; x<processNumber ; x++)
            {
                bankProof[0][x] = 0;
            }

            
            //readBelegungMatrix(belegtMatrix,processNumber,betriebsMitellNumber);



            return 1;
        }
 

        if(compare(prevProof, bankProof, betriebsMitellNumber, processNumber)){
            
            readRestMatrix(restMatrix,processNumber,betriebsMitellNumber);
            readFreeMatrix(freeMatrix,betriebsMitellNumber);
            
            freePrev(prevProof,processNumber);
            freeMatrixCopy(freeMatrix,betriebsMitellNumber);

             for(int x = 0; x<processNumber ; x++)
            {
                bankProof[0][x] = 0;
            }

            
            //readFreeMatrix(freeMatrix,betriebsMitellNumber);
            //readBelegungMatrix(belegtMatrix,processNumber,betriebsMitellNumber);

            return 0;
        }

        copy(prevProof, bankProof,betriebsMitellNumber,processNumber);

    }

    

    
}


int test (int ** bankProof, int processNumber){

    
    for(int x =0; x< processNumber; x++){

        if(bankProof[0][x] != 1){
           return 0; 
        }
    }

    return 1;
}



int calculateOperation(int * operation , int ** freeMatrix ,int ** gesamtMatrix, int ** belegungMatrix,int zuruck)
{
    

    
    
    if(zuruck == 0)
    {

        //printf("Esto es operation : %d",operation[0] );

        if(operation[0] == 65)
        {

        if(freeMatrix[0][operation[2]] >= operation[3])
        {
           //    gesamtMatrix[operation[1]][operation[2]] = gesamtMatrix[operation[1]][operation[2]] - operation[3];
            belegungMatrix[operation[1]][operation[2]] = belegungMatrix[operation[1]][operation[2]] + operation[3];
            return 1;
        }
        else{

            return 0;
        }
    }


    if(operation [0] == 82)
    {

         if(belegungMatrix[operation[1]][operation[2]] >= operation[3])
        {
            //printf("Entre aqui!!!\n");
            belegungMatrix[operation[1]][operation[2]] = belegungMatrix[operation[1]][operation[2]] - operation[3];
            freeMatrix[0][operation[2]] = freeMatrix[0][operation[2]] + operation[3];
            //printf("Esto es freematrix aqui adentro %d \n ",freeMatrix[0][operation[2]]);
            return 1;
        }
        else{

            return 0;
        }
    }

    }
    else{

     if(operation[0] == 65)
    {

        if(freeMatrix[0][operation[2]] < operation[3])
        {
            belegungMatrix[operation[1]][operation[2]] = belegungMatrix[operation[1]][operation[2]] - operation[3];
            return 1;
        }
        else{

            return 0;
        }
    }   

     if(operation [0] == 82)
    {
         if(belegungMatrix[operation[1]][operation[2]] < operation[3])
        {
            //printf("Me devuelvo\n");
            belegungMatrix[operation[1]][operation[2]] = belegungMatrix[operation[1]][operation[2]] + operation[3];
            freeMatrix[operation[0]][operation[2]] = freeMatrix[operation[0]][operation[2]] - operation[3];
            return 1;
        }
        else{

            return 0;
        }
    }



    }

    return 0;
}

int compare(int ** prevProof, int ** bankProof, int betriebsMitellNumber, int processNumber){

     
            for(int y = 0 ; y<processNumber ; y++)
            {
               
             if(prevProof[0][y] != bankProof[0][y]){
                 return 0;
             }

            }
        
        return 1;

}

void  copy(int ** prevProof, int ** bankProof, int betriebsMitellNumber, int processNumber){

    
     
            for(int y = 0 ; y<processNumber ; y++)
            {
             prevProof[0][y] = bankProof[0][y];
            }
        


}

void  initPrev(int ** prevProof,int betriebsMitellNumber, int processNumber){

    
   
            for(int y = 0 ; y<processNumber ; y++)
            {
             prevProof[0][y] = -1;
            }
        


}

void freePrev(int ** prev , int processNumber)
{
    
        
        free(prev[0]);
    

    free(prev);
}

void freeMatrixCopy(int ** copyMatrix , int betriebsMitellNumber)
{
    
        
        free(copyMatrix[0]);
    

    free(copyMatrix);
}


void readFreeMatrix(int ** matrix,int betriebsMitellNumber)
{

    printf("----------------FreeMatrix-----------------\n");
    for(int x = 0; x<betriebsMitellNumber; x++)
    {
        printf("%d ",matrix[0][x]);
    }
    printf("\n-----------------------------------------\n");

}

void readBankMatrix(int ** matrix,int processNumber)
{

    printf("----------------BankMatrix-----------------\n");
    for(int x = 0; x<processNumber; x++)
    {
        printf("%d ",matrix[0][x]);
    }
    printf("\n-----------------------------------------\n");

}

void readRestMatrix(int ** matrix,int processNumber,int betriebsMitellNumber)
{

    printf("----------------RestMatrix-----------------\n");
    for(int y = 0 ; y<processNumber ; y++)
    {
        for(int x = 0; x<betriebsMitellNumber; x++)
        {
            printf("%d ",matrix[y][x]);
        }
        printf("\n");
    }

    printf("\n-----------------------------------------\n");

}

void readBelegungMatrix(int ** matrix,int processNumber,int betriebsMitellNumber)
{

    printf("----------------RestMatrix-----------------\n");
    for(int y = 0 ; y<processNumber ; y++)
    {
        for(int x = 0; x<betriebsMitellNumber; x++)
        {
            printf("%d ",matrix[y][x]);
        }
        printf("\n");
    }

    printf("\n-----------------------------------------\n");

}

