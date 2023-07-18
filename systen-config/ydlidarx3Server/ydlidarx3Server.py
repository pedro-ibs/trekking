#!/usr/bin/env python3

import os
import ydlidar
import time
import sys
import json
import socket

# setting server
UDP_IP		= '127.0.0.1'
UDP_PORT	= 42421
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# get serial port
ydlidar.os_init();
ports = ydlidar.lidarPortList();
port = "/dev/ydlidar";
for key, value in ports.items():
	port = value;
	print(port);

# setting YDlidar X3
laser = ydlidar.CYdLidar();
laser.setlidaropt(ydlidar.LidarPropSerialPort, port);
laser.setlidaropt(ydlidar.LidarPropSerialBaudrate, 115200);
laser.setlidaropt(ydlidar.LidarPropLidarType, ydlidar.TYPE_TRIANGLE);
laser.setlidaropt(ydlidar.LidarPropDeviceType, ydlidar.YDLIDAR_TYPE_SERIAL);
laser.setlidaropt(ydlidar.LidarPropScanFrequency, 10.0);
laser.setlidaropt(ydlidar.LidarPropSampleRate, 3);
laser.setlidaropt(ydlidar.LidarPropSingleChannel, True);
laser.setlidaropt(ydlidar.LidarPropMaxAngle, 180.0);
laser.setlidaropt(ydlidar.LidarPropMinAngle, -180.0);
laser.setlidaropt(ydlidar.LidarPropMaxRange, 8.0);
laser.setlidaropt(ydlidar.LidarPropMinRange, 0.08);
laser.setlidaropt(ydlidar.LidarPropIntenstiy, False);
scan = ydlidar.LaserScan()


def scaning():
	print("get sample...")
	r = laser.doProcessSimple(scan)
	if r:
		angle = []
		ran = []
		intensity = []
		for point in scan.points:
			angle.append(point.angle)
			ran.append(point.range)
			intensity.append(point.intensity)
		
		sample = { "angle": angle, "range": ran, "intensity": intensity }
		sample = json.dumps(sample)
		
		return sample

ret = laser.initialize();
if ret:
	ret = laser.turnOn();
	if ret:
		while True:
			payload = scaning()
			sock.sendto(payload , (UDP_IP, UDP_PORT))
laser.turnOff();
laser.disconnecting();




