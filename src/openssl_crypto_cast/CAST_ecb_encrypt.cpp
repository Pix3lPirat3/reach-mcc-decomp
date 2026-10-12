typedef struct cast_key_st {
    unsigned int data[32];
    int short_key;
} CAST_KEY;
void CAST_ecb_encrypt(const unsigned char *in, unsigned char *out,
                      const CAST_KEY *key, int enc);
void CAST_encrypt(unsigned int *data, const CAST_KEY *key);
void CAST_decrypt(unsigned int *data, const CAST_KEY *key);
void CAST_ecb_encrypt(const unsigned char *in, unsigned char *out,
                      const CAST_KEY *ks, int enc)
{
    unsigned int l, d[2];
    (l =((unsigned long)(*((in)++)))<<24L, l|=((unsigned long)(*((in)++)))<<16L, l|=((unsigned long)(*((in)++)))<< 8L, l|=((unsigned long)(*((in)++))));
    d[0] = l;
    (l =((unsigned long)(*((in)++)))<<24L, l|=((unsigned long)(*((in)++)))<<16L, l|=((unsigned long)(*((in)++)))<< 8L, l|=((unsigned long)(*((in)++))));
    d[1] = l;
    if (enc)
        CAST_encrypt(d, ks);
    else
        CAST_decrypt(d, ks);
    l = d[0];
    (*((out)++)=(unsigned char)(((l)>>24L)&0xff), *((out)++)=(unsigned char)(((l)>>16L)&0xff), *((out)++)=(unsigned char)(((l)>> 8L)&0xff), *((out)++)=(unsigned char)(((l) )&0xff));
    l = d[1];
    (*((out)++)=(unsigned char)(((l)>>24L)&0xff), *((out)++)=(unsigned char)(((l)>>16L)&0xff), *((out)++)=(unsigned char)(((l)>> 8L)&0xff), *((out)++)=(unsigned char)(((l) )&0xff));
    l = d[0] = d[1] = 0;
}
