// Pointer that points to some value but that
// get deleted is known as dangling pointer
#include<stdio.h>

int *call();

int main(){
    int *ptr;
    ptr=call();
    fflush(stdin);
    printf("%d",*ptr);
    return 0;
}

// In this case, the scope of x is local
// when the program returns from call the
// x get deleted and ptr becomes a dangling
// pointer.
// Solution is to make x static to elevate
// its scope
int *call(){
    // static int x=25;
    int x=25;
    ++x;
    return &x;
}
