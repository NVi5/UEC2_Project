#pragma once

#include "line2d.hpp"
#include "textures.h"

class Floor : public Line2d {

	private:
		texture_t texture;

	public:
		Floor();
		Floor(Line2d position, texture_t texture);
		void SetTexture(texture_t texture);
		texture_t GetTexture();

};
