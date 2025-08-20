#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>

class Contact {
	private:
		std::string first;
		std::string last;
		std::string nickname;
		std::string number;
		std::string secret;

	public:
		void setFirst(const std::string& f) { first = f; }
		void setLast(const std::string& l) { last = l; }
		void setNickname(const std::string& n) { nickname = n; }
		void setNumber(const std::string& num) { number = num; }
		void setSecret(const std::string& s) { secret = s; }

		std::string getFirst() const { return first; }
		std::string getLast() const { return last; }
		std::string getNickname() const { return nickname; }
		std::string getNumber() const { return number; }
		std::string getSecret() const { return secret; }
};

class PhoneBook {
	private:
		Contact contacts[8];
		int current;
		int total;

	public:
		PhoneBook() : current(0), total(0) {}

		void addContact(const Contact& c)
		{
			contacts[current] = c;
			current = (current + 1) % 8;
			if (total < 8)
				total++;
		}

		const Contact& getContact(int index) const
		{
			return contacts[index];
		}

		int getTotal() const { return total; }
};

// Utils
void printTableHeader();
void printContactRow(int index, const Contact& c);
bool isNameValid(const std::string& name);
bool isNumberValid(const std::string& num);
std::string getNameInput(const std::string& prompt);
std::string getNumberInput(const std::string& prompt);
std::string getInput(const std::string& prompt);
