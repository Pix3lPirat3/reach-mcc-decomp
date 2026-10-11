struct pickup_entry {
    unsigned int key;
    unsigned int value;
};

struct pickup_table {
    pickup_entry entries[3];
    int count;
};

extern "C" const unsigned int* object_get_payload_by_type_mask_4739cc(int object, unsigned int type_mask);

extern "C" unsigned int c_chud_impulse_manager__get_ammo_pickup_count_2c1890(const pickup_table* table, int object) {
    if (table->count > 0) {
        const unsigned int* payload = object_get_payload_by_type_mask_4739cc(object, 4);
        if (payload == 0 || table->count <= 0)
            return 0;
        unsigned int key = *payload;
        int index = 0;
        long long slot = 0;
        long long count = table->count;
        while (table->entries[slot].key != key) {
            index++;
            slot++;
            if (slot < count)
                continue;
            return 0;
        }
        return table->entries[index].value;
    }
    return 0;
}
