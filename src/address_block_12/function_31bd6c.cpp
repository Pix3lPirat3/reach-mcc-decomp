struct source_record {
    char reserved0[0x20];
    const void* field_20;
    char reserved28[0x30];
    char text[1];
};

struct text_source {
    char reserved0[8];
    const source_record* record;
};

extern "C" long long function_35c3c(void* destination, const void* source, long long length);

extern "C" char function_31bd6c(char* object, long long, const text_source* input) {
    const source_record* record = input->record;
    if (record == nullptr)
        return 1;
    *reinterpret_cast<const void**>(object + 0x98) = record->field_20;
    function_35c3c(object + 0xA0, record->text, 0x10);
    return 1;
}
