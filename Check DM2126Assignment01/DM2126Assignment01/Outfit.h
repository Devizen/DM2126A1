#ifndef OUTFIT_H
#define OUTFIT_H
#include "Item.h"


class Outfit : public Item
{
public:
	Outfit(const string&, const int&, const int&);
	~Outfit();
	const int getSPECIAL();

protected:
	const int kSPECIAL;

private:
};

#endif