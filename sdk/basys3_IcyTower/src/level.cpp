#include "../include/level.hpp"

	Level::Level() :
		//Level			EASY				MEDIUM						HARD
		CounterMax{599,299,149},
		MaxWidth{{500,450,400,350,325}, {500,400,300,250,200}, {400,300,200,150,125}},
		MinWidth{{450,400,350,325,300}, {400,300,250,200,150}, {300,200,150,125,100}
		} {};

	unsigned int Level::GetCounterMax(unsigned int LevelIndex){
		if(LevelIndex < N_LEVELS) return this->CounterMax[LevelIndex];
		else return 0;
	}

	unsigned int Level::GetMaxWidth(unsigned int LevelIndex, unsigned int StageIndex){
		if((StageIndex < N_STAGES) && (LevelIndex < N_LEVELS)) return this->MaxWidth[LevelIndex][StageIndex];
		else return 0;
	}

	unsigned int Level::GetMinWidth(unsigned int LevelIndex, unsigned int StageIndex){
		if((StageIndex < N_STAGES) && (LevelIndex < N_LEVELS)) return this->MinWidth[LevelIndex][StageIndex];
		else return 0;
	}
