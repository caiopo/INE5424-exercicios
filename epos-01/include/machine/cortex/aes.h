// EPOS ARM Cortex AES Mediator Declarations

#ifndef __cortex_aes_h
#define __cortex_aes_h

#include <machine/aes.h>

//TODO: this is just a place holder. Replace with Cortex AES!
#include <utility/aes.h>

__BEGIN_SYS

template<unsigned int KEY_SIZE>
class AES: private AES_Common, public _UTIL::AES<KEY_SIZE> {};

__END_SYS

#endif
