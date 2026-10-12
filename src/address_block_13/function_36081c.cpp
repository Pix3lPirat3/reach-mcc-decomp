struct Context;

struct Result {
    int kind;
    int reserved4;
    char value;
};

extern "C" char function_3604b8(Context* context);

extern "C" char function_36081c(Context* context, void*, Result* result)
{
    result->value = function_3604b8(context);
    result->kind = 0;
    return 1;
}
