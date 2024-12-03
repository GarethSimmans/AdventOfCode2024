#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Doesn't work missing some safe data

int check(int* previous,int current, int increasing, int* tolerance, int* catch);

int main(){
    char buffer[30] = {0};
    int index = 0;
    FILE *fp = fopen("input.txt","r");
    unsigned int previous = 0;
    unsigned int current = 0;
    int increasing = 0;
    unsigned long safe = 0;
    int tolerance = 0;
    int catch = 0;

    while(1){
        char ch = getc(fp);
        if (ch == EOF)
            break;
        else if (ch == '\n'){
            current = atol(buffer);
            index = 0;
            memset(buffer, 0, 30);
            //printf("Current: %d\n", current);
            //printf("Previous: %d\n", previous);
            increasing = check(&previous, current, increasing, &tolerance, &catch);
            //printf("increasing: %d\n", increasing);
            if (increasing != -1){
                safe++;
                printf("Safe\n");
            }
            else
                printf("unsafe\n");
            increasing = 0;
            previous = 0;
            tolerance = 0;
            catch = 0;
        }
        else if (ch == ' '){
            current = atol(buffer);
            index = 0;
            memset(buffer, 0, 30);
            //printf("Current: %d\n", current);
            //printf("Previous: %d\n", previous);
            //printf("Catch: %d\n", catch);
            //printf("Tolerance: %d\n", tolerance);
            if (increasing == 0 && tolerance == 1){
                //printf("Entered Catch\n");
                int temp_catch = catch;
                int temp_tolerance = tolerance;
                if (check(&catch, current, increasing, &tolerance, &catch) != -1){
                    //printf("Catch succesful\n");
                    previous = temp_catch;
                }
                else
                    tolerance = temp_tolerance;
            }
            increasing = check(&previous, current, increasing, &tolerance, &catch);
            //printf("increasing: %d\n", increasing);
        }
        buffer[index] = ch;
        index++;
    }
    printf("Safe: %lu\n", safe);
}

int check(int* previous,int current, int increasing, int* tolerance, int* catch){
    if (increasing == -1)
        return -1;
    if ((*previous) == 0){
        *previous = current;
        return 0;
    }
    if (current - (*previous) <= 3 && current - (*previous) >= 1){
        if (increasing == 0){
            *previous = current;
            return 1;
        }
        if (increasing == 2){
            if ((*tolerance) < 1){
                (*tolerance)++;
                *catch = current;
                return increasing;
            }
            return -1;
        }
        else{
            *previous = current;
            return 1;
        }
    }
    if ((*previous) - current <= 3 && (*previous) - current >= 1){
        if (increasing == 0){
            *previous = current;
            return 2;
        }
       if (increasing == 1){
            if ((*tolerance) < 1){
                (*tolerance)++;
                *catch = current;
                return increasing;
            }
            return -1;
        }
       else{
           *previous = current;
           return 2;
       }
    }
    else{
        if ((*tolerance) < 1){
            (*tolerance)++;
            *catch = current;
            return increasing;
        }
        return -1;
    }
}

