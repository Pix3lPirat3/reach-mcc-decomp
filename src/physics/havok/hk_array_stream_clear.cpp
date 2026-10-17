struct array_header {
    unsigned char reserved0[8];
    int size;
};

struct array_stream {
    unsigned char reserved0[0x10];
    array_header* header;
    int size;
};

extern "C" void function_675840(void * stream);

extern "C" void function_878f80(array_stream* stream) {
    stream->header->size = 0;
    stream->size = 0;
    return function_675840(stream);
}
