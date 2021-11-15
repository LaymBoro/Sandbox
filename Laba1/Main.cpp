#include<iostream>
using namespace std;

class Vector // Класс "Вектор"
{
private:
	int x1, y1; // Координаты точки1
	int x2, y2; // Координаты точки2
	int TranslocationX, TranslocationY;
public:
	Vector() // Конструктор1 (по умолчанию)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 1;
		int y2 = 1;
		int TranslocationX = x2 - x1;
		int TranslocationY = y2 - y1;
	}
	Vector(int a, int b, int c, int d) // Конструктор2 
	{
		int x1 = a;
		int y1 = b;
		int x2 = c;
		int y2 = d;
		int TranslocationX = x2 - x1;
		int TranslocationY = y2 - y1;
	}
	Vector(const Vector& P) // Конструктор3 
	{
		x1 = P.x1;
		y1 = P.y1;
		x2 = P.x2;
		y2 = P.y2;
		int TranslocationX = x2 - x1;
		int TranslocationY = y2 - y1;
	}
	double Length(); // Рассчитать длину отрезка
	void Sum(Vector &A, Vector &B); // Сумма векторов
	void Difference(Vector &A, Vector &B); // Разность векторов
	int ScalarProduct(Vector &A, Vector &B); // Скалярное произведение
	void Print(); // Вывод элемента
};

void Vector::Sum(Vector &A, Vector &B)
{
	x1 = A.x1 + B.x1;
	y1 = A.y1 + B.y1;
	x2 = A.x2 + B.x2;
	y2 = A.y2 + B.y2;
	TranslocationX = x2 - x1;
	TranslocationY = y2 - y1;
	x2 = A.x1 + TranslocationX;
	y2 = A.y1 + TranslocationY;
	Vector D(A.x1, A.y1, x2, y2);
	cout << "x1 = " << D.x1 << ", y1 = " << D.y1 << "\n" << "x2 = " << D.x2 << ", y2 = " << D.y2;
}

void Vector::Difference(Vector &A, Vector &B)
{
	int TranslocationX1 = A.x2 - A.x1;
	int TranslocationY1 = A.y2 - A.y1;
	int TranslocationX2 = B.x2 - B.x1;
	int TranslocationY2 = B.y2 - B.y1;
	int TranslocationX3 = TranslocationX1 + TranslocationX2;
	int TranslocationY3 = TranslocationY1 + TranslocationY2;
	int x2 = A.x1 + TranslocationX3;
	int y2 = A.y1 + TranslocationY3;
	Vector D(A.x1, A.y1, x2, y2);
	cout << "x1 = " << D.x1 << ", y1 = " << D.y1 << "\n" << "x2 = " << D.x2 << ", y2 = " << D.y2;
}

double Vector::Length()
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int Vector::ScalarProduct(Vector &A, Vector &B)
{
	return(A.TranslocationX * B.TranslocationX + A.TranslocationY * B.TranslocationY);
}

void Vector::Print()
{
	cout << "x1 = " << x1 << ", y1 = " << y1 << "\n" << "x2 = " << x2 << ", y2 = " << y2;
}

int Main()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Vector A(x1, y1, x2, y2);
	Vector B(1, 6, 7, 5);
	Vector C(A);
	Vector G();
	//G.Print(); // Тест конструктора 1
	A.Print(); // Тест конструктора 2
	B.Print(); // Тест конструктора 2
	C.Print(); // Тест конструктора 3
	C.Difference(A, B);
	C.Sum(A, B);
	cout << A.Length();
	cout << B.ScalarProduct(A, B);

	return 0;
}