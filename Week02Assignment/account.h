#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>
#include <ostream>

/// <summary>
/// Class used to create an account object.
/// </summary>
class Account {
	private:
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
	public:
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
		/// Adds a deposit to the account balance.
		/// </summary>
		/// <param name="amount">Deposit amount</param>
		void add_to_account_balance(float amount);
		/// <summary>
		/// Subtracts a withdrawal from the account balance.
		/// </summary>
		/// <param name="amount">Withdrawal amount</param>
		void subtract_from_account_balance(float amount);
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
		/// <summary>
		/// Returns the account information by overloading the << operator.
		/// </summary>
		/// <param name="out"></param>
		/// <returns></returns>
		void WriteToStream(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& out, const Account& account);

#endif // ACCOUNT_HPP
