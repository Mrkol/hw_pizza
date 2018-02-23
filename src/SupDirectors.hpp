#include <memory>
#include "Sups.hpp"
#include "SupBuilders.hpp"

#pragma once


class SupDirector
{
public:
	virtual std::shared_ptr<Sup> Construct(SupBuilder&) = 0;
};

//Will try and stuff mexican ingredients into your sup
class MexicanSupBuilder : SupDirector
{
public:
	virtual std::shared_ptr<Sup> Construct(SupBuilder&) override;
};

//etc...
class ItalianSupBuilder : SupDirector
{
public:
	virtual std::shared_ptr<Sup> Construct(SupBuilder&) override;
};

//shhhhh
class AlpineSupBuilder : SupDirector
{
public:
	virtual std::shared_ptr<Sup> Construct(SupBuilder&) override;
};
