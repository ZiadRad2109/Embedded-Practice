
    char* alpha=alphabet;
    //printf("%d \t %s",*alpha,alpha);
    for(int i =0; i<26;i++){
        *alpha = i+'A';
        printf("%s  ",*alpha);