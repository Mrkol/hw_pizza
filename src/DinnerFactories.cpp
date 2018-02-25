#include "DinnerFactories.hpp"


std::shared_ptr<Dinner> CheapDinnerFactory::Produce()
{
	//add a drink here or something
	MexicanSupDirector sd;
	return std::make_shared<SimpleDinner>(sd);
}

std::shared_ptr<Dinner> EliteDinnerFactory::Produce()
{
	AlpineSupDirector sd;
	return std::make_shared<MultiDinner>(sd);
}
