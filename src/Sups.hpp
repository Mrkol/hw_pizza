#pragma once

#include <string>



//totally not a bootleg s*bway

//your sup's ingredients can be packed into a bun, or a tortilla, or even
//put in a bowl as a salad - different representations of the same taste
class Sup
{
public:
	virtual std::string GetTaste() = 0;
	virtual int GetCost() = 0;

	virtual ~Sup() = default;
};

class Sandwich : public Sup
{
	//In an actual solution there probably would be enums
	//or even dedicated classes for the ingredients
	std::string _base;
	std::string _insides;
	std::string _sauce;

	Sandwich() = default;

	friend class SandwichBuilder;

public:
	virtual std::string GetTaste() override;
	virtual int GetCost() override;

	virtual ~Sandwich() = default;
};

class Salad : public Sup
{
	std::string _filling;
	std::string _veggies;
	std::string _dressing;

	Salad() = default;

	friend class SaladBuilder;

public:
	virtual std::string GetTaste() override;
	virtual int GetCost() override;

	virtual ~Salad() = default;
};

class Roll : public Sup
{
	std::string _insides;

	Roll() = default;

	friend class RollBuilder;

public:
	virtual std::string GetTaste() override;
	virtual int GetCost() override;

	virtual ~Roll() = default;
};
