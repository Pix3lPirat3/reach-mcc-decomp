struct text_source {
    char reserved0[8];
    const void* text;
};

extern "C" long long function_35c3c(void* destination, const void* source, long long length);

extern "C" char function_311984(char* object, long long, const text_source* input) {
    const void* text = input->text;
    if (text == nullptr)
        return 1;
    function_35c3c(object + 0xD8, text, 0x10);
    object[0xF8] = 1;
    return 1;
}
