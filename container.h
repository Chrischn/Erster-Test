#ifndef CONTAINER_H
#define CONTAINER_H

#include "header.h"
#include <iostream>
#include <string>
using namespace std;

struct Knoten
{
	Medium* obj_adr;
	Knoten* next;
};

class Container														//Klasse Container
{
public:
	Knoten* erstes_element;
	Knoten* aktuelles_element;
	Knoten* tmp_element;

	Container();
	bool add(Medium*);
	bool remove(int);
	void begin();
	void next();
	Knoten* getitem();


};
#endif	/*CONTAINER_H*/