add_custom_target(devicetree_target)

set_target_properties(devicetree_target PROPERTIES "DT_CHOSEN|zephyr,sram" "/soc/memory@20000000")
set_target_properties(devicetree_target PROPERTIES "DT_CHOSEN|zephyr,flash" "/soc/flash@10000000")
set_target_properties(devicetree_target PROPERTIES "DT_CHOSEN|zephyr,console" "/soc/uart@40034000")
set_target_properties(devicetree_target PROPERTIES "DT_CHOSEN|zephyr,shell-uart" "/soc/uart@40034000")
set_target_properties(devicetree_target PROPERTIES "DT_CHOSEN|zephyr,code-partition" "/soc/flash@10000000/partitions/partition@100")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|uart0" "/soc/uart@40034000")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|led0" "/leds/led_0")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|gprs-rst" "/gprs/gprs_reset")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|m1a" "/motors/m_1a")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|m1b" "/motors/m_1b")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|m2a" "/motors/m_2a")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|m2b" "/motors/m_2b")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|m3a" "/motors/m_3a")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|m3b" "/motors/m_3b")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|m4a" "/motors/m_4a")
set_target_properties(devicetree_target PROPERTIES "DT_ALIAS|m4b" "/motors/m_4b")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_REG|/|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/chosen" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_REG|/chosen|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/chosen|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/chosen|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/aliases" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_REG|/aliases|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/aliases|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/aliases|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc|compatible" "simple-bus;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/interrupt-controller@e000e100" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|nvic" "/soc/interrupt-controller@e000e100")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/interrupt-controller@e000e100|reg" "3758153984;3072;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/interrupt-controller@e000e100|arm,num-irq-priority-bits" "3")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/interrupt-controller@e000e100|interrupt-controller" "True")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/interrupt-controller@e000e100|compatible" "arm,v6m-nvic;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/interrupt-controller@e000e100|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/interrupt-controller@e000e100|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/interrupt-controller@e000e100|ADDR" "0xe000e100;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/interrupt-controller@e000e100|SIZE" "0xc00;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/timer@e000e010" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|systick" "/soc/timer@e000e010")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/timer@e000e010|compatible" "arm,armv6m-systick;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/timer@e000e010|reg" "3758153744;16;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/timer@e000e010|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/timer@e000e010|ADDR" "0xe000e010;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/timer@e000e010|SIZE" "0x10;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/memory@20000000" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|sram0" "/soc/memory@20000000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/memory@20000000|reg" "536870912;270336;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/memory@20000000|compatible" "mmio-sram;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/memory@20000000|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/memory@20000000|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/memory@20000000|ADDR" "0x20000000;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/memory@20000000|SIZE" "0x42000;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/flash@10000000" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|flash0" "/soc/flash@10000000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000|label" "FLASH_RP2")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000|write-block-size" "1")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000|compatible" "soc-nv-flash;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000|reg" "268435456;2097152;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000|ADDR" "0x10000000;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000|SIZE" "0x200000;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/flash@10000000/partitions" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000/partitions|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000/partitions|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000/partitions|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/flash@10000000/partitions/partition@0" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|second_stage_bootloader" "/soc/flash@10000000/partitions/partition@0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000/partitions/partition@0|label" "second_stage_bootloader")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000/partitions/partition@0|read-only" "True")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000/partitions/partition@0|reg" "0;256;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000/partitions/partition@0|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000/partitions/partition@0|ADDR" "0x0;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000/partitions/partition@0|SIZE" "0x100;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/flash@10000000/partitions/partition@100" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|code_partition" "/soc/flash@10000000/partitions/partition@100")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000/partitions/partition@100|label" "code-partition")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000/partitions/partition@100|read-only" "True")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/flash@10000000/partitions/partition@100|reg" "256;2096896;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000/partitions/partition@100|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000/partitions/partition@100|ADDR" "0x100;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/flash@10000000/partitions/partition@100|SIZE" "0x1fff00;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/peripheral-clk" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|peripheral_clk" "/soc/peripheral-clk")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/peripheral-clk|clock-frequency" "125000000")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/peripheral-clk|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/peripheral-clk|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/peripheral-clk|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/system-clk" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|system_clk" "/soc/system-clk")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/system-clk|clock-frequency" "125000000")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/system-clk|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/system-clk|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/system-clk|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/reset-controller@4000c000" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|reset" "/soc/reset-controller@4000c000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/reset-controller@4000c000|reg" "1073790976;4096;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/reset-controller@4000c000|reg-width" "4")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/reset-controller@4000c000|active-low" "0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/reset-controller@4000c000|compatible" "raspberrypi,pico-reset;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/reset-controller@4000c000|label" "RESET")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/reset-controller@4000c000|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/reset-controller@4000c000|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/reset-controller@4000c000|ADDR" "0x4000c000;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/reset-controller@4000c000|SIZE" "0x1000;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/pin-controller@40014000" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|pinctrl" "/soc/pin-controller@40014000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000|status" "okay")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000|compatible" "raspberrypi,pico-pinctrl;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000|reg" "1073823744;4096;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000|label" "PINCTRL")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000|ADDR" "0x40014000;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000|SIZE" "0x1000;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/pin-controller@40014000/uart0_default" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|uart0_default" "/soc/pin-controller@40014000/uart0_default")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/uart0_default|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/uart0_default|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/uart0_default|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/pin-controller@40014000/uart0_default/group1" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group1|pinmux" "2;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group1|drive-strength" "4")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group1|slew-rate" "0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group1|bias-disable" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group1|bias-pull-up" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group1|bias-pull-down" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group1|input-enable" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group1|input-schmitt-enable" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/uart0_default/group1|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/uart0_default/group1|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/uart0_default/group1|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/pin-controller@40014000/uart0_default/group2" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group2|pinmux" "18;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group2|drive-strength" "4")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group2|slew-rate" "0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group2|bias-disable" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group2|bias-pull-up" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group2|bias-pull-down" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group2|input-enable" "True")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/uart0_default/group2|input-schmitt-enable" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/uart0_default/group2|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/uart0_default/group2|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/uart0_default/group2|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/pin-controller@40014000/i2c0_default" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|i2c0_default" "/soc/pin-controller@40014000/i2c0_default")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c0_default|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c0_default|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c0_default|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/pin-controller@40014000/i2c0_default/group1" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c0_default/group1|pinmux" "67;83;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c0_default/group1|drive-strength" "4")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c0_default/group1|slew-rate" "0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c0_default/group1|bias-disable" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c0_default/group1|bias-pull-up" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c0_default/group1|bias-pull-down" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c0_default/group1|input-enable" "True")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c0_default/group1|input-schmitt-enable" "True")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c0_default/group1|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c0_default/group1|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c0_default/group1|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/pin-controller@40014000/i2c1_default" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|i2c1_default" "/soc/pin-controller@40014000/i2c1_default")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c1_default|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c1_default|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c1_default|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/pin-controller@40014000/i2c1_default/group1" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c1_default/group1|pinmux" "227;243;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c1_default/group1|drive-strength" "4")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c1_default/group1|slew-rate" "0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c1_default/group1|bias-disable" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c1_default/group1|bias-pull-up" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c1_default/group1|bias-pull-down" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c1_default/group1|input-enable" "True")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/pin-controller@40014000/i2c1_default/group1|input-schmitt-enable" "True")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c1_default/group1|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c1_default/group1|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/pin-controller@40014000/i2c1_default/group1|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/gpio@40014000" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|gpio0" "/soc/gpio@40014000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/gpio@40014000|reg" "1073823744;4096;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/gpio@40014000|label" "GPIO_0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/gpio@40014000|gpio-controller" "True")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/gpio@40014000|ngpios" "30")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/gpio@40014000|status" "okay")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/gpio@40014000|compatible" "raspberrypi,pico-gpio;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/gpio@40014000|interrupts" "13;3;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/gpio@40014000|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/gpio@40014000|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/gpio@40014000|ADDR" "0x40014000;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/gpio@40014000|SIZE" "0x1000;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/uart@40034000" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|uart0" "/soc/uart@40034000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|reg" "1073954816;4096;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|interrupts" "20;3;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|current-speed" "115200")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|label" "UART_0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|hw-flow-control" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|status" "okay")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|compatible" "raspberrypi,pico-uart;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|interrupt-names" "uart0;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40034000|pinctrl-names" "default;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/uart@40034000|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/uart@40034000|ADDR" "0x40034000;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/uart@40034000|SIZE" "0x1000;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/uart@40038000" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|uart1" "/soc/uart@40038000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40038000|reg" "1073971200;4096;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40038000|interrupts" "21;3;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40038000|label" "UART_1")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40038000|hw-flow-control" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40038000|status" "disabled")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40038000|compatible" "raspberrypi,pico-uart;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40038000|interrupt-names" "uart1;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/uart@40038000|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/uart@40038000|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/uart@40038000|ADDR" "0x40038000;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/uart@40038000|SIZE" "0x1000;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/i2c@40044000" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|i2c0" "/soc/i2c@40044000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40044000|reg" "1074020352;4096;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40044000|interrupts" "23;3;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40044000|clock-frequency" "100000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40044000|label" "I2C_0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40044000|status" "okay")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40044000|compatible" "snps,designware-i2c;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40044000|interrupt-names" "i2c0;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40044000|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40044000|pinctrl-names" "default;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/i2c@40044000|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/i2c@40044000|ADDR" "0x40044000;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/i2c@40044000|SIZE" "0x1000;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/soc/i2c@40048000" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|i2c1" "/soc/i2c@40048000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40048000|reg" "1074036736;4096;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40048000|interrupts" "24;3;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40048000|clock-frequency" "100000")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40048000|label" "I2C_1")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40048000|status" "okay")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40048000|compatible" "snps,designware-i2c;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40048000|interrupt-names" "i2c1;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40048000|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/soc/i2c@40048000|pinctrl-names" "default;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/i2c@40048000|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/i2c@40048000|ADDR" "0x40048000;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/soc/i2c@40048000|SIZE" "0x1000;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/cpus" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_REG|/cpus|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/cpus|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/cpus|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/cpus/cpu@0" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|cpu0" "/cpus/cpu@0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/cpus/cpu@0|compatible" "arm,cortex-m0+;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/cpus/cpu@0|reg" "0;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/cpus/cpu@0|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/cpus/cpu@0|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/cpus/cpu@0|ADDR" "0x0;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/cpus/cpu@0|SIZE" "NONE;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/cpus/cpu@1" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|cpu1" "/cpus/cpu@1")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/cpus/cpu@1|compatible" "arm,cortex-m0+;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/cpus/cpu@1|reg" "1;")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/cpus/cpu@1|wakeup-source" "False")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/cpus/cpu@1|NUM" "1")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/cpus/cpu@1|ADDR" "0x1;")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/cpus/cpu@1|SIZE" "NONE;")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/leds" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_REG|/leds|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/leds|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/leds|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/leds/led_0" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|led0" "/leds/led_0")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/leds/led_0|label" "LED")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/leds/led_0|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/leds/led_0|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/leds/led_0|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/gprs" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_REG|/gprs|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/gprs|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/gprs|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/gprs/gprs_reset" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|gprs_rst" "/gprs/gprs_reset")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/gprs/gprs_reset|label" "GPRS RESET")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/gprs/gprs_reset|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/gprs/gprs_reset|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/gprs/gprs_reset|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/motors" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/motors/m_1a" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|m1a" "/motors/m_1a")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/motors/m_1a|label" "MOROT1-A GPIO")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_1a|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_1a|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_1a|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/motors/m_1b" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|m1b" "/motors/m_1b")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/motors/m_1b|label" "MOROT1-B GPIO")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_1b|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_1b|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_1b|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/motors/m_2a" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|m2a" "/motors/m_2a")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/motors/m_2a|label" "MOROT2-A GPIO")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_2a|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_2a|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_2a|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/motors/m_2b" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|m2b" "/motors/m_2b")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/motors/m_2b|label" "MOROT2-B GPIO")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_2b|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_2b|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_2b|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/motors/m_3a" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|m3a" "/motors/m_3a")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/motors/m_3a|label" "MOROT3-A GPIO")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_3a|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_3a|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_3a|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/motors/m_3b" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|m3b" "/motors/m_3b")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/motors/m_3b|label" "MOROT3-B GPIO")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_3b|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_3b|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_3b|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/motors/m_4a" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|m4a" "/motors/m_4a")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/motors/m_4a|label" "MOROT4-A GPIO")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_4a|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_4a|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_4a|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_NODE|/motors/m_4b" TRUE)
set_target_properties(devicetree_target PROPERTIES "DT_NODELABEL|m4b" "/motors/m_4b")
set_target_properties(devicetree_target PROPERTIES "DT_PROP|/motors/m_4b|label" "MOROT4-B GPIO")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_4b|NUM" "0")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_4b|ADDR" "")
set_target_properties(devicetree_target PROPERTIES "DT_REG|/motors/m_4b|SIZE" "")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|simple-bus" "/soc")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|arm,v6m-nvic" "/soc/interrupt-controller@e000e100")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|arm,armv6m-systick" "/soc/timer@e000e010")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|mmio-sram" "/soc/memory@20000000")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|soc-nv-flash" "/soc/flash@10000000")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|raspberrypi,pico-reset" "/soc/reset-controller@4000c000")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|raspberrypi,pico-pinctrl" "/soc/pin-controller@40014000")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|raspberrypi,pico-gpio" "/soc/gpio@40014000")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|raspberrypi,pico-uart" "/soc/uart@40034000;/soc/uart@40038000")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|snps,designware-i2c" "/soc/i2c@40044000;/soc/i2c@40048000")
set_target_properties(devicetree_target PROPERTIES "DT_COMP|arm,cortex-m0+" "/cpus/cpu@0;/cpus/cpu@1")
