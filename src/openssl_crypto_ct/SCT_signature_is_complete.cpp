typedef unsigned __int64 size_t;
typedef unsigned long long uint64_t;
typedef struct sct_st SCT;
typedef enum {
    CT_LOG_ENTRY_TYPE_NOT_SET = -1,
    CT_LOG_ENTRY_TYPE_X509 = 0,
    CT_LOG_ENTRY_TYPE_PRECERT = 1
} ct_log_entry_type_t;
typedef enum {
    SCT_VERSION_NOT_SET = -1,
    SCT_VERSION_V1 = 0
} sct_version_t;
typedef enum {
    SCT_SOURCE_UNKNOWN,
    SCT_SOURCE_TLS_EXTENSION,
    SCT_SOURCE_X509V3_EXTENSION,
    SCT_SOURCE_OCSP_STAPLED_RESPONSE
} sct_source_t;
typedef enum {
    SCT_VALIDATION_STATUS_NOT_SET,
    SCT_VALIDATION_STATUS_UNKNOWN_LOG,
    SCT_VALIDATION_STATUS_VALID,
    SCT_VALIDATION_STATUS_INVALID,
    SCT_VALIDATION_STATUS_UNVERIFIED,
    SCT_VALIDATION_STATUS_UNKNOWN_VERSION
} sct_validation_status_t;
int SCT_get_signature_nid(const SCT *sct);
struct sct_st {
    sct_version_t version;
    unsigned char *sct;
    size_t sct_len;
    unsigned char *log_id;
    size_t log_id_len;
    uint64_t timestamp;
    unsigned char *ext;
    size_t ext_len;
    unsigned char hash_alg;
    unsigned char sig_alg;
    unsigned char *sig;
    size_t sig_len;
    ct_log_entry_type_t entry_type;
    sct_source_t source;
    sct_validation_status_t validation_status;
};
int SCT_signature_is_complete(const SCT *sct);
int SCT_get_signature_nid(const SCT *sct)
{
    if (sct->version == SCT_VERSION_V1) {
        if (sct->hash_alg == 4) {
            switch (sct->sig_alg) {
            case 3:
                return 794;
            case 1:
                return 668;
            default:
                return 0;
            }
        }
    }
    return 0;
}
int SCT_signature_is_complete(const SCT *sct)
{
    return SCT_get_signature_nid(sct) != 0 &&
        sct->sig != ((void *)0) && sct->sig_len > 0;
}
