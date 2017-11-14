#include "RoadSign.h"

std::vector<RoadSign> RoadSign::AllRoadSign;


RoadSign::RoadSign(const int x, const int y, const char simvol)
{
	X = x;
	Y = y;
	if(simvol == 'y') Limit = 6;
	else Limit = 3;
	AllRoadSign.push_back(*this);
}


std::vector<RoadSign> & RoadSign::Vec()
{
	return AllRoadSign;
}


RoadSign::~RoadSign()
{
	X = 0;
	Y = 0;
	Limit = 0;
}

int RoadSign::getLimit() const
{
	return Limit;
}
int RoadSign::getX() const
{
	return X;
}
int RoadSign::getY() const
{
	return Y;
}
