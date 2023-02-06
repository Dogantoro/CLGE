#include "CGE.h"

#include <iostream>
#include <Windows.h>
#include <vector>

std::vector<char>* frameData;
COORD screenSize;

void draw() {
	for (int i = 0; i < screenSize.Y; i++) {
		for (int j = 0; j < screenSize.X; j++) {
			(* frameData)[i * screenSize.X + j] = '@';
		}
	}
	std::cout << "hen: " << frameData->capacity();
}

int main() {
	CGE Engine = CGE(25);
	screenSize = Engine.getSize();
	Engine.setBufferSize(screenSize);
	frameData = Engine.getFrameData();
	frameData->resize(screenSize.X * screenSize.Y);

	while (true) {
		draw();
		Engine.swap();
	}
}