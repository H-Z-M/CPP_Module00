#include "phonebook.hpp"

t_cmd	phonebook::command_input(void)
{
	std::string	input;

	std::cout << "Enter the command : ";
	if (!std::getline(std::cin, input))
		std::exit(EXIT_FAILURE);
	if (!input.compare("ADD"))
		return (ADD);
	if (!input.compare("SEARCH"))
		return (SEARCH);
	if (!input.compare("EXIT"))
		return (EXIT);
	return (OTHERS);
}

void	phonebook::command_announce(void)
{
	std::cout << "Welcome to Phonebook!" << std::endl;
	std::cout << "- ADD\n- SEARCH\n- EXIT" << std::endl;
}

void	phonebook::accept_command(void)
{
	phonebook	pb;
	size_t	contact_idx = 0;

	pb.command_announce();
	while (1)
	{
		switch (pb.command_input())
		{
			case (ADD) :
				if (contact_idx == 8 &&
					pb.contact_list[contact_idx].contact_list_is_full(contact_idx, pb.contact_list) == false)
						break ;
				pb.contact_list[contact_idx].add_contact(contact_idx);
				break ;
			case (SEARCH) :
				pb.contact_list[contact_idx].search_contact(contact_idx, pb.contact_list);
				break ;
			case (EXIT) :
				std::exit(EXIT_SUCCESS);
			default :
				break ;
		}
	}
}
