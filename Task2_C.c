#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int Search(FILE* file, char* word);
int Search(FILE* file, char* word){
    char current;
    char* temp;
    int length = 0, number_of_quots = 0, letter_flag = 0, len_of_temp = 0, min_word;
    while (fscanf(file, "%c", &current) == 1){
        length++;
    }
    min_word = INT_MAX;
    temp = (char*)malloc(len_of_temp);
    fseek(file, 0, 0);
    if (length < 3){
        printf("Error: incorrect input\n");
        exit(-1);
    }
    for (int i = 0; i < length; i++){
        fscanf(file, "%c", &current);
        if (current == '"'){
            number_of_quots++;
        }
        if ((current == '"') && (number_of_quots%2 == 0)){
            letter_flag = 0;
            for (int index = 0; index < len_of_temp; index++){
                if ((temp[index] >= 65) && (temp[index] <= 90)){
                    letter_flag++;
                }
                if (letter_flag == len_of_temp){
                    if (temp[0] == 'A'){
                        if (len_of_temp < min_word){
                            word = realloc(word, (len_of_temp+1)*sizeof(char));
                            for (int letter_index = 0; letter_index < len_of_temp + 1; letter_index++){
                                word[letter_index] = temp[letter_index];
                            }
                        }
                    }
                }
            }
            len_of_temp = 0;
            temp = realloc(temp, 0* sizeof(char));
            continue;
        }
        if ((current != '"') && (number_of_quots%2 == 1)){
            len_of_temp++;
            temp = realloc(temp, sizeof(char)*(len_of_temp+1));
            temp[len_of_temp -1] = current;
            temp[len_of_temp] = '\0';
        }
    }
    free(temp);
    return 0;
}

int Autotest(void);
int Autotest(void){
    FILE* test_file;
    char* test_word;
    test_file = fopen("F:\\prog\\test.txt", "r");
    test_word = (char*)malloc(0 * sizeof(char));
    if (!test_file){
        printf("Error: cannot open test file\n");
        exit(-1);
    }
    Search(test_file, test_word);
    if (test_word[0] == 'A'){
        printf("Autotest passed\n");
    }
    else{
        printf("Autotest not passed\n");
        exit(-1);
    }
    free(test_word);
    fclose(test_file);
    return 0;
}

int main(void){
    FILE* input_file;
    char* answer;
    input_file = fopen("F:\\prog\\test.txt", "r");
    answer = (char*)malloc(0 * sizeof(char));
    answer[0] = 'x';
    if (!input_file){
        printf("Error: cannot open file\n");
        exit(-1);
    }
    Autotest();
    Search(input_file, answer);
    if (answer[0] == 'x'){
        printf("No such words!\n");
    }
    else{
        printf("Answer is %s\n", answer);
    }
    free(answer);
    fclose(input_file);
    return 0;
}
