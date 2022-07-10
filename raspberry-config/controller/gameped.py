#!/usr/bin/env python

#import evdev
from evdev import InputDevice, categorize, ecodes

#creates object 'gamepad' to store the data
#you can call it whatever you like
gamepad = InputDevice('/dev/input/event0')

#prints out device info at start
print(gamepad)
# print(gamepad.capabilities())
print(gamepad.capabilities(verbose=True))


def show_event(absevent):
	print( "[ ", absevent.event.type, " - ", absevent.event.code," ] : ", absevent.event.value )
	


#evdev takes care of polling the controller in a loop
for event in gamepad.read_loop():
	if event.type == ecodes.EV_KEY:
		show_event(categorize(event))
	elif event.type == ecodes.EV_ABS:
		absevent = categorize(event)
		show_event(absevent)
