//#include "CTimer.h"
//#include "CGameError.h"
//#include "CConstants.h"
//
//#include <d3dx9.h>
//
//namespace Zero
//{
//
//	CTimer::CTimer()
//	{
//		m_fFps = 0;
//		m_fFrameTime = 0;
//	}
//
//
//	CTimer::~CTimer()
//	{
//
//	}
//
//	
//	bool CTimer::Initialize(void)
//	{
//		// attempt to set up high resolution timer
//		if (QueryPerformanceFrequency(&m_iTimeFreq) == false)
//			throw(CGameError(gameErrorNS::FATAL_ERROR, "Error initializing high resolution timer"));
//
//		QueryPerformanceCounter(&m_iTimeStart);        // get starting time
//
//		return true;
//	}
//
//	void CTimer::BeginCounter(void)
//	{
//		QueryPerformanceCounter(&m_iTimeStart);
//
//		// calculate elapsed time of last frame, save in frameTime
//		QueryPerformanceCounter(&m_iTimeEnd);
//		m_fFrameTime = (float)(timeEnd.QuadPart - timeStart.QuadPart) / (float)timeFreq.QuadPart;
//
//		// Power saving code, requires winmm.lib
//		// if not enough time has elapsed for desired frame rate
//		if (frameTime < MIN_FRAME_TIME)
//		{
//			sleepTime = (DWORD)((MIN_FRAME_TIME - frameTime) * 1000);
//			//timeBeginPeriod(1);         // Request 1mS resolution for windows timer
//			Sleep(sleepTime);           // release cpu for sleepTime
//			//timeEndPeriod(1);           // End 1mS timer resolution
//			return false;
//		}
//
//		if (frameTime > 0.0)
//			fps = (fps*0.99f) + (0.01f / frameTime);  // average fps
//		if (frameTime > MAX_FRAME_TIME) // if frame rate is very slow
//			frameTime = MAX_FRAME_TIME; // limit maximum frameTime
//		timeStart = timeEnd;
//
//		return;
//	}
//
//
//	void CTimer::EndCounter()
//	{
//		QueryPerformanceCounter(&m_iTimeEnd);
//		m_fFrameTime = float(m_iTimeEnd.QuadPart - m_iTimeStart.QuadPart) / (float)m_iTimeFreq.QuadPart;
//
//	}
//}