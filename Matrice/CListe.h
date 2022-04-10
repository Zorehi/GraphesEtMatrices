#pragma once

#include <string.h>

template <typename ELEMENT>
class CListe
{
private:
	ELEMENT *peLISTableau;
	unsigned int uiLISTaille;

public:
	CListe();
	CListe(unsigned int uiTaille);
	CListe(CListe &LISParam);
	~CListe();

	const unsigned int LISLireTaille();
	ELEMENT& operator[](unsigned int uiIndex);
};

