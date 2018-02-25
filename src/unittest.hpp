#include <iostream>
#include <memory>
#include <gtest/gtest.h>
#include "SupDirectors.hpp"


TEST(MainTestCase, MexicanFoodTest)
{
	SandwichBuilder sandwichBuilder;
	RollBuilder rollBuilder;
	SaladBuilder saladBuilder;

	MexicanSupDirector msd;
	std::shared_ptr<Sup> mexicanSandwich = msd.Construct(sandwichBuilder);
	std::shared_ptr<Sup> mexicanRoll = msd.Construct(rollBuilder);
	std::shared_ptr<Sup> mexicanSalad = msd.Construct(saladBuilder);

	ASSERT_EQ(mexicanSandwich->GetCost(), 31);
	ASSERT_EQ(mexicanRoll->GetCost(), 31);
	ASSERT_EQ(mexicanSalad->GetCost(), 14);
}

int main(int, char*[]);
