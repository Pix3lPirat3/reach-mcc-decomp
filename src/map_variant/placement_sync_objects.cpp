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

#pragma pack(push, 1)
struct placement_record {
    unsigned char pad0[4];
    int ref_b;
    unsigned char pad1[0x4c - 8];
};
struct variant_state {
    unsigned char head[0x14fc];
    placement_record records[651];
};
#pragma pack(pop)

extern "C" bool iterator_next_473a78(object_iterator* iterator);
extern "C" void object_update_6f240(variant_state* state, int handle);

extern "C" void forge_sync_objects_6f4f0(variant_state* state, int index) {
    placement_record* record = &state->records[index];
    object_iterator iterator;
    iterator.object = nullptr;
    iterator.field_c = 0;
    iterator.field_10 = 0;
    iterator.field_14 = 0;
    iterator.handle = -1;
    iterator.sentinel = static_cast<int>(0x86868686);
    iterator.type = 0x5ce;
    while (iterator_next_473a78(&iterator)) {
        if (iterator.object->slot == index) {
            if (iterator.handle != record->ref_b) {
                object_update_6f240(state, iterator.handle);
            }
        }
    }
}
