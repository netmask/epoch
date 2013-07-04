#include <iostream>
#include <epobject.h>
#include <epscript.h>


namespace Epoch{
    void EPScript::exec(std::string script)
    {
        std::cout << script;
    }
}
