//
// Created by daschoe on 10/6/26.
//

#include "telList.h"

#include <iostream>

bool TelList::append(const string &name, const string &telNr) {
    if (name.empty() || search(name)>PSEUDO) // Name leer oder schon vorhanden
        return false;
    v[count++] = Element(name, telNr);
    cout<<"Eintrag hinzugefügt"<<endl;
    return true;
}

bool TelList::erase(const string &name) {
    int position = search(name);
    if (position == PSEUDO)
        return false;
    v[position] = v[count-1];
    count--;
    cout<<"Eintrag gelöscht"<<endl;
    return true;
}

int TelList::search(const string &name) const {
    int position = PSEUDO;
    for (int i=0;i<count;i++) {
        if (v[i].name == name) {
            position = i;
        }
    }
    return position;
}

void TelList::print() const {
    for (int i=0;i<count;i++) {
        cout<<v[i].name<<"\t\t -\t\t"<<v[i].telNr<<endl;
    }
}

int TelList::print(const string &name) const {
    int found = PSEUDO;
    for (int i=0;i<count;i++) {
        if (v[i].name.compare(0,name.length(),name) == 0) {
            cout<<v[i].name<<"\t\t -\t\t"<<v[i].telNr<<endl;
            found = i;
        }
    }
    return found;
}

int TelList::getNewEntries() {
    while (true) {
        string name, nummer;
        cout<<"Geben Sie den Namen ein."<<endl;
        getline(cin, name);
        cout<<"Geben Sie die Telefonnummer ein."<<endl;
        getline(cin, nummer);
        if (name.empty())
            return 0;
        append(name, nummer);
    }
}
