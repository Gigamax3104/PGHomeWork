#pragma once

enum BringOut {
	Rock = 0,
	Scissors = 1,
	Paper = 2,
	None = 3,
};

enum Judgement {
	Win = 4,
	Draw = 5,
	Lose = 6,
};

extern void LimitInput();