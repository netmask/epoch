#include <iostream>

#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/dump.h"
#include "mruby/proc.h"
#include <mruby/string.h>

#ifndef EPSCRIPT_H
#define EPSCRIPT_H

namespace Epoch{
    class Script{
    public:
      Script();
      Script(mrb_state*);
      mrb_state *main_state;
      mrbc_context *current_context;
      std::string run_line(char*);
      void cleanup();
      mrb_parser_state *get_parser();
    };
}


#endif
