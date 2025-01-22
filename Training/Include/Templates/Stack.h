#pragma once

// example taken from 'C++ Templates The Complete Guide 2ed', by David Vandevoorde et al.
// It should be noted that C++ already has a stack implementation in <stack>.

#include <vector>
#include <iostream>


template<class T>
class Stack {

private:
	std::vector<T>	elems;						//	elements

public:

	/*
	Stack(Stack	const&);						//	copy	constructor
	Stack& operator=	(Stack	const&);		//	assignment	operator
	*/

	void	push(T	const& elem);				//	push	element	
	void	pop();								//	pop	element

	T const& top() const;						//	return	top	element

	bool empty() const {						//	return	whether	the	stack	is	empty	
		return	elems.empty();
	};

	void printOn(std::ostream& strm) const {
		for (T const& elem : elems) {
			strm << elem << ' ';				//	call <<	for	each	element
		}
	};
	
	//	adding support for <<. this is a non member function
	friend	std::ostream& operator<< (std::ostream& strm,
		Stack<T> const& s) {
		s.printOn(strm);
		return	strm;
	}
};

template<class T>
inline void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);					//	append	copy	of	passed	elem
}

template<class T>
inline void Stack<T>::pop()
{
	assert(!elems.empty());
	T	elem = elems.back();				//	save	copy	of	last	element
	elems.pop_back();						//	remove	last	element	
	return	elem;							//	return	copy	of	saved	element
}

template<class T>
inline T const& Stack<T>::top() const
{
	assert(!elems.empty());
	return	elems.back();					//	return	copy	of	last	element
}

// this is a specialization for the string class (because it is defined as template<>)
// specialization is similar to overloading
template<>
class Stack<std::string> {
private:
	std::deque<std::string>	elems;			//	elements

public:
	void	push(std::string	const&);	//	push element	
	void	pop();							//	pop	element
	std::string	const& top()	const;		//	return	top	element	
	
	bool	empty()	const {					//	return whether the stack is	empty	
		return	elems.empty();
	}

	void printOn(std::ostream& strm) const {
		for (std::string const& elem : elems) {
			strm << elem << ' ';			//	call <<	for	each element
		}
	};

	//	adding support for <<. this is a non member function
	friend	std::ostream& operator<< (std::ostream& strm,
		Stack<std::string> const& s) {
		s.printOn(strm);
		return	strm;
	}
};

void Stack<std::string>::push(std::string	const& elem)
{
	elems.push_back(elem);					//	append	copy	of	passed	elem
}
void Stack<std::string>::pop()
{
	assert(!elems.empty());
	elems.pop_back();						//	remove	last	element
}
std::string	const& Stack<std::string>::top()	const
{
	assert(!elems.empty());
	return	elems.back();					//	return	copy	of	last	element
}


//	partial	specialization of class Stack<> for use with pointers
template<typename T>
class	Stack<T*> {
private:
	std::vector<T*>	elems;					//	elements
public:
	void	push(T*);						//	push	element
	T*		pop();							//	pop	element
	T*		top()	const;					//	return	top	element	
	bool	empty()	const {					//	return	whether	the	stack	is	empty	
		return	elems.empty();
	}
};

template<typename T>
void Stack<T*>::push(T* elem)
{
	elems.push_back(elem);					//	append	copy	of	passed	elem
}

template<typename T>
T* Stack<T*>::pop()
{
	assert(!elems.empty());
	T* p = elems.back();
	elems.pop_back();						//	remove	last	element	
	return	p;								//	and	return	it	(unlike	in	the	general	case)
}

template<typename T>
T* Stack<T*>::top()	const
{
	assert(!elems.empty());
	return	elems.back();					//	return	copy	of	last	element
}



// a new implementation of Stack which has 2 template parameters, with a default argument for the container which is to manage the elements
template<typename T, typename Cont = std::vector<T>>
class Stack2 {
private:
	Cont	elems;							//	elements
public:
	void		push(T	const& elem);		//	push	element	
	void		pop();						//	pop	element
	T const&	top()	const;				//	return	top	element	
	bool		empty()	const {				//	return	whether	the	stack	is	empty
		return	elems.empty();
	}
};

template<typename T, typename Cont>
void Stack2<T, Cont>::push(T const& elem)
{
	elems.push_back(elem);					//	append	copy	of	passed	elem}
}

template<typename T, typename Cont>
void Stack2<T, Cont>::pop()
{
	assert(!elems.empty());
	elems.pop_back();						//	remove	last	element
}

template<typename T, typename	Cont>
T	const& Stack2<T, Cont>::top()	const
{
	assert(!elems.empty());
	return elems.back();					//	return	copy	of	last	element
}


// these are alias declarations - they are equivalent
typedef Stack2<int> intStackAlias;
using intStackAlias2 = Stack2<int>;			// C++ 11 onwards

