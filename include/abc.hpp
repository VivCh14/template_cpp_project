/** 
 *  \file   abc.hpp 
 *  \brief  Time the exection of a funtion
 *  \author SVC 
 *  \date   2022-02-03
 ***********************************************/

//=================================
// include guard
#ifndef __FUNCTION_TIMER_HPP_INCLUDED__
#define __FUNCTION_TIMER_HPP_INCLUDED__


//=================================
// included dependencies
#include <iostream>
#include <chrono>

//=================================
/**
 * \brief Template function taking another function with
 * args
 * \details Template takes in another funtion and
 * times its execution
 * \note Template classes and functions need to be in
 * the same file (header)!
 *  
 */
// the actual funtion
template<typename T, typename... Args> // can use class instead of typename
void function_timer (T func, Args&&... args) {

	auto t1 = std::chrono::high_resolution_clock::now();

	// Calling external function and passing its argumets
	func(std::forward<Args>(args)...);

	auto t2 = std::chrono::high_resolution_clock::now();

	// Getting number of milliseconds as an integer.
	auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1);

	// Getting number of milliseconds as a double.
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms\n";
	
}

#endif // __FUNCTION_TIMER_HPP_INCLUDED__

/**
* \fn void function_timer (T func, Args&&... args)
* 
* Usage example:
* \code
* 	function_timer(func,param1,param2, ...);
* \endcode
*/