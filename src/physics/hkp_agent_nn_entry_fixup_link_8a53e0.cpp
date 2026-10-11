struct entry;

struct link_slot {
    entry* owner;
    void* reserved8;
};

struct track {
    unsigned char reserved0[0x70];
    link_slot* slots;
};

struct entry {
    unsigned char reserved0[4];
    unsigned short index_a;
    unsigned short index_b;
    unsigned char reserved8[0x10];
    track* track_a;
    track* track_b;
};

extern "C" link_slot* hkp_agent_nn_entry_fixup_link_8a53e0(entry* self) {
    unsigned int index_a = self->index_a;
    unsigned int index_b = self->index_b;
    self->track_a->slots[index_a].owner = self;
    link_slot* slots_b = self->track_b->slots;
    slots_b[index_b].owner = self;
    return slots_b;
}
