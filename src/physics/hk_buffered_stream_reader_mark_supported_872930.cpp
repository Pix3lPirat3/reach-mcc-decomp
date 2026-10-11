struct buffered_stream_reader {
    unsigned char reserved0[0x28];
    int field_28;
};

extern "C" bool* hk_buffered_stream_reader_mark_supported_872930(buffered_stream_reader* reader, bool* result) {
    *result = reader->field_28 != 0;
    return result;
}
