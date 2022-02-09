////////////////////////////////////////////////////////////
/// \mainpage
///
/// \section welcome Welcome
/// Welcome to the official Sample documentation. Here you will find a detailed
/// view of all the classes and functions.
///
///
///
/// \section example Short example
/// Here is a short example, to show you how to use the Library:
///
///\code
///#include <iostream>
///#include "xyz.hpp"
///#include "abc.hpp"
///
///
///int call_100prisioners () {
///
///	cpplib::Cupboard c;
///	int success =0;
///	int num_sims = 10000;
///
///	for (int i=0; i<num_sims;++i) {
///		//success += c.random_sim(); // 0 probab.
///		success += c.optimized_sim(); // ~33% probab.
///	}
///
///	std::cout << "Probability of success is: " << (success*1.0)/num_sims << "\n";
///
///	return 0;
///}
///
///
///int main(int argc, char const *argv[]) {
///	
///	function_timer(call_100prisioners);
///	
///	return EXIT_SUCCESS;
///}
///\endcode
////////////////////////////////////////////////////////////
