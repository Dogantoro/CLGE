#include "CGE.h"


CGE::CGE(unsigned short FPS) {
	this->FPS = FPS;
	Buffer1 = GetStdHandle(STD_OUTPUT_HANDLE);
	Buffer2 = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	Back = Buffer2; switcher = true;
	GetConsoleScreenBufferInfo(Buffer1, &consoleInfo);
}

COORD CGE::getSize() {
	const auto width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	const auto height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	return COORD{ static_cast<short> (width), static_cast<short> (height) };
}

void CGE::setBufferSize(COORD size) {
	SetConsoleScreenBufferSize(Buffer1, size);
	SetConsoleScreenBufferSize(Buffer2, size);
}

void CGE::swap() {
	WriteConsole(Back, &frameData.front(), static_cast<short>(frameData.size()), nullptr, nullptr);
	SetConsoleActiveScreenBuffer(Back);
	Back = switcher ? Buffer1 : Buffer2;
	switcher = !switcher;
	Sleep(1000 / FPS);
}

std::vector<char>* CGE::getFrameData() {
	return &frameData;
}

