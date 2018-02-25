#include <iostream>
#include <memory>
#include <gtest/gtest.h>
#include "SupDirectors.hpp"
#include "DinnerFactories.hpp"


TEST(MainTestCase, MexicanFoodTest)
{
	SandwichBuilder sandwichBuilder;
	RollBuilder rollBuilder;
	SaladBuilder saladBuilder;

	MexicanSupDirector msd;
	std::shared_ptr<Sup> mexicanSandwich = msd.Construct(sandwichBuilder);
	std::shared_ptr<Sup> mexicanRoll = msd.Construct(rollBuilder);
	std::shared_ptr<Sup> mexicanSalad = msd.Construct(saladBuilder);

	ASSERT_EQ(31, mexicanSandwich->GetCost());
	ASSERT_EQ(31, mexicanRoll->GetCost());
	ASSERT_EQ(14, mexicanSalad->GetCost());
}

TEST(MainTestCase, ItalianFoodTest)
{
	SandwichBuilder sandwichBuilder;
	RollBuilder rollBuilder;
	SaladBuilder saladBuilder;

	ItalianSupDirector isd;
	std::shared_ptr<Sup> italianSandwich = isd.Construct(sandwichBuilder);
	std::shared_ptr<Sup> italianRoll = isd.Construct(rollBuilder);
	std::shared_ptr<Sup> italianSalad = isd.Construct(saladBuilder);

	ASSERT_EQ(35, italianSandwich->GetCost());
	ASSERT_EQ(35, italianRoll->GetCost());
	ASSERT_EQ(6, italianSalad->GetCost());
}

TEST(MainTestCase, AlpineFoodTest)
{
	SandwichBuilder sandwichBuilder;
	RollBuilder rollBuilder;
	SaladBuilder saladBuilder;

	AlpineSupDirector msd;
	std::shared_ptr<Sup> alpineSandwich = msd.Construct(sandwichBuilder);
	std::shared_ptr<Sup> alpineRoll = msd.Construct(rollBuilder);
	std::shared_ptr<Sup> alpineSalad = msd.Construct(saladBuilder);

	ASSERT_EQ(28, alpineSandwich->GetCost());
	ASSERT_EQ(28, alpineRoll->GetCost());
	ASSERT_EQ(7, alpineSalad->GetCost());
}

TEST(MainTestCase, CheapDinnerTest)
{
	CheapDinnerFactory cd;
	std::shared_ptr<Dinner> dinner = cd.Produce();
	
	ASSERT_EQ(41, dinner->GetCost());
	ASSERT_FALSE(dinner->GetCritique().empty());
}

TEST(MainTestCase, EliteDinnerTest)
{
	EliteDinnerFactory cd;
	std::shared_ptr<Dinner> dinner = cd.Produce();
	
	ASSERT_EQ(135, dinner->GetCost());
	ASSERT_FALSE(dinner->GetCritique().empty());
}

int main(int, char*[]);
