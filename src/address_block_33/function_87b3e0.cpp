struct small_object {
    unsigned char reserved0[8];
    long long field_8;
};

extern "C" void function_87b3e0(small_object* object) {
    object->field_8 = 0;
}
