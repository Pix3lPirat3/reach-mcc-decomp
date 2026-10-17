struct bit_writer;

extern "C" void function_461724(void* payload, void * writer);
extern "C" void function_462388(void* payload, void * writer);

extern "C" void function_462a34(void*, void*, void* payload, bit_writer* writer) {
    function_461724(payload, writer);
    function_462388(static_cast<char*>(payload) + 0x1c, writer);
}
