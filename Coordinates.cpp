#include "Coordinates.h"

Coordinates::Coordinates()
{
	x = 0;
	y = 0;
	z = 0;
}

Coordinates::Coordinates(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Coordinates::show()
{
	std::cout << std::setprecision(4) << x << ' ' << y << ' ' << z << ' ' << std::endl;
}
void Coordinates::showx()
{
	std::cout << std::setprecision(4) << x << std::endl;
}
void Coordinates::showy()
{
	std::cout << std::setprecision(4) << y << std::endl;
}
void Coordinates::showz()
{
	std::cout << std::setprecision(4) << z << std::endl;
}

void Coordinates::SetX(double x)
{
	this->x = x;
}
double Coordinates::GetX()
{
	return x;
}
void Coordinates::SetY(double y)
{
	this->y = y;
}
double Coordinates::GetY()
{
	return y;
}
void Coordinates::SetZ(double z)
{
	this->z = z;
}
double Coordinates::GetZ()
{
	return z;
}

void Coordinates::operator!()	// !
{
	this->x *= -1;
	this->y *= -1;
	this->z *= -1;
}

void Coordinates::operator--()	// метод префиксного декрементирования
{
	if (this->x > this->y && this->x > this->z)
	{
		this->z -= this->x;
		this->y -= this->x;
		this->x -= this->x;
	}
	if (this->y > this->x && this->y > this->z)
	{
		this->z -= this->y;
		this->x -= this->y;
		this->y -= this->y;
	}
	if (this->z > this->y && this->z > this->x)
	{
		this->x -= this->z;
		this->y -= this->z;
		this->z -= this->z;
	}
}

void Coordinates::operator-=(int value)	// метод постфиксного декрементирования
{
	this->z -= value;
	this->y -= value;
	this->x -= value;
}

void operator++(Coordinates& object)	// дружественная функция префиксного инкрементирования
{
	if (object.x < object.y && object.x < object.z)
	{
		object.z += object.x;
		object.y += object.x;
		object.x += object.x;
	}
	if (object.y < object.x && object.y < object.z)
	{
		object.x += object.y;
		object.z += object.y;
		object.y += object.y;
	}
	if (object.z < object.y && object.z < object.x)
	{
		object.x += object.z;
		object.y += object.z;
		object.z += object.z;
	}
}

void operator+=(Coordinates& object, int value)	// дружественная функция постфиксного инкрементирования
{
	object.z += value;
	object.y += value;
	object.x += value;
}