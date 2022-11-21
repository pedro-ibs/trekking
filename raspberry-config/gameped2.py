#!/usr/bin/env python

from evdev import InputDevice, categorize, ecodes
import os
import time
import serial
import socket

path = '/dev/input/'
UDP_PORT	= 42420
UDP_IP		= '127.0.0.1'
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP


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
			
			for elem in dir_list:
				if elem == "event1":
					FindEvent1 = False

		gamepad	= InputDevice( '/dev/input/event1' )

		print( gamepad )
		print( gamepad.capabilities( verbose = True ) )

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
