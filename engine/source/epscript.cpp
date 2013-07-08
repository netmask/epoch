#include <epscript.h>

Handle<v8::Value> Quit(const v8::Arguments& args) {
    int exit_code = args[0]->Int32Value();
    exit(exit_code);
    return v8::Undefined();
}


Epoch::Script::Script()
{
    this->isolate = v8::Isolate::GetCurrent();
    v8::HandleScope handle_scope(this->isolate);
    this->global = ObjectTemplate::New();

    this->global->Set(v8::String::New("quit"),
                      v8::FunctionTemplate::New(Quit));

    this->context = Context::New(NULL, global);

}


std::string Epoch::Script::run_line(char* source){
    Context::Scope context_scope(context);
    v8::HandleScope handle_scope;

    v8::TryCatch try_catch;
    Handle<v8::Script> script = v8::Script::Compile(v8::String::New(source),
                                                        String::New("(shell)"));

    v8::Handle<v8::Value> result = script->Run();
    v8::String::Utf8Value str(result);

    return c_string(str);
}
