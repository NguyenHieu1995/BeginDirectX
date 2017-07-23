//// Programming 2D Games
//// Copyright (c) 2011 by: 
//// Charles Kelly
//// input.cpp v1.6
//// Last modified Feb-7-2013
//
//#include "CInput.h"
//
////=============================================================================
//// default constructor
////=============================================================================
//CInput::CInput()
//{
//	// clear key down array
//	for (size_t i = 0; i < inputNS::KEYS_ARRAY_LEN; i++)
//		keysDown[i] = false;
//	// clear key pressed array
//	for (size_t i = 0; i < inputNS::KEYS_ARRAY_LEN; i++)
//		keysPressed[i] = false;
//	newLine = true;                     // start new line
//	textIn = "";                        // clear textIn
//	charIn = 0;                         // clear charIn
//
//	// mouse data
//	mouseX = 0;                         // screen X
//	mouseY = 0;                         // screen Y
//	mouseRawX = 0;                      // high-definition X
//	mouseRawY = 0;                      // high-definition Y
//	mouseWheel = 0;                     // mouse wheel position
//	mouseLButton = false;               // true if left mouse button is down
//	mouseMButton = false;               // true if middle mouse button is down
//	mouseRButton = false;               // true if right mouse button is down
//	mouseX1Button = false;              // true if X1 mouse button is down
//	mouseX2Button = false;              // true if X2 mouse button is down
//
//	for (int i = 0; i<MAX_CONTROLLERS; i++)
//	{
//		controllers[i].vibrateTimeLeft = 0;
//		controllers[i].vibrateTimeRight = 0;
//	}
//	thumbstickDeadzone = GAMEPAD_THUMBSTICK_DEADZONE;    // default
//	triggerDeadzone = GAMEPAD_TRIGGER_DEADZONE;          // default
//}
//
////=============================================================================
//// destructor
////=============================================================================
//CInput::~CInput()
//{
//	if (mouseCaptured)
//		ReleaseCapture();               // release mouse
//}
//
////=============================================================================
//// Initialize mouse and controller input
//// Set capture=true to capture mouse
//// Throws GameError
////=============================================================================
//void CInput::initialize(HWND hwnd, bool capture)
//{
//	try{
//		mouseCaptured = capture;
//
//		// register high-definition mouse
//		Rid[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
//		Rid[0].usUsage = HID_USAGE_GENERIC_MOUSE;
//		Rid[0].dwFlags = RIDEV_INPUTSINK;
//		Rid[0].hwndTarget = hwnd;
//		RegisterRawInputDevices(Rid, 1, sizeof(Rid[0]));
//
//		if (mouseCaptured)
//			SetCapture(hwnd);           // capture mouse
//
//		// Clear controllers state
//		ZeroMemory(controllers, sizeof(ControllerState)* MAX_CONTROLLERS);
//
//		checkControllers();             // check for connected controllers
//	}
//	catch (...)
//	{
//		throw(CGameError(gameErrorNS::FATAL_ERROR, "Error initializing input system"));
//	}
//}
//
////=============================================================================
//// Set true in the keysDown and keysPessed array for this key
//// Pre: wParam contains the virtual key code (0--255)
////=============================================================================
//void CInput::keyDown(WPARAM wParam)
//{
//	// make sure key code is within buffer range
//	if (wParam < inputNS::KEYS_ARRAY_LEN)
//	{
//		keysDown[wParam] = true;    // update keysDown array
//		// key has been "pressed, erased by clear()
//		keysPressed[wParam] = true; // update keysPressed array
//	}
//}
//
////=============================================================================
//// Set false in the keysDown array for this key
//// Pre: wParam contains the virtual key code (0--255)
////=============================================================================
//void CInput::keyUp(WPARAM wParam)
//{
//	// make sure key code is within buffer range
//	if (wParam < inputNS::KEYS_ARRAY_LEN)
//		// update state table
//		keysDown[wParam] = false;
//}
//
////=============================================================================
//// Save the char just entered in textIn string
//// Pre: wParam contains the char
////=============================================================================
//void CInput::keyIn(WPARAM wParam)
//{
//	if (newLine)                            // if start of new line
//	{
//		textIn.clear();
//		newLine = false;
//	}
//
//	if (wParam == '\b')                     // if backspace
//	{
//		if (textIn.length() > 0)             // if characters exist
//			textIn.erase(textIn.size() - 1);  // erase last character entered
//	}
//	else
//	{
//		textIn += wParam;                   // add character to textIn
//		charIn = wParam;                    // save last char entered
//	}
//
//	if ((char)wParam == '\r')               // if return    
//		newLine = true;                     // start new line
//}
//
////=============================================================================
//// Returns true if the specified VIRTUAL KEY is down, otherwise false.
////=============================================================================
//bool CInput::isKeyDown(UCHAR vkey) const
//{
//	if (vkey < inputNS::KEYS_ARRAY_LEN)
//		return keysDown[vkey];
//	else
//		return false;
//}
//
////=============================================================================
//// Return true if the specified VIRTUAL KEY has been pressed in the most recent
//// frame. Key presses are erased at the end of each frame.
////=============================================================================
//bool CInput::wasKeyPressed(UCHAR vkey) const
//{
//	if (vkey < inputNS::KEYS_ARRAY_LEN)
//		return keysPressed[vkey];
//	else
//		return false;
//}
//
////=============================================================================
//// Return true if any key was pressed in the most recent frame.
//// Key presses are erased at the end of each frame.
////=============================================================================
//bool CInput::anyKeyPressed() const
//{
//	for (size_t i = 0; i < inputNS::KEYS_ARRAY_LEN; i++)
//	if (keysPressed[i] == true)
//		return true;
//	return false;
//}
//
////=============================================================================
//// Clear the specified key press
////=============================================================================
//void CInput::clearKeyPress(UCHAR vkey)
//{
//	if (vkey < inputNS::KEYS_ARRAY_LEN)
//		keysPressed[vkey] = false;
//}
//
////=============================================================================
//// Clear specified input buffers
//// See input.h for what values
////=============================================================================
//void CInput::clear(UCHAR what)
//{
//	if (what & inputNS::KEYS_DOWN)       // if clear keys down
//	{
//		for (size_t i = 0; i < inputNS::KEYS_ARRAY_LEN; i++)
//			keysDown[i] = false;
//	}
//	if (what & inputNS::KEYS_PRESSED)    // if clear keys pressed
//	{
//		for (size_t i = 0; i < inputNS::KEYS_ARRAY_LEN; i++)
//			keysPressed[i] = false;
//	}
//	if (what & inputNS::MOUSE)           // if clear mouse
//	{
//		mouseX = 0;
//		mouseY = 0;
//		mouseRawX = 0;
//		mouseRawY = 0;
//		mouseWheel = 0;
//	}
//	if (what & inputNS::TEXT_IN)
//	{
//		clearTextIn();
//		clearCharIn();
//	}
//}
//
////=============================================================================
//// Reads mouse screen position into mouseX, mouseY
////=============================================================================
//void CInput::mouseIn(LPARAM lParam)
//{
//	mouseX = GET_X_LPARAM(lParam);
//	mouseY = GET_Y_LPARAM(lParam);
//}
//
////=============================================================================
//// Reads raw mouse data into mouseRawX, mouseRawY
//// This routine is compatible with a high-definition mouse
////=============================================================================
//void CInput::mouseRawIn(LPARAM lParam)
//{
//	UINT dwSize = 40;
//	static BYTE lpb[40];
//
//	GetRawInputData((HRAWINPUT)lParam, RID_INPUT,
//		lpb, &dwSize, sizeof(RAWINPUTHEADER));
//
//	RAWINPUT* raw = (RAWINPUT*)lpb;
//
//	if (raw->header.dwType == RIM_TYPEMOUSE)
//	{
//		mouseRawX = raw->data.mouse.lLastX;
//		mouseRawY = raw->data.mouse.lLastY;
//	}
//}
//
////=============================================================================
//// Reads mouse wheel movement expressed in multiples of WHEEL_DELTA, which
//// is 120. A positive value indicates that the wheel was rotated away from the
//// user, a negative value indicates that the wheel was rotated toward the user.
////=============================================================================
//void CInput::mouseWheelIn(WPARAM wParam)
//{
//	mouseWheel = GET_WHEEL_DELTA_WPARAM(wParam);
//}
//
////=============================================================================
//// Check for connected controllers
////=============================================================================
//void CInput::checkControllers()
//{
//	DWORD result;
//	for (DWORD i = 0; i <MAX_CONTROLLERS; i++)
//	{
//		result = XInputGetState(i, &controllers[i].state);
//		if (result == ERROR_SUCCESS)
//			controllers[i].connected = true;
//		else
//			controllers[i].connected = false;
//	}
//}
//
////=============================================================================
//// Read state of connected controllers
////=============================================================================
//void CInput::readControllers()
//{
//	DWORD result;
//	for (DWORD i = 0; i <MAX_CONTROLLERS; i++)
//	{
//		if (controllers[i].connected)
//		{
//			result = XInputGetState(i, &controllers[i].state);
//			if (result == ERROR_DEVICE_NOT_CONNECTED)    // if controller disconnected
//				controllers[i].connected = false;
//		}
//	}
//}
//
////=============================================================================
//// Return value of controller n Left Trigger (0 through 255).
//// Trigger movement less than triggerDeadzone returns 0.
//// Return value is scaled to 0 through 255
////=============================================================================
//BYTE CInput::getGamepadLeftTrigger(UINT n)
//{
//	BYTE value = getGamepadLeftTriggerUndead(n);
//	if (value > triggerDeadzone)             // if > dead zone
//		//adjust magnitude relative to the end of the dead zone
//		value = (value - triggerDeadzone) * 255 /
//		(255 - triggerDeadzone);
//	else                                    // else, < dead zone
//		value = 0;
//	return value;
//}
//
////=============================================================================
//// Return value of controller n Right Trigger (0 through 255).
//// Trigger movement less than triggerDeadzone returns 0.
//// Return value is scaled to 0 through 255
////=============================================================================
//BYTE CInput::getGamepadRightTrigger(UINT n)
//{
//	BYTE value = getGamepadRightTriggerUndead(n);
//	if (value > triggerDeadzone)    // if > dead zone
//		//adjust magnitude relative to the end of the dead zone
//		value = (value - triggerDeadzone) * 255 /
//		(255 - triggerDeadzone);
//	else                                    // else, < dead zone
//		value = 0;
//	return value;
//}
//
////=============================================================================
//// Return value of controller n Left Thumbstick X (-32767 through 32767).
//// Stick movement less than thumbstickDeadzone returns 0.
//// Return value is scaled to -32768 through 32767
////=============================================================================
//SHORT CInput::getGamepadThumbLX(UINT n)
//{
//	int x = getGamepadThumbLXUndead(n);
//	if (x > thumbstickDeadzone) // if +x outside dead zone
//		//adjust x relative to the deadzone and scale to 0 through 32767
//		x = (x - thumbstickDeadzone) * 32767 /
//		(32767 - thumbstickDeadzone);
//	else if (x < -thumbstickDeadzone)   // if -x outside dead zone
//		//adjust y relative to the deadzone and scale to 0 through -32767
//		x = (x + thumbstickDeadzone) * 32767 /
//		(32767 - thumbstickDeadzone);
//	else        // else, x inside dead zone
//		x = 0;  // return 0
//	return static_cast<SHORT>(x);
//}
//
////=============================================================================
//// Return value of controller n Left Thumbstick Y (-32768 through 32767).
//// Stick movement less than thumbstickDeadzone returns 0.
//// Return value is scaled to -32768 through 32767
////=============================================================================
//SHORT CInput::getGamepadThumbLY(UINT n)
//{
//	int y = getGamepadThumbLYUndead(n);
//	if (y > thumbstickDeadzone) // if +y outside dead zone
//		//adjust magnitude relative to the end of the dead zone
//		y = (y - thumbstickDeadzone) * 32767 /
//		(32767 - thumbstickDeadzone);
//	else if (y < -thumbstickDeadzone)   // if -y outside dead zone
//		//adjust magnitude relative to the end of the dead zone
//		y = (y + thumbstickDeadzone) * 32767 /
//		(32767 - thumbstickDeadzone);
//	else        // else, y inside dead zone
//		y = 0;  // return 0
//	return static_cast<SHORT>(y);
//}
//
////=============================================================================
//// Return value of controller n Right Thumbstick X (-32768 through 32767).
//// Stick movement less than thumbstickDeadzone returns 0.
//// Return value is scaled to -32768 through 32767
////=============================================================================
//SHORT CInput::getGamepadThumbRX(UINT n)
//{
//	int x = getGamepadThumbRXUndead(n);
//	if (x > thumbstickDeadzone) // if +x outside dead zone
//		//adjust magnitude relative to the end of the dead zone
//		x = (x - thumbstickDeadzone) * 32767 /
//		(32767 - thumbstickDeadzone);
//	else if (x < -thumbstickDeadzone)   // if -x outside dead zone
//		//adjust magnitude relative to the end of the dead zone
//		x = (x + thumbstickDeadzone) * 32767 /
//		(32767 - thumbstickDeadzone);
//	else        // else, x inside dead zone
//		x = 0;  // return 0
//	return static_cast<SHORT>(x);
//}
//
////=============================================================================
//// Return value of controller n Right Thumbstick Y (-32768 through 32767).
//// Stick movement less than thumbstickDeadzone returns 0.
//// Return value is scaled to -32768 through 32767
////=============================================================================
//SHORT CInput::getGamepadThumbRY(UINT n)
//{
//	int y = getGamepadThumbRYUndead(n);
//	if (y > thumbstickDeadzone) // if +y outside dead zone
//		//adjust magnitude relative to the end of the dead zone
//		y = (y - thumbstickDeadzone) * 32767 /
//		(32767 - thumbstickDeadzone);
//	else if (y < -thumbstickDeadzone)   // if -y outside dead zone
//		//adjust magnitude relative to the end of the dead zone
//		y = (y + thumbstickDeadzone) * 32767 /
//		(32767 - thumbstickDeadzone);
//	else        // else, y inside dead zone
//		y = 0;  // return 0
//	return static_cast<SHORT>(y);
//}
//
////=============================================================================
//// Vibrate connected controllers
////=============================================================================
//void CInput::vibrateControllers(float frameTime)
//{
//	for (int i = 0; i < MAX_CONTROLLERS; i++)
//	{
//		if (controllers[i].connected)
//		{
//			controllers[i].vibrateTimeLeft -= frameTime;
//			if (controllers[i].vibrateTimeLeft < 0)
//			{
//				controllers[i].vibrateTimeLeft = 0;
//				controllers[i].vibration.wLeftMotorSpeed = 0;
//			}
//			controllers[i].vibrateTimeRight -= frameTime;
//			if (controllers[i].vibrateTimeRight < 0)
//			{
//				controllers[i].vibrateTimeRight = 0;
//				controllers[i].vibration.wRightMotorSpeed = 0;
//			}
//			XInputSetState(i, &controllers[i].vibration);
//		}
//	}
//}
//
