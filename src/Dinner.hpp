#pragma once

#include <string>
#include "Sups.hpp"
#include "SupDirectors.hpp"

class Dinner
{
public:
	virtual std::string GetCritique() = 0;
	virtual int GetCost() = 0;

	virtual ~Dinner() = default;
};

class SimpleDinner : public Dinner
{
	std::shared_ptr<Sup> _sandwich;

public:
	SimpleDinner(SupDirector&);

	virtual std::string GetCritique() override;
	virtual int GetCost() override;
};

class MultiDinner : public Dinner
{
	std::shared_ptr<Sup> _roll;
	std::shared_ptr<Sup> _salad;

public:
	MultiDinner(SupDirector&);

	virtual std::string GetCritique() override;
	virtual int GetCost() override;
};