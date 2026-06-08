#ifndef __CLI_H__
#define __CLI_H__

#include "io_helpers.h"

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED
} MetaCommandResult;

MetaCommandResult handle_meta_command(InputBuffer *inbuf);

void handle_sql_command(InputBuffer *inbuf);

#endif
