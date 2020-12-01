#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char **parse_args(char *line) {
    char **args = malloc(5 * sizeof(char*));
    char p[100];
    strcpy(p, line);
    char *q = p;
    char *token;
    for (int i = 0; i < 5 && q != NULL; i++) {
        token = strsep(&q, " ");
        args[i] = malloc(5 * sizeof(char));
        args[i] = token;
    }
    return args;
}

int main(int argc, char *argv[]) {
    char *line = "ls -a -l"; 
    char ** args = parse_args(line);
    execvp(args[0], args);
    free(args);
}
