struct text_source {
    char reserved0[8];
    const void* text;
};

extern "C" long long function_35c3c(void* destination, const void* source, long long length);

extern "C" char function_30ff80(char* object, long long, const text_source* input) {
    const void* text = input->text;
    if (text == nullptr)
        return 1;
    function_35c3c(object + 0xA0, text, 0x18);
    object[0xD1] = 1;
    return 1;
}
