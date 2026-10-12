typedef struct bf_key_st {
    unsigned int P[16 + 2];
    unsigned int S[4 * 256];
} BF_KEY;
void BF_decrypt(unsigned int *data, const BF_KEY *key);
void BF_decrypt(unsigned int *data, const BF_KEY *key)
{
    register unsigned int l, r;
    register const unsigned int *p, *s;
    p = key->P;
    s = &(key->S[0]);
    l = data[0];
    r = data[1];
    l ^= p[16 + 1];
    ( r^=p[16], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[15], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[14], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[13], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[12], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[11], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[10], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[9], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[8], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[7], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[6], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[5], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[4], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[3], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    ( r^=p[2], r^=((( s[ ((l>>24)&0xff)] + s[0x0100+((l>>16)&0xff)])^ s[0x0200+((l>> 8)&0xff)])+ s[0x0300+((l )&0xff)])&0xffffffffU );
    ( l^=p[1], l^=((( s[ ((r>>24)&0xff)] + s[0x0100+((r>>16)&0xff)])^ s[0x0200+((r>> 8)&0xff)])+ s[0x0300+((r )&0xff)])&0xffffffffU );
    r ^= p[0];
    data[1] = l & 0xffffffffU;
    data[0] = r & 0xffffffffU;
}
