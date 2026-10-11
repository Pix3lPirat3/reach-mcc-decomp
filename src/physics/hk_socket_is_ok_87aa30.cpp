struct socket_object {
    unsigned char reserved0[0x40];
    long long handle;
};

extern "C" bool* hk_socket_is_ok_87aa30(socket_object* socket, bool* result) {
    *result = socket->handle != -1;
    return result;
}
