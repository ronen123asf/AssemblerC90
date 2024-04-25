#include "header.h"

int SignLinesNeeded(codeFile *source){
    int i;
    int ctr;
    for(i = 0; i < source->height; i++)
        if(strstr(source->codeLines[i].code, ":") || strstr(source->codeLines[i].code, ".extern") ||
        strstr(source->codeLines[i].code, "define") || strstr(".entry", source->codeLines[i].code))
            ctr++;
    return ctr;
}

char *getSignName(char *line){
    int i;
    char *sign;
    while(line[i] != ":")
        sign += line[i];
    return sign;
}