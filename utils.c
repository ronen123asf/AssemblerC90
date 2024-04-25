#include "header.h"
void printError(char *error){
    printf(error);
}
char *copyString(char* text) {
    char *copy;
    if(text == NULL){
        return NULL;
    }
    copy = malloc((strlen(text) + 1) * sizeof(char));
    if (copy == NULL){
        printError("line is empty...");
    }
    strcpy(copy, text);
    return copy;
}

char *copyToFirstFormat(char *text, char *format) {
    char *token = strtok(text, format);
    char *tokenCopy = token;
    free(token);
    return tokenCopy;
}

bool isContainSpace(char *text){
    return (bool)strstr(text, BLANKSTR);
}

int getNumber(char *text){
    long ret;
    char *ptr;
    if(text == NULL){
        return ERROR;
    }
    if(text[strlen(text) - 1] == '+'){
        return ERROR;
    }
    ret = strtol(text, &ptr, 10);
    if(!ptr || strlen(ptr))
        return ERROR;
    return ret;
}

void deleteUnneededSpaces(codeFile *source) {
    int i, j;
    i = j = 0;
    for(i = 0; i < source->height; i++) {
        char *text = source->codeLines[i].code;
        if (text == NULL) {
            return;
        }
        while (text[i]) {
            if (text[i] != ' ') {
                text[j] = text[i];
                j++;
            }
            i++;
        }
        text[j] = '\0';
    }
}

void removeUntilChar(char *text, char c) {
    char *position = strchr(text, c);
    if(text == NULL){
        return;
    }
    if (position != NULL) {
        memmove(text, position + 1, strlen(position));
    }
}

bool isStringContainOnlyLettersOrNumbers(char *text) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
            return false;
        }
    }
    return true;
}

void changeNameOfFile(char **pText) {strcat(*pText,".am\0");}

bool stringValid(char *str){return !(strstr(str, """") || strstr(str, ":") || strstr(str, "]") || strstr(str, "["));}

void ARE(binaryCodeCell *cell, char *line){
    if(strstr(line, "entry"))
        cell->binaryMachineCode.binaryCode[0] = 1;
    if(strstr(line,"mov"))
        cell->binaryMachineCode.binaryCode[1] = 1;
}
void flipArray(int *array, int n) {
    int i, reversedArr[n];
    for (i = 0; i < n; i++) {
        reversedArr[i] = array[n - i - 1];
    }
}

int strpos(char *s1, char *s2)
{
    const char *p = strstr(s1, s2);
    if (p)
        return p - s1;
    printError("no string position...");
    exit(1);
}