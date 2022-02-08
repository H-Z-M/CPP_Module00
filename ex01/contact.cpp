#include "contact.hpp"

/*------ADD------*/
void	contact::add_first_name(std::string &first_name)
{ this->first_name = first_name; }

void	contact::add_last_name(std::string &last_name)
{ this->last_name = last_name; }

void	contact::add_nickname(std::string &nickname)
{ this->nickname = nickname; }

void	contact::add_phone_number(std::string &phone_number)
{ this->phone_number = phone_number; }

void	contact::add_darkest_secret(std::string &darkest_secret)
{ this->darkest_secret = darkest_secret; }

void	contact::add_contact(size_t &contact_idx)
{
	std::string	input;
	void	(contact::* func_list[5])(std::string &) =
	{
		&contact::add_first_name,
		&contact::add_last_name,
		&contact::add_nickname,
		&contact::add_phone_number,
		&contact::add_darkest_secret,
	};
	const std::string	information[5] =
	{
		"    first name : ",
		"     last name : ",
		"      nickname : ",
		"  phone number : ",
		"darkest secret : "
	};

	for (int i = 0; i < 5; i++)
	{
		std::cout << information[i];
		if (!std::getline(std::cin, input))
			std::exit(EXIT_FAILURE);
		(this->* func_list[i])(input);
	}
	contact_idx++;
}

void	contact::clear()
{
	this->first_name.clear();
	this->last_name.clear();
	this->nickname.clear();
	this->phone_number.clear();
	this->darkest_secret.clear();
}

bool	contact::contact_list_is_full(size_t &contact_idx, contact contact_list[8])
{
	std::string	input;

	std::cout << "The contact list is full" << std::endl;
	while (1)
	{
		std::cout << "Delete the oldest contacts? [yes/no] : ";
		if (!std::getline(std::cin, input))
			exit(EXIT_FAILURE);
		if (!input.compare("yes"))
		{
			for (int i = 1; i < 8; i++)
				contact_list[i - 1] = contact_list[i];
			contact_list[7].clear();
			contact_idx--;
			return (true);
		}
		else if (!input.compare("no"))
			return (false);
	}
}

/*------SEARCH------*/
void	contact::print_contact(void) const
{
	std::cout << "    first name : " << first_name << std::endl;
	std::cout << "     last name : " << last_name << std::endl;
	std::cout << "      nickname : " << nickname << std::endl;
	std::cout << "  phone number : " << phone_number << std::endl;
	std::cout << "darkest secret : " << darkest_secret << std::endl;
}

void	contact::conform_to_format(std::string s) const
{
	if (s.length() > 10)
		std::cout << s.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::right << s;
}

void	contact::search_information(size_t contact_idx, contact contact_list[8]) const
{
	contact	ct;
	size_t	i = 0;

	std::cout << "     index|first name| last name|  nickname" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	while (i < contact_idx)
	{
		std::cout << "         " << i << "|";
		ct.conform_to_format(contact_list[i].first_name);
		std::cout << "|";
		ct.conform_to_format(contact_list[i].last_name);
		std::cout << "|";
		ct.conform_to_format(contact_list[i].nickname);
		std::cout << std::endl;
		i++;
	}
	std::cout << "Select a number [" << 0 << " - " << i - 1 << "] : ";
}

void	contact::search_contact(size_t contact_idx, contact contact_list[8]) const
{
	size_t		select_num;
	std::string	input;

	if (contact_idx == 0)
	{
		std::cout << "Not registered yet" << std::endl;;
		return ;
	}
	search_information(contact_idx, contact_list);
	if (!std::getline(std::cin, input))
		std::exit(EXIT_FAILURE);
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' )
	{
		select_num = input[0] - '0';
		if (select_num < contact_idx)
		{
			contact_list[select_num].print_contact();
			return ;
		}
	}
	std::cout << "Invalid input" << std::endl;
}
