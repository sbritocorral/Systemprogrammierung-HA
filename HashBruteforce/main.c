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


int main(int argc, char* argv[])
{
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

	/* CRACK THE FOLLOWING SHA256 HASH:

		fab6b3381ec4dc44084b23206f3a1e7ea3b2fb795a0e5e01e42f6cff11d4c175

	*/

    /* HIER KÖNNTE IHRE IMPLEMENTIERUNG STEHEN */

}
