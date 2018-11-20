#include "stdafx.h"
#include "DoubleBuffer.h"

CDoubleBuffer::CDoubleBuffer()
{
	m_nBufferIndex = 0;                 // 버퍼 인덱스 초기화
}
CDoubleBuffer::~CDoubleBuffer()
{
}

void CDoubleBuffer::createBuffer()
{
	CONSOLE_CURSOR_INFO cci;            // 콘솔창 깜박이는 커서
	COORD size = { SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT };     // 버퍼 크기를 저장하는 구조체
	SMALL_RECT rect;                    // 창 크기를 저장하는 구조체
	rect.Left = 0;
	rect.Top = 0;
	rect.Right = SCREEN_SIZE_WIDTH - 1;
	rect.Bottom = SCREEN_SIZE_HEIGHT - 1;

	// 1번 버퍼 생성
	m_hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE
		, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_hBuffer[0], size);  // 버퍼 크기 설정
	SetConsoleWindowInfo(m_hBuffer[0], TRUE, &rect); // 창 크기 설정

	// 2번 버퍼 생성
	m_hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE
		, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_hBuffer[1], size);  // 버퍼 크기 설정
	SetConsoleWindowInfo(m_hBuffer[1], TRUE, &rect); // 창 크기 설정

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(m_hBuffer[0], &cci); // 1번 버퍼에 깜박이는 커서 지움
	SetConsoleCursorInfo(m_hBuffer[1], &cci); // 2번 버퍼에 깜박이는 커서 지움
}

void CDoubleBuffer::writeBuffer(int x, int y, char *string)
{
	DWORD dw;                           // 좌표 저장 구조체
	COORD CursorPosition = { x, y };    // 좌표 설정

	// 좌표 이동
	SetConsoleCursorPosition(m_hBuffer[m_nBufferIndex], CursorPosition);
	// 버퍼에 쓰기
	WriteFile(m_hBuffer[m_nBufferIndex], string, strlen(string), &dw, NULL);
}

void CDoubleBuffer::flippingBuffer()
{
//	Sleep(30);                        // 시간 함수를 대체할 버퍼 전환 속도

	// 버퍼 활성화. 버퍼의 내용을 한번에 출력
	SetConsoleActiveScreenBuffer(m_hBuffer[m_nBufferIndex]);

	m_nBufferIndex = !m_nBufferIndex; // 다음 버퍼 선택
}

void CDoubleBuffer::clearBuffer()
{
	COORD Coor = { 0, 0 };  // 아래 함수를 위한 구조체
	DWORD dw;               // 아래 함수를 위한 구조체

	// 해당 버퍼의 Coor 좌표부터 ' '값을 채워서 지워진 것처럼 만들기
	FillConsoleOutputCharacter(m_hBuffer[m_nBufferIndex], ' '
		, SCREEN_SIZE_WIDTH * SCREEN_SIZE_HEIGHT, Coor, &dw);
}

void CDoubleBuffer::destroyBuffer()
{
	MyCloseHandle(m_hBuffer[0]);    // 1번 버퍼 해제
	MyCloseHandle(m_hBuffer[1]);    // 2번 버퍼 해제

	// (HANDLE이 지정한 정수값은 그대로. 해당 정수에 대한 HANDLE 커널만 삭제)
	// CloseHandle(m_hBuffer[0]); 
	// CloseHandle(m_hBuffer[1]);
	// 안전하게 CloseHandle을 처리하기 위해 MyCloseHandle 만듬    
}

bool CDoubleBuffer::MyCloseHandle(HANDLE& hFile)
{
	if (INVALID_HANDLE_VALUE != hFile)
	{
		__try
		{
			return (0 != ::CloseHandle(hFile));
		}
		__finally
		{
			hFile = INVALID_HANDLE_VALUE;
		}
	}
	return false;
}
// INVALID_HANDLE_VALUE 
// 해당 플랫폼에서 HANDLE이 가질수 있는 최대정수값
// #define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1) 
// ex) 0xffffffff
