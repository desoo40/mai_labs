#include <iostream>

class TString {
	public:
		TString();
		~TString();

		friend std::ostream& operator<<(std::ostream&, const TString&);
		friend std::istream& operator>>(std::istream&, TString&);
		friend bool operator==(const TString&, const TString&);

	private:
		char* Str;
        int Lenght();
};