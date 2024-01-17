#include "Base.hpp"
#include "misc.hpp"

int main(void)
{
	Base *r = generate();

	Base &rp = *r;

	identify(r);

	identify(rp);

	delete(r);

	return (0);
}