typedef struct bio_st BIO;
typedef struct conf_st CONF;
typedef struct lhash_st OPENSSL_LHASH;
void *OPENSSL_LH_retrieve(OPENSSL_LHASH *lh, const void *data);
typedef struct {
    char *section;
    char *name;
    char *value;
} CONF_VALUE;
struct lhash_st_CONF_VALUE { union lh_CONF_VALUE_dummy { void* d1; unsigned long d2; int d3; } dummy; };
static  __inline CONF_VALUE *lh_CONF_VALUE_retrieve(struct lhash_st_CONF_VALUE *lh, const CONF_VALUE *d) { return (CONF_VALUE *)OPENSSL_LH_retrieve((OPENSSL_LHASH *)lh, d); }
struct lhash_st_CONF_VALUE;
struct conf_st;
struct conf_method_st;
typedef struct conf_method_st CONF_METHOD;
struct conf_method_st {
    const char *name;
    CONF *(*create) (CONF_METHOD *meth);
    int (*init) (CONF *conf);
    int (*destroy) (CONF *conf);
    int (*destroy_data) (CONF *conf);
    int (*load_bio) (CONF *conf, BIO *bp, long *eline);
    int (*dump) (const CONF *conf, BIO *bp);
    int (*is_number) (const CONF *conf, char c);
    int (*to_int) (const CONF *conf, char c);
    int (*load) (CONF *conf, const char *name, long *eline);
};
struct conf_st {
    CONF_METHOD *meth;
    void *meth_data;
    struct lhash_st_CONF_VALUE *data;
};
CONF_VALUE *_CONF_get_section(const CONF *conf, const char *section);
CONF_VALUE *_CONF_get_section(const CONF *conf, const char *section)
{
    CONF_VALUE *v, vv;
    if ((conf == ((void *)0)) || (section == ((void *)0)))
        return ((void *)0);
    vv.name = ((void *)0);
    vv.section = (char *)section;
    v = lh_CONF_VALUE_retrieve(conf->data, &vv);
    return v;
}
