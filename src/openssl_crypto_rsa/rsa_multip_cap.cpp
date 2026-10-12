int rsa_multip_cap(int bits);
int rsa_multip_cap(int bits)
{
    int cap = 5;
    if (bits < 1024)
        cap = 2;
    else if (bits < 4096)
        cap = 3;
    else if (bits < 8192)
        cap = 4;
    if (cap > 5)
        cap = 5;
    return cap;
}
