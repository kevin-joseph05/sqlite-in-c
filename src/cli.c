#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cli.h"
#include "io_helpers.h"

MetaCommandResult handle_meta_command(InputBuffer *inbuf) {
    return META_COMMAND_UNRECOGNIZED;
}

void handle_sql_command(InputBuffer *inbuf) {
    return;
}
