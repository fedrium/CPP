#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain &c);
		Brain &operator=(const Brain &c);
		~Brain();
		std::string getIdea(int i) const;
		void	setIdea(int i, std::string input);
	private:
		std::string idea[100];
};

#endif