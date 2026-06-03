#include <stdio.h>
#include "io_helpers.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>



int main() {
    InputBuffer* inbuf = malloc(sizeof(InputBuffer));
    char *prompt = "sqlite> ";
    inbuf->input_buf = malloc(MAX_STR_LEN + 1);
    //input_buf[MAX_STR_LEN] = '\0';


    while (1) {
        write(1, prompt, strlen(prompt));
        int ret = get_input(inbuf);

    }

    free(inbuf);
}
