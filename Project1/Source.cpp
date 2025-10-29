#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}

    int getX() { return x; }
    int getY() { return y; }
    void setX(int a) { x = a; }
    void setY(int b) { y = b; }
};


ostream& operator<<(ostream& out, Point p)
{
    out << "(" << p.getX() << ", " << p.getY() << ")";
    return out;
}

template<class T1, class T2>
class Numbers
{
    T1 a;
    T2 b;
public:
    Numbers();
    Numbers(T1 _a, T2 _b);
    void Init(T1 _a, T2 _b);
    void InitRandom();  
    void Output();

    T1 getA() { return a; }
    T2 getB() { return b; }
    void setA(T1 _a) { a = _a; }
    void setB(T2 _b) { b = _b; }
};

template<class T1, class T2>
Numbers<T1, T2>::Numbers()
{
    a = T1(); 
    b = T2();
}

template<class T1, class T2>
Numbers<T1, T2>::Numbers(T1 _a, T2 _b)
{
    a = _a;
    b = _b;
}

template<class T1, class T2>
void Numbers<T1, T2>::Init(T1 _a, T2 _b)
{
    a = _a;
    b = _b;
}


template<class T1, class T2>
void Numbers<T1, T2>::InitRandom()
{
    srand(time(0));   
    a = rand() % 100;     
    b = rand() % 100;
}

template<class T1, class T2>
void Numbers<T1, T2>::Output()
{
    cout << a << "\t" << b << endl;
}


template<class T1, class T2>
ostream& operator<<(ostream& out, Numbers<T1, T2>& obj)
{
    out << obj.getA() << " | " << obj.getB();
    return out;
}


template<>
void Numbers<Point, Point>::InitRandom()
{
    srand(time(0));
    a.setX(rand() % 100);
    a.setY(rand() % 100);
    b.setX(rand() % 100);
    b.setY(rand() % 100);
}

int main()
{
    Numbers<int, double> obj1(10, 2.5);
    obj1.Output();

    obj1.InitRandom();
    cout << "After InitRandom (int,double): " << obj1 << endl;

    Numbers<Point, Point> obj2(Point(1, 2), Point(3, 4));
    cout << "Obj2 before random: " << obj2 << endl;

    obj2.InitRandom(); 
    cout << "Obj2 after InitRandom: " << obj2 << endl;
}