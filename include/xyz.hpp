/** 
 *  \file   xyz.hpp 
 *  \brief  Simulate the 100 prisoner puzzle
 *  \author SVC 
 *  \date   2022-02-03
 ***********************************************/

//=================================
// include guard
#ifndef __100prisoners_HPP_INCLUDED__
#define __100prisoners_HPP_INCLUDED__

//=================================
// forward declared dependencies (for pointers and references)
//class Foo;
//class Bar;

//=================================
// included dependencies
#include <array>
#include <random>
#include <algorithm>

namespace cpplib {

//=================================
/**
 * \brief Class for defining a Cupboard object.
 * \details Cupboard having numberd
 * drawers each having a randomly placed numbered card
 */

//=================================
// the actual class
//final: this class cannot be inherited!
class Cupboard final { 
		
	public:

		/**
		 * \brief Standard Constructor.
		 * \details The constructor initializes the
		 * member variables by calling initialize_game
		 */
		Cupboard();

		/**
		 * \brief Destructor.
		 */
		// generate a virtual default destructor
		virtual ~Cupboard() = default; 


	private:

		std::array<int, 100> m_card;

		void initialize_game ();


	public:

		/**
		 * \brief numbered prisioners
		 */ 
		std::array<int, 100> m_prisoners;
		/**
		 * \brief numbered drawers in the Cupboard
		 */ 
		std::array<int, 100> m_drawers;
		/**
		 * \brief if a prisioner succeeds then 1 else 0
		 */ 
		std::array<int, 100> m_success;
		/**
		 * \brief sum of m_success
		 */ 
		std::size_t m_sum;
		/**
		 * \brief current opened drawer
		 */ 
		std::size_t m_drawer;
		/**
		 * \brief Each prisoner randomly checks 50 drawers at most.
		 */ 
		int random_sim();
		/**
		 * \brief Each prisoner checks 50 drawers following the optimal
		 * strategy.
		 */ 
		int optimized_sim ();

};
}
#endif //__100prisoners_HPP_INCLUDED__

/**
* \class cpplib::Cupboard
* 
* Usage example:
* \code
* 	cpplib::Cupboard c;
* 	c.optimized_sim();
* \endcode
*/