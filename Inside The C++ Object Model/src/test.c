#include <stdio.h>
#include <stdlib.h>

void func(void*value){
    printf("value: %d\n",(int)value);
}

int main(){
    int*pvalue=malloc(sizeof(int));
    *pvalue=10;
    func((void*)*pvalue);
    free(pvalue);

    return 0;
}