typedef struct bf_key_st {
    unsigned int P[16 + 2];
    unsigned int S[4 * 256];
} BF_KEY;
void BF_encrypt(unsigned int *data, const BF_KEY *key);
void BF_decrypt(unsigned int *data, const BF_KEY *key);
void BF_ecb_encrypt(const unsigned char *in, unsigned char *out,
                    const BF_KEY *key, int enc);
void BF_ecb_encrypt(const unsigned char *in, unsigned char *out,
                    const BF_KEY *key, int encrypt)
{
    unsigned int l, d[2];
    (l =((unsigned long)(*((in)++)))<<24L, l|=((unsigned long)(*((in)++)))<<16L, l|=((unsigned long)(*((in)++)))<< 8L, l|=((unsigned long)(*((in)++))));
    d[0] = l;
    (l =((unsigned long)(*((in)++)))<<24L, l|=((unsigned long)(*((in)++)))<<16L, l|=((unsigned long)(*((in)++)))<< 8L, l|=((unsigned long)(*((in)++))));
    d[1] = l;
    if (encrypt)
        BF_encrypt(d, key);
    else
        BF_decrypt(d, key);
    l = d[0];
    (*((out)++)=(unsigned char)(((l)>>24L)&0xff), *((out)++)=(unsigned char)(((l)>>16L)&0xff), *((out)++)=(unsigned char)(((l)>> 8L)&0xff), *((out)++)=(unsigned char)(((l) )&0xff));
    l = d[1];
    (*((out)++)=(unsigned char)(((l)>>24L)&0xff), *((out)++)=(unsigned char)(((l)>>16L)&0xff), *((out)++)=(unsigned char)(((l)>> 8L)&0xff), *((out)++)=(unsigned char)(((l) )&0xff));
    l = d[0] = d[1] = 0;
}
