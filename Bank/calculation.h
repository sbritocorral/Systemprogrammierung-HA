

void calculateRestAnforderung(int ** gesamt, int ** belegungen, int ** rest,int processNumber , int betriebsMitellNumber);
void calculateFreeMatrix(int ** available, int ** belegungen,int ** freeMatrix,int processNumber , int betriebsMitellNumber);
int calculateBankAlgo(int ** freeMatrix,int ** restMatrix,int ** belegtMatrix,int ** bankProof,int processNumber,int betriebsMitellNumber);
void  initPrev(int ** prevProof,int betriebsMitellNumber, int processNumber);
void  copy(int ** prevProof, int ** bankProof, int betriebsMitellNumber, int processNumber);
int compare(int ** prevProof, int ** bankProof, int betriebsMitellNumber, int processNumber);
int test (int ** bankProof, int processNumber);
void freePrev(int ** prev , int processNumber);
void readFreeMatrix(int ** matrix,int betriebsMitellNumber);
void readRestMatrix(int ** matrix,int processNumber,int betriebsMitellNumber);
void readBankMatrix(int ** matrix,int betriebsMitellNumber);
void freeMatrixCopy(int ** copyMatrix , int betriebsMitellNumber);
int calculateOperation(int * operation , int ** freeMatrix ,int ** gesamtMatrix, int ** belegungMatrix,int zuruck);
void readBelegungMatrix(int ** matrix,int processNumber,int betriebsMitellNumber);
