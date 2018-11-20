#pragma once
#include "CSingleTon.h"
class CDoubleBuffer : public CSinglton<CDoubleBuffer>
{
public:
	CDoubleBuffer();
	~CDoubleBuffer();

	void createBuffer(); // 버퍼 생성
	void writeBuffer(int x, int y, char *string);           // 버퍼 쓰기
	void flippingBuffer();                                  // 버퍼 전환
	void clearBuffer();                                     // 버퍼 지우기
	void destroyBuffer();

private:
	int m_nBufferIndex;                                     // 버퍼 Index

	HANDLE m_hBuffer[2];
	// HANDLE
	// 핸들은 구체적인 어떤 대상을 구분하기 위해 붙여진 유일한 번호. 
	// 운영 체제가 부여하는 중복되지 않는 정수값.
	// 기존에는 object나 structure 등의 포인터를 직접 다뤘으나 포인터 값의 처리
	// 위험성 때문에 객체를 지칭하는데 포인터를 쓰지 않고 번호를 쓴 것이다.

	bool MyCloseHandle(HANDLE& hFile);         // 안전하게 CloseHandle 처리 
};

