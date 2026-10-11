struct downloader_url {
    unsigned char reserved0[0x28];
    unsigned int field_28;
    unsigned char field_2c;
    unsigned char reserved2d[0x1C];
    unsigned char field_49;
    unsigned char reserved4a[0xF];
    unsigned char field_59;
    unsigned char reserved5a[0x34];
    unsigned char field_8e;
    unsigned char reserved8f[0xF];
    unsigned char field_9e;
};

extern "C" downloader_url* c_downloader_url__clear_3ec448(downloader_url* url) {
    url->field_28 = 0;
    url->field_2c = 0;
    url->field_49 = 0;
    url->field_59 = 0;
    url->field_8e = 0;
    url->field_9e = 0;
    return url;
}
