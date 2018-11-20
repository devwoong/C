#pragma once
#include "CSingleTon.h"
class CDoubleBuffer : public CSinglton<CDoubleBuffer>
{
public:
	CDoubleBuffer();
	~CDoubleBuffer();

	void createBuffer(); // ���� ����
	void writeBuffer(int x, int y, char *string);           // ���� ����
	void flippingBuffer();                                  // ���� ��ȯ
	void clearBuffer();                                     // ���� �����
	void destroyBuffer();

private:
	int m_nBufferIndex;                                     // ���� Index

	HANDLE m_hBuffer[2];
	// HANDLE
	// �ڵ��� ��ü���� � ����� �����ϱ� ���� �ٿ��� ������ ��ȣ. 
	// � ü���� �ο��ϴ� �ߺ����� �ʴ� ������.
	// �������� object�� structure ���� �����͸� ���� �ٷ����� ������ ���� ó��
	// ���輺 ������ ��ü�� ��Ī�ϴµ� �����͸� ���� �ʰ� ��ȣ�� �� ���̴�.

	bool MyCloseHandle(HANDLE& hFile);         // �����ϰ� CloseHandle ó�� 
};

