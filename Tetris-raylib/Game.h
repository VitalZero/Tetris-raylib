#pragma once
#include "Board.h"
#include "Mino.h"

class Game
{
public:
	Game(int width, int height);
	void Run();

private:
	void Input();
	void Update(float dt);
	void Draw();

private:
	Board board;
	Mino mino;
	float delay = 1.5f; //2 seconds
	float accumulator = 0.0f;
	float moveLR = 0.0f;
	Music music;
};