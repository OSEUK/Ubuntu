#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    int reverse = 0;

    // -r 옵션이 있으면 역순으로 출력
    if (argc > 1 && strcmp(argv[1], "-r") == 0) {
        reverse = 1;
        argc--;
        argv++;		// -r일때와 아닐 때 정렬을 동일하게 하기 위해
    }

    // 단어들을 사전순으로 정렬
    qsort(argv + 1, argc - 1, sizeof(char *), cmp);

    // 역순으로 출력할 경우 배열을 뒤집음
    if (reverse) {
        for (int i = argc-1; i > 0; i--) {
            printf("%s ", argv[i]);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
    }
    printf("\n");

    return 0;
}


	

