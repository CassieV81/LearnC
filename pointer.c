#include <stdio.h>

int main(void) {
    int n = 100;
    int *p = &n;
    int size_v = sizeof(n);
    int size_m = sizeof(*p);
    printf("Address: %p\nValue: %i\nMemory Size: %i\nValue Size: %i\n", p, *p, size_m, size_v);
    
    char s[] = "Hello"; // char *s = "Hello"; This also works...
    int size_v1 = sizeof(s[0]);
    int size_m1 = sizeof(s);
    
    printf("Address: %p\nValue: %s\nMemory Size: %i\nValue Size: %i\n", &s, s, size_m1, size_v1);
    for (int i = 0; i < 6; i++) {
        printf("Address: %p\nValue: %c\n", &s[i], s[i]);
    }
}