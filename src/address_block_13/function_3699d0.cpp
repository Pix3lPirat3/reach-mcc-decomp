struct Result {
    int kind;
    int reserved4;
    int value;
};

extern "C" int function_7b014();

extern "C" char function_3699d0(void*, void*, Result* result)
{
    result->value = static_cast<unsigned char>(function_7b014());
    result->kind = 1;
    return 1;
}
