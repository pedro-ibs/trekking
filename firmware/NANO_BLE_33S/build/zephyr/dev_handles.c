#include <device.h>
#include <toolchain.h>

/* 1 : /soc/clock@40000000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/soc/interrupt-controller@e000e100)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_clock_40000000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 2 : /soc/gpio@50000000:
 * Direct Dependencies:
 *   - (/soc)
 * Supported:
 *   - /mic_pwr
 *   - /vdd-env
 *   - (/leds/led_0)
 *   - (/leds/led_1)
 *   - (/leds/led_2)
 *   - (/leds/led_3)
 *   - (/soc/i2c@40004000/apds9960@39)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_gpio_50000000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 10, 9, DEVICE_HANDLE_ENDS };

/* 3 : /soc/gpio@50000300:
 * Direct Dependencies:
 *   - (/soc)
 * Supported:
 *   - (/zephyr,user)
 *   - (/leds/led_4)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_gpio_50000300[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 4 : /soc/usbd@40027000/cdc_acm_uart0:
 * Direct Dependencies:
 *   - (/soc/usbd@40027000)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_usbd_40027000_S_cdc_acm_uart0[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 5 : /soc/uart@40002000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/pin-controller/uart0_default)
 *   - (/pin-controller/uart0_sleep)
 *   - (/soc/interrupt-controller@e000e100)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_uart_40002000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 6 : /soc/i2c@40004000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/pin-controller/i2c1_default)
 *   - (/pin-controller/i2c1_sleep)
 *   - (/soc/interrupt-controller@e000e100)
 * Supported:
 *   - (/soc/i2c@40004000/apds9960@39)
 *   - (/soc/i2c@40004000/hts221@5f)
 *   - (/soc/i2c@40004000/lps22hb-press@5c)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_i2c_40004000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 7 : /soc/i2c@40003000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/pin-controller/i2c0_default)
 *   - (/pin-controller/i2c0_sleep)
 *   - (/soc/interrupt-controller@e000e100)
 * Supported:
 *   - /soc/i2c@40003000/vl53l0x@29
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_i2c_40003000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, 11, DEVICE_HANDLE_ENDS };

/* 8 : /soc/spi@40023000:
 * Direct Dependencies:
 *   - (/soc)
 *   - (/pin-controller/spi2_default)
 *   - (/pin-controller/spi2_sleep)
 *   - (/soc/interrupt-controller@e000e100)
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_spi_40023000[] = { DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 9 : /mic_pwr:
 * Direct Dependencies:
 *   - (/)
 *   - /soc/gpio@50000000
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_mic_pwr[] = { 2, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 10 : /vdd-env:
 * Direct Dependencies:
 *   - (/)
 *   - /soc/gpio@50000000
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_vdd_env[] = { 2, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };

/* 11 : /soc/i2c@40003000/vl53l0x@29:
 * Direct Dependencies:
 *   - /soc/i2c@40003000
 */
const device_handle_t __aligned(2) __attribute__((__section__(".__device_handles_pass2")))
__devicehdl_DT_N_S_soc_S_i2c_40003000_S_vl53l0x_29[] = { 7, DEVICE_HANDLE_SEP, DEVICE_HANDLE_SEP, DEVICE_HANDLE_ENDS };
