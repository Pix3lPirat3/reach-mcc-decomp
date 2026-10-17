struct object_state {
    unsigned char reserved0[0x388];
    int field_388;
};

extern "C" int function_2f7a70(object_state* object);

extern "C" int function_2f872c(object_state* object) {
    return function_2f7a70(object) + object->field_388;
}
