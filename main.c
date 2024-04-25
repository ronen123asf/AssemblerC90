#include "header.h"
int main(int argc, char *argv[]) {
    int amountOfFiles = (argc - 1);
    FILE *files = malloc((argc - 1) * sizeof(FILE));
    codeFile **source;
    binaryMap **binaryMachineCode;
    signTable **pSignTable;
    if (argc == 1){
        printError("arguments missing....");
    }

    assembler(&files, amountOfFiles, source, binaryMachineCode, pSignTable);
    int i;

    for(i = 0; i < amountOfFiles; i++){
        createENTFile(source[i], pSignTable[i], binaryMachineCode[i]);
        createEXTFile(source[i], pSignTable[i], binaryMachineCode[i]);
        createOBFile(source[i], pSignTable[i], binaryMachineCode[i]);
    }
}
