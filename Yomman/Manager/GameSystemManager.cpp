#include "GameSystemManager.h"
#include "../GameSystem/GameSystem_Logo.h"
#include "../GameSystem/GameSystem_InGame.h"


GameSystemManager::GameSystemManager()
{
	GameSystemList = nullptr;
	CurrentSystemType = GameSystemType::None;
}


void GameSystemManager::Start()
{//GameSystem_Base 주소값 3개의 배열을 동적할당으로 GameSystemList에 넣어줌
	GameSystemList = new GameSystem_Base*[2];
//GameSystem_Logo의 주소값을 GameSystemList 첫번째 배열에 넣어줌
	GameSystemList[0] = new GameSystem_Logo;
//GameSystem_InGame의 주소값을 GameSystemList 첫번째 배열에 넣어줌
	GameSystemList[1] = new GameSystem_InGame;
//GameSystem_Shop 의 주소값을 GameSystemList 첫번째 배열에 넣어줌


	//. GameSystemList 배열의 값을 순회 후 Start 호출
	for (int i = 0; i < 2; i++)
	{
		GameSystemList[i]->Start(this);
	}
	

}

void GameSystemManager::Update(int InSleepTime)
{//현재 게임 시스템 타입에 업데이트를 호출 
	if (CurrentSystemType != GameSystemType::None)
	{
		if (GameSystemList[GetArrayIndexbyType(CurrentSystemType)] != nullptr)
		{
			GameSystemList[GetArrayIndexbyType(CurrentSystemType)]->Update(InSleepTime);
		}
	}
	
}

void GameSystemManager::UpdateRander()
{
	if (CurrentSystemType != GameSystemType::None)
	{
		if (GameSystemList[GetArrayIndexbyType(CurrentSystemType)] != nullptr)
		{
			GameSystemList[GetArrayIndexbyType(CurrentSystemType)]->UpdateRander();
		}
	}
}

void GameSystemManager::End()
{
	for (int i = 0; i < 2; i++)
	{//직접 배열 값에 접근을 해서 지운거고
		delete GameSystemList[i];
	}//배열(리스트)를 지운거
	delete[] GameSystemList;
}

void GameSystemManager::OnInputEvent(InputKey InInputType)
{
	if (CurrentSystemType != GameSystemType::None)
	{
		if (GameSystemList[GetArrayIndexbyType(CurrentSystemType)] != nullptr)
		{
			GameSystemList[GetArrayIndexbyType(CurrentSystemType)]->InputEvent(InInputType);
		}
	}
	
}

void GameSystemManager::ChangeSystem(GameSystemType InNextSystemType)
{//현재 시스템 게임 시스템을 종료

	if (CurrentSystemType != GameSystemType::None)
	{
		if (GameSystemList[GetArrayIndexbyType(CurrentSystemType)] != nullptr)
		{
			GameSystemList[GetArrayIndexbyType(CurrentSystemType)]->End();
		}
	}

	// 바꿔야할 시스템의 비긴 플레이 함수를 호출
	GameSystemList[GetArrayIndexbyType(InNextSystemType)]->BeingPlay();
	//커런트 타입을 바뀌야할 시스템으로 지정
	CurrentSystemType = InNextSystemType;

}

int GameSystemManager::GetArrayIndexbyType(GameSystemType InSystemType)
{
	if (InSystemType > GameSystemType::None && InSystemType < GameSystemType::Max)
		return static_cast<int>(InSystemType) - 1;

	return -1;
}
