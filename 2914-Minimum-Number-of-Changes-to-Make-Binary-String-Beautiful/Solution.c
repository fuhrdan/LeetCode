int minChanges(char* s) {
    int len = strlen(s);
    int count = 0;
    for(int i = 1; i < len; i += 2)
    {
        count += s[i] != s[i-1];
    }
    return count;
}