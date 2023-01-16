//#pragma once

//헤더파일의 중복 선언을 방지해주는 Include Guard
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
	//얕은 복사 함수
	void ShallowCopy(int* p)
	{
		m_pData = p;		
	}
	//깊은 복사 함수
	void DeepCopy(int* p)
	{
		if (m_pData == nullptr)
		{
			m_pData = new int;
		}
		*m_pData = *p;		
	}
	void DisplayData();
	//멤버 변수의 값을 변경하지 않는 멤버함수라는 의미
	void DisplayData2() const;	
	static void DisplayCount();
};

#endif
