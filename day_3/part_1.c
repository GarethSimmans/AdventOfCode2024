#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int check(char buffer[]){
    int first = 0;
    int second = 0;
    char first_buffer[3] = {0};
    char second_buffer[3] = {0};
    int count = 0;

    char *ptr = strstr(buffer, "mul(");
    ptr[0] = 'c';
    for (int i = 0; i < 4; i++){
        count++;
        if (ptr[4+i] == ','){
            first = atoi(first_buffer);
            if (first != 0 && first < 1000)
                break;
            else{
                return 0;
            }
        }
        if (isdigit(ptr[4+i])){
            first_buffer[i] = ptr[4+i];
        }
        else{
            return 0;
        }
    }

    for (int i = 0; i < 4; i++){
        if (ptr[4+count+i] == ')'){
            second = atoi(second_buffer);
            if (second != 0 && first < 1000){
                return first * second;
            }
            else{
                return 0;
            }
        }
        if (isdigit(ptr[4+count+i])){
            second_buffer[i] = ptr[4+count+i];
        }
        else{
            return 0;
        }
    }
}


int main(){
    FILE *fp = fopen("input.txt","r");
    char buffer[10000] = {0};
    int index = 0;
    unsigned long total = 0;

    while(1){
        char ch = fgetc(fp);
        if (ch == EOF)
            break;
        if (ch == '\n'){
            while (strstr(buffer, "mul(") != NULL)
                total += check(buffer);
            memset(buffer, 0, 1000);
            index = 0;
        }
        else{
            buffer[index] = ch;
            index++;
        }
    }
    printf("Total: %lu\n", total);
}



