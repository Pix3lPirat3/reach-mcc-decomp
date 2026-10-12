typedef struct bf_key_st {
    unsigned int P[16 + 2];
    unsigned int S[4 * 256];
} BF_KEY;
void BF_encrypt(unsigned int *data, const BF_KEY *key);
void BF_encrypt(unsigned int *data, const BF_KEY *key)
{
    register unsigned int l, r;
    register const unsigned int *p, *s;
    p = key->P;
    s = &(key->S[0]);
    l = data[0];
    r = data[1];
    l ^= p[0];
    ( r^=p[1], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[2], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[3], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[4], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[5], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[6], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[7], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[8], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[9], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[10], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[11], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[12], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[13], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[14], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[15], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[16], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    r ^= p[16 + 1];
    data[1] = l & 0xffffffffU;
    data[0] = r & 0xffffffffU;
}
