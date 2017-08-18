#ifndef __CFRAMETIME_H__
#define __CFRAMETIME_H__

#include <d3dx9.h>

#define DEFAULT_FPS 60

class CFrameTime
{
public:
	CFrameTime();
	~CFrameTime();

protected:
	INT64 m_iCurrentTime;
	INT64 m_iPreviouTime;

	INT64 m_iBaseTime;
	INT64 m_iPausedTime;
	INT64 m_iStopTime;
	INT64 m_iPrevTime;
	INT64 m_iCurrTime;

	bool m_isStopped;

	double m_dCountPersecond;
	double m_dDeltaTime;

public:
	void Reset();
	void Start();
	void Stop();
	void Update();

	float getGameTime() const;
	float getDeltaTime() const;
};

#endif