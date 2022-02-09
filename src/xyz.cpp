#include "xyz.hpp"

namespace cpplib {

/**
 * Standard Constructor
 */
Cupboard::Cupboard () {

			initialize_game();

}

/**
 * Destructor
 */
/*Cupboard::~Cupboard () {

}*/

void Cupboard::initialize_game() {

			m_sum = std::size_t (0);
			m_drawer = std::size_t (0);

			for (std::size_t prisoner{0}; prisoner<m_prisoners.size();++prisoner) {
				m_prisoners.at(prisoner) = prisoner;
				m_success.at(prisoner) = std::size_t (0);
			}			

			m_card = m_prisoners;
			m_drawers = m_prisoners;

			std::random_device rd;
			std::default_random_engine generator(rd()); //generator
			std::shuffle(m_card.begin(), m_card.end(), generator);
			std::shuffle(m_drawers.begin(), m_drawers.end(), generator);

}

int Cupboard::random_sim() {

			initialize_game();

			std::random_device rd;
			std::default_random_engine generator(rd()); //generator

			for (std::size_t prisoner{0}; prisoner<m_prisoners.size();++prisoner)	{
				std::shuffle(m_drawers.begin(), m_drawers.end(), generator);
				for (std::size_t j{0}; j<50;++j) {
					m_drawer = m_drawers.at(j);
					if(prisoner == m_card.at(m_drawer)) {
						++m_success.at(prisoner);
						break; // break if prisoner finds his card
					}
				} // max draws reached
			}

		
			m_sum = std::accumulate(m_success.begin(), m_success.end(), m_sum);
			if (m_sum == m_prisoners.size()) {
				//std::cout << "All Pardoned!! ;)" << " " << m_sum << " prisoners succeeded" << " of 100" << "\n";
				return 1;
			} else {
				//std::cout << "All Sentenced! :(" << " " << m_sum << " prisoners succeeded" << " of 100" << "\n";
				return 0;
			}

}


int Cupboard::optimized_sim () {

			initialize_game();

			for (std::size_t prisoner{0}; prisoner<m_prisoners.size();++prisoner) {
				int turns = 0;
				m_drawer = prisoner;
				do {					
					if (prisoner == m_card.at(m_drawer)) {
						++m_success.at(prisoner);
						break;
					} else {
						m_drawer = m_card.at(m_drawer);
						if (prisoner == m_card.at(m_drawer)) {
							++m_success.at(prisoner);
							break;
						}
					}
					++turns;
				} while (turns<50);
				
			}

			m_sum = std::accumulate(m_success.begin(), m_success.end(), m_sum);
			if (m_sum == m_prisoners.size()) {
				//std::cout << "All Pardoned!! ;)" << " " << m_sum << " prisoners succeeded" << " of 100" << "\n";
				return 1;

			} else {
				//std::cout << "All Sentenced! :(" << " " << m_sum << " prisoners succeeded" << " of 100" << "\n";
				return 0;
			}

}
}
