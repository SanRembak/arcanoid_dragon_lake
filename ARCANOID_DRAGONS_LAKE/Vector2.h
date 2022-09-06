#pragma once;
#include<math.h>

static struct Vector2
{
	Vector2(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	Vector2()
	{
		x = 0;
		y = 0;
	}

	int x;
	int y;

	Vector2 operator+(Vector2 position) const { return Vector2(x + position.x, y + position.y); }
	Vector2 operator-(Vector2 position) const {return Vector2(x - position.x, y - position.y);}
	Vector2 operator*(float digit) const { return Vector2(x * digit, y * digit); }
	Vector2 operator/(float digit) const { return Vector2(x / digit, y / digit); }

	Vector2 operator-=(Vector2 position)
	{
		x -= position.x;
		y -= position.y;

		return Vector2(x, y);
	}

	Vector2 operator+=(Vector2 position)
	{
		x += position.x;
		y += position.y;

		return Vector2(x, y);
	}

	Vector2 operator*=(float digit)
	{
		x *= digit;
		y *= digit;

		return Vector2(x, y);
	}

	Vector2 operator/=(float digit)
	{
		x /= digit;
		y /= digit;

		return Vector2(x, y);
	}
};

static struct Vector2Float
{
	Vector2Float(float nx, float ny)
	{
		x = nx;
		y = ny;
	}

	Vector2Float()
	{
		x = 0;
		y = 0;
	}

	float x;
	float y;

	float length()
	{
		return sqrt(x * x + y * y);
	}

	Vector2Float normal()
	{
		float currentLength = length();
		return Vector2Float(x / currentLength, y / currentLength);
	}

	Vector2Float operator+(Vector2Float position) const { return Vector2Float(x + position.x, y + position.y); }
	Vector2Float operator-(Vector2Float position) const { return Vector2Float(x - position.x, y - position.y); }
	Vector2Float operator*(float digit) const { return Vector2Float(x * digit, y * digit); }
	Vector2Float operator/(float digit) const { return Vector2Float(x / digit, y / digit); }

	Vector2Float operator-=(Vector2Float position)
	{
		x -= position.x;
		y -= position.y;

		return Vector2Float(x, y);
	}

	Vector2Float operator+=(Vector2Float position)
	{
		x += position.x;
		y += position.y;

		return Vector2Float(x, y);
	}

	Vector2Float operator*=(float digit)
	{
		x *= digit;
		y *= digit;

		return Vector2Float(x, y);
	}

	Vector2Float operator/=(float digit)
	{
		x /= digit;
		y /= digit;

		return Vector2Float(x, y);
	}
};