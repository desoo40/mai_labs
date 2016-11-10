#ifndef _STR_H_
#define _STR_H_

#include <iostream>

class TString {
	public:
		TString();
        TString(const char*);
		~TString();

		int Lenght();
        void ToLower();
		friend std::ostream& operator<<(std::ostream&, const TString&);
		friend std::istream& operator>>(std::istream&, TString&);
		friend bool operator==(TString&, TString&);
        friend bool operator==(TString&, const char*);

	private:
		char* Str;
};

#endif
