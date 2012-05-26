#include "container.h"
#include <string>
using namespace std;


Container::Container()
{
	erstes_element = NULL;
	aktuelles_element = NULL;
	tmp_element = NULL;
};

bool Container::add(Medium* T)
{
		if(NULL == erstes_element)
		{
			aktuelles_element = new Knoten;
			aktuelles_element->obj_adr = T;
			aktuelles_element->next = 0;
			erstes_element = aktuelles_element;
			return 1;
		}
		else
		{
			aktuelles_element = erstes_element;
			while(aktuelles_element->next != NULL)
			{
				aktuelles_element = aktuelles_element->next;
			}
			Knoten* neues_Element = new Knoten;
			neues_Element->obj_adr = T;
			neues_Element->next = NULL;
			aktuelles_element->next = neues_Element;
			aktuelles_element = neues_Element;
			return 1;
		}
	return 0;
};

bool Container::remove(int s)
{
	int _signatur = s;
	short x = 0;
	tmp_element = erstes_element;

	if(aktuelles_element == tmp_element){aktuelles_element = NULL;}

	while(tmp_element != NULL)
	{
		if(tmp_element->obj_adr->sigi(_signatur))
		{
			if(erstes_element == tmp_element && erstes_element->next == NULL){x = 1;}		//Erstes Element ohne Nachfolger aka nur ein Medium vorhanden

			else if(erstes_element == tmp_element && tmp_element->next != NULL){x = 2;}		//Erstes Element MIT NACHFOLGER

			else if(tmp_element != erstes_element && tmp_element->next == NULL){x = 3;}		//Letztes Element in der Liste ohne Nachfolger

			else {x = 0;}																	//NICHT erstes Element und MIT NACHFOLGER aka mitten drin													
	
			Knoten* _tmp_element_zwei = erstes_element;

			switch(x)
			{
////------------------------------------------------------------------------------------------------------------------------------------
				case 1:	
				erstes_element = NULL;
				aktuelles_element = NULL;
				break;
////------------------------------------------------------------------------------------------------------------------------------------
				case 2:
				erstes_element = tmp_element->next;
				aktuelles_element = erstes_element;
				break;
////------------------------------------------------------------------------------------------------------------------------------------
				case 3:
				while(_tmp_element_zwei->next != tmp_element)
				{
					_tmp_element_zwei = _tmp_element_zwei->next;
				}
				_tmp_element_zwei->next = NULL;
				break;
////------------------------------------------------------------------------------------------------------------------------------------
				default:
				while(_tmp_element_zwei->next != tmp_element)
				{
					_tmp_element_zwei = _tmp_element_zwei->next;
				}
				_tmp_element_zwei->next = tmp_element->next;
				break;
////------------------------------------------------------------------------------------------------------------------------------------
			}
			delete tmp_element->obj_adr;
			delete tmp_element;
			tmp_element = NULL;
			return 1;
		}
		else
		{
			tmp_element = tmp_element->next;
		}
	}
	tmp_element = NULL;
	return 0;
};

void Container::begin()
{
	aktuelles_element = erstes_element;
};

void Container::next()
{
};

Knoten* Container::getitem()
{
	return aktuelles_element;
};