#include <fstream>
#include <sstream>
#include <cstdio>
#define ASSERT(condition, fmt, ...)  do { if (!(condition)) { fprintf(stderr, fmt, ##__VA_ARGS__); exit(1); } } while (0)
int main(int argc, char **argv) {
    ASSERT(argc == 2, "Usage: %s <file.bf>\n", argv[0]);
    std::ifstream ifs(argv[1]); ASSERT(ifs, "Open file %s failed\n", argv[1]);
    std::stringstream ss; ss << ifs.rdbuf(); std::string script = ss.str();
    char memory[1024 * 1024];
    char *ptr = memory;
    int size = script.size(), pair;
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
    return 0;
}
