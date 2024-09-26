#ifndef account_hpp
#define date_hpp
#include <string>

namespace bank_account_app {
	class Account {
	private:
		int account_id;
		std::string account_name;
		float account_balance;
	public:
		Account();
		void set_account_id(int previous_account_id);
		int get_account_id()const;
		void set_account_name(std::string acc_name);
		std::string get_account_name()const;
		void set_account_balance(float balance);
		float get_account_balance()const;
	};
}

#endif
