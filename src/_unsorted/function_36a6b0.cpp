struct Context;

struct Argument {
    char reserved[8];
    int value;
};

extern "C" void function_36a47c(Context* context, int value);

extern "C" char function_36a6b0(Context* context, void*, const Argument* argument)
{
    function_36a47c(context, argument->value);
    return 1;
}
