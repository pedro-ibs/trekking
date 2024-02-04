#!/usr/bin/env python3

from evdev import InputDevice, categorize, ecodes
import sys
import os
import time
#import serial
import socket

path		= '/dev/input/'
event		= ''
UDP_PORT	= 42420
UDP_IP		= '127.0.0.1'
sock		= socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
gamepad		= ''

def put_event(_type='null', _code='null', _value='null'):
	if _type == 0:
		return;

	payload = '{"type":'+str(_type)+',"code":'+str(_code)+',"value":'+str(_value)+'}'
	print(payload);
	sock.sendto(bytes(payload , "utf-8"), (UDP_IP, UDP_PORT))



while True:
	try:
		put_event()

		FindEvent1 = True
		while FindEvent1:
			time.sleep(1)
			dir_list = os.listdir(path)
			print( "find devices between: " + str(dir_list) )
			print( "----------------------" )
			for elem in dir_list:
				try:
					gamepad = 'null'
					gamepad	= InputDevice( path + elem )
					print( "check [ " +   path + elem + " ]--> " + str( gamepad ) )
				except:
					gamepad = 'null'
					print( "check [ " +   path + elem + " ]--> " + str( gamepad ) )
					pass

				if "Microsoft X-Box 360 pad" in str(gamepad):
					print("gameped connected!!")
					event = path + elem
					FindEvent1 = False
					break

		print( gamepad.capabilities( verbose = True ) )

		put_event('42', '42', '42')

		for event in gamepad.read_loop():
			if event.type == ecodes.EV_ABS:
				absevent = categorize(event)
				put_event(_type=absevent.event.type, _code=absevent.event.code, _value=absevent.event.value)
			else:
				put_event(_type=event.type, _code=event.code, _value=event.value)
			time.sleep(0.02)

	except OSError as Error:
		print(Error)
		FindEvent1 = True
		pass
