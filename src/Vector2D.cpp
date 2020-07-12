#include "Vector2D.h"

Vector2D::Vector2D(int x, int y)
	:x(x), y(y)
{}

void Vector2D::setX(const int x)
{
	this->x = x;
}

void Vector2D::setY(const int y)
{
	this->y = y;
}

const int Vector2D::getX() const
{
	return this->x;
}

const int Vector2D::getY() const
{
	return this->y;
}

void Vector2D::operator+(Vector2D& other)
{
	this->x += other.x;
	this->y += other.y;
}

void Vector2D::operator-(Vector2D& other)
{
	this->x -= other.x;
	this->y -= other.y;
}

void Vector2D::operator+(const int& num)
{
	x += num;
	y += num;
}

void Vector2D::operator-(const int& num)
{
	x -= num;
	y -= num;
}

void Vector2D::operator=(const int& num)
{
	this->x = num;
	this->y = num;
}
