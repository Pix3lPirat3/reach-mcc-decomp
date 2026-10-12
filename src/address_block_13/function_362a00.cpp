struct Context;

struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" int function_361fc8(Context* context);

extern "C" char function_362a00(Context* context, void*, Result* result)
{
    result->value = function_361fc8(context);
    result->kind = 1;
    return 1;
}
