# Imports go at the top
from microbit import *

BAUDRATE=1200
channel=0
channel_pitch = 5
cont=0

def radioEnable():
    uart.init(baudrate=BAUDRATE, bits=8, parity=None, stop=1, tx=pin15, rx=pin16)
    pin14.write_digital( True )

def radioSetMode():
    uart.init(baudrate=BAUDRATE, bits=8, parity=None, stop=1, tx=pin15, rx=pin16)
    pin14.write_digital( False )
    sleep( 300 )

def radioSetAtCommand( at_cmmoand ):
    at_cmmoand = at_cmmoand + '\r\n'
    radioSetMode()
    print( at_cmmoand )
    sleep( 300 )
    ans = str( uart.read() ).replace("b'", '').replace("\\r\\n", '').replace("'", '').replace('OK', '')
    radioEnable()
    display.clear()
    display.scroll( ans, delay=100, wait=False )

def radioSetChannel(channel=1):
    if(channel<=0):
        channel=1
    if(channel>=100):
        channel=100
    radioSetAtCommand('AT+C{:03}'.format(channel))

def redioTransmit( data ):
    pin14.write_digital( True )
    print( data )
    sleep(2080)


if( button_a.is_pressed() and button_b.is_pressed() ):
    radioSetAtCommand('AT+FU2')
    sleep(3000)


if( button_a.is_pressed() ):
    radioSetAtCommand('AT+FU3')
    sleep(3000)

if( button_b.is_pressed() ):
    radioSetAtCommand('AT+FU4')
    sleep(3000)


radioSetAtCommand('AT+RX')
sleep(500)
radioEnable()
button_b.get_presses()
button_a.get_presses()


while True:
    cont = cont + 1
    if( button_b.get_presses() == 1 ):
        display.show( '>', delay=300, wait=False )
        channel = channel + channel_pitch
        radioSetChannel(channel)
        
    if( button_a.get_presses() == 1 ):
        display.show( '<', delay=300, wait=False )
        channel = channel - channel_pitch
        radioSetChannel(channel)

    msg = "{:06}>".format( cont ) + "{:03}".format( int( pin1.read_analog()/4 ) ) + "{:03}".format( int( pin2.read_analog()/4 ) ) + '#'
    
    redioTransmit( msg )
    
    
    

    
