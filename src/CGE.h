#pragma once

#include <Windows.h>
#include <vector>

class CGE
{
	unsigned short FPS;
	std::vector<char> frameData;
	HANDLE Buffer1, Buffer2, Back;
	bool switcher;
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
public:
	CGE(unsigned short FPS);
	COORD getSize();
	void setBufferSize(COORD size);
	void swap();
	std::vector<char>* getFrameData();
};