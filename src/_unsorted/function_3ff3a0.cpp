struct record {
    unsigned int words[4];
};

struct table {
    unsigned char reserved0[0x88];
    record records[1];
};

struct request {
    int index;
    record value;
};

extern "C" char function_3ff3a0(table* destination, request* source) {
    long long index = source->index;
    destination->records[index] = source->value;
    return 1;
}
