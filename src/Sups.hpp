#include <string>

#pragma once


//totally not a bootleg s*bway

//your sup's ingredients can be packed into a bun, or a tortilla, or even
//put in a bowl as a salad - different representations of the same taste
class Sup
{
public:
	virtual std::string GetTaste() = 0;
	virtual int GetCost() = 0;
};

class Sandwich : Sup
{
public:
	virtual std::string GetTaste() override;
	virtual int GetCost() override;
};

class Salad : Sup
{
public:
	virtual std::string GetTaste() override;
	virtual int GetCost() override;
};

class Roll : Sup
{
public:
	virtual std::string GetTaste() override;
	virtual int GetCost() override;
};
