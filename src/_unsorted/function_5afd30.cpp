struct connection_owner {
    unsigned char reserved0[0x210];
    void* connection;
};

struct channel_group {
    unsigned char reserved0[0x40];
    void* matrix_40;
    unsigned char reserved48[0x28];
    connection_owner* owner_70;
};

extern "C" int function_5923a0(channel_group* group, float* matrix, int in_channels, int out_channels, int stride, unsigned char flag);
extern "C" int function_5889f0(void* connection, float* matrix, int in_channels, int out_channels, int stride, int count, unsigned char flag);

extern "C" int function_5afd30(channel_group* group, float* matrix, int in_channels, int out_channels, int stride, unsigned char flag) {
    if (matrix == 0 && group->matrix_40 == 0)
        return 0;
    if (flag != 0) {
        int result = function_5923a0(group, matrix, in_channels, out_channels, stride, flag);
        if (result != 0)
            return result;
    }
    int result = function_5889f0(group->owner_70->connection, matrix, in_channels, out_channels, stride, 0x40, 1);
    if (result != 0)
        return result;
    return 0;
}
