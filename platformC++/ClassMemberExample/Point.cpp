#include "Point.h"
#include <iostream>
using namespace std;
// :: (Scope Resolution Opterator) ���� ���� ������

//static ������ �ʱ�ȭ
int Point::m_count = 100;

Point::Point() : m_x(0), m_y(0)
{

}
Point::Point(int x, int y) : m_x(x), m_y(y)
{
	
}
Point::Point(const Point& pt)
{
	cout << "���������ȣ��" << endl;
	m_x = pt.m_x;
	m_y = pt.m_y;
}
Point::~Point()
{
	delete m_pData;
	m_pData = nullptr;
}
void Point::DisplayData()
{
	cout << m_x << endl;
	cout << m_y << endl;
}
void Point::DisplayData2() const
{
	cout << m_x << endl;
	cout << m_y << endl;
}
void Point::DisplayCount()
{
	cout << "static ��� ������ �� = " << Point::m_count << endl;
}
void Point::SetX(int x) { m_x = x; }
void Point::SetY(int y) { m_y = y; }