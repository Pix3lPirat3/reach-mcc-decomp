typedef struct err_state_st {
    int err_flags[16];
    unsigned long err_buffer[16];
    char *err_data[16];
    int err_data_flags[16];
    const char *err_file[16];
    int err_line[16];
    int top, bottom;
} ERR_STATE;
ERR_STATE *ERR_get_state(void);
static __inline unsigned int constant_time_msb(unsigned int a);
static __inline unsigned int constant_time_is_zero(unsigned int a);
static __inline unsigned int constant_time_eq(unsigned int a,
                                                 unsigned int b);
static __inline unsigned int constant_time_eq_int(int a, int b);
static __inline unsigned int constant_time_select(unsigned int mask,
                                                     unsigned int a,
                                                     unsigned int b);
static __inline int constant_time_select_int(unsigned int mask, int a,
                                                int b);
static __inline unsigned int constant_time_msb(unsigned int a)
{
    return 0 - (a >> (sizeof(a) * 8 - 1));
}
static __inline unsigned int constant_time_is_zero(unsigned int a)
{
    return constant_time_msb(~a & (a - 1));
}
static __inline unsigned int constant_time_eq(unsigned int a,
                                                 unsigned int b)
{
    return constant_time_is_zero(a ^ b);
}
static __inline unsigned int constant_time_eq_int(int a, int b)
{
    return constant_time_eq((unsigned)(a), (unsigned)(b));
}
static __inline unsigned int constant_time_select(unsigned int mask,
                                                     unsigned int a,
                                                     unsigned int b)
{
    return (mask & a) | (~mask & b);
}
static __inline int constant_time_select_int(unsigned int mask, int a,
                                                int b)
{
    return (int)constant_time_select(mask, (unsigned)(a), (unsigned)(b));
}
void err_clear_last_constant_time(int clear);
void err_clear_last_constant_time(int clear)
{
    ERR_STATE *es;
    int top;
    es = ERR_get_state();
    if (es == ((void *)0))
        return;
    top = es->top;
    clear = constant_time_select_int(constant_time_eq_int(clear, 0),
                                     0, 0x02);
    es->err_flags[top] |= clear;
}
