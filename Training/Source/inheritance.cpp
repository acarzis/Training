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
	automobile a;

	m.build();		// machinery build
	a.build();		// automobile build

	mm = new automobile();
	build(m);		// machinery build
	build(mm);		// automobile build
	build(a);		// automobile build	- because polymorphism works with references as well 
}

