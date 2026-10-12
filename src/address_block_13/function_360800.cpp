struct Context;

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_360490(Context* context);

extern "C" char function_360800(Context* context, void*, Result* result)
{
    result->value = function_360490(context);
    result->kind = 0;
    return 1;
}
