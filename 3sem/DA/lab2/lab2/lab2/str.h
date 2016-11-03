#include <iostream>

class TString {
	public:
		TString();
        TString(const char*);
		~TString();

		int Lenght();
		friend std::ostream& operator<<(std::ostream&, const TString&);
		friend std::istream& operator>>(std::istream&, TString&);
		friend bool operator==(TString&, TString&);
        friend bool operator==(TString&, const char*);

	private:
		char* Str;
};