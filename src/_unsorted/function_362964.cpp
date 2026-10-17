struct Context;

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_361f10(Context* context);

extern "C" char function_362964(Context* context, void*, Result* result)
{
    result->value = function_361f10(context);
    result->kind = 0;
    return 1;
}
