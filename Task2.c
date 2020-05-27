#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int func(const char* filename, char* slovo);

int func(const char* filename, char* slovo){
FILE *input;
int b=0;
char str[512],word[512], *sbegin, *send;
int min=INT_MAX;
input=fopen(filename, "r");
if (input){
    while(fgets(str,256,input))
          {
        for(sbegin=strchr(str, '"'), send=(sbegin?strchr(sbegin+1,'"'):NULL);
        sbegin&&send;
        sbegin=strchr(send+1,'"'),send=(sbegin?strchr(sbegin+1,'"'):NULL))
        {
            strncpy(word,sbegin+1,send-sbegin-1);
             word[send-sbegin-1]='\0';
             if(strlen(word) <= min && *word <= 'A' && *word <= 'Z' && word[0] == 'A')
            {
              b = 1;
              min=strlen(word);
              slovo[0]='\0';
              strcpy(slovo,word);
            }
        }
    }
}
else
    {
        printf("Невозможно открыть файл\n");
        return -5;
    }
fclose(input);
return b;
}

int main(void){
  char slovo[512];
  int b;
  b = func("test.txt", slovo);
  if (b == 1){
    printf("%s\n", slovo);
           }
  else{
    printf("Такого слова нет\n");
      }
}
