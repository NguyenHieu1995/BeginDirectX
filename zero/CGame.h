////
////Created: 21/07/2017
////Creator: Zero.Se08
////Class: CGame
////Function: Management Main Loop Game
////
//
//
//#ifndef __CGAME_H__
//#define __CGAME_H__
//
//namespace Zero
//{
//
//	class CGame
//	{
//	protected:
//		CGame(void); //Constructor
//
//	public:
//		virtual ~CGame(void); //Destructor
//
//
//	public:
//		virtual void Run(void); //Management main loop of game
//		virtual void Exit(void); //Request Exit Game
//		virtual void Pause(void); //Pause Game
//		virtual void Resume(void); //Resume Game call before pause Game
//		bool IsAlive(void); //Return Alived
//		bool IsPause(void);	//Return Paused
//
//
//	protected:
//		virtual bool Init(void) = 0; //Init variable for game
//		virtual void Destroy(void) = 0; //call before exit game. Free memory
//
//
//	protected:
//		bool m_isAlived; //Check game Alived
//		bool m_isPaused; //Check game Paused
//
//
//		//Singleton pattern
//	protected:
//		static CGame* m_psInstance;
//
//		
//	public:
//		static CGame* GetInstance();
//		static void FreeInstance();
//
//	};
//
//
//}
//
//#endif