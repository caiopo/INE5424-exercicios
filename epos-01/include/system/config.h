// EPOS Configuration Engine

#ifndef __config_h
#define __config_h

//============================================================================
// ARCHITECTURE, MACHINE, AND APPLICATION SELECTION
// This section is generated automatically from makedefs by $EPOS/etc/makefile
//============================================================================
#define MODE library
#define ARCH ia32
#define MACH pc
#define MMOD legacy_pc
#define APPL hello
#define __mode_library__
#define __arch_ia32__
#define __mach_pc__
#define __mmod_legacy_pc__

//============================================================================
// NAMESPACES AND DEFINITIONS
//============================================================================
namespace EPOS {
    namespace S {
        namespace U {}
        using namespace U;
    }
}

#define __BEGIN_API             namespace EPOS {
#define __END_API               }
#define _API                    ::EPOS

#define __BEGIN_UTIL            namespace EPOS { namespace S { namespace U {
#define __END_UTIL              }}}
#define __USING_UTIL            using namespace S::U;
#define _UTIL                   ::EPOS::S::U

#define __BEGIN_SYS             namespace EPOS { namespace S {
#define __END_SYS               }}
#define __USING_SYS             using namespace EPOS::S;
#define _SYS                    ::EPOS::S

#ifndef __mode_kernel__
namespace EPOS {
    using namespace S;
    using namespace S::U;
}
#endif

#define __HEADER_ARCH(X)        <architecture/ARCH/X.h>
#define __HEADER_MACH(X)        <machine/MACH/X.h>
#define __MACH_TRAITS_T(X)      <machine/MACH/X##_traits.h>
#define __MACH_TRAITS(X)        __MACH_TRAITS_T(X)
#define __MACH_CONFIG_T(X)      <machine/MACH/X##_config.h>
#define __MACH_CONFIG(X)        __MACH_CONFIG_T(X)
#define __APPL_TRAITS_T(X)      <../app/X##_traits.h>
#define __APPL_TRAITS(X)        __APPL_TRAITS_T(X)

#define __ARCH_TRAITS_H         __HEADER_ARCH(traits)
#define __MACH_TRAITS_H         __MACH_TRAITS(MMOD)
#define __MACH_CONFIG_H         __MACH_CONFIG(MMOD)
#define __APPL_TRAITS_H         __APPL_TRAITS(APPL)

#define ASM                     __asm__ __volatile__

//============================================================================
// ASSERT (for pre and post conditions)
//============================================================================
#define assert(expr)    ((expr) ? static_cast<void>(0) : Assert::fail (#expr, __FILE__, __LINE__, __PRETTY_FUNCTION__))
//#define assert(expr)    (static_cast<void>(0))

//============================================================================
// CONFIGURATION
//============================================================================
#include <system/types.h>
#include <system/meta.h>
#include __APPL_TRAITS_H

#define __CPU_H         __HEADER_ARCH(cpu)
#define __MMU_H         __HEADER_ARCH(mmu)

#define __MACH_H        __HEADER_MACH(machine)
#define __MODEL_H       __HEADER_MACH(MMOD)
#define __IC_H          __HEADER_MACH(ic)
#define __TIMER_H       __HEADER_MACH(timer)

#ifdef __mmod_legacy_pc__
#define __TSC_H         __HEADER_ARCH(tsc)
#define __PMU_H         __HEADER_ARCH(pmu)

#define __PCI_H         __HEADER_MACH(pci)
#define __RTC_H         __HEADER_MACH(rtc)
#define __EEPROM_H      __HEADER_MACH(eeprom)
#define __UART_H        __HEADER_MACH(uart)
#define __DISPLAY_H     __HEADER_MACH(display)
#define __KEYBOARD_H    __HEADER_MACH(keyboard)
#define __SCRATCHPAD_H  __HEADER_MACH(scratchpad)
#define __NIC_H         __HEADER_MACH(nic)
#define __FPGA_H        __HEADER_MACH(fpga)
#define __AES_H         __HEADER_MACH(aes)
#define __ipv4__
#define __tstp__
#endif

#ifdef __mmod_lm3s811__
#define __TSC_H                 __HEADER_ARCH(tsc)

#define __RTC_H                 __HEADER_MACH(rtc)
#define __UART_H                __HEADER_MACH(uart)
#define __USB_H                 __HEADER_MACH(usb)
#define __GPIO_H                __HEADER_MACH(gpio)
#define __AES_H                 __HEADER_MACH(aes)
#endif

#ifdef __mmod_emote3__
#define __TSC_H                 __HEADER_ARCH(tsc)

#define __RTC_H                 __HEADER_MACH(rtc)
#define __EEPROM_H              __HEADER_MACH(eeprom)
#define __UART_H                __HEADER_MACH(uart)
#define __SPI_H                 __HEADER_MACH(spi)
#define __RS485_H               __HEADER_MACH(rs485)
#define __USB_H                 __HEADER_MACH(usb)
#define __I2C_H                 __HEADER_MACH(i2c)
#define __GPIO_H                __HEADER_MACH(gpio)
#define __ADC_H                 __HEADER_MACH(adc)
#define __PWM_H                 __HEADER_MACH(pwm)
#define __WATCHDOG_H            __HEADER_MACH(watchdog)
#define __NIC_H                 __HEADER_MACH(nic)
#define __AES_H                 __HEADER_MACH(aes)
#define __CO2_H                 __HEADER_MACH(cm1101)
#define __tstp__
#endif

#ifdef __mmod_zynq__
#define __TSC_H                 __HEADER_ARCH(tsc)
#define __PMU_H                 __HEADER_ARCH(pmu)

#define __RTC_H                 __HEADER_MACH(rtc)
#define __UART_H                __HEADER_MACH(uart)
#define __NIC_H                 __HEADER_MACH(nic)
#define __AES_H                 __HEADER_MACH(aes)
#define __ipv4__
#endif

//============================================================================
// THINGS EVERBODY NEEDS
//============================================================================
#include <utility/ostream.h>
#include <utility/debug.h>

#endif
