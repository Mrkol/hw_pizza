#include "SupBuilders.hpp"

void SupBuilder::SetBase(std::string) { }
void SupBuilder::AddMain(std::string)  { }
void SupBuilder::AddExtra(std::string)  { }
void SupBuilder::AddVegetables(std::string)  { }
void SupBuilder::AddSauce(std::string) { }

SandwichBuilder::SandwichBuilder()
	: _current(nullptr)
{

}

void SandwichBuilder::Create()
{
	_current.reset(new Sandwich());
}

void SandwichBuilder::SetBase(std::string base)
{
	if (!Initialized()) throw -1;
	_current->_base = base;
}

void SandwichBuilder::AddMain(std::string ingr)
{
	if (!Initialized()) throw -1;
	_current->_insides = ingr + "," + _current->_insides;
}

void SandwichBuilder::AddExtra(std::string ingr)
{
	if (!Initialized()) throw -1;
	_current->_insides += ingr + ",";
}

void SandwichBuilder::AddVegetables(std::string ingr)
{
	if (!Initialized()) throw -1;
	_current->_insides += ingr + ",";
}

void SandwichBuilder::AddSauce(std::string sauce)
{
	if (!Initialized()) throw -1;
	_current->_sauce += sauce + ",";
}

bool SandwichBuilder::Initialized()
{
	return _current != nullptr;
}

std::shared_ptr<Sup> SandwichBuilder::GetConstructed()
{
	if (!Initialized()) throw -1;
	//Something more complicated than removing
	//a comma from a string might be here
	if (_current->_base.empty())
	{
		std::cerr << "Can't make a sandwcich with no bun";
		throw -1;
	}

	if (_current->_sauce.size() > 0)
		_current->_sauce.pop_back();

	
	if (_current->_insides.size() > 0)
		_current->_insides.pop_back();

	std::shared_ptr<Sup> tmp = _current;
	_current.reset();
	return tmp;
}

RollBuilder::RollBuilder()
	: _current(nullptr)
{

}

void RollBuilder::Create()
{
	_current.reset(new Roll());
}

void RollBuilder::AddMain(std::string ingr)
{
	if (!Initialized()) throw -1;
	_current->_insides = ingr + "," + _current->_insides;
}

void RollBuilder::AddExtra(std::string ingr)
{
	if (!Initialized()) throw -1;
	_current->_insides += ingr + ",";
}

void RollBuilder::AddVegetables(std::string ingr)
{
	if (!Initialized()) throw -1;
	_current->_insides += ingr + ",";
}

bool RollBuilder::Initialized()
{
	return _current != nullptr;
}

std::shared_ptr<Sup> RollBuilder::GetConstructed()
{
	if (!Initialized()) throw -1;
	if (_current->_insides.size() > 0)
	{
		_current->_insides.pop_back();
	}
	else
	{
		std::cerr << "What are you, stupid? ";
		std::cerr << "This is just an empty sheet of tortilla" << std::endl;
		throw -1;
	}

	std::shared_ptr<Sup> tmp = _current;
	_current.reset();
	return tmp; 
}



SaladBuilder::SaladBuilder()
	: _current(nullptr)
{

}

void SaladBuilder::Create()
{
	if (_current != nullptr) delete _current;

	_current = new Salad();
}

void SaladBuilder::AddMain(std::string ingr)
{
	//too lazy to add proper cerr'ing for each method
	if (!Initialized()) throw -1;
	_current->_filling += ingr + ",";
}

void SaladBuilder::AddVegetables(std::string ingr)
{
	if (!Initialized()) throw -1;
	_current->_veggies += ingr + ",";
}

void SaladBuilder::AddSauce(std::string ingr)
{
	if (!Initialized()) throw -1;
	_current->_dressing += ingr + ",";
}

bool SaladBuilder::Initialized()
{
	return _current != nullptr;
}

std::shared_ptr<Sup> SaladBuilder::GetConstructed()
{
	if (!Initialized()) throw -1;
	if (_current->_filling.empty() || _current->_veggies.empty()
		|| _current->_dressing.empty())
	{
		std::cerr << "This ain't a sald" << std::endl;
		throw -1;
	}

	_current->_filling.pop_back();
	_current->_veggies.pop_back();
	_current->_dressing.pop_back();
	
	std::shared_ptr<Sup> tmp(_current);
	_current = nullptr;
	return tmp;
}

