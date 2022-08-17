from machine import Pin, PWM, UART
import time

time.sleep(3)


########################################################################### 
############################## CONFIGURAÇÕES ############################## 
########################################################################### 
duty_resolution = 128+64
freq_pwm = 400
up_down = False
dy_s = 0.01
hello = '\r\nMotor Driver Started!\r\n'
buffer = ''
cmd = {}

motor1a_dy  = 0
motor1B_dy  = 0
motor2A_dy  = 0
motor2B_dy  = 0
motor3A_dy  = 0
motor3B_dy  = 0
motor4A_dy  = 0
motor4B_dy  = 0
led_dy      = 0

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

def to_front( dy_b=0  ):
    motor1B.duty_u16( dy_b )
    motor2B.duty_u16( dy_b )
    motor3B.duty_u16( dy_b )
    motor4B.duty_u16( dy_b )

    motor1A.duty_u16( 0 )
    motor2A.duty_u16( 0 )
    motor3A.duty_u16( 0 )
    motor4A.duty_u16( 0 )


def to_back( dy_a=0  ):
    motor1B.duty_u16( 0 )
    motor2B.duty_u16( 0 )
    motor3B.duty_u16( 0 )
    motor4B.duty_u16( 0 )

    motor1A.duty_u16( dy_a )
    motor2A.duty_u16( dy_a )
    motor3A.duty_u16( dy_a )
    motor4A.duty_u16( dy_a )

def turn_left( dy ):
    motor1B.duty_u16( 0 )
    motor2B.duty_u16( 0 )
    motor3B.duty_u16( dy )
    motor4B.duty_u16( dy )

    motor1A.duty_u16( dy )
    motor2A.duty_u16( dy )
    motor3A.duty_u16( 0 )
    motor4A.duty_u16( 0 )


def turn_right( dy ):
    motor1B.duty_u16( dy )
    motor2B.duty_u16( dy )
    motor3B.duty_u16( 0 )
    motor4B.duty_u16( 0 )

    motor1A.duty_u16( 0 )
    motor2A.duty_u16( 0 )
    motor3A.duty_u16( dy )
    motor4A.duty_u16( dy )

def turn_off(  ):
    motor1B.duty_u16( 0 )
    motor2B.duty_u16( 0 )
    motor3B.duty_u16( 0 )
    motor4B.duty_u16( 0 )

    motor1A.duty_u16( 0 )
    motor2A.duty_u16( 0 )
    motor3A.duty_u16( 0 )
    motor4A.duty_u16( 0 )


uart0.write(hello)
while True:
    bt = uart0.read(1)

    if bt:
        bt = bt.decode()
        uart0.write(bt)
        if bt == '/':

            cmd = buffer.split(':')
            buffer = ''
            bt = ''

            if cmd[0] == 'f':
                to_front( int(cmd[1]) )

            if cmd[0] == 'b':
                to_back( int(cmd[1]) )

            if cmd[0] == 'l':
                turn_left( int(cmd[1]) )

            if cmd[0] == 'r':
                turn_right( int(cmd[1]) )

            if cmd[0] == 's':
                turn_off()

        elif bt:
            buffer = buffer + bt

    led_app( 512 )

    led.duty_u16( led_dy )
    time.sleep( dy_s )
