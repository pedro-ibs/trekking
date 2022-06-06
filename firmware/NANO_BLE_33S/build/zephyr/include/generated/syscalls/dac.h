/* auto-generated by gen_syscalls.py, don't edit */

#ifndef Z_INCLUDE_SYSCALLS_DAC_H
#define Z_INCLUDE_SYSCALLS_DAC_H


#include <tracing/tracing_syscall.h>

#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <syscall.h>

#include <linker/sections.h>


#ifdef __cplusplus
extern "C" {
#endif

extern int z_impl_dac_channel_setup(const struct device * dev, const struct dac_channel_cfg * channel_cfg);

__pinned_func
static inline int dac_channel_setup(const struct device * dev, const struct dac_channel_cfg * channel_cfg)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		union { uintptr_t x; const struct dac_channel_cfg * val; } parm1 = { .val = channel_cfg };
		return (int) arch_syscall_invoke2(parm0.x, parm1.x, K_SYSCALL_DAC_CHANNEL_SETUP);
	}
#endif
	compiler_barrier();
	return z_impl_dac_channel_setup(dev, channel_cfg);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define dac_channel_setup(dev, channel_cfg) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_DAC_CHANNEL_SETUP, dac_channel_setup, dev, channel_cfg); 	retval = dac_channel_setup(dev, channel_cfg); 	sys_port_trace_syscall_exit(K_SYSCALL_DAC_CHANNEL_SETUP, dac_channel_setup, dev, channel_cfg, retval); 	retval; })
#endif
#endif


extern int z_impl_dac_write_value(const struct device * dev, uint8_t channel, uint32_t value);

__pinned_func
static inline int dac_write_value(const struct device * dev, uint8_t channel, uint32_t value)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		union { uintptr_t x; const struct device * val; } parm0 = { .val = dev };
		union { uintptr_t x; uint8_t val; } parm1 = { .val = channel };
		union { uintptr_t x; uint32_t val; } parm2 = { .val = value };
		return (int) arch_syscall_invoke3(parm0.x, parm1.x, parm2.x, K_SYSCALL_DAC_WRITE_VALUE);
	}
#endif
	compiler_barrier();
	return z_impl_dac_write_value(dev, channel, value);
}

#if (CONFIG_TRACING_SYSCALL == 1)
#ifndef DISABLE_SYSCALL_TRACING

#define dac_write_value(dev, channel, value) ({ 	int retval; 	sys_port_trace_syscall_enter(K_SYSCALL_DAC_WRITE_VALUE, dac_write_value, dev, channel, value); 	retval = dac_write_value(dev, channel, value); 	sys_port_trace_syscall_exit(K_SYSCALL_DAC_WRITE_VALUE, dac_write_value, dev, channel, value, retval); 	retval; })
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif
#endif /* include guard */