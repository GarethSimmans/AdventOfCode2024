#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readinput(int left_array[1000], int right_array[1000]);
void sort(int array[1000], int size);

int main(){
    int left_array[1000] = {0};
    int right_array[1000] = {0};
    int size = sizeof(left_array)/sizeof(left_array[0]);
    unsigned long total = 0;


    readinput(left_array, right_array);

    sort(left_array, size);
    sort(right_array, size);

    for (int i = 0; i < size; i++){
        if (left_array[i] > right_array[i])
            total += left_array[i] - right_array[i];
        else
            total += right_array[i] - left_array[i];
    }
    printf("Total: %d\n", total);
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

void sort(int array[1000], int size){
   for (int i = 0; i < size - 1; ++i){
        for (int j = 0; j < size - i - 1; ++j){
            if (array[j] > array[j + 1]){
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
   }
}

