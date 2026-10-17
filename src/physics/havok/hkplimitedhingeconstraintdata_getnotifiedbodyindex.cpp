struct limited_hinge_constraint_data {
    unsigned char reserved0[0xEA];
    unsigned char flags;
};

extern "C" char function_8b4560(limited_hinge_constraint_data* data) {
    return data->flags >> 1;
}
