void _fini() __attribute__ ((section(".fini")));

typedef void (*fptr) (void);

static fptr __CTOR_LIST__[1] __attribute__ ((used, section(".init_array"), aligned(sizeof(fptr)))) = { (fptr)(-1) };
static fptr __DTOR_LIST__[1] __attribute__ ((section(".fine_array"), aligned(sizeof(fptr)))) = { (fptr)(-1) };

static void __do_global_dtors_aux()
{
    fptr * p;
    for(p = __DTOR_LIST__; *p != (fptr) -1; p++)
        (*p)();
}

void _fini()
{
    __do_global_dtors_aux();
}
