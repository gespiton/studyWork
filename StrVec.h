/*
 * StrVec.h
 *
 *  Created on: 2016-4-13
 *      Author: sher
 */

#ifndef STRVEC_H_
#define STRVEC_H_
#include<iostream>
#include<string>
#include<utility>
#include<memory>
#include<list>
using std::list;
using std::string;
using std::allocator;
using std::pair;
using std::cout;
using std::endl;
class StrVec {
	public:
		StrVec ( ) :
				elements ( 0 ), first_free ( 0 ), cap ( 0 ) {
		}
		StrVec ( std::initializer_list<string> i ) {
			auto size1 = i.size ();
			elements = alloc.allocate ( size1 );
			first_free = cap = uninitialized_copy ( i.begin (), i.end (),
					elements );
		}

		StrVec ( const StrVec& old ) {
			auto p = copy_to ( old );
			elements = p.first;
			cap = first_free = p.second;
			cout<<"copy intialized"<<endl;
		}
		StrVec& operator= ( const StrVec& );
		StrVec(StrVec&&old):elements(old.elements),first_free(old.first_free),cap(old.cap){
			old.elements=old.first_free=old.cap=0;
			cout<<"move intialized"<<endl;
		}
		StrVec& operator=(StrVec&&s){
			if(&s!=this){
				free();
				elements=s.elements,first_free=s.first_free,cap=s.cap;
				s.elements=s.first_free=s.cap=0;
			}
			cout<<"move assignment"<<endl;
			return *this;
		}
		~StrVec ( ) {
			free ();
		}

//		StrVec& StrVec ( const StrVec& );                   make a lot otherthing bad
		unsigned capacity ( ) const{
			return cap - first_free;
		}
		void pushback ( const string&s ) {
			check ();
			alloc.construct ( first_free++, s );
		}
		void pushbake (string&&s){
			check();
			alloc.construct(first_free++,std::move(s));
		}
		void print ( ) const {
			if (elements) {
				for (auto ele = elements; ele != first_free;)
					cout << *ele++ << " ";
			}
		}
		void resize ( unsigned i );
		size_t size ( ) const{
			return first_free - elements;
		}
		void free ( );
		void reserve(unsigned);
	private:
		void check ( );
		pair<string*, string*> copy_to ( const StrVec& );
		string* elements;
		string* first_free;
		string* cap;
		allocator<string> alloc;
		void reallocate ( );
};
StrVec& StrVec::operator = ( const StrVec& str ) {
auto p = copy_to ( str );
free ();
elements = p.first;
cap = first_free = p.second;
return *this;
}
pair<string*, string*> StrVec::copy_to ( const StrVec &str ) {
// why can't i use old.capa
auto ele = alloc.allocate ( str.first_free - str.elements );
return {ele,uninitialized_copy(str.elements,str.first_free,ele)};
}
void StrVec::reallocate ( ) {
auto size = this->size ();
auto ele = alloc.allocate ( elements ?
		int ( 2 * size ) : 1 );
//for (unsigned i = 0; i != size; ++i)
//	alloc.construct ( ele++, std::move ( * ( elements + i ) ) ); // move's parameter is not a pointer
uninitialized_copy(make_move_iterator(elements),make_move_iterator(first_free),ele);
free ();
elements = ele ;
first_free = ele+size;
cap = ele +2* size;
}
void StrVec::free ( ) {
if (elements) {
	for (auto p = elements; p != first_free; ++p) {
		alloc.destroy ( p );
	}
	alloc.deallocate ( elements, cap - elements );
}
}
void StrVec::resize ( unsigned size ) {
auto ele = alloc.allocate ( size );
auto beg = ele;
if (size > this->size ()) {
	for (unsigned i = 0; i != this->size (); ++i)
		alloc.construct ( ele++, std::move ( * ( elements + i ) ) );
	for (unsigned i = this->size (); i != size; ++i) {
		alloc.construct ( ele++, "" );
	}
} else if (size < this->size ()) {
	for (unsigned i = 0; i <= size; ++i)
		alloc.construct ( ele++, std::move ( * ( elements + i ) ) );
} else
	return;
free ();
elements = beg;
cap = first_free = ele;
}
void StrVec::check ( ) {
if (cap == first_free)
	reallocate ();
}
void StrVec::reserve(unsigned size){
	auto ele = alloc.allocate (cap-elements+size);
	for (unsigned i = 0; i !=this->size(); ++i)
		alloc.construct ( ele++, std::move ( * ( elements + i ) ) ); // move's parameter is not a pointer
	free ();
	elements = ele - this->size();
	first_free = ele;
	cap = ele + size;
}
#endif /* STRVEC_H_ */
