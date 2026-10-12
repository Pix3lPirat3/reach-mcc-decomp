typedef unsigned int RC2_INT;
typedef struct rc2_key_st {
    RC2_INT data[64];
} RC2_KEY;
void RC2_ecb_encrypt(const unsigned char *in, unsigned char *out,
                     RC2_KEY *key, int enc);
void RC2_encrypt(unsigned long *data, RC2_KEY *key);
void RC2_decrypt(unsigned long *data, RC2_KEY *key);
void RC2_ecb_encrypt(const unsigned char *in, unsigned char *out, RC2_KEY *ks,
                     int encrypt)
{
    unsigned long l, d[2];
    (l =((unsigned long)(*((in)++))) , l|=((unsigned long)(*((in)++)))<< 8L, l|=((unsigned long)(*((in)++)))<<16L, l|=((unsigned long)(*((in)++)))<<24L);
    d[0] = l;
    (l =((unsigned long)(*((in)++))) , l|=((unsigned long)(*((in)++)))<< 8L, l|=((unsigned long)(*((in)++)))<<16L, l|=((unsigned long)(*((in)++)))<<24L);
    d[1] = l;
    if (encrypt)
        RC2_encrypt(d, ks);
    else
        RC2_decrypt(d, ks);
    l = d[0];
    (*((out)++)=(unsigned char)(((l) )&0xff), *((out)++)=(unsigned char)(((l)>> 8L)&0xff), *((out)++)=(unsigned char)(((l)>>16L)&0xff), *((out)++)=(unsigned char)(((l)>>24L)&0xff));
    l = d[1];
    (*((out)++)=(unsigned char)(((l) )&0xff), *((out)++)=(unsigned char)(((l)>> 8L)&0xff), *((out)++)=(unsigned char)(((l)>>16L)&0xff), *((out)++)=(unsigned char)(((l)>>24L)&0xff));
    l = d[0] = d[1] = 0;
}
