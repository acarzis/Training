#include "../Include/inheritance.h"


void build(machinery& machine)
{
	machine.build();
}

void build(machinery* machine)
{
	machine->build();
}

void example1_inheritance()
{
	machinery m, *mm;
	automobile a;		// inherits from vehicle

	m.build();			// machinery build
	a.build();			// automobile build

	mm = new automobile();
	build(m);			// machinery build
	build(mm);			// automobile build
	build(a);			// automobile build	- because polymorphism works with references as well 
}

void example2_inheritance()
{
	machinery m;
	vehicle v;			// inherits from machinery
	automobile a;		// inherits from vehicle, member engine

	/*
		output:
		machinery ctor
		machinery ctor
		vehicule ctor
		machinery ctor
		vehicule ctor
		engine ctor
		automobile ctor

		automobile dtor
		engine dtor
		vehicule dtor
		machinery dtor
		vehicule dtor
		machinery dtor
		machinery dtor
	*/
}

void example3_inheritance()
{
	machinery m;
	static vehicle v;			// inherits from machinery
	automobile a;				// inherits from vehicle, member engine

	/*
		output:
		machinery ctor
		machinery ctor
		vehicle ctor
		machinery ctor
		vehicle ctor
		engine ctor
		automobile ctor

		automobile dtor
		engine dtor
		vehicle dtor
		machinery dtor
		machinery dtor

		vehicle dtor		// from the static vehicle
		machinery dtor
	*/
}
