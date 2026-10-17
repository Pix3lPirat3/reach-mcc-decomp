struct ragdoll_constraint_data {
    unsigned char reserved0[0x15A];
    unsigned char flags;
};

extern "C" char function_8b3640(ragdoll_constraint_data* data) {
    return data->flags >> 1;
}
