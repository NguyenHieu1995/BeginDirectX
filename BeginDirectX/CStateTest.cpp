//#include "CStateTest.h"
//#include <stdio.h>
//
//CStateTest::CStateTest() : CState()
//{
//	m_iCount = 0;
//}
//
//CStateTest::~CStateTest()
//{
//
//}
//
//bool CStateTest::Init()
//{
//	printf("State Logo: Init\n");
//	m_iCount = 0;
//
//	return true;
//}
//
//void CStateTest::Update()
//{
//	m_iCount++;
//	if (m_iCount >= 50)
//	{
//		//CStateManagement::GetInstance()->SwitchState(new CStatePoster());
//		CGame::GetInstance()->Exit();
//	}
//}
//
//void CStateTest::Render()
//{
//	printf("State Logo: %d\n", m_iCount);
//}
//
//void CStateTest::Exit()
//{
//	printf("State Logo: Exit\n");
//}