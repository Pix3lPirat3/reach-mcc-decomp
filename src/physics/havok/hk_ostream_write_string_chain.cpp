struct hk_ostream_writer;

struct hk_ostream_owner {
    unsigned char reserved0[0x10];
    hk_ostream_writer* writer;
};

extern "C" void function_8719e0(void * writer, void * text);

extern "C" hk_ostream_owner* function_871a90(hk_ostream_owner* owner, void * text) {
    function_8719e0(owner->writer, text);
    return owner;
}
