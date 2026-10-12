struct object_c {
    unsigned char reserved0[8];
    unsigned long long field_8;
};

struct object_a {
    unsigned char reserved0[0x288];
    unsigned long long field_288;
};
extern "C" bool function_360278(object_a* object, long long, object_c* input) {
    object->field_288 = input->field_8;
    return true;
}
