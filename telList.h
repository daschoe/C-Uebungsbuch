//
// Created by daschoe on 10/6/26.
//
// telList.h
// Eine Klasse TelList zur Darstellung einer
// Liste mit Namen und Telefonnummern.
// ----------------------------------------------------
#ifndef TELLIST_H
#define TELLIST_H
#include <string>
using namespace std;
#define PSEUDO -1 // Pseudoposition
#define MAXTEL 100 // Maximale Anzahl Elemente
// Typ eines Listen-Elements:
struct Element { string name, telNr; };
class TelList
{
private:
    Element v[MAXTEL]; // Der Vektor und die
    int count; // aktuelle Anzahl Elemente
public:
    TelList(){ count = 0;}
    int getCount()const { return count; }
    Element *retrieve( int i )
    {
        return (i >= 0 && i < count)? &v[i] : NULL;
    }
    bool append( const Element& el )
    {
        return append( el.name, el.telNr);
    }
    bool append( const string& name, const string& telNr);
    bool erase( const string& name);
    int search( const string& name)const;
    void print()const;
    int print( const string& name)const;
    int getNewEntries();
};
#endif // TELLIST_H