#pragma once

#include <memory>
#include "Dinner.hpp"
#include "SupDirectors.hpp"

class DinnerFactory
{
public:
	virtual std::shared_ptr<Dinner> Produce() = 0;
};

class CheapDinnerFactory : public DinnerFactory
{
public:
	virtual std::shared_ptr<Dinner> Produce() override;
};

class EliteDinnerFactory : public DinnerFactory
{
public:
	virtual std::shared_ptr<Dinner> Produce() override;
};