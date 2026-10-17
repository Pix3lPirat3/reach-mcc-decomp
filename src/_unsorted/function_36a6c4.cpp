struct Context;

struct Argument {
    char reserved[8];
    int value;
};

extern "C" void function_36a4ac(Context* context, int value);

extern "C" char function_36a6c4(Context* context, void*, const Argument* argument)
{
    function_36a4ac(context, argument->value);
    return 1;
}
