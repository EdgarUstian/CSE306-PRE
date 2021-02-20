#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //open file first
    FILE *fp = fopen(argv[argc - 1], "r");
    if (fp == NULL)
    {
        return EXIT_FAILURE;
    }
    printf("File opened\n");
    //array of arguments
    int iter;
    for (iter = 1; iter < argc - 1; iter++ ){
        printf("In the for loop %d\n", iter);
        printf("Arg %s\n", argv[iter]);
        char *f = "-f";
        printf("Arg %s\n", f);
        if (argv[iter] == "-f"){
            printf("entered -f\n");
            //get first line of array and split on commas
            char *line = NULL;
            size_t z = 0;
            getline(&line, &z, fp);
            int fields = 1;
            char *field;
            field = strtok(line, ",");
            while (field != NULL){
                fields += 1;
                field = strtok(NULL, ",");
            }
            printf("%d\n", fields);
        }
        if (argv[iter] == "-r"){
            int records = 1;
            char *line = NULL;
            size_t z = 0;
            ssize_t bytesread;
            while ((bytesread = getline(&line, &z, fp)) != -1){
                char *record = strtok(line, ",");
                while (record != NULL){
                    records += 1;
                    record = strtok(NULL, ",");
                }
            }
            printf("%d\n", records);
        }
        if (argv[iter] == "-h"){
            char *m = argv[iter + 1];
            char *targetfield = argv[iter + 2];
            char *line = NULL;
            size_t z = 0;
            getline(&line, &z, fp);
            int targetnum;
            int num = 0;
            char *field = strtok(line, ",");
            while (field != NULL){
                field = strtok(NULL, ",");
                if (field == targetfield){
                    targetnum = num;
                }
                num += 1;
            }
            if (m == "-min"){
                ssize_t bytesread;
                int lowest = 10000000;
                while ((bytesread = getline(&line, &z, fp)) != -1){
                    char *record = strtok(line, ",");
                    int fieldcount = 0;
                    while (record != NULL){
                        if (fieldcount == targetnum){
                            if (atoi(record) < lowest){
                                lowest = atoi(record);
                            }
                        }
                        fieldcount += 1;
                        record = strtok(NULL, ",");
                    }
                }
                printf("%d\n", lowest);
            }
            if (m == "-max"){
                ssize_t bytesread;
                int highest = 0;
                while ((bytesread = getline(&line, &z, fp)) != -1){
                    char *record = strtok(line, ",");
                    int fieldcount = 0;
                    while (record != NULL){
                        if (fieldcount == targetnum){
                            if (atoi(record) > highest){
                                highest = atoi(record);
                            }
                        }
                        fieldcount += 1;
                        record = strtok(NULL, ",");
                    }
                }
                printf("%d\n", highest);
            }
            if (m == "-mean"){
                ssize_t bytesread;
                int sum = 0;
                int fieldcount = 0;
                while ((bytesread = getline(&line, &z, fp)) != -1){
                    char *record = strtok(line, ",");
                    while (record != NULL){
                        if (fieldcount == targetnum){
                            sum += atoi(record);
                        }
                        fieldcount += 1;
                        record = strtok(NULL, ",");
                    }
                }
                printf("%d\n", sum/fieldcount);
            }
        }
    }
    return EXIT_SUCCESS;
}
