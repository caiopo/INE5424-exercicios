#ifndef __traits_h
#define __traits_h

#include <system/config.h>

__BEGIN_SYS

// Global Configuration
template<typename T>
struct Traits
{
    static const bool enabled = true;
    static const bool debugged = true;
    static const bool hysterically_debugged = false;
    typedef LIST<> DEVICES;
    typedef TLIST<> ASPECTS;
};

template<> struct Traits<Build>
{
    enum {LIBRARY, BUILTIN, KERNEL};
    static const unsigned int MODE = LIBRARY;

    enum {IA32, AVR8, ARMv7};
    static const unsigned int ARCHITECTURE = IA32;

    enum {PC, ATmega, Cortex};
    static const unsigned int MACHINE = PC;

    enum {Legacy_PC, eMote3, LM3S811, Zynq};
    static const unsigned int MODEL = Legacy_PC;

    static const unsigned int CPUS = 1;
    static const unsigned int NODES = 1; // > 1 => NETWORKING
};


// Utilities
template<> struct Traits<Debug>
{
    static const bool error   = true;
    static const bool warning = true;
    static const bool info    = false;
    static const bool trace   = false;
};

template<> struct Traits<Lists>: public Traits<void>
{
    static const bool debugged = hysterically_debugged;
};

template<> struct Traits<Spin>: public Traits<void>
{
    static const bool debugged = hysterically_debugged;
};

template<> struct Traits<Heaps>: public Traits<void>
{
    static const bool debugged = hysterically_debugged;
};


// System Parts (mostly to fine control debugging)
template<> struct Traits<Boot>: public Traits<void>
{
};

template<> struct Traits<Setup>: public Traits<void>
{
};

template<> struct Traits<Init>: public Traits<void>
{
};


// Mediators
template<> struct Traits<Serial_Display>: public Traits<void>
{
    static const bool enabled = true;
    enum {UART, USB};
    static const int ENGINE = UART;
    static const int COLUMNS = 80;
    static const int LINES = 24;
    static const int TAB_SIZE = 8;
};

__END_SYS

#include __ARCH_TRAITS_H
#include __MACH_TRAITS_H

__BEGIN_SYS


// Components
template<> struct Traits<Application>: public Traits<void>
{
    static const unsigned int STACK_SIZE = Traits<Machine>::STACK_SIZE;
    static const unsigned int HEAP_SIZE = Traits<Machine>::HEAP_SIZE;
    static const unsigned int MAX_THREADS = Traits<Machine>::MAX_THREADS;
};

template<> struct Traits<System>: public Traits<void>
{
    static const unsigned int mode = Traits<Build>::MODE;
    static const bool multithread = (Traits<Application>::MAX_THREADS > 1);
    static const bool multiheap = true;

    enum {FOREVER = 0, SECOND = 1, MINUTE = 60, HOUR = 3600, DAY = 86400, WEEK = 604800, MONTH = 2592000, YEAR = 31536000};
    static const unsigned long LIFE_SPAN = 1 * HOUR; // in seconds

    static const bool reboot = true;

    static const unsigned int STACK_SIZE = Traits<Machine>::STACK_SIZE;
    static const unsigned int HEAP_SIZE = (Traits<Application>::MAX_THREADS + 1) * Traits<Application>::STACK_SIZE;
};

template<> struct Traits<Thread>: public Traits<void>
{
    typedef Scheduling_Criteria::RR Criterion;
    static const unsigned int QUANTUM = 10000; // us

    static const bool trace_idle = hysterically_debugged;
};

template<> struct Traits<Scheduler<Thread>>: public Traits<void>
{
    static const bool debugged = Traits<Thread>::trace_idle || hysterically_debugged;
};

template<> struct Traits<Time>: public Traits<void>
{
    static const bool visible = hysterically_debugged;
};

template<> struct Traits<Synchronizer>: public Traits<void>
{
    static const bool enabled = Traits<System>::multithread;
};

__END_SYS

#endif
