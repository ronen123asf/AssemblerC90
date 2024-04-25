#include "structures.h"
#include "math.h"

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define INVALID_NUMBER -1000
#define MIN_VAL -256
#define MAX_VAL 255
#define MAX_VAL_DATA 511
#define MIN_VAL_DATA -512

#define BASE_10_BITES 1023
#define BASE_12_BITES 4095

#define NOCMD 99

#define DST_LOCATION 2
#define OP_CODE_LOCATION 5
#define ORIGIN_LOCATION 9
#define STRING_START_INDEX 14;
#define BLANK ' '
#define BLANKSTR " "
#define LINE_MAX_LEN 79
#define EXTRA_TXT 0
#define ENDMCR "endmcr"
#define MCR "mcr"
#define MAX_LEN_LENGTH 99

extern char chars[4] = {'*', '#', '%', '!'};

extern char *fileName;
extern int height;

extern int signTablePointer;
extern char* guideList[16]={"mov","cmp","add","sub" ,"not" ,"clr" ,"lea" ,"inc" ,"dec","jmp","bne","red" ,"prn","jsr","rts" ,"hlt"};

void buildBinaryCell(binaryCodeCell , char *);

void ARE(binaryCodeCell *, char *);

int *numberToBinary(int);

void flipArray(int *, int);

int binaryLinesNeeded(char *);

int countBrackets(char *);

int countRegisters(char *);

bool stringValid(char *);

binaryNum integerToBinaryNum(int);

void printError(char *);

void buildCodeFile(FILE *, codeFile *source);

char *getLine(FILE *, bool *);

void swapLines(codeLine *,codeLine *);

void secondPass(codeFile *, binaryMap *, signTable *);

void signTableEntryLine(codeFile *, signTable *);

bool isEntryLine(char *);

char *getEntry(char *);

void sortSignTable(signTable *);

bool lineHasTwoRegisters(char *);

int signLinesNeeded(codeFile *);

char *getSignName(char *);

void defineLine(char *, int, signTable *);

void binaryMapFirstPass(codeFile *, binaryMap *);

void signTableFirstPass( codeFile *, signTable *);

bool isEndingWithColon(char *);

void dataLine(char *, int, signTable *);

void externalLine(char *, int, signTable *);

void firstPass(codeFile *, binaryMap *, signTable *);

void conflictingNamesOfVariables(signTable *);

void preAssembler(codeFile *);

int strpos(char *, char *);

void deleteMacro(codeFile *, int);

void changeNameofFile(FILE *file);

void emptyLines(codeFile  *, int , int);

void insertFile(codeFile *, codeFile *, int);

void deleteUnneededSpaces(codeFile *);

void assembler(FILE **files, int len, codeFile  **, binaryMap **, signTable **);

void createEXTFile(codeFile *, signTable *, binaryMap *);

void createENTFile(codeFile *, signTable *, binaryMap *);

void createOBFile(codeFile *, signTable *, binaryMap *);