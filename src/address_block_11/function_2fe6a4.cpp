struct object_c {
    unsigned char reserved0[8];
    unsigned int field_8;
};

struct object_a {
    unsigned char reserved0[0x74];
    unsigned int field_74;
    unsigned char reserved78[4];
    unsigned int field_7c;
};
extern "C" bool function_2fe6a4(object_a* object, long long, object_c* input) {
    unsigned int loaded = input->field_8;
    object->field_7c = 0;
    object->field_74 = loaded;
    return true;
}
