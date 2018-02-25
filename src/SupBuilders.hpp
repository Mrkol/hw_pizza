#pragma once

#include <memory>
#include <iostream>
#include <string>
#include "Sups.hpp"



class SupBuilder
{
public:
	virtual void Create() = 0;

	//Following methods are deliberately left
	//non-pure virtual and have a default empty
	//implementation.
	//Some derived builders might not want to add
	//one of the ingredients.
	virtual void SetBase(std::string);
	virtual void AddMain(std::string);
	virtual void AddExtra(std::string);
	virtual void AddVegetables(std::string);
	virtual void AddSauce(std::string);

	virtual bool Initialized() = 0;

	//this also resets the current object being constructed
	//would prevent an object's livetime extending without
	//need
	virtual std::shared_ptr<Sup> GetConstructed() = 0;
};

//they'll put whatever you want into your sandwich
class SandwichBuilder : public SupBuilder
{
	std::shared_ptr<Sandwich> _current;

public:
	SandwichBuilder();

	virtual void Create() override;
	virtual void SetBase(std::string) override;
	virtual void AddMain(std::string) override;
	virtual void AddExtra(std::string) override;
	virtual void AddVegetables(std::string) override;
	virtual void AddSauce(std::string) override;
	virtual bool Initialized() override;
	virtual std::shared_ptr<Sup> GetConstructed() override;
};


//I'd still add some sauce into my roll, but lets pretend that
//all rolls have the same sauce and it doesn't even make sense
//to add a specific one to it
class RollBuilder : public SupBuilder
{
	std::shared_ptr<Roll> _current;

public:
	RollBuilder();

	virtual void Create() override;
	virtual void AddMain(std::string) override;
	virtual void AddExtra(std::string) override;
	virtual void AddVegetables(std::string) override;
	virtual bool Initialized() override;
	virtual std::shared_ptr<Sup> GetConstructed() override;
};

//a salad doesn't have a base (a bun or a tortilla in other cases)
//also, you can't add extras to a sald. Why? Well damn me if i know
class SaladBuilder : public SupBuilder
{
	//Done purely to demonstrate that a builder might
	//work a bit different that expected
	Salad* _current;

public:
	SaladBuilder();

	virtual void Create() override;
	virtual void AddMain(std::string) override;
	virtual void AddVegetables(std::string) override;
	virtual void AddSauce(std::string) override;
	virtual bool Initialized() override;
	virtual std::shared_ptr<Sup> GetConstructed() override;
};
