#include "header.h"

void createEXTFile(codeFile * source, signTable *finalSignTable, binaryMap *finalBinaryMap){
    int i;
    FILE *ps = fopen("ps.ext", "w");
    for(i = 0; i < finalSignTable->height; i++){
        char *line;
        if(strcmp(finalSignTable->signDecLines[i].prop, "external")){
            strcat(line, finalSignTable->signDecLines[i].wordFromFile);
            strcat(line, "    ");
            strcat(line, (char *)finalSignTable->signDecLines[i].DECBaseVal);
            strcat(line, "\n");
            fputs(line, ps);
            fputc('\n', ps);
        }
        free(line);
    }
}

void createENTFile(codeFile * source, signTable *finalSignTable, binaryMap *finalBinaryMap){
    int i;
    FILE *ps;
    ps = fopen("ps.ent", "w");

    for(i = 0; i < finalSignTable->height; i++){
        char *line;
        if(strcmp(finalSignTable->signDecLines[i].prop, ".entry")){
            strcat(line, finalSignTable->signDecLines[i].wordFromFile);
            strcat(line, "    ");
            strcat(line, (char *)finalSignTable->signDecLines[i].DECBaseVal);
            fputs(line, ps);
            fputc('\n', ps);
        }
        free(line);
    }
}

void createOBFile(codeFile *source, signTable *finalSignTable, binaryMap *finalBinaryMap){
    int i, p = 0;
    char *output;
    FILE *ps = fopen("ps.ob", "w");
    for(i = 0; i < finalBinaryMap->height; i++){
        int j, sum = 0;

        for(j = 0; j < 2; j++){
            if(finalBinaryMap->binaryCodeCells[i].binaryMachineCode.binaryCode[j] == 1)
                sum += (int)pow(2, j);
        }
        output += chars[sum];
        sum = 0;

        for(j = 2; j < 4; j++){
            if(finalBinaryMap->binaryCodeCells[i].binaryMachineCode.binaryCode[j] == 1)
                sum += (int)pow(2, j - 2);
        }

        output += chars[sum];
        sum = 0;

        for(j = 4; j < 6; j++){
            if(finalBinaryMap->binaryCodeCells[i].binaryMachineCode.binaryCode[j] == 1)
                sum += (int)pow(2, j - 4);
        }
        output += chars[sum];
        sum = 0;

        for(j = 6;  j < 8; j++){
            if(finalBinaryMap->binaryCodeCells[i].binaryMachineCode.binaryCode[j] == 1)
                sum += (int)pow(2, j - 6);
        }
        output += chars[sum];
        sum = 0;

        for(j = 8;  j < 10; j++){
            if(finalBinaryMap->binaryCodeCells[i].binaryMachineCode.binaryCode[j] == 1)
                sum += (int)pow(2, j - 8);
        }
        output += chars[sum];
        sum = 0;
        for(j = 10;  j < 12; j++){
            if(finalBinaryMap->binaryCodeCells[i].binaryMachineCode.binaryCode[j] == 1)
                sum += (int)pow(2, j - 10);
        }
        output += chars[sum];
        sum = 0;

        for(j = 12;  j < 14; j++){
            if(finalBinaryMap->binaryCodeCells[i].binaryMachineCode.binaryCode[j] == 1)
                sum += (int)pow(2, j - 12);
        }
        output += chars[sum];
        fputs(output, ps);
        fputc('\n', ps);
    }
}
