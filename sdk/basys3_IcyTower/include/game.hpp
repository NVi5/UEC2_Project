#pragma once

#include "floor.hpp"
#include "player.hpp"
#include "point2d.hpp"
#include "textures.h"
#include "menu.hpp"
#include "keyboard.hpp"
#include "level.hpp"

#define N_FLOORS        (6L)
#define FLOOR_SPACING   (182L)

#define DELTA_T			(0.1)

#define PLAYER_WIDTH    (64L)
#define PLAYER_HEIGHT   (64L)
#define FLOOR_HEIGHT	(32L)

#define ACCELERATION    (-100.0f)
#define MIN_X           (128L)
#define MAX_X           (1279L - MIN_X)
#define MIN_Y           (-64L)
#define MAX_Y           (1023L)

#define SCREEN_WIDTH	(1024L)

#define PLAYER_MIN_Y	(-2*PLAYER_HEIGHT+1)
#define PLAYER_MAX_Y	(MAX_Y - (PLAYER_HEIGHT + FLOOR_HEIGHT) - PLAYER_HEIGHT / 2)

#define INITIAL_HEIGHT	(32L)
#define SCROLL_HEIGHT	(800L)

#define NEXT_STAGE		(50L)
#define MAX_STAGES		(5L)

#define FLOOR_FRICTION  (0.95f)
#define AIR_FRICTION    (0.85f)

#define N_GAME_LEVELS		(3)

class Game{

    private:

		bool KeyUp, KeyDown, KeyEsc, KeyEnter, LastKeyUp, LastKeyDown, LastKeyEsc, LastKeyEnter;
        Floor floors[N_FLOORS];
        unsigned int relativeFloorNumber[N_FLOORS];

        Player Player1;
        Menu GameMenu;
        unsigned int MenuPosition;

        bool gameOver;
        float gameTime;

        enum Menu::State CurrentState;
        unsigned int CurrentLevel;

        unsigned int playerFloor;
        unsigned int floorCounter;

        float floorsPosition;
        float backgroundPosition;

        bool ScrollGame;

        bool PlayerLocked;
        int PlayerLockFloor;

        int CurrentStage;

        Keyboard keyboard;
        Level GameLevel;

        void StatePaused(void);
        void StateMenu(void);
        void StateGame(void);

        int Counter;
        unsigned int CounterMax;
        int CounterOverflows;

        void chceckCollisionsAndLock(int moveRate);
        void moveFloors(int moveRate);
        void CountDown();

    public:

        Game(char * buf, uint32_t *ptrKeys);
        void Reset();
        void Run();

		unsigned int GetXPos(void);
		unsigned int GetYPos(void);
		unsigned int GetColor(void);
		unsigned int GetScale(void);

		Floor GetFloor(int FloorIndex);
        texture_t GetFloorTexture(int FloorIndex);
        Player GetPlayer();

        float GetFloorsPosition();
		int GetFloorCount();
		int GetPlayerFloor();
		int GetCounter();
		unsigned int GetCounterMax();
};
