#include "header.h"

void buildCodeFile(FILE *file, codeFile *source) {
    int height = 0;
    codeLine  *codeLineBuilder = NULL;
    bool *isFileValid;
    char *currentLine = getLine(file, isFileValid);

    while(currentLine != NULL){
        height++;
        codeLineBuilder = (codeLine *) realloc(codeLineBuilder, (height + 1) * sizeof(codeLine));
        if(codeLineBuilder == NULL){
            printError("an empty code line...");
            exit(1);
        }
        if(!codeLineBuilder)
            codeLineBuilder[height - 1].code = currentLine;
        currentLine = getLine(file, isFileValid);
    }
    source->codeLines = codeLineBuilder;
    source->height = height;

    free(codeLineBuilder);
}

int countBrackets(char * line){
    int i, ctr=0;
    for(i = 0; i < strlen(line); i++){
        if(line[i] == '[')
            ctr += 2;
    }
    return ctr;
}

int countRegisters(char *line){
    int i, ctr=0;
    for(i = 0; i < strlen(line) - 1; i++){
        if(line[i] == 'r' && (line[i + 1] == '1' || line[i + 1] == '2' || line[i + 1] == '3' || line[i + 1] == '4'
                              || line[i + 1] == '5' || line[i + 1] == '7' ||line[i + 1] == '6'))
            ctr++;
    }
    return ctr;
}

bool lineHasTwoRegisters(char * line){
    int i, j, ctr = 0;
    for(i = 0; i < strlen(line) - 1; i++){
        if(strstr(line, "mov") && line[i]  == 'r' && (0 <= line[i + 1] < 8))
            ctr++;
    }
    return ctr;
}

bool isEntryLine(char *line){
    if(strstr(line, ".entry"))
        return true;
    return false;
}

bool isExternalLine(char *line){
    if(strstr(line, ".extern"))
        return TRUE;
    return FALSE;
}

void EmptyLines(codeFile *source, int start, int end){
    int i;
    for(i = start; i <= end; i++)
        source->codeLines[i].code = BLANKSTR;
}

void swapLines(codeLine *line1, codeLine *line2){
    codeLine *tmp = line1;
    line1 = line2;
    line2 = tmp;
}

char *getLine(FILE *file, bool *isValid) {
    int c = -1 , counter = 0;
    char *currentLine = (char *) malloc(LINE_MAX_LEN * sizeof(char));
    if (currentLine == NULL){
        printError("empty line...");
    }
    while ((c = fgetc(file)) != EOF) {
        if (counter > 79) {
            printError("line too big");
            (*isValid) = 0;
            free(currentLine);
            return NULL;
        }
        if ((c == '\n' || c == '\t' || c == ' ' || c == '\v' || c == '\r') && counter == 0) {
            continue;
        }
        if (c == '\n') {
            currentLine[counter] = '\0';
            return currentLine;
        }
        if (c == '\r') {
            continue;
        }
        currentLine[counter] = c;
        counter++;
    }

    if (counter > 0) {
        currentLine[counter] = '\0';
        return currentLine;
    }

    free(currentLine);
    return NULL;
}

void deleteUnneededSpaces(codeFile * source){
    int i;
    for(i = 0; i < source->height; i++){
        if(strcmp(source->codeLines[i].code, BLANKSTR)){
            int j;
            for(j = i + 1; j < source->height; j++){
                swapLines(&source->codeLines[i], &source->codeLines[j]);
            }
        }
    }
}