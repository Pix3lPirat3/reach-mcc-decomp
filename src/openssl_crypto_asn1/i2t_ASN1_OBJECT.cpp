typedef struct asn1_object_st ASN1_OBJECT;
int i2t_ASN1_OBJECT(char *buf, int buf_len, const ASN1_OBJECT *a);
int OBJ_obj2txt(char *buf, int buf_len, const ASN1_OBJECT *a, int no_name);
struct asn1_object_st {
    const char *sn, *ln;
    int nid;
    int length;
    const unsigned char *data;
    int flags;
};
int i2t_ASN1_OBJECT(char *buf, int buf_len, const ASN1_OBJECT *a)
{
    return OBJ_obj2txt(buf, buf_len, a, 0);
}
