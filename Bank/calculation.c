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


// int calculateBankAlgo(int ** freeMatrix,int ** restMatrix,int ** belegtMatrix,int ** bankProof,int processNumber,int betriebsMitellNumber){

//     int bo=0;

//     int prevProof[processNumber][betriebsMitellNumber];
    
//     initPrev(prevProof, betriebsMitellNumber, processNumber);
        
//     while(1)
//     {
//         for(int x = 0 ; x<processNumber ; x++ )
//         {
//             for(int y = 0 ; y<betriebsMitellNumber ; y++)
//             {
//                if(restMatrix[x][y] > freeMatrix[0][y])
//                {
//                  bo=1; 
//                  break;  
//                } 
               
//             }

//             if(bo != 1){

//                 bankProof[0][y] = 1;
//                 freeMatrix[0][y] = freeMatrix[0][y] + belegtMatrix[x][y];

//                 bo=0;
//                 break;
//             }
//         }

//         if(test(bankProof, betriebsMitellNumber)){
//             return 1;
//         }
 

//         if(compare(prevProof, bankProof, betriebsMitellNumber, processNumber)){
//             return 0;
//         }

//         copy(prevProof, bankProof);

//     }

    
// }


// int test (int ** bankProof, int betriebsMitellNumber){

    
//     for(int x =0; x< betriebsMitellNumber; x++){

//         if(bankProof[0][x] != 1){
//            return 0; 
//         }
//     }

//     return 1;
// }


// int compare(int ** prevProof, int ** bankProof, int betriebsMitellNumber, int processNumber){

//      for(int x = 0 ; x<processNumber ; x++ )
//         {
//             for(int y = 0 ; y<betriebsMitellNumber ; y++)
//             {
               
//              if(prevProof[x][y] != bankProof[x][y]){
//                  return 0;
//              }

//             }
//         }
//         return 1;

// }

// void  copy(int ** prevProof, int ** bankProof, int betriebsMitellNumber, int processNumber){

    
//      for(int x = 0 ; x<processNumber ; x++ )
//         {
//             for(int y = 0 ; y<betriebsMitellNumber ; y++)
//             {
//              prevProof[x][y] = bankProof[x][y];
//             }
//         }


// }

// void  initPrev(int ** prevProof,int betriebsMitellNumber, int processNumber){

    
//      for(int x = 0 ; x<processNumber ; x++ )
//         {
//             for(int y = 0 ; y<betriebsMitellNumber ; y++)
//             {
//              prevProof[x][y] = -1;
//             }
//         }


// }
