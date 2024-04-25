#include "header.h"
//error 1
void conflictingNamesOfVariables(signTable *finalSignTable){
    int i, j;
    for(i = 0; i < finalSignTable->height; i++)
        for(j = i + 1; j < finalSignTable->height; j++)
            if(strcmp(finalSignTable->signDecLines[i].wordFromFile, finalSignTable->signDecLines[j].wordFromFile))
                printError("conflicting Types of variables...");
}

bool isEndingWithColon(char *text){
    int length = strlen(text);
    if (text[length - 1] == ':')
        return true;
    return false;
}

