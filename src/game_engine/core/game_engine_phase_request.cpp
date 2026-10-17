struct block_a {
    char reserved_00[17];
    char byte_11;
};

struct block_b {
    char reserved_00[0x840c];
    int value;
};

extern __declspec(thread) block_b * tls_20;
extern __declspec(thread) block_a * tls_48;

extern "C" void function_7fbec(int value)
{
    if (tls_48->byte_11 != 4)
        tls_20->value = value;
}
