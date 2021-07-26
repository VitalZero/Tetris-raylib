#pragma once
#include "Block.h"
#include "Board.h"
#include <vector>
#include <random>
#include <raylib.h>

class Mino
{
public:
	enum class Shape
	{
		S, W, O, L, J, Z, I
	};
	static constexpr Color colors[5] =
	{
		RED, BLUE, GREEN, LIGHTGRAY, SKYBLUE
	};

public:
	Mino(int x, int y, Shape shapeType, int size, Board& board);

public:
	void Update(float dt);
	void Draw();
	void Move(int x, int y);
	void Rotate(int rotation);
	bool CanMove(int x, int y) const;
	void Put();
	void Reset();

private:
	void SetPos(int x, int y);

private:
	int x;
	int y;
	int size;
	Board& board;
	Shape shapeType;
	std::vector<Block> figure;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> figureDst;
	std::uniform_int_distribution<int> colorDst;
	Color randomColor;
	int colorIndex;

	const Block Figures[7][4] =
	{
		{ {0, -1}, {0, 0},  {1, 0},  {1, 1} }, // S
		{ {-1, 0}, {0, 0},  {0, -1}, {1, 0} }, // T
		{ {0, 0},  {1, 0},  {0, 1},  {1, 1} }, // O
		{ {0, -1}, {0, 0},  {0, 1},  {1, 1} }, // L
		{ {0, -1}, {0, 0},  {0, 1},  {-1, 1} }, // J
		{ {0, -1}, {-1, 0}, {0, 0},  {-1, 1} },// Z
		{ {0, -1}, {0, 0},  {0, 1},  {0, 2} }  // I
	};
};