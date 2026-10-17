typedef long long (*handler)(void);

extern "C" long long function_904b00(char* table, long long, unsigned char* op) {
    return (*(handler*)(table + ((unsigned long long)op[1] << 5) + 0x138))();
}
