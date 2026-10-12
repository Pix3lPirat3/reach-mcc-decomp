typedef struct asn1_string_st ASN1_INTEGER;
typedef struct asn1_string_st ASN1_TIME;
typedef struct x509_revoked_st X509_REVOKED;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
struct stack_st_X509_EXTENSION;
void *X509_REVOKED_get_ext_d2i(const X509_REVOKED *x, int nid, int *crit,
                               int *idx);
struct x509_revoked_st {
    ASN1_INTEGER serialNumber;
    ASN1_TIME *revocationDate;
    struct stack_st_X509_EXTENSION *extensions;
    struct stack_st_GENERAL_NAME *issuer;
    int reason;
    int sequence;
};
struct stack_st_GENERAL_NAME;
void *X509V3_get_d2i(const struct stack_st_X509_EXTENSION *x, int nid, int *crit,
                     int *idx);
void *X509_REVOKED_get_ext_d2i(const X509_REVOKED *x, int nid, int *crit, int *idx)
{
    return X509V3_get_d2i(x->extensions, nid, crit, idx);
}
