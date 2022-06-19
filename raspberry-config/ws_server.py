#!/usr/bin/env python

import asyncio
import os

from websockets import serve

async def echo(websocket):
	async for message in websocket:
		await websocket.send(message)
		os.system('echo ' + message + ' > ' + '/dev/ttyS0' )

async def main():
	async with serve(echo, "localhost", 8765):

asyncio.run(main())

