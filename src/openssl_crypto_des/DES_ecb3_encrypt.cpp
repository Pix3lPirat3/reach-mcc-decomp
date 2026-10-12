typedef unsigned int DES_LONG;
typedef unsigned char DES_cblock[8];
typedef  unsigned char const_DES_cblock[8];
typedef struct DES_ks {
    union {
        DES_cblock cblock;
        DES_LONG deslong[2];
    } ks[16];
} DES_key_schedule;
void DES_ecb3_encrypt(const_DES_cblock *input, DES_cblock *output,
                      DES_key_schedule *ks1, DES_key_schedule *ks2,
                      DES_key_schedule *ks3, int enc);
void DES_encrypt3(DES_LONG *data, DES_key_schedule *ks1,
                  DES_key_schedule *ks2, DES_key_schedule *ks3);
void DES_decrypt3(DES_LONG *data, DES_key_schedule *ks1,
                  DES_key_schedule *ks2, DES_key_schedule *ks3);
void DES_ecb3_encrypt(const_DES_cblock *input, DES_cblock *output,
                      DES_key_schedule *ks1, DES_key_schedule *ks2,
                      DES_key_schedule *ks3, int enc)
{
    register DES_LONG l0, l1;
    DES_LONG ll[2];
    const unsigned char *in = &(*input)[0];
    unsigned char *out = &(*output)[0];
    (l0 =((DES_LONG)(*((in)++))) , l0|=((DES_LONG)(*((in)++)))<< 8L, l0|=((DES_LONG)(*((in)++)))<<16L, l0|=((DES_LONG)(*((in)++)))<<24L);
    (l1 =((DES_LONG)(*((in)++))) , l1|=((DES_LONG)(*((in)++)))<< 8L, l1|=((DES_LONG)(*((in)++)))<<16L, l1|=((DES_LONG)(*((in)++)))<<24L);
    ll[0] = l0;
    ll[1] = l1;
    if (enc)
        DES_encrypt3(ll, ks1, ks2, ks3);
    else
        DES_decrypt3(ll, ks1, ks2, ks3);
    l0 = ll[0];
    l1 = ll[1];
    (*((out)++)=(unsigned char)(((l0) )&0xff), *((out)++)=(unsigned char)(((l0)>> 8L)&0xff), *((out)++)=(unsigned char)(((l0)>>16L)&0xff), *((out)++)=(unsigned char)(((l0)>>24L)&0xff));
    (*((out)++)=(unsigned char)(((l1) )&0xff), *((out)++)=(unsigned char)(((l1)>> 8L)&0xff), *((out)++)=(unsigned char)(((l1)>>16L)&0xff), *((out)++)=(unsigned char)(((l1)>>24L)&0xff));
}
