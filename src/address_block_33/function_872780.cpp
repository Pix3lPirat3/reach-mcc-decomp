struct buffered_stream_reader {
    unsigned char reserved0[0x20];
    char ok;
};

extern "C" char* function_872780(buffered_stream_reader* reader, char* result) {
    *result = reader->ok;
    return result;
}
