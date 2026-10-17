struct dsp_connection {
    unsigned char reserved0[0x38];
    short rows;
    short columns;
    unsigned char reserved3c[4];
    float* source;
    unsigned char reserved48[8];
    float* target;
    unsigned char reserved58[0x10];
    float volume;
    unsigned int field_6c;
    unsigned char reserved70[0x10];
    float last_volume;
};

extern "C" long long function_585f50(dsp_connection* connection) {
    if (connection->source != 0) {
        int index = 0;
        if (connection->columns * connection->rows > 0) {
            do {
                connection->target[index] = connection->source[index] * connection->volume;
                index++;
            } while (index < connection->columns * connection->rows);
        }
    }
    connection->last_volume = connection->volume;
    connection->field_6c = 0;
    return 0;
}
