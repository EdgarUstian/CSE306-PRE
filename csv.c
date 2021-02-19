#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 3 || argc == 5 || argc == 6){
        FILE *fp = fopen(argv[argc - 1], "r");
        if (fp == NULL){
            return EXIT_FAILURE;
        }
        if (argc == 3){
            //open file and count fields or records
            if (argv[2] == "-f"){
                char *line = NULL;
                //dont know 2nd argument should be a size
                fgets(line, ,fp);
                char *field = strtok(line, ",");
                int fieldnum = 1;
                while (field != NULL){
                    fieldnum += 1;
                    field = strtok(NULL, ",");
                }
                printf("%d",fieldnum);
            }
            
            else if (argv[2] == "-r"){
                
            }
            else {
                return EXIT_FAILURE
            }
        }
        else if (argc == 5){
            //open file and check min/max/mean
        }
        else if (argc == 6){
            //open file and check record
        }
    }
    else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int min(char *field){
    
}

int max(char *field){

}

int mean(char *field){
    
}
