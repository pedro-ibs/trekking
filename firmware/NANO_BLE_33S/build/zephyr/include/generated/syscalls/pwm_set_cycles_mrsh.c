/* auto-generated by gen_syscalls.py, don't edit */

#include <syscalls/pwm.h>

extern int z_vrfy_pwm_set_cycles(const struct device * dev, uint32_t channel, uint32_t period, uint32_t pulse, pwm_flags_t flags);
uintptr_t z_mrsh_pwm_set_cycles(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	(void) arg5;	/* unused */
	union { uintptr_t x; const struct device * val; } parm0;
	parm0.x = arg0;
	union { uintptr_t x; uint32_t val; } parm1;
	parm1.x = arg1;
	union { uintptr_t x; uint32_t val; } parm2;
	parm2.x = arg2;
	union { uintptr_t x; uint32_t val; } parm3;
	parm3.x = arg3;
	union { uintptr_t x; pwm_flags_t val; } parm4;
	parm4.x = arg4;
	int ret = z_vrfy_pwm_set_cycles(parm0.val, parm1.val, parm2.val, parm3.val, parm4.val);
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}

