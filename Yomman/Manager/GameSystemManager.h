#pragma once

#include "../GameSystem/GameSystem_Base.h"

class GameSystemManager
{
public:
	GameSystemManager();
	//���� �÷��̿� �ʿ��� �ý����� ���� �� ������ ��ŸƮ �Լ� ȣ��
	void Start();
	//������Ʈ �Լ�
	void Update(int InSleepTime);
	// ������Ʈ �� ���� ������ �Լ�
	void UpdateRander();
	// �ý��� ���� �� ȣ��
	void End();
	// ��ǲ�̺�Ʈ �߻��� ���� ó�� �Լ�
	void OnInputEvent(InputKey InInputType);

	/* ���� �� ���� �ý���*/
	void ChangeSystem(GameSystemType InNewSystem);

protected:

	int GetArrayIndexbyType(GameSystemType InSystemType);

protected://����� ���� �ܺο��� ����
	GameSystem_Base** GameSystemList;

	GameSystemType CurrentSystemType;
};
