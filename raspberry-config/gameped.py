#!/usr/bin/env python

from evdev import InputDevice, categorize, ecodes
import os
import time
import serial

ser		= serial.Serial('/dev/ttyS0', 19200, timeout=0 )
path		= '/dev/input/'

target_L	= 2 
target_R	= 2

def show_event( absevent ):
	print( "[ ", absevent.event.type, " - ", absevent.event.code," ] : ", absevent.event.value )

def send_cmd( data ):
	data = bytes(data, 'utf-8')
	print ( data )
	ser.write(  data )

def remap_value( cmd='s', value=0, factor=2.0 ):
	if value > 0:
		send_cmd( cmd + ":" + str( int( value * factor ) ) + ":0/" )
	else:
		send_cmd( cmd + ":0:" + str( int( value * factor * -1 ) ) + "/" )
	return value

def run_command( absevent ):
	# if absevent.event.type != 3:
		# return

	code = absevent.event.code
	value = absevent.event.value
	global target_L
	global target_R


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
	elif code == 5:
		if value == 0:
			target_R = 2
		elif value > 0:
			target_R = 1
	elif code == 2:
		if value == 0:
			target_L = 2
		elif value > 0:
			target_L = 1
	elif code == 311:
		print("aaaaa")
		if value == 0:
			target_R = 2
		elif value == 1:
			target_R = 0.5
	elif code == 310:
		print("bbbb")
		if value == 0:
			target_L = 2
		elif value == 1:
			target_L = 0.5

	elif code == 1:
		if value == -1 or value == 0:
			send_cmd( "L:0:0/" )
			return
		remap_value( 'L', value, target_L)
	elif code == 4:
		if value == -1 or value == 0:
			send_cmd( "R:0:0/" )
			return
		remap_value( 'R', value, target_R )
		
while True:

	try:
		send_cmd( "s:0/" )
		
		FindEvent1 = True
		while FindEvent1:
			time.sleep(1)
			dir_list = os.listdir(path)
			
			for elem in dir_list:
				if elem == "event1":
					FindEvent1 = False

		gamepad	= InputDevice( '/dev/input/event1' )

		print( gamepad )
		print( gamepad.capabilities( verbose = True ) )

		for event in gamepad.read_loop():
			run_command( categorize( event ) )
			if event.type == ecodes.EV_KEY:
				show_event(categorize(event))
			elif event.type == ecodes.EV_ABS:
				absevent = categorize(event)
				show_event(absevent)


	except OSError as Error:
		print(Error)
		FindEvent1 = True
		pass

