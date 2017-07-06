#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void freeFile(file * fileToFree)
{
    free(fileToFree->fileInfo);
    free(fileToFree);
}

file * openFile(char * path)
{

    FILE * f = fopen(path,"r");

    file * fileTemp = malloc(sizeof(file));

    char lineGetter[255];


    fileTemp->fileLines = 0;
    fileTemp->fileSize = 0 ;

    while(fgets(lineGetter, 255, f))
    {

        fileTemp->fileLines++;
        fileTemp->fileSize = fileTemp->fileSize + strlen(lineGetter);

    }

    fileTemp->fileSize++;
    //printf("Estos son las lineas %ld" , fileTemp->fileLines );
    //printf("Estos son las size %ld" , fileTemp->fileSize );


    fileTemp->fileInfo = (char *) malloc(fileTemp->fileLines + fileTemp->fileSize );

    fileTemp->fileInfo[fileTemp->fileSize] = '\0';

    rewind(f);
    long position = 0 ;
    while(!feof(f))
    {
            fileTemp->fileInfo[position] = fgetc(f);
            position++;
    }

    fclose(f);


    return fileTemp;

}


information * getParsedInformation(file * fileToParse){
 
    const char * delim = "\n";

    information * info = malloc(sizeof(information));

    char * tempFileInfo = malloc(strlen(fileToParse->fileInfo) + 1);

    strncpy(tempFileInfo,fileToParse->fileInfo , strlen(fileToParse->fileInfo) + 1);

    char * token = strtok(tempFileInfo,delim);

    char ** infoToParse = malloc(sizeof(char * ) * (fileToParse->fileLines));

    int counter = 0;
    while(token != NULL)
    {
        infoToParse[counter] = malloc(sizeof(char) * (strlen(token) + 1));
        strncpy(infoToParse[counter],token,strlen(token) + 1);
        token = strtok(NULL,delim);
        counter++;
      
    }
     free(tempFileInfo);

   int pN = getInfoNumber(infoToParse[0]);
   int bN = getInfoNumber(infoToParse[1]);
    
    info->processNumber = pN;
    info->betriebsMitellNumber = bN;

    info->gesamtAnforderungenMatrix = NULL;
    
    info->gesamtAnforderungenMatrix = createMatrix(info->processNumber,info->betriebsMitellNumber);
    info->aktuelleBelegungenMatrix = createMatrix(info->processNumber,info->betriebsMitellNumber);
    info->memoryAvalible = createMatrix(1,info->betriebsMitellNumber);
    info->freeMemoryAfter = createMatrix(1,info->betriebsMitellNumber);
   // info->bankProof = createMatrix(1,info->processNumber);
    info->restAnforderung = createMatrix(info->processNumber,info->betriebsMitellNumber);
    

    int calculation = 2;
    

     parsingMatrixByReference(info->gesamtAnforderungenMatrix,infoToParse,calculation,calculation + info->processNumber);
     calculation = calculation + info->processNumber;
    
     parsingMatrixByReference(info->aktuelleBelegungenMatrix,infoToParse,calculation,calculation + info->processNumber);
     calculation = calculation + info->processNumber;

     parsingMatrixByReference(info->memoryAvalible,infoToParse,calculation,calculation + 1);
     calculation++;

    freeParserInformation(infoToParse,counter);
   
    counter = 0;

    return info;

}

void parsingMatrixByReference(int ** matrix,char ** information, int init,int final){
    



    for(int x = init ; x< final ; x++)
    {
        const char * delim = " ";
        int  y = 0;
        //printf("Esto es lo que se va a parsear info : %s\n",information[x] );
        char * token = strtok(information[x],delim);

        
        while(token != NULL)
        {


            if(token[0] >= 48 && token[0] <= 57)
            {

                // printf("Esto es token !!! : %d \n",atoi(token)); 
                // printf("Esto es x menos init %d \n",x-init);
                // printf("Esto es y :  %d\n" , y );
                // printf("\n");
                matrix[x-init][y] = atoi(token);
                y++;

            }
           
          
           token = strtok(NULL,delim);
           
        }
    }

}

int ** createMatrix(int column,int row){

    int ** matrix = malloc(sizeof(int * ) * (column));

     for(int x = 0 ; x< column ; x++)
    {
        
            matrix[x] =  malloc( row * sizeof(int));
        
    }

    return matrix;
}

void freeParserInformation(char ** info,int infoLongitude){

    for(int x = 0 ; x<infoLongitude ; x++)
    {
        free(info[x]);
    }

    free(info);

}

int getInfoNumber(char * info)
{
    int number = -1;

    const char * delim = " ";

    int length = strlen(info) + 1;

    char temp[length];

    strncpy(temp,info,strlen(info) + 1);

    char * token = strtok(temp,delim);

    while(token != NULL)
    {
        int temp = atoi(token);
        if(temp!= 0)
        {
            number = temp;
        }

        token = strtok(NULL,delim);
    }

    return number;

}

void freeInfo(information * info)
{
    freeMatrix(info->processNumber,info->betriebsMitellNumber,info->gesamtAnforderungenMatrix);

    freeMatrix(info->processNumber,info->betriebsMitellNumber,info->aktuelleBelegungenMatrix);

    freeMatrix(info->processNumber,info->betriebsMitellNumber,info->restAnforderung);

    freeMatrix(1,0,info->memoryAvalible);

    freeMatrix(1,0,info->freeMemoryAfter);

    //freeMatrix(1,0,info->bankProof);
        
    free(info);
}


void freeMatrix(int column,int rows , int ** matrix){

    for(int x = 0 ; x<column  ; x++)
    {
        
        free(matrix[x]);
    }

    free(matrix);

}


// void  initMatrix(int ** prevProof,int betriebsMitellNumber, int processNumber){

    
//      for(int x = 0 ; x<processNumber ; x++ )
//         {
//             for(int y = 0 ; y<betriebsMitellNumber ; y++)
//             {
//              prevProof[x][y] = -1;
//             }
//         }


// }

