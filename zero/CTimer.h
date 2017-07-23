////
////Created: 21/07/2017
////Creator: Zero.Se08
////Class: CTimer
////
//
//#ifndef __CTIMER_H__
//#define __CTIMER_H__
//
//#include <Windows.h>
//
//namespace Zero
//{
//	class CTimer
//	{
//	public:
//		CTimer();
//		virtual ~CTimer();
//
//	public:
//		bool Initialize(void); //Init
//		void BeginCounter(void);
//		void EndCounter(void);
//
//	protected:
//		LARGE_INTEGER m_iTimeStart;    // Performance Counter start value
//		LARGE_INTEGER m_iTimeEnd;      // Performance Counter end value
//		LARGE_INTEGER m_iTimeFreq;    // Performance Counter frequency
//		float   m_fFrameTime;          // time required for last frame
//		float   m_fFps;                // frames per second
//		DWORD   m_iSleepTime;          // number of milli-seconds to sleep between frames
//
//	};
//
//
//}
//
//
//#endif