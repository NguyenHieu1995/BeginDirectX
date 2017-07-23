//#include "CGame.h"
//#include <stdio.h>
//#include <Windows.h>
//#include "CStateManagement.h"
//#include "CConstants.h"
//#include "CTimer.h"
//
//namespace Zero
//{
//	CGame* CGame::m_psInstance = nullptr;
//
//	CGame* CGame::GetInstance()
//	{
//		return m_psInstance;
//	}
//
//	void CGame::FreeInstance()
//	{
//		SAFE_DELETE(m_psInstance);
//	}
//
//
//	CGame::CGame(void)
//	{
//		m_psInstance = this;
//
//		m_isAlived = true;
//		m_isPaused = false;
//	}
//
//
//	CGame::~CGame(void)
//	{
//
//	}
//
//
//	bool CGame::IsAlive(void)
//	{
//		return m_isAlived;
//	}
//
//
//	bool CGame::IsPause(void)
//	{
//		return m_isPaused;
//	}
//
//	void CGame::Run(void)
//	{
//		Init();
//		CTimer::GetInstance()->Initialize();
//
//		while (m_isAlived)
//		{
//			//Begin count Time
//
//			//Update Input	
//			//Input->Update();
//
//			//Loop Update
//			if (CTimer::GetInstance()->CheckTime())
//			{
//				if (m_isPaused)
//				{
//					CStateManagement::GetInstance()->UpdateState(true);
//				}
//				else
//				{
//					CStateManagement::GetInstance()->UpdateState(false);
//				}
//			}
//
//			//Render
//
//		}
//
//
//		CStateManagement::GetInstance()->SwitchState(0);
//		CStateManagement::GetInstance()->UpdateState(false);
//
//
//		Destroy();
//
//		return;
//	}
//
//
//	void CGame::Exit(void)
//	{
//		m_isAlived = false;
//		return;
//	}
//
//
//	void CGame::Pause(void)
//	{
//		m_isPaused = true;
//		return;
//	}
//
//
//	void CGame::Resume(void)
//	{
//		m_isPaused = false;
//		return;
//	}
//
//
//}