#include <climits>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <ctime>
#include "myMakros.h"
#include "summe.h"
#include "Passw2.cpp"
#include "Datum.h"
#include "Artikel.h"

using namespace std;


static void kapitel1_aufgabe1() {
    cout << "Moegen" << endl;
    cout << "taeten wir schon wollen," << endl;
    cout << "aber koennen" << endl;
    cout << "haben wir uns nicht getraut!" << endl;
}

static int kapitel1_aufgabe2() {
    cout << "Wenn dieser Text",
    cout << " auf Ihrem Bildschirm erscheint, ";
    cout << "können Sie sich auf die Schulter "
    << "klopfen!" << endl;
    return 0;
}

static void kapitel2_aufgabe1() {
    cout << "char " << sizeof(char) << endl;
    cout << "char16_t " << sizeof(char16_t) << endl;
    cout << "char32_t " << sizeof(char32_t) << endl;
    cout << "wchar_t " << sizeof(wchar_t) << endl;

    cout << "short " << sizeof(short) << endl;
    cout << "int " << sizeof(int) << endl;
    cout << "long " << sizeof(long) << endl;
    cout << "long long " << sizeof(long long) << endl;

    cout << "float " << sizeof(float) << endl;
    cout << "double " << sizeof(double) << endl;
    cout << "long double " << sizeof(long double) << endl;
}

static void kapitel2_aufgabe2() {
    cout << "\tICH" << endl;
    cout << "\t\t\"SAUSE\"" << endl;
    cout << "\t\t\t\\HIN\\" << endl;
    cout << "\t\tUND" << endl;
    cout << "\t/HER/" << endl;
}

static void kapitel2_aufgabe4() {
    constexpr float zahl1 = 123.456;
    constexpr float zahl2 = 76.543;
    cout << "Summe:"<< zahl1 + zahl2 << endl;
    cout << "Differenz:"<< zahl1 - zahl2 << endl;
}

static void kapitel3_aufgabe1() {
    cout << "ZAHL\tWURZEL" << endl;
    cout << 4 << "\t\t" << sqrt(4) << endl;
    cout << 12.25 << "\t" << sqrt(12.25) << endl;
    cout << 0.0121 << "\t" << sqrt(0.0121) << endl;
    double eigene_Zahl;
    cout << "Wurzel von :"<< endl;
    cin >> eigene_Zahl;
    cout << "ZAHL\tWURZEL" << endl;
    cout << eigene_Zahl << "\t\t" << sqrt(eigene_Zahl) << endl;
}

static int kapitel3_aufgabe2() {
    const string meldung = "\nAus Fehlern wird man klug!";
    cout << meldung << endl;
    const int len = meldung.size();
    cout << "Die Laenge des Strings: " << len << endl;
    // Und noch eine Zufallszahl:
    int a, b;
    srand(12.5);
    b = rand();
    cout << "\nZufallszahl: " << b << endl;
    return 0;
}

static void kapitel3_aufgabe3() {
    string ersterString = "Schon wieder was dazugelernt!";
    cout << ersterString << " hat eine Länge von " << ersterString.length() << " Zeichen!" << endl;
    string teil1, teil2;
    cout << "Gib eine Zeile ein" << endl;
    cin >> teil1;
    cout << "Gib noch eine Zeile ein" << endl;
    cin >> teil2;
    cout << teil1 + " * " + teil2 << endl;
}

static void kapitel4_aufgabe2() {
    cout << setw(15) << left << 0.123456 << endl;
    cout << fixed << setw(12) << right << setprecision(2) << 23.987 << endl;
    cout << scientific << setw(10) << setprecision(4) << -123.456 << endl;
}

static void kapitel4_aufgabe3() {
    int artikelnummer, stueckzahl;
    double preis;
    cout << "Geben Sie eine Artikelnummer ein:\n";
    cin >> artikelnummer;
    cout << "Geben Sie eine Stückzahl ein:\n";
    cin >> stueckzahl;
    cout << "Geben Sie einen Stückpreis ein:\n";
    cin >> preis;
    cout << "Artikelnummer\tStückzahl\tStückpreis\n";
    cout << setw(13) << artikelnummer << "\t" << setw(9) << stueckzahl << "\t" << setw(10) << fixed << setprecision(2)  << preis << "EURO" << endl;
}

static void kapitel4_aufgabe4() {
    int zahl;
    cout << "Geben Sie eine positive ganze Zahl ein!:\n";
    cin >> zahl;
    cout << char(zahl) << " " << dec << zahl << " " << oct << zahl << " " << hex << zahl << endl;
}

static void kapitel4_aufgabe5() {
    string wort;
    cout << "Los geht's mit der Return-Taste: ";
    cin.get();
    cout << "Geben Sie ein Wort mit höchstens drei Zeichen ein: ";
    cin >> setw(3) >> wort;
    cout << "Ihre Eingabe: " << wort << endl;
}

static void kapitel6_aufgabe1() {
    long euro, maxEuro; // Euro-Beträge
    double kurs; // Euro/$-Kurs
    cout << "\n* * * KURSTABELLE Euro – US-$ * * *\n\n";
    cout << "\nBitte den Preis von einem Euro in US-$"
    " eingeben: ";
    cin >> kurs;
    cout << "\nBitte die Obergrenze für Euro eingeben: ";
    cin >> maxEuro;
    // --- Ausgabe der Tabelle ---
    // Spaltenüberschriften:
    cout << '\n'
    << setw(12) << "Euro" << setw(20) << "US-$"
    << "\t\tKurs: " << kurs << endl;
    // Ausgabeformat für $:
    cout << fixed << setprecision(2) << endl;
    long lower = 1, upper, // Unter-/Obergrenze
    step = 1; // Schrittweite
    // Die äußere Schleife bestimmt die aktuelle
    // Untergrenze und die Schrittweite:
    while (lower <= maxEuro) {
        // Die innere Schleife gibt einen "Block" aus:
        euro = lower;
        upper = 10 * step;
        while (euro <= upper && euro <= maxEuro) {
            cout << setw(12) << euro << setw(20) << euro*kurs << endl;
            euro += step;
        }
        step *=10;
        lower = 2*step;
    }
}

static void kapitel6_aufgabe2() {
    cout << setw(55) << internal << "******\tDAS KLEINE EINMALEINS\t******" << endl;
    cout << setw(5) << " ";
    for (int i =1; i<=10; i++) {
        cout << setw(5) << i;
    }
    cout << endl;
    cout << setw(5) << " "<<cout.fill('_') << setw(50) << "_"<< endl;
    cout.fill(' ');
    for (int i =1; i<=10; i++) {
        cout << setw(5) << i<< "|";
        for (int j =1; j<=10; j++) {
            cout << setw(5) << j*i;
            if (j==10) cout << endl;
        }
    }
}

static void kapitel6_aufgabe3() {
    int zahl;
    cout << "Geben Sie eine Zahl zwischen 0 und 65535 ein."<< endl;
    cin >> zahl;
    srand(zahl);
    for (int i =1; i<=20; i++) {
        cout << rand()%100+1 << endl;
    }
}

static void kapitel6_aufgabe4() {
    time_t sek;
    time( &sek ); // Anzahl Sekunden holen und
    srand( (unsigned)sek ); // zur Initialisierung verwenden

    int zufallszahl = rand()%15+1;
    int guess;
    char continueQuit;
    for (int i =1; i<=3; i++) {
        cout << i << ". Versuch" << endl;
        cin >> guess;
        if (guess == zufallszahl) {
            cout << "Die Zahl wurde erraten!!!" << endl;
            break;
        }
        else if (guess > zufallszahl) {
            cout << "Die gesuchte Zahl ist kleiner." << endl;
        }
        else if (guess < zufallszahl) {
            cout << "Die gesuchte Zahl ist größer." << endl;
        }
    }
    cout << "Die gesuchte Zahl war " << zufallszahl <<"."<< endl;

    cout << "Nuer Versuch? (y|n)" << endl;
    cin >> continueQuit;
    if (continueQuit == 'y') {
        kapitel6_aufgabe4();
    }
}

static void kapitel7_aufgabe1() {
    FARBE( WEISS, BLAU);
    //CLS;
    INVERS;
    LOCATE(8,20);
    cout << "\aHallo!" << endl;
    FARBE( WEISS, BLAU);
    LOCATE(12,1);
    cout << "Makros ABS(a), MIN(a,b) und MAX(a,b) testen!\n"
    << "Geben Sie zwei ganzzahlige Testwerte ein: ";
    long a=0, b=0;
    cin >> a >> b;
    FARBE( GELB, SCHWARZ);
    cout << "Absolutwert von " << a << " : "
    << ABS(a) << endl;
    cout << "Minimum von " << a << " und " << b << " : "
    << MIN(a,b) << endl;
    cout << "Maximum von " << a << " und " << b << " : "
    << MAX(a,b) << endl;
    LOCATE(24,1);
    NORMAL;
}

static void kapitel7_aufgabe2() {
    int start_x = 10, end_x=10+64;
    string title = "------- Die Sinus Kurve -------";
    float step = 2*M_PI/64;
    CLS;
    LOCATE(0,(int)((end_x+4)/2-(title.length()/2)));
    cout << title;
    // Y-Achse
    for (int y=2;y<21;y++) {
        LOCATE(y, start_x);
        if (y == 2) {
            cout << "\136 sin(x)";
        }
        else if (y % 2 == 0) {
            cout << '+';
            if (y == 4)
                cout << " 1";
            else if (y == 20)
                cout << " -1";
        }
        else if (y % 2 == 1) {
            cout << '|';
        }
    }

    // X-Achse
    for (int x=0;x<end_x+5;x++) {
        LOCATE(12,x);
        if (x%8-1 ==1)
            cout << '+';
        else if (x == 78)
            cout << '>';
        else
            cout << '-';
    }
    LOCATE(11,end_x-1);
    cout << "2PI  x";

    // Funktion
    for (int i=start_x; i<=end_x; i++) {
        int spalte = i;
        int zeile = (int)(sin((i-start_x)*step)*-8+0.5);
        LOCATE(12+zeile, spalte);
        cout << "*";
    }
    LOCATE(22,0);
}

static void loesung_7_2() {
    #define PI 3.1415926536
    #define START 0.0 // Untergrenze
    #define ENDE (2.0 * PI) // Obergrenze
    #define PKT 64 // Anzahl Punkte der Kurve
    #define SCHRITT ((ENDE-START)/PKT)
    #define xA 14 // Zeile für x-Achse
    #define yA 10 // Spalte für y-Achse
    int zeile, spalte;
    CLS;
    LOCATE(2,25);
    cout << "------- Die Sinus-Kurve -------";
    // --- Koordinaten-Kreuz zeichnen: ---
    LOCATE(xA,1); // x-Achse
    for( spalte = 1 ; spalte < 78 ; ++spalte)
    {
        cout << ((spalte - yA) % 8 ? '-' : '+');
    }
    cout << '>'; // Spitze
    LOCATE(xA-1, yA+64); cout << "2PI x";
    for( zeile = 5 ; zeile < 22 ; zeile +=2) // y-Achse
    {
        LOCATE(zeile, yA); cout << '|';
        LOCATE(zeile+1, yA); cout << '+';
    }
    LOCATE( 4, yA); cout << "\136 sin(x)"; // Spitze
    LOCATE( xA-8, yA+1); cout << " 1";
    LOCATE( xA+8, yA+1); cout << " -1";
    // --- Sinus-Kurve ausgeben: ---
    int anfsp = yA,
    endsp = anfsp + PKT;
    for( spalte = anfsp; spalte <= endsp; ++spalte)
    {
        double x = double(spalte-yA) * SCHRITT;
        zeile = (int)(xA - 8 * sin(x) + 0.5);
        LOCATE( zeile, spalte); cout << '*';
    }
    LOCATE(23,1); // Cursor unter die Kurve setzen.
}

static void kapitel7_aufgabe3() {  // TODO
    char c;
    char prev;
    int numSteuer=0;
    while (cin.get(c)) {
        if (c>=0 && c<=31 && c!='\n' && c!='\t') { //Es ist ein zu löschendes Steuerzeichen
            numSteuer++;
            prev = c;
        }
        else {
            if (numSteuer>1)
                cout << " ";
            cout << c;
            prev = c;
            numSteuer = 0;
        }

    }
}

static void kapitel8_aufgabe1() {
    string s1 = "Alle Jahre kommt ...";
    string s2 = "wieder.";
    cout << s1 << endl;
    s1.insert(s1.find("kommt"), s2);
    cout << s1 << endl;
    s1.erase(s1.find("kommt"));
    cout << s1 << endl;
    s1.replace(s1.find("Jahre"), 5, "kommen");
    cout << s1 << endl;
}

static void kapitel8_aufgabe2() {
    string palindrom;
    do {
        bool same = true;
        cout << "Wort eingeben oder q zum abbrechen"<< endl;
        cin >> palindrom;
        if (palindrom.length()>1) {
            for (int x=0;x<(int)(palindrom.length()/2+0.5);x++) {
                if (palindrom[x]!=palindrom[palindrom.length()-x-1]) {
                    cout << palindrom << " ist kein Palindrom" << endl;
                    same = false;
                    break;
                }
            }
            if (same) {
                cout << palindrom << " ist ein Palindrom" << endl;
            }
        }

    } while (palindrom != "q");

}

static void kapitel9_aufgabe1() {
    srand(1);
    int a = rand();
    int b = rand();
    int c = rand();
    int d = rand();
    cout << "Die Summe von " << a << ", "<< b << ", " << c << ", " << d << " ist "<< summe(a,b,c,d) << endl;
    cout << "Die Summe von " << a << ", "<< b << ", " << c << " ist "<< summe(a,b,c) << endl;
    cout << "Die Summe von " << a << ", "<< b << " ist "<< summe(a,b) << endl;
}

// Für Aufgabe 2, Kapitel 9
inline double Max(double x, double y) { return x>y ? x : y; }
inline char Max(char x, char y) { return x>y ? x : y; }

static void kapitel9_aufgabe2() {
    cout << Max(0.9, 0.2) << endl;
    cout << Max('a', 'b') << endl;
    //cout << Max(40, 99) << endl; // Funktioniert nicht, wenn es überladene Funktionen gibt!

}

static long fakultaet_schleife(int n) {
    long ergebnis = 1;
    for (int i = 1; i <= n; i++) {
        ergebnis *= i;
    }
    return ergebnis;
}

static long fakultaet_rekursiv (int n) {
    if (n==0)
        return 1;
    return fakultaet_schleife(n-1)*n;
}

static void kapitel9_aufgabe3() {
    cout << setw(4) << "n" << " | " << "Fakultät von n Schleife" << " | " << "Fakultät von n rekursiv" << endl;
    cout << string((4+3+23+3+23), '-') << endl;
    for (int i = 0; i <= 20; i++) {
        cout << setw(4) << i << " | " << setw(23) << fakultaet_schleife(i) << " | " << setw(23) << fakultaet_rekursiv(i) << endl;
    }
}

// Für Aufgabe 4, Kapitel 9
double pow(double basis, int exp) {
    // Sonderfälle
    if (exp==0)
        return 1.0;
    if (basis==0 && exp>0)
        return 0.0;
    if (basis==0 && exp<=0)
        return HUGE_VAL;

    // normales Verhalten
    basis = exp > 0 ? basis : 1.0/basis;
    exp = exp > 0 ? exp : -exp;
    double result = basis;
        for (int i = 1; i < exp; i++) {
            result *= basis;
        }

    return result;
}

static void kapitel9_aufgabe4() {
    cout << 2.5 << " hoch " << 3 << " ist " << pow(2.5, 3)<< endl;
    cout << 2.5 << " hoch " << 0 << " ist " << pow(2.5, 0)<< endl;
    cout << 0 << " hoch " << 3 << " ist " << pow(0.0, 3)<< endl;
    cout << 0 << " hoch " << -3 << " ist " << pow(0.0, -3)<< endl;
    cout << 2 << " hoch " << -2 << " ist " << pow(2.0, -2)<< endl;
}
// Für Aufgabe 2, Kapitel 10
namespace TOOL1 {
        #include "tool1.h"
    }
    namespace TOOL2 {
        #include "tool2.h"
    }
static void kapitel10_aufgabe2() {

    cout << "Tool1 aufgerufen mit (1, 2): " << TOOL1::calculate(1,2) << endl;
    cout << "Tool2 aufgerufen mit (1, 2): " << TOOL2::calculate(1,2) << endl;
}

static void kapitel10_aufgabe4() {
    bool first_start = true;
    int entry;
    do {
        if (!first_start)
            cin.ignore(LLONG_MAX,'\n');
        first_start = false;
        cout << "Willkommen beim Buchungsportal\nWählen Sie 'B' für Buchen oder 'E' für Ende." << endl;
        entry = cin.get();
        if (entry== 'B') {
            cout<<"Bitte geben Sie das Passwort ein, um den Buchungsvorgang zu starten."<<endl;
            if (getPassword())
                changePasswortRequest();
            else
                cout << "Passworteingabe fehlgeschlagen."<<endl;
        }
    } while (entry != 'E');
    cout << "Das Buchungsprogramm wurde beendet. Auf Wiedersehen!"<<endl;
}

// Für Aufgabe 11.2
static void kreis(const double& radius, double& umfang, double& flaeche) {
    static const double pi = 3.1415926536;
    umfang = 2.0*pi*radius;
    flaeche = pi * radius * radius;
}

static void kapitel11_aufgabe2() {
    cout << "Radius | Umfang | Fläche"<<endl;
    cout << string(27,'-')<<endl;
    double umfang, flaeche;
    for (double r=0.5; r<10.5; r+=0.5) {
        kreis(r,umfang,flaeche);
        cout<<setw(6)<<r<<" | "<<setw(6)<<umfang<<" | "<<setw(6)<<flaeche<<endl;
    }
}

// Für Aufgabe 11.3
void swap_ptr(float *p1, float *p2)
{
    float temp; // Hilfsvariable
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void swap_ref(float &p1, float &p2)
{
    float temp; // Hilfsvariable
    temp = p1;
    p1 = p2;
    p2 = temp;
}

static void kapitel11_aufgabe3() {
    float x = 0.5;
    float y = 99.9;
    cout<<"ursprüngliche Werte\nx: "<<x<<", y: "<<y<<endl;
    swap_ptr(&x,&y);
    cout<<"nach \"swap_ptr\"\nx: "<<x<<", y: "<<y<<endl;
    swap_ref(x,y);
    cout<<"nach \"swap_ref\"\nx: "<<x<<", y: "<<y<<endl;
}

// Für 11.4
bool quadGleich(const double& a, const double& b, const double& c, double& x1, double& x2) {
    if ((b*b -4*a*c) >= 0) {
        x1 = (-b+sqrt((b*b-4*a*c)))/(2*a);
        x2 = (-b-sqrt((b*b-4*a*c)))/(2*a);
        return true;
    }
    return false;
}

static void printGleichung(const double a, const double b, const double c) {
    double x1=0,x2=0;
    if (quadGleich(a,b,c,x1,x2)) {
        cout << setw(4)<<a<<" | "<<setw(4)<<b<<" | "<<setw(4)<<c<< " | "<<setw(4)<<x1<<" | "<<setw(4)<<x2<<endl;

    }
    else
        cout << setw(4)<<a<<" | "<<setw(4)<<b<<" | "<<setw(4)<<c<< " | "<<setw(4)<<""<<" | "<<setw(4)<<""<<endl;

}

static void kapitel11_aufgabe4() {

    cout << setw(4)<<"a"<<" | "<<setw(4)<<"b"<<" | "<<setw(4)<<"c"<< " | "<<setw(4)<<"x1"<<" | "<<setw(4)<<"x2"<<endl;
    cout << string(32,'-')<<endl;
    printGleichung(2,-2,-1.5);
    printGleichung(1,-6,9);
    printGleichung(2,0,2);
}

void kapitel12_aufgabe1() {
    Datum datum1, datum2;
    datum1.init();
    datum2.init(23,12,1953);
    datum1.print();
    datum2.print();
}

// Für Kapitel 13 Aufgabe 1
void test() {
    cout<<"test wird aufgerufen..."<<endl;
    static Artikel artikel1(1234567890, "Testobjekt", 12.99);
    Artikel artikel2(9000200931, "Käse", 1.99);
    artikel1.print();
    artikel2.print();
    cout<<"test wird beendet..."<<endl;
}

void test(Artikel art) {
    cout<<"test mit Artikel wird aufgerufen..."<<endl;
    static Artikel artikel1(1234567890, "Testobjekt", 12.99);
    Artikel artikel2(9000200931, "Käse", 1.99);
    artikel1.print();
    artikel2.print();
    cout<<"test mit Artikel wird beendet..."<<endl;
    // Kopiert das übergebene Objekt mit Default-Konstruktor (num_artikel wird nicht inkrementiert)! -> negativer Zähler am Ende
}

//Artikel artikel1(1000000,"erste Sahne",1.99);

void kapitel13_aufgabe1() {
    cout<<"main wird aufgerufen..."<<endl;
    Artikel artikel2(48439458, "Zweite Geige",999.99);
    //artikel1.print();
    artikel2.print();
    //artikel1.setArtikelnummer(11111111);
    //artikel1.setBezeichnung("Veränderungstrank");
    //artikel1.setPreis(-99);
    //artikel1.print();
    test();
    test();
    //test(artikel1);
    cout<<"main wird beendet..."<<endl;
}

void kapitel13_aufgabe2() {
    Datum datum1;
    Datum datum2(23,12,1995);
    datum1.print();
    datum2.print();
    cout<<datum1.asString()<<endl;
    cout<<"Vergleich Equal "<<datum1.isEqual(datum2)<<endl;
    cout<<"Vergleich isLess "<<datum1.isLess(datum2)<<endl;
    datum1.setDatum();
    cout<<"Vergleich Equal "<<datum2.isEqual(datum1)<<endl;
    cout<<"Vergleich isLess "<<datum2.isLess(datum1)<<endl;
    datum2.setDatum(3,10,2026);
    cout<<"Vergleich Equal "<<datum1.isEqual(datum2)<<endl;
    cout<<"Vergleich isLess "<<datum1.isLess(datum2)<<endl;
    cout<<datum1.getTag()<<"."<<datum1.getMonat()<<"."<<datum1.getJahr()<<endl;
    Datum datum3(30,2,1995);
    datum3.print();
    datum3.setDatum(29,2,2024);
    datum3.print();
}

int main() {
    //kapitel1_aufgabe1();
    //kapitel1_aufgabe2();
    //kapitel2_aufgabe1();
    //kapitel2_aufgabe2();
    //kapitel2_aufgabe4();
    //kapitel3_aufgabe1();
    //kapitel3_aufgabe2();
    //kapitel3_aufgabe3();
    //kapitel4_aufgabe2();
    //kapitel4_aufgabe3();
    //kapitel4_aufgabe4();
    //kapitel4_aufgabe5();
    //kapitel6_aufgabe1();
    //kapitel6_aufgabe2();
    //kapitel6_aufgabe3();
    //kapitel6_aufgabe4();
    //kapitel7_aufgabe1();
    //kapitel7_aufgabe2();
    //loesung_7_2();
    //kapitel8_aufgabe1();
    //kapitel8_aufgabe2();
    //kapitel9_aufgabe1();
    //kapitel9_aufgabe2();
    //kapitel9_aufgabe3();
    //kapitel9_aufgabe4();
    //kapitel10_aufgabe2();
    //kapitel10_aufgabe4();
    //kapitel11_aufgabe2();
    //kapitel11_aufgabe3();
    //kapitel11_aufgabe4();
    //kapitel12_aufgabe1();
    //kapitel13_aufgabe1();
    //kapitel13_aufgabe2();
    return 0;
}
