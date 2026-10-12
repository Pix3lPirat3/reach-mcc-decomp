typedef unsigned int IDEA_INT;
typedef struct idea_key_st {
    IDEA_INT data[9][6];
} IDEA_KEY_SCHEDULE;
void IDEA_ecb_encrypt(const unsigned char *in, unsigned char *out,
                      IDEA_KEY_SCHEDULE *ks);
void IDEA_encrypt(unsigned long *in, IDEA_KEY_SCHEDULE *ks);
void IDEA_ecb_encrypt(const unsigned char *in, unsigned char *out,
                      IDEA_KEY_SCHEDULE *ks)
{
    unsigned long l0, l1, d[2];
    (l0 =((unsigned long)(*((in)++)))<<24L, l0|=((unsigned long)(*((in)++)))<<16L, l0|=((unsigned long)(*((in)++)))<< 8L, l0|=((unsigned long)(*((in)++))));
    d[0] = l0;
    (l1 =((unsigned long)(*((in)++)))<<24L, l1|=((unsigned long)(*((in)++)))<<16L, l1|=((unsigned long)(*((in)++)))<< 8L, l1|=((unsigned long)(*((in)++))));
    d[1] = l1;
    IDEA_encrypt(d, ks);
    l0 = d[0];
    (*((out)++)=(unsigned char)(((l0)>>24L)&0xff), *((out)++)=(unsigned char)(((l0)>>16L)&0xff), *((out)++)=(unsigned char)(((l0)>> 8L)&0xff), *((out)++)=(unsigned char)(((l0) )&0xff));
    l1 = d[1];
    (*((out)++)=(unsigned char)(((l1)>>24L)&0xff), *((out)++)=(unsigned char)(((l1)>>16L)&0xff), *((out)++)=(unsigned char)(((l1)>> 8L)&0xff), *((out)++)=(unsigned char)(((l1) )&0xff));
    l0 = l1 = d[0] = d[1] = 0;
}
