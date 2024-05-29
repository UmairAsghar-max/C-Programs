#include <stdio.h>

int main(){
    const int a = 25;
    printf("Const Value: %d\n", a);
    
    int *ptr = &a;
    *ptr = 26;
    printf("Changed Value: %d", a);
    return 0;
}
