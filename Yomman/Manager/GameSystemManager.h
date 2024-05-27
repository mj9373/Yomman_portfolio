#pragma once

#include "../GameSystem/GameSystem_Base.h"

class GameSystemManager
{
public:
	GameSystemManager();
	//게임 플레이에 필요한 시스템을 구성 후 각각의 스타트 함수 호출
	void Start();
	//업데이트 함수
	void Update(int InSleepTime);
	// 업데이트 된 것을 랜더할 함수
	void UpdateRander();
	// 시스템 변경 시 호출
	void End();
	// 인풋이벤트 발생에 따른 처리 함수
	void OnInputEvent(InputKey InInputType);

	/* 변경 될 다음 시스템*/
	void ChangeSystem(GameSystemType InNewSystem);

protected:

	int GetArrayIndexbyType(GameSystemType InSystemType);

protected://상속은 가능 외부에서 못씀
	GameSystem_Base** GameSystemList;

	GameSystemType CurrentSystemType;
};
