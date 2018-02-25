#include "Dinner.hpp"



SimpleDinner::SimpleDinner(SupDirector& sd) 
{
	SandwichBuilder sb;
	_sandwich = sd.Construct(sb);	
}

std::string SimpleDinner::GetCritique()
{
	return "Barely enough to be a midday snack.";
}

int SimpleDinner::GetCost()
{
	return _sandwich->GetCost() + 10;
}

MultiDinner::MultiDinner(SupDirector& sd)
{
	SaladBuilder sb;
	RollBuilder rb;
	_salad = sd.Construct(sb);	
	_roll = sd.Construct(rb);	
}

std::string MultiDinner::GetCritique()
{
	return "Plentyful!";
}

int MultiDinner::GetCost()
{
	return _salad->GetCost() + _roll->GetCost() + 100;
}
