struct algorithm_id {
    void* algorithm;
};

struct key_bits {
    int length;
    unsigned char reserved4[4];
    void* data;
};

struct public_key_info {
    algorithm_id* algor;
    key_bits* public_key;
};

extern "C" long long X509_PUBKEY_get0_param_7b76a0(void** algorithm_out, void** data_out, int* length_out, algorithm_id** algor_out, public_key_info* info) {
    if (algorithm_out != 0)
        *algorithm_out = info->algor->algorithm;
    if (data_out != 0) {
        *data_out = info->public_key->data;
        *length_out = info->public_key->length;
    }
    if (algor_out == 0)
        return 1;
    *algor_out = info->algor;
    return 1;
}
