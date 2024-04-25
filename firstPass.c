#include "header.h"

void firstPass(codeFile  * source, binaryMap *finalBinaryMap, signTable *finalSignTable){
    signTableFirstPass(source, finalSignTable);
    binaryMapFirstPass(source, finalBinaryMap);
    finalSignTable->DC = finalSignTable->IC + 100;
    finalSignTable->IC = 0;
}
void binaryMapFirstPass(codeFile *source, binaryMap *finalBinaryMap){
    int i, j = 0;
    int linesNeeded;
    for(i = 0; i < source->height; i++)
        linesNeeded += binaryLinesNeeded(source->codeLines[i].code);
    realloc(finalBinaryMap->binaryCodeCells, (linesNeeded) * sizeof (binaryCodeCell));
    for(i = 0; i < source->height; i++)
        buildBinaryCell(finalBinaryMap->binaryCodeCells[j], source->codeLines[i].code);

}

void signTableFirstPass(codeFile *source, signTable *finalSignTable){
    int i, j = 0;
    int linesNeeded = signLinesNeeded(finalSignTable);
    realloc(finalSignTable->signDecLines, (linesNeeded) * sizeof (signDECLine));
    for(i = 0; i < source->height; i++){
        if(!isEndingWithColon(source->codeLines[i].code)) {
            printError("line doesnt end with colon...");
            printError("line doesnt end with colon...");
            exit(1);
        }
        if(strstr(source->codeLines[i].code, "define"))
            defineLine(source->codeLines[i].code, j, finalSignTable);
        if(strstr(source->codeLines[i].code, ".string") || strstr(source->codeLines[i].code, ".data"))
            dataLine(source->codeLines[i].code, j, finalSignTable);
        if(strstr(source->codeLines[i].code, "extern")){
            externalLine(source->codeLines[i].code, j, finalSignTable);
        }
        if(strstr(source->codeLines[i].code, ":")){
            finalSignTable->IC += binaryLinesNeeded(&source->codeLines[i]);
            finalSignTable->signDecLines->wordFromFile = getSignName(source->codeLines[i].code);
            finalSignTable->signDecLines[i].prop = "code";
            finalSignTable->signDecLines[i].DECBaseVal = finalSignTable->IC + 100;
        }
    }
    signTablePointer = j;
}

void defineLine(char *line, int j, signTable *finalSignTable){
    int i = 0;
    char *word, *value;
    while(line[i] != '=')
        word += line[i];
    i++;
    while(i < strlen(line)){
        value += line[i];
    }
    finalSignTable->signDecLines[i].wordFromFile = word;
    finalSignTable->signDecLines[i].DECBaseVal = atoi(value);
    finalSignTable->signDecLines[i].prop = "mdefine";
    j++;
}

void dataLine(char *line, int j, signTable *finalSignTable){
    if(strlen(getSignName(line)) > MAX_LEN_LENGTH){
        printError("sign too big...");
        exit(1);
    }
    finalSignTable->IC += binaryLinesNeeded(line);
    finalSignTable->signDecLines[j].wordFromFile = getSignName(line);
    finalSignTable->signDecLines[j].DECBaseVal = finalSignTable->IC + 100;
    finalSignTable->signDecLines[j].prop = "data";
    j++;
}

void externalLine( char *line, int j, signTable *finalSignTable){
    int i = 0;
    char *name;
    while(line[i] != BLANK)
        i++;
    i++;
    while(i < strlen(line)){
        if(line[i] == ','){
            finalSignTable->signDecLines[i].wordFromFile = name;
            finalSignTable->signDecLines[i].prop = "external";
            j++;
        }
        else
            name += line[i];
    }
    finalSignTable->signDecLines[i].wordFromFile = name;
    finalSignTable->signDecLines[i].prop = "external";
    j++;
}