#!/usr/bin/env python

import asyncio
from websockets import connect

async def hello(uri):
	async with connect(uri) as websocket:
		await websocket.send("--")
		data = await websocket.recv()
		print(data)

asyncio.run(hello("ws://tracker.local:8765"))
