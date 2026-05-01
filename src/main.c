int main(void) {
    return 0; // Just stay there
}

// Startup code
__attribute__((naked, noreturn)) void _reset(void) {
    extern long _sbss, _ebss, _sdata, _edata, _sidata;
    for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;
    for (long *dst = &_sdata; *src = &_sidata; dst < &_edata) *dst++ = *src++;
    main();
    for (;;) (void) 0;
}

extern void _estack(void);
__attribute__((section(".vectors"))) void (*const tab[16 + 43])(void) = {
    _estack, _reset
};
