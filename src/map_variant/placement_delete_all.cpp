struct iterated_object {
    unsigned char head[0x1c];
    short slot;
};

struct object_iterator {
    iterated_object* object;
    int type;
    unsigned int field_c;
    unsigned int field_10;
    unsigned int field_14;
    int handle;
    int sentinel;
};

extern "C" bool iterator_next_473a78(object_iterator* iterator);
extern "C" void object_delete_46f2a4(int handle);

extern "C" void forge_delete_all_6ef48() {
    object_iterator iterator;
    iterator.object = nullptr;
    iterator.field_c = 0;
    iterator.field_10 = 0;
    iterator.field_14 = 0;
    iterator.handle = -1;
    iterator.sentinel = static_cast<int>(0x86868686);
    iterator.type = 0x5ce;
    while (iterator_next_473a78(&iterator)) {
        if (-1 != iterator.object->slot) {
            object_delete_46f2a4(iterator.handle);
        }
    }
}
