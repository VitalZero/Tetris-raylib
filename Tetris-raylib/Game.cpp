#include "Game.h"
#include <iostream>
#include <raylib.h>

Game::Game(int width, int height)
	:
	board(0, 0, Board::TileSize), mino(0, 0, Mino::Shape::S, Board::TileSize, board)
{
	InitWindow(width, height, "Tetris raylib!");
}

void Game::Run()
{
	while (!WindowShouldClose())
	{
		Input();
		Update(GetFrameTime());

		BeginDrawing();
		ClearBackground(BLACK);
		Draw();
		EndDrawing();
	}

	CloseWindow();
}

void Game::Input()
{
	if (IsKeyDown(KEY_DOWN))
	{
		accumulator += 0.03f;
	}

	if (IsKeyPressed(KEY_UP))
	{
		mino.Rotate(1);
	}


	if (IsKeyPressed(KEY_LEFT))
	{
		if(mino.CanMove(-1, 0))
			mino.Move(-1, 0);
	}
	else if (IsKeyPressed(KEY_RIGHT))
	{
		if (mino.CanMove(1, 0))
			mino.Move(1, 0);
	}
}

void Game::Update(float dt)
{
	accumulator += dt;
	

	if (accumulator >= delay)
	{
		if (mino.CanMove(0, 1))
		{
			mino.Move(0, 1);
		}
		else
		{
			mino.Put();
			mino.Reset();
		}

		accumulator = 0.0f;
	}
}

void Game::Draw()
{
	board.Draw();
	
	mino.Draw();

	DrawText("Tetris raylib!", 390, 30, 20, RAYWHITE);
	DrawText("Score: 000000", 390, 60, 20, RAYWHITE);
	DrawText("Next", 390, 90, 30, RAYWHITE);
}
