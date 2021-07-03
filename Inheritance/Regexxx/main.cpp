#include<iostream>
#include<string>
#include<regex>

using namespace std;
//#define NAME_CHECK
#define EMAIL_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef NAME_CHECK
	std::string last_name = "Tupenko";
	std::string first_name = "Vasya";
	//cout << "¬ведите фамилию, им€: "; cin >> last_name >> first_name;

	std::regex rgx("[A-Z][a-z]{1,15}");
	if (std::regex_match(last_name, rgx/*, std::regex_constants::match_any*/))
	{
		cout << "Surname OK: " << last_name << endl;
	}
	else
	{
		cout << "Bad Surname!!!" << endl;
	}
	if (std::regex_match(first_name, rgx))
	{
		cout << "Surname OK: " << first_name << endl;
	}
	else
	{
		cout << "Bad Surname!!!" << endl;
	}
#endif // NAME_CHECK

#ifdef EMAIL_CHECK


		string email;
	do
	{
		cout << "Type your e-mail: " << endl; cin >> email;
		if (email.find('@') == std::string::npos || email.size() < 8)cout << "Not E-mail, try again.\n";
	} while (email.find('@') == std::string::npos || email.size() < 8);
	try
	{
	std::regex rgx("(\\w+)(\\.?)(\\w*)@(\\w+)((\\.)[:alpha:]{2,5})+");

	if (std::regex_match(email, rgx))
	{
		cout << "E-mail Ok: " << email << endl;
	}
	else
	{
		cout << "Bad E-mail!!! " << endl;
	}

	}
	catch (const std::exception&e)
	{
		std::cerr << e.what() << endl;
	}

#endif // EMAIL_CHECK
	main();
}