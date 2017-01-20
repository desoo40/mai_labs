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

bool operator==(TString &lhs, TString &rhs)
{
    int lenght = lhs.Lenght();

	if (lenght != rhs.Lenght()) {
		return false;
	}
    
	for (int i = 0; i < lenght; ++i) {
		if (lhs.Str[i] != rhs.Str[i]){
            return false;
		}
	}

	return true;
}

bool operator==(TString &lhs, const char* rhs)
{
    TString srhs = TString(rhs);

    return lhs == srhs;
}

bool operator>(TString &lhs, TString &rhs) {
    int llen = lhs.Lenght();
    int rlen = rhs.Lenght();

    if (llen == rlen) {
        if (lhs == rhs)
            return false;

        for (int i = 0; i < llen; i++) {
            if (lhs.Str[i] > rhs.Str[i]) {
                return true;
            }
            if (lhs.Str[i] < rhs.Str[i]) {
                return false;
            }
        }
    }

    else if (llen > rlen)
        return true;

    return false;
}

bool operator<(TString &lhs, TString &rhs) {
    int llen = lhs.Lenght();
    int rlen = rhs.Lenght();

    if (llen == rlen) {
        if (lhs == rhs)
            return false;

        for (int i = 0; i < llen; i++) {
            if (lhs.Str[i] < rhs.Str[i]) {
                return true;
            }
            if (lhs.Str[i] > rhs.Str[i]) {
                return false;
            }
        }
    }

    else if (llen < rlen)
        return true;

    return false;
}

TString::TString()
{
    this->Str = new char[257];
	this->Str[0] = '\0';
}

TString::TString(const char *s)
{
    int i = 0;
    this->Str = new char[257];

    for (; s[i] != '\0' && i < 257; ++i) {
        this->Str[i] = s[i];
    }

    this->Str[i] = '\0';
}

char* TString::ToCharsArr() {
    return this->Str;
}

TString::~TString()
{
}

int TString::Lenght()
{
	int size = 0;

	while (this->Str[size] != '\0') {
		++size;
	}

	return size;
}

void TString::ToLower() {
    int strLenght = this->Lenght();

    for(int i = 0; i < strLenght; ++i) {
        if (this->Str[i] >= 'A' && this->Str[i] <= 'Z') {
            this->Str[i] += 32;
        }
    }
}
