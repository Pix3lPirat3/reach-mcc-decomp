struct x509_sig_info {
    int digest_nid;
    int pubkey_nid;
    int security_bits;
    int flags;
};

extern "C" int X509_SIG_INFO_set_7fc140(x509_sig_info* info, int digest_nid, int pubkey_nid, int security_bits, int flags) {
    info->flags = flags;
    info->digest_nid = digest_nid;
    info->pubkey_nid = pubkey_nid;
    info->security_bits = security_bits;
    return flags;
}
