#include <stdio.h>
#include "io_helpers.h"
#include "cli.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>



int main() {
    InputBuffer* inbuf = malloc(sizeof(InputBuffer));
    char *prompt = "sqlite> ";
    inbuf->input_buf = malloc(MAX_STR_LEN + 1);
    char *token_arr[MAX_STR_LEN] = {NULL};


    while (1) {
        write(1, prompt, strlen(prompt));
        int ret = get_input(inbuf);
        size_t token_count = tokenize_input(inbuf, token_arr);
        if (inbuf->input_buf[0] == '.') {
            handle_meta_command(inbuf);
        } else {
            handle_sql_command(inbuf);
        }
    }

    free(inbuf);
}
