__pragma(warning(disable: 4115 4267))
typedef unsigned __int64 size_t;
size_t __cdecl strlen(
      char const* _Str
    );
typedef struct asn1_string_st ASN1_TIME;
typedef struct asn1_string_st ASN1_GENERALIZEDTIME;
typedef struct asn1_string_st ASN1_STRING;
struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};
int ASN1_STRING_copy(ASN1_STRING *dst, const ASN1_STRING *str);
int ASN1_GENERALIZEDTIME_check(const ASN1_GENERALIZEDTIME *a);
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s, const char *str);
int asn1_time_to_tm(struct tm *tm, const ASN1_TIME *d);
int asn1_generalizedtime_to_tm(struct tm *tm, const ASN1_GENERALIZEDTIME *d);
int asn1_generalizedtime_to_tm(struct tm *tm, const ASN1_GENERALIZEDTIME *d)
{
    if (d->type != 24)
        return 0;
    return asn1_time_to_tm(tm, d);
}
int ASN1_GENERALIZEDTIME_check(const ASN1_GENERALIZEDTIME *d)
{
    return asn1_generalizedtime_to_tm(((void *)0), d);
}
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s, const char *str)
{
    ASN1_GENERALIZEDTIME t;
    t.type = 24;
    t.length = strlen(str);
    t.data = (unsigned char *)str;
    t.flags = 0;
    if (!ASN1_GENERALIZEDTIME_check(&t))
        return 0;
    if (s != ((void *)0) && !ASN1_STRING_copy(s, &t))
        return 0;
    return 1;
}
