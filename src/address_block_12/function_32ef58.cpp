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
    int number;
};

extern "C" char function_32ef58(object_layout* object, void*, value_slot* out) {
    char* data = object->data;
    int value = 0;
    if (data != nullptr && object->state == 2)
        value = *reinterpret_cast<int*>(data + 0x1e1cc);
    out->number = value;
    out->kind = 1;
    return 1;
}
