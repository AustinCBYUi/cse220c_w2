#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>
#include <ostream>
#include <map>
#include <list>
#include <algorithm>
#include <numeric>
#include <IContact.h>

/// <summary>
/// Class used to create an account object.
/// </summary>
class Account {

	private:
		/// <summary>
		/// Map used to store all accounts, static map to be accessed by all initialized classes.
		/// </summary>
		static std::map<int, Account> accounts;

		/// <summary>
		/// Integer used to assign a unique account ID to each account.
		/// </summary>
		static int next_id;

		/// <summary>
		/// Unique account id.
		/// </summary>
		int account_id;

		/// <summary>
		/// Account holder name.
		/// </summary>
		std::string account_name;

		/// <summary>
		/// Account balance.
		/// </summary>
		float account_balance;

		std::shared_ptr<Contact> contact_info;


	public:
		void add_contact_info();
		void display_contact_info() const;

		/// <summary>
		/// Finds an account by account ID and returns an iterator to the account.
		/// </summary>
		/// <param name="id">Account ID</param>
		/// <returns>An iterator to the account</returns>
		std::map<int, Account>::iterator find_account_iter(int id);

		/// <summary>
		/// Removes an account from the static accounts map.
		/// </summary>
		/// <param name="account_id">Account ID</param>
		void remove_accounts(int account_id);

		/// <summary>
		/// Uses accumulate to get the total deposits from all accounts.
		/// </summary>
		/// <returns>All deposits added together, a float.</returns>
		float get_total_deposits() const;

		/// <summary>
		/// Applies a dividend to all accounts
		/// </summary>
		/// <param name="percentage">Percentage of dividend to apply</param>
		void apply_dividends(float percentage);

		/// <summary>
		/// Finds an account by account ID.
		/// </summary>
		/// <param name="account_id">Account ID as an integer</param>
		void find_account(int account_id) const;

		/// <summary>
		/// Adds an account to the static accounts map
		/// </summary>
		/// <param name="account">An initialized account</param>
		void add_account(const Account& account);

		/// <summary>
		/// Gets all accounts from the static accounts map.
		/// </summary>
		void get_accounts()const;

		/// <summary>
		/// Getter for the static accounts map. Accesses private static map variable.
		/// </summary>
		/// <returns>Accounts map</returns>
		std::map<int, Account>& get_accounts_map();

		/// <summary>
		/// Constructor used to initialize the account ID and account balance.
		/// </summary>
		Account();

		/// <summary>
		/// Allows the user to input account information during initialization.
		/// </summary>
		void inputAccountInfo();

		/// <summary>
		/// Returns the account ID.
		/// </summary>
		/// <returns>The account id as an integer.</returns>
		int get_account_id()const;

		/// <summary>
		/// Sets the account holder name.
		/// </summary>
		/// <param name="acc_name">Account holder name as a string.</param>
		void set_account_name(std::string acc_name);

		/// <summary>
		/// Returns the name of the account holder.
		/// </summary>
		/// <returns>The account holder name as a string.</returns>
		std::string get_account_name()const;

		/// <summary>
		/// Sets account balance to a specific amount during account initialization.
		/// </summary>
		/// <param name="balance">Initial Balance</param>
		void set_account_balance(float balance);

		/// <summary>
		/// Returns the account balance.
		/// </summary>
		/// <returns>Account balance as a float</returns>
		float get_account_balance()const;

		/// <summary>
		/// Returns the account information.
		/// </summary>
		/// <param name="out">Must be std::cout</param>
		/// <returns>Account information as a print</returns>
		std::ostream& display(std::ostream& out) const;

		/// <summary>
		/// Adds a deposit to the account balance by overloading the += operator.
		/// </summary>
		/// <param name="deposit">Amount to deposit</param>
		/// <returns>A reference to the object as *this</returns>
		Account& operator+= (float deposit);

		/// <summary>
		/// Subtracts a withdrawal from the account balance by overloading the -= operator.
		/// </summary>
		/// <param name="withdrawal">Amount to withdraw</param>
		/// <returns>A reference to the object as *this</returns>
		Account& operator-=(float withdrawal);

		Account& operator*=(float percentage);

		/// <summary>
		/// Returns the account information by overloading the << operator.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		void WriteToStream(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& out, const Account& account);

#endif // ACCOUNT_HPP
