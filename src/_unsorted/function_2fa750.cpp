struct value_in {
    unsigned char reserved0[8];
    void* value;
};

extern "C" void function_2fa238(void* object, void* value);

extern "C" char function_2fa750(void* object, void*, value_in* in) {
    function_2fa238(object, in->value);
    return 1;
}
