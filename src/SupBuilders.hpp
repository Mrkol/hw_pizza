#include <memory>
#include <string>
#include "Sups.hpp"

#pragma once


class SupBuilder
{
public:
	virtual void Create() = 0;

	//Following methods are deliberately left
	//non-pure virtual and have a default empty
	//implementation.
	//Some derived builders might not want to add
	//one of the ingredients.
	virtual void AddBase(std::string);
	virtual void AddMain(std::string);
	virtual void AddExtra(std::string);
	virtual void AddVegetables(std::string);
	virtual void AddSauce(std::string);
	virtual std::shared_ptr<Sup> GetConstructed() = 0;
};

//they'll put whatever you want into your sandwich
class SandwichBuilder : SupBuilder
{
public:
	virtual void Create() override;
	virtual void AddBase(std::string) override;
	virtual void AddMain(std::string) override;
	virtual void AddExtra(std::string) override;
	virtual void AddVegetables(std::string) override;
	virtual void AddSauce(std::string) override;
	virtual std::shared_ptr<Sup> GetConstructed() override;
};


//I'd still add some sauce into my roll, but lets pretend that
//all rolls have the same sauce and it doesn't even make sense
//to add a specific one to it
class RollBuilder : SupBuilder
{
public:
	virtual void Create() override;
	virtual void AddBase(std::string) override;
	virtual void AddMain(std::string) override;
	virtual void AddExtra(std::string) override;
	virtual void AddVegetables(std::string) override;
	virtual std::shared_ptr<Sup> GetConstructed() override;
};

//a salad doesn't have a base (a bun or a tortilla in other cases)
//also, you can't add extras to a sald. Why? Well damn me if i know
class SaladBuilder : SupBuilder
{
public:
	virtual void Create() override;
	virtual void AddMain(std::string) override;
	virtual void AddVegetables(std::string) override;
	virtual void AddSauce(std::string) override;
	virtual std::shared_ptr<Sup> GetConstructed() override;
};
