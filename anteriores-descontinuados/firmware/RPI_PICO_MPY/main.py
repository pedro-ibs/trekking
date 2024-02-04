from machine import Pin, PWM, UART, WDT
import time

# time.sleep(3)
wdt = WDT(timeout=1500)

freq_pwm = 400
up_down = False
led_dy = 0
dy_s = 0.001
hello = '\r\nMotor Driver Started!\r\n'
buffer = ''
uart0 = UART(0, baudrate=19200, tx=Pin(0), rx=Pin(1))

motor1A = PWM(Pin( 3    ))
motor1B = PWM(Pin( 2    ))
motor2A = PWM(Pin( 6    ))
motor2B = PWM(Pin( 7    ))
motor3A = PWM(Pin( 10   ))
motor3B = PWM(Pin( 11   ))
motor4A = PWM(Pin( 12   ))
motor4B = PWM(Pin( 13   ))
led     = PWM(Pin( 25   ))

motor1A.freq( freq_pwm )
motor1B.freq( freq_pwm )
motor2A.freq( freq_pwm )
motor2B.freq( freq_pwm )
motor3A.freq( freq_pwm )
motor3B.freq( freq_pwm )
motor4A.freq( freq_pwm )
motor4B.freq( freq_pwm )
led.freq( freq_pwm )

def led_app ( resolution ):
    global led_dy
    global up_down
    if led_dy >= (65535-resolution):
        up_down = False
    elif led_dy <= 0:
        up_down = True
    if up_down:
        led_dy = led_dy + resolution
    else:
        led_dy = led_dy - resolution
    led.duty_u16( led_dy )


def motors_left(dy_a=0, dy_b=0):
    motor1A.duty_u16( dy_a )
    motor1B.duty_u16( dy_b )
    motor2A.duty_u16( dy_a )
    motor2B.duty_u16( dy_b )

def motors_right(dy_a=0, dy_b=0):
    motor3A.duty_u16( dy_a )
    motor3B.duty_u16( dy_b )
    motor4A.duty_u16( dy_a )
    motor4B.duty_u16( dy_b )

def to_front( dy=0  ):
    motors_left(dy_a=0, dy_b=dy)
    motors_right(dy_a=0, dy_b=dy)

def to_back( dy=0  ):
    motors_left(dy_a=dy, dy_b=0)
    motors_right(dy_a=dy, dy_b=0)

def turn_left( dy=0 ):
    motors_left(dy_a=dy, dy_b=0)
    motors_right(dy_a=0, dy_b=dy)

def turn_right( dy=0 ):
    motors_left(dy_a=0, dy_b=dy)
    motors_right(dy_a=dy, dy_b=0)

def turn_off(  ):
    motors_left(dy_a=0, dy_b=0)
    motors_right(dy_a=0, dy_b=0)

def cmd_run( cmd_arg = { 's', 0, 0 } ):
    if cmd_arg[0] == 'x':
        turn_off()
        time.sleep(5)
    elif cmd_arg[0] == 's':
        turn_off()
    elif cmd_arg[0] == 'f':
        to_front( int( cmd_arg[ 1 ] ) )
    elif cmd_arg[0] == 'b':
        to_back( int( cmd_arg [ 1 ] ) )
    elif cmd_arg[0] == 'l':
        turn_left( int( cmd_arg [ 1 ] ) )
    elif cmd_arg[0] == 'L':
        motors_left( dy_a=int( cmd_arg[ 1 ] ), dy_b=int( cmd_arg[ 2 ] ) )
    elif cmd_arg[0] == 'r':
        turn_right( int( cmd_arg[ 1 ] ) )
    elif cmd_arg[0] == 'R':
        motors_right( dy_a=int( cmd_arg[ 1 ] ), dy_b=int( cmd_arg[ 2 ] ) )

uart0.write(hello)

while True:
    bt = uart0.read(1)
    if bt:
        bt = bt.decode()
        uart0.write(bt)
        if bt == '/':
            cmd_run( cmd_arg=buffer.split(':') )
            buffer = ''
            bt = ''
        elif bt:
            buffer = buffer + bt
    led_app( 128 )
    time.sleep( dy_s )
    wdt.feed()
