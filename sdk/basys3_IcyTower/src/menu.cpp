/*
 * menu.c
 *
 *  Created on: 22.08.2019
 *      Author: nvade
 */
#include "../include/menu.hpp"
#include "xparameters.h"
#include <string.h>
#include "../include/tinyprintf.h"

static const char text_start[]={"Start"};
static const char text_restart[]={"Restart"};
static const char text_resume[]={"Resume"};
static const char text_exit[]={"Exit"};
static const char text_level_easy[]={"Level: Easy"};
static const char text_level_medium[]={"Level: Medium"};
static const char text_level_hard[]={"Level: Hard"};

static const char * menu_level[]={
		text_level_easy,
		text_level_medium,
		text_level_hard
};


Menu::Menu(char * buf){
	this->Position = 0;
	this->Level = 0;
	this->State = State::STARTED;
	this->Counter = 0;

	this->XPos = 0;
	this->YPos = 0;
	this->Color = 0;
	this->Scale = 0;
	this->Buffer = buf;

	memset(this->Buffer, 0, BUFFERSIZEX*BUFFERSIZEY);
}

void Menu::SetState(enum Menu::State st){
	this->State = st;
}

void Menu::SetPosition(unsigned int pos){
	this->Position = pos;
}

void Menu::SetLevel(unsigned int lv){
	this->Level = lv;
}

void Menu::SetCounter(unsigned int count){
	this->Counter = count;
}

unsigned int Menu::GetXPos(void){
	return this->XPos;
}

unsigned int Menu::GetYPos(void){
	return this->YPos;
}

unsigned int Menu::GetColor(void){
	return this->Color;
}

unsigned int Menu::GetScale(void){
	return this->Scale;
}

void Menu::Draw(void){

	memset(this->Buffer, 0, BUFFERSIZEX*BUFFERSIZEY);

	switch(this->State){
		case State::STARTED:
			this->XPos = MENUX;
			this->YPos = MENUY;
			this->Color = 0x000;
			this->Scale = 2;
			sprintf(this->Buffer + BUFFERSIZEX * this->Position, ">");
			sprintf(this->Buffer + POINTERSIZE, "%s", text_start);
			sprintf(this->Buffer + BUFFERSIZEX + POINTERSIZE, "%s", menu_level[this->Level]);
			break;
		case State::PAUSED:
			this->XPos = MENUX;
			this->YPos = MENUY;
			this->Color = 0x000;
			this->Scale = 2;
			sprintf(this->Buffer + POINTERSIZE, "Result: %d", this->Counter);
			sprintf(this->Buffer + BUFFERSIZEX * (this->Position+1), ">");
			sprintf(this->Buffer + BUFFERSIZEX + POINTERSIZE, "%s", text_resume);
			sprintf(this->Buffer + 2*BUFFERSIZEX + POINTERSIZE, "%s", text_exit);
			break;
		case State::FAILED:
			this->XPos = MENUX;
			this->YPos = MENUY;
			this->Color = 0x000;
			this->Scale = 2;
			sprintf(this->Buffer + POINTERSIZE, "Result: %d", this->Counter);
			sprintf(this->Buffer + BUFFERSIZEX * (this->Position+1), ">");
			sprintf(this->Buffer + BUFFERSIZEX + POINTERSIZE, "%s", text_restart);
			sprintf(this->Buffer + 2*BUFFERSIZEX + POINTERSIZE, "%s", menu_level[this->Level]);
			break;
		case State::GAME:
			this->XPos = COUNTERX;
			this->YPos = COUNTERY;
			this->Color = 0x000;
			this->Scale = 2;
			sprintf(this->Buffer, "%d", this->Counter);
			break;
		default:
			break;
	}
}
