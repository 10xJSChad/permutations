#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int* perm;
int  len;


static inline
void swap(int left, int right) {
    int temp = perm[left];
    perm[left] = perm[right];
    perm[right] = temp;
}


static inline
void reverse(int left) {
    int right = len - 1;

    while (left < right)
        swap(left++, right--);
}


static inline
bool advance(void) {
    int max = perm[len - 1];

    for (int i = len - 1; i > -1; --i) {
        if (perm[i] >= max) {
            max = perm[i];
            continue;
        }

        for (int j = len - 1; j > i; --j) {
            if (perm[i] < perm[j]) {
                swap(i, j);
                reverse(i + 1);
                return true;
            }
        }
    }

    return false;
}


void print_words(char** arr) {
    for (int i = 0; i < len; ++i)
        printf("%s%s", arr[perm[i]], i != len - 1 ? ", " : "" );

    putchar('\n');
}


void print_string(char* str) {
    for (int i = 0; i < len; ++i)
        putchar(str[perm[i]]);

    putchar('\n');
}


int main(int argc, char** argv) {
    int is_word = (argc == 2);

    if (argc == 1) {
        printf("usage: %s <STRING> [STRING] [...]\n", argv[0]);
        exit(1);
    }

    len  = is_word ? strlen(argv[1]) : argc - 1;
    perm = malloc((sizeof *perm) * len);

    if (perm == NULL) {
        perror("malloc");
        exit(1);
    }

    for (int i = 0; i < len; ++i)
        perm[i] = i;

    if (is_word) {
        print_string(argv[1]);

        while (advance())
            print_string(argv[1]);
    } else {
        print_words(argv + 1);

        while (advance())
            print_words(argv + 1);
    }

    free(perm);
    return 0;
}
