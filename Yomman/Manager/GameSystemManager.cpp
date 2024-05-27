#include "GameSystemManager.h"
#include "../GameSystem/GameSystem_Logo.h"
#include "../GameSystem/GameSystem_InGame.h"


GameSystemManager::GameSystemManager()
{
	GameSystemList = nullptr;
	CurrentSystemType = GameSystemType::None;
}


void GameSystemManager::Start()
{//GameSystem_Base �ּҰ� 3���� �迭�� �����Ҵ����� GameSystemList�� �־���
	GameSystemList = new GameSystem_Base*[2];
//GameSystem_Logo�� �ּҰ��� GameSystemList ù��° �迭�� �־���
	GameSystemList[0] = new GameSystem_Logo;
//GameSystem_InGame�� �ּҰ��� GameSystemList ù��° �迭�� �־���
	GameSystemList[1] = new GameSystem_InGame;
//GameSystem_Shop �� �ּҰ��� GameSystemList ù��° �迭�� �־���


	//. GameSystemList �迭�� ���� ��ȸ �� Start ȣ��
	for (int i = 0; i < 2; i++)
	{
		GameSystemList[i]->Start(this);
	}
	

}

void GameSystemManager::Update(int InSleepTime)
{//���� ���� �ý��� Ÿ�Կ� ������Ʈ�� ȣ�� 
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
	{//���� �迭 ���� ������ �ؼ� ����Ű�
		delete GameSystemList[i];
	}//�迭(����Ʈ)�� �����
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
{//���� �ý��� ���� �ý����� ����

	if (CurrentSystemType != GameSystemType::None)
	{
		if (GameSystemList[GetArrayIndexbyType(CurrentSystemType)] != nullptr)
		{
			GameSystemList[GetArrayIndexbyType(CurrentSystemType)]->End();
		}
	}

	// �ٲ���� �ý����� ��� �÷��� �Լ��� ȣ��
	GameSystemList[GetArrayIndexbyType(InNextSystemType)]->BeingPlay();
	//Ŀ��Ʈ Ÿ���� �ٲ���� �ý������� ����
	CurrentSystemType = InNextSystemType;

}

int GameSystemManager::GetArrayIndexbyType(GameSystemType InSystemType)
{
	if (InSystemType > GameSystemType::None && InSystemType < GameSystemType::Max)
		return static_cast<int>(InSystemType) - 1;

	return -1;
}
