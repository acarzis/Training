#pragma once

// example taken from 'C++ Templates The Complete Guide 2ed', by David Vandevoorde et al.
// It should be noted that C++ already has a stack implementation in <stack>.

#include <vector>
#include <iostream>


template<class T>
class Stack {

private:
	std::vector<T>	elems;	//	elements

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
	elems.push_back(elem);	//	append	copy	of	passed	elem
}

template<class T>
inline void Stack<T>::pop()
{
	assert(!elems.empty());
	T	elem = elems.back();	//	save	copy	of	last	element
	elems.pop_back();	//	remove	last	element	
	return	elem;	//	return	copy	of	saved	element
}

template<class T>
inline T const& Stack<T>::top() const
{
	assert(!elems.empty());
	return	elems.back();	//	return	copy	of	last	element
}




// this is a specialization for the string class 
template<>
class Stack<std::string> {
private:
	std::deque<std::string>	elems;	//	elements

public:
	void	push(std::string	const&);	//	push element	
	void	pop();	//	pop	element
	std::string	const& top()	const;		//	return	top	element	
	
	bool	empty()	const {					//	return whether the stack is	empty	
		return	elems.empty();
	}

	void printOn(std::ostream& strm) const {
		for (std::string const& elem : elems) {
			strm << elem << ' ';				//	call <<	for	each element
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
	elems.push_back(elem);	//	append	copy	of	passed	elem
}
void Stack<std::string>::pop()
{
	assert(!elems.empty());
	elems.pop_back();	//	remove	last	element
}
std::string	const& Stack<std::string>::top()	const
{
	assert(!elems.empty());
	return	elems.back();	//	return	copy	of	last	element
}
