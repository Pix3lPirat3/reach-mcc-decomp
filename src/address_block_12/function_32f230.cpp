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

extern "C" char function_32f230(object_layout* object, void*, value_slot* out) {
    char* data = object->data;
    int value;
    if (data == nullptr || object->state != 2) {
        value = -1;
    } else {
        long long index = object->field_7c;
        if ((int)index < 0 || (int)index >= *reinterpret_cast<int*>(data + 0x1e1cc)) {
            value = -1;
        } else {
            value = *reinterpret_cast<short*>(data + index * 4 + 0x1e1d0);
        }
    }
    out->kind = 1;
    out->number = value;
    return 1;
}
