#pragma once
class Vector2D
{
private:
	int x;
	int y;
public:
	Vector2D(int x, int y);
	void setX(const int x);
	void setY(const int y);
	const int getX() const;
	const int getY() const;
	void operator+(Vector2D& other);
	void operator-(Vector2D& other);
	void operator+(const int& num);
	void operator-(const int& num);
	void operator=(const int& num);
};

