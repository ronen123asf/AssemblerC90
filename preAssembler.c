#include "header.h"

void preAssembler(codeFile *source){
    int i;
    for(i = 0; i < source->height; i++)
        if(strstr(MCR, source[i].codeLines->code))
            deleteMacro(source, i);
    deleteUnneededSpaces(source);
}

void deleteMacro(codeFile *source, int declarationLine){
    int linePtr = declarationLine;
    int ptr=0;
    codeFile *newFile;
    char* string = source->codeLines[declarationLine].code;
    int tmpPtr = strpos(source->codeLines[declarationLine].code, MCR) + 2;
    char *macroName;
    if( !tmpPtr || string[tmpPtr] ==' ') {
        printError("illegal string");
        exit(1);
    }
    //get macro name
    while(tmpPtr < source->codeLines[declarationLine].length)
        macroName += string[tmpPtr];
    if(!macroName) {
        printError("not a valid macro name...");
        exit(1);
    }
    //copies macro data into a new file
    while(!strstr(source->codeLines[linePtr].code, ENDMCR)) {
        if(linePtr == source->height){
            printError("invalid macro...");
            exit(1);
        }
        newFile->codeLines[ptr].code = source->codeLines[linePtr].code;
        linePtr++;
        ptr++;
    }
    int endMcr = linePtr;
    emptyLines(source, declarationLine, endMcr);
    free(string);
    while(linePtr < source->height){
        if(strstr(source->codeLines[linePtr].code, macroName)){
            insertFile(source, newFile, linePtr);
        }
        linePtr++;
    }
}

void insertFile(codeFile *source, codeFile  *codeFile1, int start){
    int i, j = 0, size = codeFile1->height , p;
    for(i = start; i <= start + codeFile1->height; i ++){
        for(p = i + 1; p < source->height; p++)
            swapLines(&source->codeLines[p], &source->codeLines[p + 1]);
        source->codeLines[i].code = codeFile1->codeLines[j].code;
        j++;
    }
    source->height += codeFile1->height - 1;
}