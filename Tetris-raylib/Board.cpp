#include "Board.h"
#include <raylib.h>
#include "Mino.h"

Board::Board(int x, int y, int tileSize)
{
}

void Board::Draw()
{
	for (int y = 0; y < tilesHeight; ++y)
	{
		for (int x = 0; x < tilesWidth; ++x)
		{
			int tileData = TileAt(x, y);

			Color color = RAYWHITE;

			if (tileData == -1)
				color = BLACK;
			if (tileData == 9)
				color = RAYWHITE;
			else
				color = Mino::colors[TileAt(x, y)];

			DrawRectangle(x * TileSize + 1, y * TileSize + 1, TileSize - 1, TileSize - 1, color);
		}
	}
}

int Board::TileAt(int x, int y) const
{
	return map[y * tilesWidth + x];
}

void Board::SetTile(int x, int y, int value)
{
	map[y * tilesWidth + x] = value;
}

void Board::Check()
{
	CheckLines();
}

void Board::CheckLines()
{
	int allFilled = 0;

	for (int y = tilesHeight - 2; y >= 0; --y)
	{
		for (int x = 1; x < tilesWidth - 1; ++x)
		{
			if (TileAt(x, y) >= 0)
			{
				allFilled = 1;
			}
			else
			{
				allFilled = 0;
				break;
			}
		}

		if (allFilled > 0)
		{
			lineFilled = y;
			++y;

			Rearrange();
		}
	}
}

void Board::DeleteLines()
{
	for (int i = 1; i < tilesWidth - 1; ++i)
	{
		SetTile(i, lineFilled, -1);
	}

	Rearrange();
}

void Board::Rearrange()
{
	for(int y = lineFilled; y > 0; --y)
	{
		for (int x = 1; x < tilesWidth - 1; ++x)
		{
			SetTile(x, y, TileAt(x, y - 1));
		}
	}
}
