import select
import sys
import time
import machine
import _thread

from machine import Pin, UART, I2C

led = machine.Pin('LED', machine.Pin.OUT)
rs485 = machine.Pin('GPIO18', machine.Pin.OUT)

uart = UART(0, baudrate=38400, tx=Pin(16), rx=Pin(17), bits=8, parity=None, stop=1)
sLock = _thread.allocate_lock()


led.value(True)
rs485.value(True)

def CoreTask():
    while True:
        time.sleep(1)
            
_thread.start_new_thread(CoreTask, ())

while True:
    uart.write('dasdahkdhsja_turnon_djdsnfmdsnfsdf')
    led.value(True)
    time.sleep(0.5)

    uart.write('dasdahkdhsja_turnoff_djdsnfmdsnfsdf')
    led.value(False)
    time.sleep(0.5)
