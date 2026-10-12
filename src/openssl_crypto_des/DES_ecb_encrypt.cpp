typedef unsigned int DES_LONG;
typedef unsigned char DES_cblock[8];
typedef  unsigned char const_DES_cblock[8];
typedef struct DES_ks {
    union {
        DES_cblock cblock;
        DES_LONG deslong[2];
    } ks[16];
} DES_key_schedule;
void DES_ecb_encrypt(const_DES_cblock *input, DES_cblock *output,
                     DES_key_schedule *ks, int enc);
void DES_encrypt1(DES_LONG *data, DES_key_schedule *ks, int enc);
void DES_ecb_encrypt(const_DES_cblock *input, DES_cblock *output,
                     DES_key_schedule *ks, int enc)
{
    register DES_LONG l;
    DES_LONG ll[2];
    const unsigned char *in = &(*input)[0];
    unsigned char *out = &(*output)[0];
    (l =((DES_LONG)(*((in)++))) , l|=((DES_LONG)(*((in)++)))<< 8L, l|=((DES_LONG)(*((in)++)))<<16L, l|=((DES_LONG)(*((in)++)))<<24L);
    ll[0] = l;
    (l =((DES_LONG)(*((in)++))) , l|=((DES_LONG)(*((in)++)))<< 8L, l|=((DES_LONG)(*((in)++)))<<16L, l|=((DES_LONG)(*((in)++)))<<24L);
    ll[1] = l;
    DES_encrypt1(ll, ks, enc);
    l = ll[0];
    (*((out)++)=(unsigned char)(((l) )&0xff), *((out)++)=(unsigned char)(((l)>> 8L)&0xff), *((out)++)=(unsigned char)(((l)>>16L)&0xff), *((out)++)=(unsigned char)(((l)>>24L)&0xff));
    l = ll[1];
    (*((out)++)=(unsigned char)(((l) )&0xff), *((out)++)=(unsigned char)(((l)>> 8L)&0xff), *((out)++)=(unsigned char)(((l)>>16L)&0xff), *((out)++)=(unsigned char)(((l)>>24L)&0xff));
    l = ll[0] = ll[1] = 0;
}
