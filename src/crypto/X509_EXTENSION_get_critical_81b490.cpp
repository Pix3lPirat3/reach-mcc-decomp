struct extension {
    unsigned char reserved0[8];
    int critical;
};

extern "C" long long X509_EXTENSION_get_critical_81b490(extension* ext) {
    if (ext == 0)
        return 0;
    return ext->critical > 0;
}
