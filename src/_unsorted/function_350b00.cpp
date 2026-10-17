struct Value {
    int kind;
    int reserved_4;
    void* address;
};

extern "C" char function_350b00(char* object, void*, Value* out)
{
    out->kind = 3;
    out->address = object + 0x4c4;
    return 1;
}
