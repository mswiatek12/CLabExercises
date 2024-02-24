#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    if(argc == 0) {
        return 0;
    }
    
    int i;
    for(i = 1; i < argc; i++) {
        printf("%s\n", *(argv+i));
    }
    char result[256] = " ";
    for(int i = 1; i < argc; i++) {
        if(strcmp(*(argv+1), *(argv+i)) != 0){
            strcat(result, *(argv+1));
        }
    }
    
    printf("%s\n", result);
    
    return 0;
}