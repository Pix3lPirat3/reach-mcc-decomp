typedef struct bio_st BIO;
int PEM_read_bio(BIO *bp, char **name, char **header,
                 unsigned char **data, long *len);
int PEM_read_bio_ex(BIO *bp, char **name, char **header,
                    unsigned char **data, long *len, unsigned int flags);
int PEM_read_bio(BIO *bp, char **name, char **header, unsigned char **data,
                 long *len)
{
    return PEM_read_bio_ex(bp, name, header, data, len, 0x2);
}
