////
////Created: 21/07/2017
////Creator: Zero.Se08
////Class: CStateManagement
////Function: Management State 
////
//
//
//#ifndef __CSTATEMANAGEMENT_H__
//#define __CSTATEMANAGEMENT_H__
//
//
//#include "CState.h"
//
//
//namespace Zero
//{
//
//
//	class CStateManagement
//	{
//	protected:
//		CStateManagement();
//
//	public:
//		virtual ~CStateManagement();
//
//
//	public:
//		void UpdateState(bool isPause);			//Update State
//		void RenderState();
//		void SwitchState(CState* nextState);	//Switch State 
//
//
//	protected:
//		CState* m_pCurrentState;
//		CState* m_pNextState;
//
//
//	//Singleton pattern
//	public:
//		static CStateManagement* GetInstance(void);
//
//
//	protected:
//		static CStateManagement* m_psInstance;
//	//
//
//	};
//
//
//}
//
//
//#endif