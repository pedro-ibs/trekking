#include <zephyr/device.h>
#include <zephyr/toolchain.h>

/* 1 : /soc/reset-controller@4000c000:
 * Direct Dependencies:
 *   - (/soc)
 * Supported:
 *   - /soc/pwm@40050000
 *   - /soc/uart@40034000
 *   - /soc/uart@40038000
 *   - (/soc/usbd@50100000)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_reset_controller_4000c000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 3, 7, 2, DEVICE_HANDLE_ENDS };

/* 2 : /soc/uart@40038000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - (/soc/peripheral-clk)
 *   - /soc/reset-controller@4000c000
 *   - (/soc/pin-controller@40014000/uart1_default)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_uart_40038000[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 3 : /soc/uart@40034000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - (/soc/peripheral-clk)
 *   - /soc/reset-controller@4000c000
 *   - (/soc/pin-controller@40014000/uart0_default)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_uart_40034000[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 4 : /soc/gpio@40014000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 * Supported:
 *   - (/gprs/gprs_reset)
 *   - (/leds/led_0)
 *   - (/motors/m_1a)
 *   - (/motors/m_1b)
 *   - (/motors/m_2a)
 *   - (/motors/m_2b)
 *   - (/motors/m_3a)
 *   - (/motors/m_3b)
 *   - (/motors/m_4a)
 *   - (/motors/m_4b)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_gpio_40014000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 5 : /soc/i2c@40048000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - (/soc/system-clk)
 *   - (/soc/pin-controller@40014000/i2c1_default)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_i2c_40048000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 6 : /soc/i2c@40044000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - (/soc/system-clk)
 *   - (/soc/pin-controller@40014000/i2c0_default)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_i2c_40044000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 7 : /soc/pwm@40050000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 *   - /soc/reset-controller@4000c000
 *   - (/soc/system-clk)
 *   - (/soc/pin-controller@40014000/pwm_ch4b_default)
 * Supported:
 *   - (/motors_pwm/pwm_m1a)
 *   - (/pwm_leds/pwm_led_0)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_pwm_40050000[] = { 1, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 8 : /motors_pwm:
 * Direct Dependencies:
 *   - (/)
 * Supported:
 *   - (/motors_pwm/pwm_m1a)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_motors_pwm[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 9 : /pwm_leds:
 * Direct Dependencies:
 *   - (/)
 * Supported:
 *   - (/pwm_leds/pwm_led_0)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_pwm_leds[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };
