#include <epoch.h>

Epoch::Engine::Engine()
    :script(new Script())
{
    this->REPL();
}

void Epoch::Engine::REPL(){
    char* script_line;

    while((script_line = linenoise("epoch>"))){
        std::cout << script->run_line(script_line) << std::endl;
    }
}
