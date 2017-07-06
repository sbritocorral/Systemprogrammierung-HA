typedef struct {


    long fileSize;
    long fileLines;
    char * fileInfo;


}file;

typedef struct {

    int processNumber;
    int betriebsMitellNumber;

    int ** gesamtAnforderungenMatrix;
    int ** aktuelleBelegungenMatrix;
    int ** memoryAvalible;
    int ** restAnforderung;
    int ** freeMemoryAfter;
    int ** bankProof;


}information;

file * openFile(char * path);

void freeFile(file * fileToFree);

information * getParsedInformation(file * fileToParse);

void freeParserInformation(char ** info, int infoLongitude);
void freeInfo(information * info);

int getInfoNumber(char * totalInfo);

int ** createMatrix(int column,int row);

void parsingMatrixByReference(int ** matrix,char ** information, int init,int final);


void freeMatrix(int column,int rows , int ** matrix);


//void initMatrix(int ** matrix,int betriebsMitellNumber, int processNumber);



