struct vertex_data {
    int x;
    unsigned char reserved4[0xC];
    int y;
    unsigned char reserved14[0xC];
    int z;
};

struct convex_shape {
    unsigned char reserved0[0x50];
    vertex_data* vertices;
};

struct vertex_out {
    int x;
    int y;
    int z;
    int w;
};

extern "C" int function_883470(convex_shape* shape, vertex_out* out) {
    vertex_data* data = shape->vertices;
    out->x = data->x;
    out->y = data->y;
    int z = data->z;
    out->z = z;
    out->w = 0;
    return z;
}
