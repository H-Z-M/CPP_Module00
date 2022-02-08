#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

typedef enum e_commands
{
	ADD,
	SEARCH,
	EXIT,
	OTHERS
}	t_cmd;

class phonebook
{
	public:
		void	accept_command(void);

	private:
		void	command_announce(void);
		t_cmd	command_input(void);

		contact contact_list[8];
};

#endif
