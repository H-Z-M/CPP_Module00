#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class contact
{
	public:
	void	add_contact(size_t &contact_idx);
	void	add_first_name(std::string &first_name);
	void	add_last_name(std::string &last_name);
	void	add_nickname(std::string &nickname);
	void	add_phone_number(std::string &phone_number);
	void	add_darkest_secret(std::string &darkest_secret);
	bool	contact_list_is_full(size_t &contact_idx, contact contact_list[8]);
	void	clear(void);

	void	search_contact(size_t contact_idx, contact contact_list[8]) const;
	void	search_information(size_t contact_idx, contact contact_list[8]) const;
	void	conform_to_format(std::string s) const;
	void	print_contact(void) const;

	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif
