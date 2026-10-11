struct buffered_stream_reader {
    unsigned char reserved0[0x20];
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
};

extern "C" int hk_buffered_stream_reader_set_mark_872910(buffered_stream_reader* reader, int mark_limit) {
    reader->field_2C = reader->field_20;
    int field_28 = reader->field_28;
    reader->field_30 = mark_limit;
    return mark_limit > field_28;
}
