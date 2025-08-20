#include "phonebook.hpp"

void addContactFlow(PhoneBook& phonebook)
{
	Contact contact;
	contact.setFirst(getNameInput("Enter the first name: "));
	contact.setLast(getNameInput("Enter the last name: "));
	contact.setNickname(getInput("Enter a nickname: "));
	contact.setNumber(getNumberInput("Enter the phone number: "));
	contact.setSecret(getInput("Enter a darkest secret: "));

	phonebook.addContact(contact);
	std::cout << "New contact added to phonebook!\n" << std::endl;
}

void searchFlow(const PhoneBook& phonebook)
{
	if (phonebook.getTotal() == 0)
	{
		std::cout << "Phonebook is empty!\n" << std::endl;
		return;
	}

	printTableHeader();
	for (int i = 0; i < phonebook.getTotal(); ++i)
		printContactRow(i, phonebook.getContact(i));

	std::string str = getInput("Enter contact index: ");
	if (!str.empty() && str.find_first_not_of("0123456789") == std::string::npos)
	{
		int index = std::atoi(str.c_str());
		if (index >= 0 && index < phonebook.getTotal())
		{
			const Contact& c = phonebook.getContact(index);
			std::cout << "First name: " << c.getFirst() << "\n";
			std::cout << "Last name: " << c.getLast() << "\n";
			std::cout << "Nickname: " << c.getNickname() << "\n";
			std::cout << "Phone number: " << c.getNumber() << "\n";
			std::cout << "Darkest secret: " << c.getSecret() << "\n\n";
		}
		else
			std::cout << "Invalid index!\n" << std::endl;
	}
	else
		std::cout << "Invalid input!\n" << std::endl;
}

int main()
{
	PhoneBook phonebook;
	std::string input;

	std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
	while (true)
	{
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nExiting...\n";
			break;
		}
		if (input == "ADD")
		{
			addContactFlow(phonebook);
			std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		}
		else if (input == "SEARCH")
		{
			searchFlow(phonebook);
			std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		}
		else if (input == "EXIT")
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid command. Try again!\n" << std::endl;
			std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		}
	}
	return (0);
}
