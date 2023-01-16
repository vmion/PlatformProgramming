// ClassMemberExample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Point.h"
#define SAFE_DELETE(x) if(x!=nullptr){delete x;x=nullptr;}
int main()
{
    Point* pt1 = new Point();
    pt1->DisplayData();
    SAFE_DELETE(pt1);

    Point* pt2 = new Point(10, 20);
    pt2->DisplayData();
    SAFE_DELETE(pt2);

    //복사생성자 사용
    Point p3(100, 200);
    Point p4 = p3;
    Point* p5 = new Point(p3);    
    SAFE_DELETE(p5);

    //static 변수와 함수의 사용
    Point p6, p7, p8;
    Point::m_count = 200;
    p8.DisplayCount();
    Point::DisplayCount();

    //const
    //변수 선언시 const 사용
    //pA의 멤버 변수를 수정할 수 없다.
    const Point* pA = new Point();
    SAFE_DELETE(pA);
    //pB를 다른 메모리 주소값으로 변경할 수 없다.
    Point* const pB = new Point();
    //B의 멤버를 수정할 수 없다.
    Point const B;        
}
