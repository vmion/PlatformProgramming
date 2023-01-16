//#pragma once

//��������� �ߺ� ������ �������ִ� Include Guard
#ifndef _POINT__H_
#define _POINT__H_
using namespace std;
class Point
{
private: 
	int m_x;
	int m_y;
	int* m_pData;
public:
	static int m_count;
public:
	Point();
	Point(int x, int y);
	Point(const Point& pt);
	~Point();

	inline int GetX() { return m_x; }
	inline int GetY() { return m_y; }
	void SetX(int x);
	void SetY(int y);
	//���� ���� �Լ�
	void ShallowCopy(int* p)
	{
		m_pData = p;		
	}
	//���� ���� �Լ�
	void DeepCopy(int* p)
	{
		if (m_pData == nullptr)
		{
			m_pData = new int;
		}
		*m_pData = *p;		
	}
	void DisplayData();
	//��� ������ ���� �������� �ʴ� ����Լ���� �ǹ�
	void DisplayData2() const;	
	static void DisplayCount();
};

#endif
