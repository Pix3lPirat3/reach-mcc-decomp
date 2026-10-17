struct resampler {
    unsigned char reserved0[0x288];
    unsigned char* field_288;
    unsigned char reserved290[0xC];
    int field_29c;
    unsigned char reserved2a0[0x50];
    int field_2f0;
};

struct holder {
    resampler* field_0;
};

extern "C" long long function_625c10(resampler* target);

extern "C" int function_64bc80(holder* object) {
    resampler* inner = object->field_0;
    inner->field_288 = (unsigned char*)inner + 0x4F8;
    function_625c10(inner);
    unsigned char* block = inner->field_288;
    inner->field_29c = 0;
    *(int*)(block + 0x10) = 0;
    inner->field_2f0 = 0;
    return 0;
}
