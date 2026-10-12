struct object_layout {
    char reserved0[0x28];
    char state;
    char reserved29[0x47];
    char* data;
    int field_78;
};

extern "C" long long function_32e4bc(object_layout* object, int* out, int index) {
    char* data = object->data;
    int value;
    if (data == nullptr || object->state != 2) {
        value = -1;
    } else {
        long long slot = object->field_78;
        char* block;
        if ((int)slot < 0 || (int)slot >= *reinterpret_cast<int*>(data + 0x254a4))
            block = nullptr;
        else
            block = data + 0x1e250 + (long long)*reinterpret_cast<int*>(data + slot * 4 + 0x254a8) * 0x261c;
        long long entry = *reinterpret_cast<int*>(block + (long long)index * 4 + 0x241c);
        char* record = block + (entry + entry * 8 + 3) * 8;
        if (record == nullptr)
            value = -1;
        else
            value = *reinterpret_cast<int*>(record);
    }
    *out = value;
    return (long long)out;
}
