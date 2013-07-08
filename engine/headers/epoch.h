#include <epscript.h>
#include <linenoise.h>

#ifndef EPOCH_H
#define EPOCH_H

namespace Epoch{
  class Engine{
  public:
    Script* script;
    Engine();
    void start();
    void REPL();
  };
}

#endif
