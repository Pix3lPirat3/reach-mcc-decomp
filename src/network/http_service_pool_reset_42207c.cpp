struct http_pool_entry {
    int id;
    int count;
};

struct http_pool_request {
    int state;
    int handle_a;
    int handle_b;
    unsigned char flag;
    unsigned char reserved0d[0x2f];
};

struct http_service_pool {
    http_pool_entry entries[8];
    unsigned char reserved40[0x954];
    http_pool_request requests[16];
    unsigned char reserved_d54[4];
    int tail_value;
};

extern "C" void http_service_pool_reset_stats_421dc8(http_service_pool* pool);

extern "C" long long http_service_pool_reset_42207c(http_service_pool* pool) {
    http_service_pool_reset_stats_421dc8(pool);
    char* cursor = reinterpret_cast<char*>(&pool->requests[0].handle_b);
    long long remaining = 16;
    do {
        *reinterpret_cast<int*>(cursor - 8) = 0;
        *reinterpret_cast<int*>(cursor - 4) = -1;
        *reinterpret_cast<int*>(cursor) = -1;
        *reinterpret_cast<unsigned char*>(cursor + 4) = 0;
        cursor += 0x3c;
        remaining--;
    } while (remaining != 0);
    long long entry_index = 0;
    do {
        pool->entries[entry_index].id = -1;
        pool->entries[entry_index].count = 0;
        entry_index++;
    } while (entry_index < 8);
    pool->tail_value = 0;
    return entry_index;
}
