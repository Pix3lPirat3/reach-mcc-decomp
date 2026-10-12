struct object_layout {
    char reserved0[0x28];
    char state;
    char reserved29[0x47];
    char* data;
    int field_78;
    int field_7c;
};

struct value_slot {
    int kind;
    int reserved4;
    char* pointer;
};

extern "C" char function_32ec0c(object_layout* object, void*, value_slot* out) {
    char* data = object->data;
    char* block = nullptr;
    if (data != nullptr && object->state == 2)
        block = data + 0x1090;
    out->kind = 3;
    out->pointer = block != nullptr ? block + 8 : nullptr;
    return 1;
}
