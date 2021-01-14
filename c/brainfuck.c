#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASSERT(condition, fmt, ...)  do { if (!(condition)) { fprintf(stderr, fmt, ##__VA_ARGS__); exit(1); } } while (0)
int main(int argc, char **argv) {
    ASSERT(argc == 2, "Usage: %s <file.bf>\n", argv[0]);
    FILE *fp = fopen(argv[1], "r");
    fseek(fp, 0, SEEK_END); int size = ftell(fp); fseek(fp, 0, SEEK_SET);
    char *script = malloc(size);
    fread(script, 1, size, fp); fclose(fp);
    char memory[1024 * 1024];
    char *ptr = memory;
    int pair;
    for (int pc = 0; pc < size; ++pc) {
        switch (script[pc]) {
            case '>': ++ptr; break;
            case '<': --ptr; break;
            case '+': ++*ptr; break;
            case '-': --*ptr; break;
            case '.': putchar(*ptr); break;
            case ',': *ptr = (char) getchar(); break;
            case '[':
                for (pair = 0; !*ptr && pc < size; ++pc)
                    if (script[pc] == ']' && (!--pair)) { break; }
                    else if (script[pc] == '[') { ++pair; }
                ASSERT(!pair, "Expected character ']'\n"); break;
            case ']':
                for(pair = 0; pc >= 0; --pc)
                    if (script[pc] == '[' && (!--pair)) { --pc; break; }
                    else if (script[pc] == ']') { ++pair; }
                ASSERT(!pair, "Unexpected character ']'\n"); break;
            case ' ': case '\t': case '\r': case '\n': break;
            default: printf("Unexpected character '%c'\n", script[pc]); exit(1);
        }
    }
    free(script);
    return 0;
}
