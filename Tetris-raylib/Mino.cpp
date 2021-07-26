#include "Mino.h"
#include <Raylib.h>

Mino::Mino(int x, int y, Shape shapeType, int size, Board& board)
	:
	x(x), y(y), shapeType(shapeType), size(size), board(board), rng(rd()), figureDst(0, 6), colorDst(0, 4)
{
	int randomFigure = figureDst(rng);
	colorIndex = colorDst(rng);
	randomColor = colors[colorIndex];

	figure.emplace_back(Figures[randomFigure][0]);
	figure.emplace_back(Figures[randomFigure][1]);
	figure.emplace_back(Figures[randomFigure][2]);
	figure.emplace_back(Figures[randomFigure][3]);

	SetPos(4, 5);
}

void Mino::Update(float dt)
{
	Move(0, 1);
}

void Mino::Draw()
{
	for (const auto& f : figure)
	{
		DrawRectangle((f.x + x) * f.size + 1, (f.y + y) * f.size + 1, f.size - 1, f.size - 1, randomColor);
		
		if(f.x == 0 && f.y == 0)
			DrawRectangleLines((f.x + x) * f.size, (f.y + y) * f.size, f.size, f.size, RED);
	}
}

void Mino::Move(int x, int y)
{
	this->x += x;
	this->y += y;
}

void Mino::Rotate(int rotation)
{
	rotation = (rotation) % 4;

	if (rotation < 0)
		rotation += 4;

	for (int r = 0; r < rotation; ++r)
	{
		for (auto& f : figure)
		{
			int tmpX = f.x;
			f.x = -(f.y);
			f.y = (tmpX);
		}
	}
}

void Mino::SetPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Mino::CanMove(int x, int y) const
{
	for (const auto& f : figure)
	{
		if (board.TileAt( (f.x + this->x) + x, (f.y + this->y) + y) >= 0)
			return false;
	}

	return true;
}

void Mino::Put()
{
	for (const auto& f : figure)
	{
		board.SetTile(f.x + x, f.y + y, colorIndex);
	}

	board.Check();
}

void Mino::Reset()
{
	figure.clear();

	int randomFigure = figureDst(rng);
	colorIndex = colorDst(rng);
	randomColor = colors[colorIndex];

	figure.emplace_back(Figures[randomFigure][0]);
	figure.emplace_back(Figures[randomFigure][1]);
	figure.emplace_back(Figures[randomFigure][2]);
	figure.emplace_back(Figures[randomFigure][3]);

	SetPos(4, 0);
}
