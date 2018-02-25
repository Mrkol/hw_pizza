#include "Sups.hpp"

std::string Sandwich::GetTaste()
{
	return _insides + " on a " + _base + " with " + _sauce;
}

int Sandwich::GetCost()
{
	return _insides.size();
}

std::string Salad::GetTaste()
{
	return "exquisite " + _filling + " with some " + _veggies + " dessed with " + _dressing;
}

int Salad::GetCost()
{
	return _filling.size();
}

std::string Roll::GetTaste()
{
	return "tons of sauce, little ingredients";
}

int Roll::GetCost()
{
	return _insides.size();
}