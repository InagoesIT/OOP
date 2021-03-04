#include "Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;

	canva = new char * [height];
	for (int i = 0; i < width; i++)
		canva[i] = new char[width];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			canva[i][j] = ' ';
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if (x && y && x + ray * 2 <= width && y + ray * 2 <= height)
	{
		int NR_POINTS = ray + 5;
		int i = 0;
		float X = 0;
		float Y = 0;
		float** points = new float* [2];
		for (int i = 0; i < 4 * NR_POINTS; i++)
			points[i] = new float[width];

		for (; i < NR_POINTS; i++)
		{
			X += ray / NR_POINTS;
			Y = sqrt(ray * ray - X * X);
			points[0][i] = X + x - ray;
			points[1][i] = y - Y + ray;
		}
		Y = 0;
		for (; i < NR_POINTS * 2; i++)
		{
			Y += ray / NR_POINTS;
			X = sqrt(ray * ray - Y * Y);
			points[0][i] = x + x + X - ray;
			points[1][i] = y - ray + Y;
		}
		X = 0;
		for (; i < NR_POINTS * 3; i++)
		{
			X += ray / NR_POINTS;
			Y = sqrt(ray * ray - X * X);
			points[0][i] = x + ray - X;
			points[1][i] = y - ray + Y;
		}
		Y = 0;
		for (; i < NR_POINTS * 4; i++)
		{
			Y += ray / NR_POINTS;
			X = sqrt(ray * ray - Y * Y);
			points[0][i] = x - X + ray;
			points[1][i] = y + ray - Y;
		}

		for (i = 0; i < NR_POINTS * 4 - 1; i++)
			DrawLine(points[0][i], points[1][i], points[0][i + 1], points[1][i + 1], ch);
		DrawLine(points[0][NR_POINTS * 4 - 1], points[1][NR_POINTS * 4 - 1], points[0][0], points[1][0], ch);
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	if (x && y && x + ray * 2 <= width && y + ray * 2 <= height)
	{
		int originX = x + ray;
		int originY = y + ray;

		for (int y = -ray; y <= ray; y++)
			for (int x = -ray; x <= ray; x++)
				if (x * x + y * y <= ray * ray)
					SetPoint(originX + x, originY + y, ch);
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left && top && right <= width && bottom <= height)
	{
		for (int x = left; x <= right; x++) // ---- ->
			canva[top][x] = ch;
		for (int y = top; y <= bottom; y++) // |
			canva[y][right] = ch;
		for (int x = right; x >= left; x--) // ---
			canva[bottom][x] = ch;
		for (int y = bottom; y >= top; y--) // |
			canva[y][right] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int y = top - 1; y < bottom; y++)
		for (int x = left; x < right; x++)
			canva[y][x] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x && y && x <= width && y <= height)
		this->canva[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, p, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	p = 2 * dy - dx;
	while (x < x2)
	{
		if (p >= 0)
		{
			SetPoint(x, y, ch);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			SetPoint(x, y, ch);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

void Canvas::Print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << canva[i][j];
		}
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; i < width; i++)
		{
			canva[i][j] = ' ';
		}
	}
}