#include "../include/floor.hpp"

Floor::Floor()
{
	this->texture = TEXTURE_PURPLEDIRT;
}

Floor::Floor(Line2d position, texture_t texture) :
	Line2d(position.GetStart(), position.GetEnd())
{
	this->texture = texture;
}

void Floor::SetTexture(texture_t texture){this->texture = texture;};
texture_t Floor::GetTexture(){return this->texture;};
