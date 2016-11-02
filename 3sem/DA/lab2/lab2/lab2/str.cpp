#include "str.h"


std::ostream & operator<<(std::ostream & os, const TString & obj)
{
    os << obj.Str;

    return os;
}

std::istream & operator >> (std::istream & is, TString & obj)
{
	is >> obj.Str;

	return is;
}

bool operator==(const TString &, const TString &)
{
	return false;
}

TString::TString()
{
    this->Str = new char[257];
	this->Str[0] = '\0';
}

TString::~TString()
{
	delete this->Str;
}

int TString::Lenght()
{
	int size = 0;

	while (this->Str[size] != '\0') {
		++size;
	}

	return size;
}
