#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "main.h"
#include "utils.h"
#include "bruteforce.h"

pid_t pid,wpid;


//callback um die prozesse zu killen
void signalProcessing(int signal)
{
    kill(0, SIGINT);
    
}



int main(int argc, char* argv[])
{

    int status = 0;
    // Process Commandline arguments
    if(argc != 5 || !strcmp("-h", argv[1]) || !strcmp("--help", argv[1]))
    {
        printf("\nUsage: %s <sha256 hash> <process count> <min> <max>\n\n", argv[0]);
        printf("\t\t<sha256 hash>  \t = 64 character long hex character sequence\n");
        printf("\t\t<process count>\t = Number of processes to split workload to\n");
        printf("\t\t<min>          \t = lowest number of cleartext length\n");
        printf("\t\t<max>          \t = highest number of cleartext length\n\n");
        return 0;
    }

    process_count = atoi(argv[2]);
    min_password_length = atoi(argv[3]);
    max_password_length = atoi(argv[4]);

    int processing = -1;

	/* CRACK THE FOLLOWING SHA256 HASH:

		fab6b3381ec4dc44084b23206f3a1e7ea3b2fb795a0e5e01e42f6cff11d4c175

	*/

    /* HIER KÖNNTE IHRE IMPLEMENTIERUNG STEHEN */

    

    //definiert die callback
    signal(SIGALRM,signalProcessing);

    int z = 0;
    int IDProcess = 0 ;
    
    
    //definiert die variablen wo die arbeit gespeichert wird
    char  **bounds = malloc(sizeof(char *) * (process_count + 1));
    //definirt dynamisch die hash 
    char * target = malloc(strlen(argv[1]) + 1);
    strcpy(target,argv[1]);

    //aufteilung der arbeit abhaengig zu den prozess anzahl 
    split_work(bounds,26/process_count);

   printf("I am cracking the password!\n")

    while(z < process_count)
    {
        processing++;
        IDProcess++;
        pid = fork(); // Neue prozess erstellen und damit raus gehen.
        
        if(pid == 0) break;
        
        z++;
    }

    if(pid!=0)
    {
        //warten auf alle prozessen
      while((wpid = wait(&status)) > 0);
    }
   
    if(pid == 0 )
    {  
        //Bruteforce anfangen
        char *result = brute(argv[1],bounds[processing],bounds[processing + 1]);

         if(result == NULL)
        {

           
            exit(0);
        }

        if(result != NULL)
        {
            printf("I Cracked it!!! : %s\n",result);
            //sageb den Eltern , dass ich fertig bin
            kill(getppid(),SIGALRM);
            
        }

       
    
    }

    
    

return 0;

}



