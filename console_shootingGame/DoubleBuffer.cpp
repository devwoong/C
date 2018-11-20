#include "stdafx.h"
#include "DoubleBuffer.h"

CDoubleBuffer::CDoubleBuffer()
{
	m_nBufferIndex = 0;                 // ���� �ε��� �ʱ�ȭ
}
CDoubleBuffer::~CDoubleBuffer()
{
}

void CDoubleBuffer::createBuffer()
{
	CONSOLE_CURSOR_INFO cci;            // �ܼ�â �����̴� Ŀ��
	COORD size = { SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT };     // ���� ũ�⸦ �����ϴ� ����ü
	SMALL_RECT rect;                    // â ũ�⸦ �����ϴ� ����ü
	rect.Left = 0;
	rect.Top = 0;
	rect.Right = SCREEN_SIZE_WIDTH - 1;
	rect.Bottom = SCREEN_SIZE_HEIGHT - 1;

	// 1�� ���� ����
	m_hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE
		, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_hBuffer[0], size);  // ���� ũ�� ����
	SetConsoleWindowInfo(m_hBuffer[0], TRUE, &rect); // â ũ�� ����

	// 2�� ���� ����
	m_hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE
		, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(m_hBuffer[1], size);  // ���� ũ�� ����
	SetConsoleWindowInfo(m_hBuffer[1], TRUE, &rect); // â ũ�� ����

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(m_hBuffer[0], &cci); // 1�� ���ۿ� �����̴� Ŀ�� ����
	SetConsoleCursorInfo(m_hBuffer[1], &cci); // 2�� ���ۿ� �����̴� Ŀ�� ����
}

void CDoubleBuffer::writeBuffer(int x, int y, char *string)
{
	DWORD dw;                           // ��ǥ ���� ����ü
	COORD CursorPosition = { x, y };    // ��ǥ ����

	// ��ǥ �̵�
	SetConsoleCursorPosition(m_hBuffer[m_nBufferIndex], CursorPosition);
	// ���ۿ� ����
	WriteFile(m_hBuffer[m_nBufferIndex], string, strlen(string), &dw, NULL);
}

void CDoubleBuffer::flippingBuffer()
{
//	Sleep(30);                        // �ð� �Լ��� ��ü�� ���� ��ȯ �ӵ�

	// ���� Ȱ��ȭ. ������ ������ �ѹ��� ���
	SetConsoleActiveScreenBuffer(m_hBuffer[m_nBufferIndex]);

	m_nBufferIndex = !m_nBufferIndex; // ���� ���� ����
}

void CDoubleBuffer::clearBuffer()
{
	COORD Coor = { 0, 0 };  // �Ʒ� �Լ��� ���� ����ü
	DWORD dw;               // �Ʒ� �Լ��� ���� ����ü

	// �ش� ������ Coor ��ǥ���� ' '���� ä���� ������ ��ó�� �����
	FillConsoleOutputCharacter(m_hBuffer[m_nBufferIndex], ' '
		, SCREEN_SIZE_WIDTH * SCREEN_SIZE_HEIGHT, Coor, &dw);
}

void CDoubleBuffer::destroyBuffer()
{
	MyCloseHandle(m_hBuffer[0]);    // 1�� ���� ����
	MyCloseHandle(m_hBuffer[1]);    // 2�� ���� ����

	// (HANDLE�� ������ �������� �״��. �ش� ������ ���� HANDLE Ŀ�θ� ����)
	// CloseHandle(m_hBuffer[0]); 
	// CloseHandle(m_hBuffer[1]);
	// �����ϰ� CloseHandle�� ó���ϱ� ���� MyCloseHandle ����    
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
// �ش� �÷������� HANDLE�� ������ �ִ� �ִ�������
// #define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1) 
// ex) 0xffffffff
