#include <iostream>
#include <raylib.h>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

Rectangle textBox = { 800 / 2.0f - 100, 180, 225, 50 };

std::string getKeyString(int keyCode) {
	switch (keyCode) {
		//Null data
		case 0:        // Key: NULL, used for no key pressed
			return "NULL";

		// Alphanumeric keys
		case 39:       // Key: '
			return "'";
		case 44:       // Key: ,
			return ",";
		case 45:       // Key: -
			return "-";
		case 46:       // Key: .
			return ".";
		case 47:       // Key: /
			return "/";
		case 48:       // Key: 0
			return "0";
		case 49:       // Key: 1
			return "1";
		case 50:       // Key: 2
			return "2";
		case 51:       // Key: 3
			return "3";
		case 52:       // Key: 4
			return "4";
		case 53:       // Key: 5
			return "5";
		case 54:       // Key: 6
			return "6";
		case 55:       // Key: 7
			return "7";
		case 56:       // Key: 8
			return "8";
		case 57:       // Key: 9
			return "9";
		case 59:       // Key: ;
			return ";";
		case 61:       // Key: =
			return "=";
		case 65:       // Key: A | a
			return "A";
		case 66:       // Key: B | b
			return "B";
		case 67:       // Key: C | c
			return "C";
		case 68:       // Key: D | d
			return "D";
		case 69:       // Key: E | e
			return "E";
		case 70:       // Key: F | f
			return "F";
		case 71:       // Key: G | g
			return "G";
		case 72:       // Key: H | h
			return "H";
		case 73:       // Key: I | i
			return "I";
		case 74:       // Key: J | j
			return "J";
		case 75:       // Key: K | k
			return "K";
		case 76:       // Key: L | l
			return "L";
		case 77:       // Key: M | m
			return "M";
		case 78:       // Key: N | n
			return "N";
		case 79:       // Key: O | o
			return "O";
		case 80:       // Key: P | p
			return "P";
		case 81:       // Key: Q | q
			return "Q";
		case 82:       // Key: R | r
			return "R";
		case 83:       // Key: S | s
			return "S";
		case 84:       // Key: T | t
			return "T";
		case 85:       // Key: U | u
			return "U";
		case 86:       // Key: V | v
			return "V";
		case 87:       // Key: W | w
			return "W";
		case 88:       // Key: X | x
			return "X";
		case 89:       // Key: Y | y
			return "Y";
		case 90:       // Key: Z | z
			return "Z";
		case 91:       // Key: [
			return "[";
		case 92:       // Key: '\'
			return "\\";
		case 93:       // Key: ]
			return "]";
		case 96:       // Key: `
			return "`";

		// Function keys
		case 32:       // Key: Space
			return "Space";
		case 256:      // Key: Esc
			return "Esc";
		case 257:      // Key: Enter
			return "Enter";
		case 258:      // Key: Tab
			return "Tab";
		case 259:      // Key: Backspace
			return "Backspace";
		case 260:      // Key: Ins
			return "Ins";
		case 261:      // Key: Del
			return "Del";
		case 262:      // Key: Cursor right
			return "Right";
		case 263:      // Key: Cursor left
			return "Left";
		case 264:      // Key: Cursor down
			return "Down";
		case 265:      // Key: Cursor up
			return "Up";
		case 266:      // Key: Page up
			return "Page up";
		case 267:      // Key: Page down
			return "Page down";
		case 268:      // Key: Home
			return "Home";
		case 269:      // Key: End
			return "End";
		case 280:      // Key: Caps lock
			return "Caps lock";
		case 281:      // Key: Scroll down
			return "Scroll down";
		case 282:      // Key: Num lock
			return "Num lock";
		case 283:      // Key: Print screen
			return "Print screen";
		case 284:      // Key: Pause
			return "Pause";
		case 290:      // Key: F1
			return "F1";
		case 291:      // Key: F2
			return "F2";
		case 292:      // Key: F3
			return "F3";
		case 293:      // Key: F4
			return "F4";
		case 294:      // Key: F5
			return "F5";
		case 295:      // Key: F6
			return "F6";
		case 296:      // Key: F7
			return "F7";
		case 297:      // Key: F8
			return "F8";
		case 298:      // Key: F9
			return "F9";
		case 299:      // Key: F10
			return "F10";
		case 300:      // Key: F11
			return "F11";
		case 301:      // Key: F12
			return "F12";
		case 340:      // Key: Shift left
			return "Shift left";
		case 341:      // Key: Control left
			return "Control left";
		case 342:      // Key: Alt left
			return "Alt left";
		case 343:      // Key: Super left
			return "Super left";
		case 344:      // Key: Shift right
			return "Shift right";
		case 345:      // Key: Control right
			return "Control right";
		case 346:      // Key: Alt right
			return "Alt right";
		case 347:      // Key: Super right
			return "Super right";
		case 348:      // Key: KB menu
			return "KB menu";

		// Keypad keys
		case 320:      // Key: Keypad 0
			return "0";
		case 321:      // Key: Keypad 1
			return "1";
		case 322:      // Key: Keypad 2
			return "2";
		case 323:      // Key: Keypad 3
			return "3";
		case 324:      // Key: Keypad 4
			return "4";
		case 325:      // Key: Keypad 5
			return "5";
		case 326:      // Key: Keypad 6
			return "6";
		case 327:      // Key: Keypad 7
			return "7";
		case 328:      // Key: Keypad 8
			return "8";
		case 329:      // Key: Keypad 9
			return "9";
		case 330:      // Key: Keypad .
			return ".";
		case 331:      // Key: Keypad /
			return "/";
		case 332:      // Key: Keypad *
			return "*";
		case 333:      // Key: Keypad -
			return "-";
		case 334:      // Key: Keypad +
			return "+";
		case 335:      // Key: Keypad Enter
			return "Enter";
		case 336:      // Key: Keypad =
			return "=";

		//Default
		default:
			return "UNKNOWN";
		}
}

//*************************************************************************
//*************************************************************************
//*************************************************************************
int main() {

	//Window initialization
	InitWindow(800, 600, "Asteroids in C++ [Raylib]");
	SetTargetFPS(60);

	//Timing variables
	int gameTotalSeconds = GetTime();
	int seconds = 0;
	int minutes = 0;
	float deltaTime;

	//Input Variables
	int gameState = 0; //0 = pick number, 1 = active game
	char UsrInputArray [10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'}; //index 2 = "\0"
	string pressedKey_str = "Key Pressed:";
	string outBox_str = "";

	//Game Objects
	string promptUsr = " ";
	string question = " ";

	//If window isnt closed, continue to run game
	while (!WindowShouldClose()) {

		//Game Loop
		BeginDrawing();
		ClearBackground(BLACK);

		//Timing mechanics
		deltaTime = GetFrameTime();
		int currentTime = GetTime();
		if (gameTotalSeconds != currentTime) {
			seconds++;
			if (seconds == 60) {
				seconds = 0;
				minutes++;
			}
			gameTotalSeconds = currentTime;
		}
		string seconds_str = "Seconds: " + to_string(seconds);
		string minutes_str = "Minutes: " + to_string(minutes);
		string deltaTime_str = "Delta Time: " + to_string(deltaTime);

		//General input mechanics
		int key = GetKeyPressed();
		if (key != 0 /*null*/) {
			pressedKey_str = "Key Pressed: " + getKeyString(key);
			string pressedKey_str_2 = getKeyString(key);
			
			//Multiple ways of copying string values as needed
				//1	
					//UsrInputArray[0] = pressedKey_str_2[0];
				//2
					//strcpy_s(UsrInputArray, pressedKey_str_2.c_str());
				//3
					//might have to use a counter that equals the length
					//of the amount of keys that will be inserted into the 
					//array, once the last character is reached, start back
					//at 0

		}

		//Console (Left of red line)
		DrawLine(210, 0, 210, 600, RED);
		DrawFPS(2, 2);
		DrawText(seconds_str.c_str(), 2, 20, 20, GREEN);
		DrawText(minutes_str.c_str(), 2, 40, 20, GREEN);
		DrawText(deltaTime_str.c_str(), 2, 60, 20, GREEN);
		DrawText(pressedKey_str.c_str(), 2, 80, 20, GREEN);
		
		//Grey input box
		DrawText(promptUsr.c_str(), 300, 150, 20, GREEN);
		DrawRectangleRec(textBox, LIGHTGRAY);
		DrawText(UsrInputArray,305, 180, 50, BLACK);

		//Game (Right of red line)
		if (gameState == 0) {
			promptUsr = "Pick a number to train: ";
		}
		else {
			promptUsr = question;
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
