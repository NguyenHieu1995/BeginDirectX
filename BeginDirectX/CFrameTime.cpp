#include "CFrameTime.h"

CFrameTime::CFrameTime()
{
	m_dCountPersecond = 0.0f;
	m_iCurrentTime = 0;
	m_iPreviouTime = 0;
	m_dDeltaTime = -1.0f;
	m_isStopped = false;
	m_iBaseTime = 0;
	m_iPausedTime = 0;

	INT64 countPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countPerSec);
	m_dCountPersecond = 1.0f / (double)countPerSec;
}

CFrameTime::~CFrameTime()
{

}

void CFrameTime::Reset()
{
	INT64 currentTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	m_iCurrentTime = currentTime;
	m_iPreviouTime = currentTime;
	m_iStopTime = 0;
	m_isStopped = false;
}

void CFrameTime::Stop()
{
	if (!m_isStopped)
	{
		INT64 currentTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

		m_iStopTime = currentTime;
		m_isStopped = true;
	}
}

void CFrameTime::Start()
{
	INT64 startTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

	if (m_isStopped)
	{
		m_iPausedTime += (startTime - m_iStopTime);
		m_iPreviouTime = startTime;
		m_iStopTime = 0;
		m_isStopped = false;
	}
}

void CFrameTime::Update()
{
	if (m_isStopped)
	{
		m_dDeltaTime = 0.0f;
		return;
	}

	INT64 currentTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	m_iCurrentTime = currentTime;

	m_dDeltaTime = (m_iCurrentTime - m_iPreviouTime) * m_dCountPersecond;

	m_iPreviouTime = m_iCurrentTime;

	if (m_dDeltaTime < 0)
	{
		m_dDeltaTime = 0.0f;
	}
}

float CFrameTime::getDeltaTime() const
{
		return (float)m_dDeltaTime;
}

float CFrameTime::getGameTime() const
{
	if (m_isStopped)
	{
		return (float)(m_iStopTime - m_iBaseTime) * m_dCountPersecond;
	}
	else
	{
		return (float)(((m_iCurrentTime - m_iPausedTime) - m_iBaseTime) * m_dCountPersecond);
	}
}