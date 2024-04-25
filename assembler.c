#include "header.h"

void assembler(FILE **files, int len, codeFile **source, binaryMap **finalBinaryMap, signTable **signTable) {
    int i;
    for (i = 0; i < len ; i++) {

        buildCodeFile(files[i], source[i]);

        preAssembler(source[i]);

        if(!(files[i]))
            continue;

        firstPass(source[i] , finalBinaryMap[i], signTable[i]);

        secondPass(source[i], finalBinaryMap[i], signTable[i]);

        free(source[i]);
        free(fileName);
    }
}
