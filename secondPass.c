#include "header.h"

void secondPass(codeFile *source, binaryMap *finalBinaryMap, signTable *finalSignTable){
    signTableEntryLine(source, finalSignTable);
    sortSignTable(finalSignTable);
}
void signTableEntryLine(codeFile *source, signTable *finalSignTable) {
    int i, j = signTablePointer;
    for (i = 0; i < source->height; i++) {
        if (isEntryLine(source->codeLines[i].code)) {
            finalSignTable->IC += binaryLinesNeeded(source->codeLines[i].code);
            finalSignTable->signDecLines[j].DECBaseVal = finalSignTable->IC + 100;
            finalSignTable->signDecLines[j].prop = ".entry";
            finalSignTable->signDecLines[j].wordFromFile = getEntry(source->codeLines[i].code);
        }
    }
    conflictingNamesOfVariables(finalSignTable);
}

char *getEntry(char *line){
    int i = 7;
    char *output;
    while(i < strlen(line)){
        output += line[i];
        i++;
    }
    return output;
}

void sortSignTable(signTable *finalSignTable){
    int i, j;
    for(i = 0; i < finalSignTable->height; i++){
        for(j = i + 1; j < finalSignTable->height; j++){
            if(finalSignTable->signDecLines[i].DECBaseVal > finalSignTable->signDecLines[j].DECBaseVal &&
            !strcmp(finalSignTable->signDecLines[i].prop, "mdefine") && strcmp(finalSignTable->signDecLines[i].prop, "mdefine")){
                int tmp = finalSignTable->signDecLines[i].DECBaseVal;
                finalSignTable->signDecLines[i].DECBaseVal = finalSignTable->signDecLines[j].DECBaseVal;
                finalSignTable->signDecLines[j].DECBaseVal = tmp;
            }
        }
    }
}