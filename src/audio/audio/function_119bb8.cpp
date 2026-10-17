struct request_block {
    unsigned char reserved0[16];
    int field_10;
    int reserved14;
    int field_18;
    unsigned char reserved1c[36];
};

struct handle_table {
    unsigned char reserved0[0xC];
    unsigned int handles[4];
};

extern "C" request_block* function_bc170(request_block* request);

extern "C" long long function_119bb8(handle_table* table) {
    request_block request;
    unsigned int* slot = table->handles;
    long long count = 4;
    long long result;
    do {
        result = *slot;
        if ((int)result != -1) {
            request.field_10 = 0x20;
            request.field_18 = (int)result;
            result = (long long)function_bc170(&request);
            *slot = (unsigned int)-1;
        }
        slot += 1;
        --count;
    } while (count != 0);
    return result;
}
