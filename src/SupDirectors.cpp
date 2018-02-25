#include "SupDirectors.hpp"


std::shared_ptr<Sup> MexicanSupDirector::Construct(SupBuilder& builder)
{
	builder.Create();
	builder.SetBase("triangular bread");
	builder.AddMain("friend chicken");
	builder.AddExtra("nachos");
	builder.AddVegetables("jalapenos");
	builder.AddSauce("red hot chilli sauce");
	return builder.GetConstructed();
}

std::shared_ptr<Sup> ItalianSupDirector::Construct(SupBuilder& builder)
{
	builder.Create();
	builder.SetBase("baguet"); //cuz why not
	builder.AddMain("salami");
	builder.AddExtra("chedar");
	builder.AddVegetables("tomatoes");
	builder.AddVegetables("olives");
	builder.AddVegetables("basil");
	builder.AddSauce("tomato sauce");
	return builder.GetConstructed();	
}

std::shared_ptr<Sup> AlpineSupDirector::Construct(SupBuilder& builder)
{
	builder.Create();
	builder.SetBase("rye bread");
	builder.AddVegetables("lettuce");
	builder.AddMain("sausage");
	builder.AddExtra("fried onions");
	builder.AddSauce("mayo");
	return builder.GetConstructed();
}