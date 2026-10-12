struct hinge_constraint_data {
    unsigned char reserved0[0xB6];
    unsigned char flags;
};

extern "C" char function_8b3f40(hinge_constraint_data* data) {
    return data->flags >> 1;
}
