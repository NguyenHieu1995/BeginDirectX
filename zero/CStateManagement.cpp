//#include "CStateManagement.h"
//#include "CHeader.h"
//
//namespace Zero
//{
//
//	//
//	CStateManagement* CStateManagement::m_psInstance = nullptr;
//
//
//	CStateManagement* CStateManagement::GetInstance(void)
//	{
//		if (!m_psInstance)
//		{
//			m_psInstance = new CStateManagement();
//		}
//		
//
//		return m_psInstance;
//	}
//	//
//
//	CStateManagement::CStateManagement()
//	{
//		m_pCurrentState = nullptr;
//		m_pNextState = nullptr;
//	}
//
//	CStateManagement::~CStateManagement()
//	{
//
//	}
//
//
//	void CStateManagement::UpdateState(bool isPaused)
//	{
//		if (m_pCurrentState != m_pNextState)
//		{
//			if (m_pCurrentState)
//			{
//				m_pCurrentState->Exit();
//				SAFE_DELETE(m_pCurrentState);
//			}
//			if (m_pNextState)
//			{
//				m_pNextState->Init();
//			}
//			m_pCurrentState = m_pNextState;
//		}
//
//
//		if (m_pCurrentState)
//		{
//			if (!isPaused)
//			{
//				m_pCurrentState->Update();
//			}
//			m_pCurrentState->Render();
//		}
//	}
//
//	
//	void CStateManagement::RenderState()
//	{
//		if (m_pCurrentState)
//		{
//			m_pCurrentState->Render();
//		}
//	}
//
//
//	void CStateManagement::SwitchState(CState* nextState)
//	{
//		m_pNextState = nextState;
//	}
//
//}