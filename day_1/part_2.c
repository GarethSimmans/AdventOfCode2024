#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readinput(int left_array[1000], int right_array[1000]);

int main(){
    int left_array[1000] = {0};
    int right_array[1000] = {0};
    int size = sizeof(left_array)/sizeof(left_array[0]);
    unsigned long similarity = 0;


    readinput(left_array, right_array);


    for (int i = 0; i < size; i++){
        int check = left_array[i];
        int num_of_times = 0;
        for (int j = 0; j < size; j++){
            if (right_array[j] == check)
                num_of_times++;
        }
        similarity += check * num_of_times;
    }
    printf("Total: %d\n", similarity);
}

void readinput(int left_array[1000], int right_array[1000]){
    FILE *fp = fopen("input.txt", "r");
    int left_index = 0;
    int right_index = 0;
    char buffer[12];
    int index = 0;
    unsigned int left = 0;
    unsigned int right = 0;
    int swap = 0;
    unsigned int result = 0;

    while(1){
        char ch = getc(fp);
        if (ch == EOF){
                break;
        }
        if (ch == ' ' || ch == '\n'){
            if (swap == 0){
                if (!atol(buffer))
                        continue;
                left = atol(buffer);
                left_array[left_index] = left;
                left_index++;
                swap = 1;
                memset(buffer, 0, 12);
                index = 0;
            }
            if (swap == 1){
                if (!atol(buffer))
                        continue;
                right = atol(buffer);
                right_array[right_index] = right;
                right_index++;
                swap = 0;
                memset(buffer, 0, 12);
                index = 0;
            }
        }
        buffer[index] = ch;
        index++;
    }
}

