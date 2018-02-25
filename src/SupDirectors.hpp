#pragma once

#include <memory>
#include "Sups.hpp"
#include "SupBuilders.hpp"



class SupDirector
{
public:
	virtual std::shared_ptr<Sup> Construct(SupBuilder&) = 0;
};

//Will try and stuff mexican ingredients into your sup
class MexicanSupDirector : public SupDirector
{
public:
	virtual std::shared_ptr<Sup> Construct(SupBuilder&) override;
};

//etc...
class ItalianSupDirector : public SupDirector
{
public:
	virtual std::shared_ptr<Sup> Construct(SupBuilder&) override;
};

//shhhhh
class AlpineSupDirector : public SupDirector
{
public:
	virtual std::shared_ptr<Sup> Construct(SupBuilder&) override;
};
