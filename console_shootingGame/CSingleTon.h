#pragma once

template<typename T >
class CSinglton
{
public:
	static T* GetInstance()
	{
		static T* Instance = NULL;
		if (Instance == NULL)
		{
			Instance = new T();
		}
		return Instance;
	}
};