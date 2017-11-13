#pragma once
#include "Include.h"

class Map;
class RoadSign
{
	int Limit;
	int X, Y;

public:
	static std::vector<RoadSign> AllRoadSign;

	RoadSign(const int x, const int y, const char simvol);
	~RoadSign();
	int getLimit() const;
	int getX() const;
	int getY() const;
};

