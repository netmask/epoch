#include <epscript.h>

static std::string
return_inspect(mrb_state *mrb, mrb_value obj)
{
    obj = mrb_funcall(mrb, obj, "inspect", 0);
    return std::string(RSTRING_PTR(obj));
}


Epoch::Script::Script()
    :main_state(mrb_open())
{
    std::cout << "Init script sub system: Ruby \n";
    this->current_context = mrbc_context_new(this->main_state);
}

Epoch::Script::Script(mrb_state *current_state)
{
    this->main_state = current_state;
}

std::string Epoch::Script::run_line(char* source){
    struct mrb_parser_state *parser = this->get_parser();
    parser->s = source;
    parser->send = source + strlen(source);
    mrb_parser_parse(parser, this->current_context);

    int compilation_result = mrb_generate_code(this->main_state, parser);

    if (0 < parser->nerr) {
        printf("line %d: %s\n", parser->error_buffer[0].lineno, parser->error_buffer[0].message);
    }

    mrb_value result = mrb_run(this->main_state,
                               mrb_proc_new(this->main_state, this->main_state->irep[compilation_result]),
                               mrb_top_self(this->main_state));

    return return_inspect(this->main_state, result);
}

void Epoch::Script::cleanup()
{
    mrb_close(this->main_state);
}


mrb_parser_state * Epoch::Script::get_parser()
{
    return mrb_parser_new(this->main_state);
}
