#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "io_helpers.h"


ssize_t get_input(InputBuffer* inbuf) {
    int read_len;
    int retval;
    int while_check = true;
    int curr_size = MAX_STR_LEN;
    int pos = 0;
    int bread = 0; 

    while (while_check) {
        int retval = read(STDIN_FILENO, inbuf->input_buf + pos, MAX_STR_LEN);
        int read_len = retval;

        if (read_len == -1) {
            while_check = false;
        } else if (read_len == 0) {
            while_check = false;
        } else if (read_len < curr_size) {
            bread += read_len;
            inbuf->input_length = bread;
            inbuf->buffer_length = curr_size;


            while_check = false;
        }


        if (read_len == curr_size) {
            bread += read_len;
            curr_size *= 2;
            inbuf->input_buf = realloc(inbuf->input_buf, curr_size);
            pos += bread;
            // do some realloc error handling here 
            // i want at this point to continue reading from the new/updated position 
            // so to keep it clean and tidy, there should be one read call at the top of the loop - and that read call should have a variable to handle this behaviour

        }
    }
    //in_ptr[read_len] = '\0';
    return retval;
}
/**
 * i need to rework this function to satisfy this logic
 *
 * Read 1 byte
 * If it's \n or EOF, stop
 * Otherwise, if you've hit your current buffer limit, realloc to double
 * Go back to 1
**/
