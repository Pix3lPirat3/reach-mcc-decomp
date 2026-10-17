struct object_layout {
    char reserved0[0x28];
    char state;
    char reserved29[0x47];
    long long data;
    int field_78;
    int field_7c;
};

struct value_slot {
    int kind;
    int reserved4;
    int number;
};

extern "C" char function_32fa74(object_layout* object, void*, value_slot* out) {
    long long data = object->data;
    int value = -1;
    if (data != 0 && object->state == 2) {
        long long index = object->field_7c;
        long long entry;
        if ((int)index < 0 || (int)index >= *reinterpret_cast<int*>(data + 0x1e1cc)) {
        no_entry:
            entry = 0;
        } else {
            short slot = (short)*reinterpret_cast<unsigned short*>(data + index * 4 + 0x1e1d0);
            if ((short)value == slot)
                goto no_entry;
            entry = data + 0x1148 + (long long)slot * 0x1af8;
        }
        if (entry != 0)
            value = *reinterpret_cast<int*>(entry + 0x140);
    }
    out->kind = 6;
    out->number = value;
    return 1;
}
