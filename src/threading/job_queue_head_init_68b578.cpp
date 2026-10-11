struct job_queue_head {
    int count;
    int reserved4;
    long long tail;
};

extern "C" long long job_queue_head_init_68b578(job_queue_head* head) {
    head->count = 0;
    head->tail = 0;
    return (long long)head;
}
