/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef GLOBAL_H_
#define GLOBAL_H_

/*
 * A macro to disallow the copy constructor and operator= functions
 * This should be used in the private: declarations for a class
 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&);         \
	void operator=(const TypeName&)

/*
 * A macro to disallow all the implicit constructors, namely the
 * default constructor, copy constructor and operator= functions.
 *
 * This should be used in the private: declarations for a class
 * that wants to prevent anyone from instantiating it. This is
 * especially useful for classes containing only static methods.
 */
#define DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
	TypeName();                              \
	DISALLOW_COPY_AND_ASSIGN(TypeName)


#endif  // GLOBAL_H_
