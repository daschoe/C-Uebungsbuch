//
// Created by daschoe on 9/30/26.
//
// Passw1.cpp
// Die Funktionen getPassword() und zeitdiff()
// zum Einlesen und Überprüfen eines Passworts.
// -----------------------------------------------------
#include <climits>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;
static long zeitdiff(void); // Prototyp
static bool changePassword(); //Prototyp
static string geheimwort = "ISUS"; // Passwort
static long maxanzahl = 3, maxzeit = 60; // Limits

static bool getPassword() // Passwort einlesen und überprüfen.
{ // Return-Wert: true, falls Passwort ok.
    bool ok_flag = false; // Für die Rückgabe
    string wort; // Für die Eingabe
    int anzahl = 0, zeit = 0;
    zeitdiff(); // Die Stoppuhr starten
    while( ok_flag != true &&
    ++anzahl <= maxanzahl) // Anzahl Versuche
    {
        cout << "\n\nGeben Sie das Passwort ein: ";
        cin >> setw(20) >> wort;
        cin.ignore(LLONG_MAX,'\n'); // Rest der Zeile löschen
        zeit += zeitdiff();
        if( zeit >= maxzeit ) // Im Zeitlimit?
            break; // nein!
        if( wort != geheimwort)
            cout << "Passwort ungültig!" << endl;
        else
            ok_flag = true; // Erlaubnis geben
    }
    return ok_flag; // Ergebnis
}

static long zeitdiff() // Liefert die Anzahl Sekunden
{ // seit dem letzten Aufruf.
    static time_t sek = 0; // Zeit vom letzten Aufruf.
    time_t altsek = sek; // Alte Zeit merken.
    time( &sek); // Neue Zeit lesen.
    return long(sek - altsek); // Differenz zurückgeben.
}

static void changePasswortRequest() {
    string response;
    cout << "Wollen Sie Ihr Passwort jetzt ändern?\n[J]a, [N]ein"<<endl;
    cin >> response;
    if (response == "J" || response=="Ja")
        if (changePassword())
            cout<<"Das Passwort wurde erfolgreich geändert."<<endl;
        else
            cout << "Passwortänderung fehlgeschlagen!" <<endl;
    else if (!(response == "N" || response == "Nein"))
        changePasswortRequest();

}

static bool changePassword() {
    cout << "Geben Sie ein neues Passwort ein."<<endl;
    string new_pw, new_pw_repeat;
    cin>>new_pw;
    cout << "Bitte wiederholen Sie das neue Passwort."<<endl;
    cin>>new_pw_repeat;
    if (new_pw==new_pw_repeat)
        geheimwort = new_pw;
        cout<<"Passwort erfolgreich geändert!"<<endl;
        return true;
    cout << "Fehler: Die Passwörter sind nicht gleich."<<endl;
    return false;
}
