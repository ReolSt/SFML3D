// SFMLPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <memory>
#include "Program.h"
#include "Practice3D.h"
int main()
{
	std::shared_ptr<Program> p;
	p.reset((Program*)new Practice3D);
}

