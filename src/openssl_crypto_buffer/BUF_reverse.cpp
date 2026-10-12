typedef unsigned __int64 size_t;
void BUF_reverse(unsigned char *out, const unsigned char *in, size_t siz);
void BUF_reverse(unsigned char *out, const unsigned char *in, size_t size)
{
    size_t i;
    if (in) {
        out += size - 1;
        for (i = 0; i < size; i++)
            *out-- = *in++;
    } else {
        unsigned char *q;
        char c;
        q = out + size - 1;
        for (i = 0; i < size / 2; i++) {
            c = *q;
            *q-- = *out;
            *out++ = c;
        }
    }
}
