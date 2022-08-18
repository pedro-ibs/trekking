#!/usr/bin/env python

import serial
from evdev import InputDevice, categorize, ecodes

gamepad	= InputDevice( '/dev/input/event1' )
ser	= serial.Serial('/dev/ttyS0', 19200, timeout=0 ) 

print( gamepad )
print( gamepad.capabilities( verbose = True ) )

def show_event( absevent ):
	print( "[ ", absevent.event.type, " - ", absevent.event.code," ] : ", absevent.event.value )

def send_cmd( data ):
	data = bytes(data, 'utf-8')
	print ( data )
	ser.write(  data )

def remap_value( cmd, value ):
	if value > 0:
		send_cmd( cmd + ":" + str( value * 2 ) + ":0/" )
	else:
		send_cmd( cmd + ":0:" + str( value * 2 * -1 ) + "/" )
	return value

def run_command( absevent ):
	if absevent.event.type != 3:
		return

	code = absevent.event.code
	value = absevent.event.value

	if code == 17:
		if value == 0:
			send_cmd( "s:0/" )
		if value == -1:
			send_cmd( "f:65535/" )
		if value == 1:
			send_cmd( "b:65535/" )
	elif code == 16:
		if value == 0:
			send_cmd( "s:0/" )
		if value == -1:
			send_cmd( "l:65535/" )
		if value == 1:
			send_cmd( "r:65535/" )
	elif code == 1:
		if value == -1 or value == 0:
			send_cmd( "L:0:0/" )
			return
		remap_value( 'L', value )
	elif code == 4:
		if value == -1 or value == 0:
			send_cmd( "R:0:0/" )
			return
		remap_value( 'R', value )
		

for event in gamepad.read_loop():
	run_command( categorize( event ) )
	# if event.type == ecodes.EV_KEY:
	# 	show_event(categorize(event))
	# elif event.type == ecodes.EV_ABS:
	# 	absevent = categorize(event)
	# 	show_event(absevent)
