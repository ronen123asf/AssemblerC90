#include "header.h"
#include "math.h"

void buildBinaryCell(binaryCodeCell cell, char *line1) {
    int i;
    binaryNum *binaryLine;
    preBinary *array;
    cell.code = line1;
    char *str = line1;
    for (i = 0; i < strlen(line1); i++) {
        if (strstr(str, "mov"))
            array->pre[1] = mov;
        if (strstr(str, "cmp"))
            array->pre[1] = cmp;
        if (strstr(str, "add"))
            array->pre[1] = add;
        if (strstr(str, "sub"))
            array->pre[1] = sub;
        if (strstr(str, "not")) {
            array->pre[1] = not;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "clr")) {
            array->pre[1] = clr;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "lea")) {
            array->pre[1] = lea;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "inc")) {
            array->pre[1] = inc;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "dec")) {
            array->pre[1] = dec;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "jmp")) {
            array->pre[1] = jmp;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "bne")) {
            array->pre[1] = bne;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "red")) {
            array->pre[1] = red;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "prn")) {
            array->pre[1] = prn;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "jsr")) {
            array->pre[1] = jsr;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
        }
        if (strstr(str, "rts")) {
            array->pre[1] = mov;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
            binaryLine->binaryCode[3] = 0;
            binaryLine->binaryCode[2] = 0;
        }
        if (strstr(str, "hlt")) {
            array->pre[1] = hlt;
            binaryLine->binaryCode[5] = 0;
            binaryLine->binaryCode[4] = 0;
            binaryLine->binaryCode[3] = 0;
            binaryLine->binaryCode[2] = 0;
        }
        if (strstr(str, "#")) {
            binaryLine->binaryCode[2] = 0;
            binaryLine->binaryCode[3] = 0;
            binaryLine->binaryCode[4] = 0;
            binaryLine->binaryCode[5] = 0;
        }
        if (strstr(str, ".extern") || strstr(str, ".data") || strstr(str, ".string")) {
            binaryLine->binaryCode[2] = 0;
            binaryLine->binaryCode[3] = 1;
            binaryLine->binaryCode[4] = 0;
            binaryLine->binaryCode[5] = 0;
        }
        if (strstr(str, "[") && strstr(str, "]")) {
            binaryLine->binaryCode[2] = 0;
            binaryLine->binaryCode[3] = 1;
            binaryLine->binaryCode[4] = 0;
            binaryLine->binaryCode[5] = 0;
        }
        if (lineHasTwoRegisters(line1)) {
            binaryLine->binaryCode[2] = 1;
            binaryLine->binaryCode[3] = 1;
            binaryLine->binaryCode[4] = 0;
            binaryLine->binaryCode[5] = 0;
        }
        int* tmp = numberToBinary(array->pre[1]);
        for (i = 0; i < 4; i++)
            binaryLine->binaryCode[i + 6] = tmp[i];
    }
    ARE(binaryLine, line1);
    for (i = 0; i < 14; i++)
        cell.binaryMachineCode.binaryCode[i] = binaryLine->binaryCode[i];
    flipArray(cell.binaryMachineCode.binaryCode, 14);
}

int *numberToBinary(int num){
    switch (num){
        case 0: {
            int result[4] = {0, 0, 0, 0};
            return result;
        }
        case 1 : {
            int result[4] = {0, 0, 0, 1};
            return result;
        }
        case 2 : {
            int result[4] = {0, 0, 1, 0};
            return result;
        }
        case 3 : {
            int result[4] = {0, 0, 1, 1};
            return result;
        }
        case 4 : {
            int result[4] = {0, 1, 0, 0};
            return result;
        }
        case 5 : {
            int result[4] = {0, 1, 0, 1};
            return result;
        }
        case 6 : {
            int result[4] = {0, 1, 1, 0};
            return result;
        }
        case 7 : {
            int result[4] = {0, 1, 1, 1};
            return result;
        }
        case 8 : {
            int result[4] = {1, 0, 0, 0};
            return result;
        }
        case 9 : {
            int result[4] = {1, 0, 0, 1};
            return result;
        }
        case 10 : {
            int result[4] = {1, 0, 1, 0};
            return result;
        }
        case 11 : {
            int result[4] = {1, 0, 1, 1};
            return result;
        }
        case 12 : {
            int result[4] = {1, 1, 0, 0};
            return result;
        }
        case 13 : {
            int result[4] = {1, 1, 0, 01};
            return result;
        }
        case 14 : {
            int result[4] = {1, 1, 1, 0};
            return result;
        }
        case 15: {
            int result[4] = {1,1,1,1};
            return result;
        }
    }
}

int binaryLinesNeeded(char *line1) {
    char *text = line1;
    if(strstr(line1, ".string"))
        return strlen(line1) - STRING_START_INDEX;
    return countBrackets(line1) + countRegisters(line1);
}

void addStringLine(binaryMap  *finalBinaryMap, int j, char *line){
    int i = 14;
    char *x;
    finalBinaryMap->binaryCodeCells[i].code = line;
    while(i < strlen(line)){
        x += line[i];
        finalBinaryMap->binaryCodeCells[j].binaryMachineCode = integerToBinaryNum((int)line[i]);
        i++;
        j++;
    }
    if(!stringValid(x) || strlen(line) > LINE_MAX_LEN){
        printError("invalid string...");
        exit(1);
    }
}

binaryNum integerToBinaryNum(int x){
    int y = x, length = 0, i;
    binaryNum *binaryNum1;
    while(y != 0) {
        y /= 10;
        length++;
    }
    char *string;
    itoa(x, string, length);
    for(i = 0; i < length; i++)
        binaryNum1->binaryCode[i]  = string[i];
    for(i = length; i < 14; i++)
        binaryNum1->binaryCode[i]  = 0;
    return *binaryNum1;
}