#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int check(int* previous,int current, int increasing);

int main(){
    char buffer[20];
    int index = 0;
    FILE *fp = fopen("input.txt","r");
    unsigned int previous = 0;
    unsigned int current = 0;
    int increasing = 0;
    unsigned long safe = 0;

    while(1){
        char ch = getc(fp);
        if (ch == EOF)
            break;
        else if (ch == '\n'){
            current = atol(buffer);
            index = 0;
            memset(buffer, 0, 20);
            increasing = check(&previous, current, increasing);
            if (increasing != -1)
                safe++;
            increasing = 0;
            previous = 0;
        }
        else if (ch == ' '){
            current = atol(buffer);
            index = 0;
            memset(buffer, 0, 20);
            increasing = check(&previous, current, increasing);
        }
        buffer[index] = ch;
        index++;
    }
    printf("Safe: %lu\n", safe);
}

int check(int* previous,int current, int increasing){
    if (increasing == -1)
        return -1;
    else if ((*previous) == 0){
        *previous = current;
        return 0;
    }
    if (current > (*previous) && current - (*previous) <= 3){
        if (increasing == 0){
            *previous = current;
            return 1;
        }
        if (increasing != 1)
            return -1;
        else{
            *previous = current;
            return 1;
        }
    }
    else if (current < (*previous) && (*previous) - current <= 3){
        if (increasing == 0){
            *previous = current;
            return 2;
        }
       if (increasing != 2)
            return -1;
       else{
           *previous = current;
           return 2;
       }
    }
    else
        return -1;
}
