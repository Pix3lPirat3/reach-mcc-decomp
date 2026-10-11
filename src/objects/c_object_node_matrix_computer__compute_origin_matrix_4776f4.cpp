struct object_data {
    unsigned char reserved0[4];
    unsigned int flags;
    unsigned char reserved8[0x3C];
    float block_44[3];
    float block_50[3];
    float block_5c[3];
    unsigned char reserved68[0x18];
    float field_80;
};

struct node_computer {
    unsigned char reserved0[8];
    object_data* object;
    unsigned char reserved10[0x478];
    void* field_488;
    char field_490;
};

extern "C" float function_4794ac(node_computer* computer, float* first, float* second, float* third, float scale, char flag, void* extra, char mode, void* output);

extern "C" float c_object_node_matrix_computer__compute_origin_matrix_4776f4(node_computer* computer, void* output) {
    object_data* object = computer->object;
    return function_4794ac(computer, object->block_44, object->block_50, object->block_5c, object->field_80, (char)((object->flags >> 9) & 1), computer->field_488, computer->field_490, output);
}
