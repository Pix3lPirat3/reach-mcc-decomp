struct source {
    char reserved0[0x238];
    int field_238;
};

struct request {
    int field_0;
};

extern "C" void function_34d418(void * object, void * other);

extern "C" void function_30684c(source* object, request* other) {
    function_34d418(object, other);
    int value = other->field_0;
    object->field_238 = value;
}
