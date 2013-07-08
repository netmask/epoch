#include <iostream>

#include <v8.h>

#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#ifndef EPSCRIPT_H
#define EPSCRIPT_H

using namespace v8;

namespace Epoch{
    class Script{
    public:
        Script();
        Isolate* isolate;
        std::string run_line(char*);
        Handle<v8::ObjectTemplate> global;
        Handle<v8::Context> context;

        const char* c_string(const v8::String::Utf8Value& value) {
            return *value ? *value : "<string conversion failed>";
        };

    };
}


#endif
