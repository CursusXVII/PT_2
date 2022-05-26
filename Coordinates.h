#ifndef _COORDINATES_H_     //директива, которая защищает от повторного включения заголовочных файлов, чтобы не было переопределения одних и тех же функций/классов.
#define _COORDINATES_H_
#include "Library.h"

class Coordinates
{
private:
	double x, y, z;

public:
	Coordinates();
	Coordinates(double x, double y, double z);

	void show();
	void showx();
	void showy();
	void showz();

	void SetX(double x);
	double GetX();
	void SetY(double y);
	double GetY();
	void SetZ(double z);
	double GetZ();

	void operator!();
	void operator-=(int x);
	void operator--();

	friend void operator+=(Coordinates& object, int value);
	friend void operator++(Coordinates& object);

};

void operator+=(Coordinates& object, int value);
void operator++(Coordinates& object);
#endif // !_COORDINATES_H_