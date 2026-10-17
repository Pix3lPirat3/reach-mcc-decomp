struct Context;

struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" int function_360618(Context* context);

extern "C" char function_3609b0(Context* context, void*, Result* result)
{
    result->value = function_360618(context);
    result->kind = 1;
    return 1;
}
