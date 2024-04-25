
typedef enum {false = 0, true = 1} bool;

typedef enum {absolute, external, relocatable}codeType;

typedef enum{
    immediate,
    straight,
    constantIndex,
    straightRegister,
} address;

typedef enum {
    mov = 0,
    cmp = 1,
    add = 2,
    sub = 3,
    not = 4,
    clr = 5,
    lea = 6,
    inc = 7,
    dec = 8,
    jmp = 9,
    bne = 10,
    red = 11,
    prn = 12,
    jsr = 13,
    rts = 14,
    hlt = 15,
}OPCODE;

typedef struct codeLine{
    char * code;
    int length;
    int lineValid;
}codeLine, line;

typedef struct codeFile{
    int warnings;
    char *name;
    int height;
    codeLine* codeLines;
}codeFile, sourceFile;

typedef struct signDECLine{
    char * wordFromFile;
    int DECBaseVal;
    char *prop;
}signDECLine;


typedef struct signTable{
    signDECLine *signDecLines;
    int IC;
    int DC;
    int height;
}signTable;

typedef struct{
    int binaryCode[14];
} binaryNum;

typedef struct {int pre[3]}preBinary;

typedef struct {
    char *code;
    binaryNum binaryMachineCode;
}binaryCodeCell;

typedef struct binaryMap{
    binaryCodeCell *binaryCodeCells;
    int height
}binaryMap;