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
int SCT_set_log_entry_type(SCT *sct, ct_log_entry_type_t entry_type);
int SCT_set_source(SCT *sct, sct_source_t source);
void ERR_put_error(int lib, int func, int reason, const char *file, int line);
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
int SCT_set_log_entry_type(SCT *sct, ct_log_entry_type_t entry_type)
{
    sct->validation_status = SCT_VALIDATION_STATUS_NOT_SET;
    switch (entry_type) {
    case CT_LOG_ENTRY_TYPE_X509:
    case CT_LOG_ENTRY_TYPE_PRECERT:
        sct->entry_type = entry_type;
        return 1;
    case CT_LOG_ENTRY_TYPE_NOT_SET:
        break;
    }
    ERR_put_error(50,(102),(102),"crypto\\ct\\ct_sct.c",76);
    return 0;
}
int SCT_set_source(SCT *sct, sct_source_t source)
{
    sct->source = source;
    sct->validation_status = SCT_VALIDATION_STATUS_NOT_SET;
    switch (source) {
    case SCT_SOURCE_TLS_EXTENSION:
    case SCT_SOURCE_OCSP_STAPLED_RESPONSE:
        return SCT_set_log_entry_type(sct, CT_LOG_ENTRY_TYPE_X509);
    case SCT_SOURCE_X509V3_EXTENSION:
        return SCT_set_log_entry_type(sct, CT_LOG_ENTRY_TYPE_PRECERT);
    case SCT_SOURCE_UNKNOWN:
        break;
    }
    return 1;
}
