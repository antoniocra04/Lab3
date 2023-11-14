#pragma once

struct RingBufferItem
{
	RingBufferItem* _prev;
	RingBufferItem* _next;
	int _value;
};