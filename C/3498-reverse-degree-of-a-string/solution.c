//*****************************************************************************
//** 3498. Reverse Degree of a String                               leetcode **
//*****************************************************************************

int reverseDegree(char* s) {
    int export = 0;
    int total = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        export = s[i];
        export = 27 - (export - 96);
        total = total + (export * (i + 1));
//        printf("%c[%d] = %d\n", s[i],i,export);
    }
    return total;
}