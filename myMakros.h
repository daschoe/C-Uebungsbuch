//
// Created by bo on 9/23/26.
//
/*
#ifndef ÜBUNGSBUCH_MYMAKROS_H
#define ÜBUNGSBUCH_MYMAKROS_H

#define ABS(x) ((x)<0?-(x):(x))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

#define CLS (std::cout << "\033[2J")
#define LOCATE(z,s) (std::cout <<"\033["<< (z) <<';'<< (s) <<'H')

#define SCHWARZ 0
#define ROT 1
#define GRUEN 2
#define GELB 3
#define BLAU 4
#define MAGENTA 5
#define CYAN 6
#define WEISS 7
#define FARBE(v,h) (std::cout << "\033[1;3"<<(v)<<';4'<<(h)<<'m'<<flush)

#define NORMAL (std::cout << "\033[0m")
#define INVERS (cout << "\033[7m")

#endif //ÜBUNGSBUCH_MYMAKROS_H
*/

// -------------------------------------------------------
// myMakros.h
// Header-Datei mit den Makros
// ABS, MIN, MAX, CLS, LOCATE, FARBE, NORMAL, INVERS
// und symbolische Konstane für Farben.
// -------------------------------------------------------
// Version für Windows (d.h, falls _WIN32 definiert ist)
// ==> Verwendet die Quelldateien console.h und console.cpp
// Die Quelldatei console.cpp im Projekt aufnehmen!
// -------------------------------------------------------
// In allen anderen Fällen (z.B. Linux)
// ==> Verwendet die ANSI-Bildschirmsteuerzeichen.
// -------------------------------------------------------
#ifndef MYMAKROS_H
#define MYMAKROS_H
// -------------------------------------------------------
// Makro ABS
// Aufruf: ABS( wert)
// Liefert den Absolutwert von wert
#define ABS(a) ( (a) >= 0 ? (a) : -(a))
// -------------------------------------------------------
// Makro MIN
// Aufruf: MIN(x,y)
// Liefert das Minimum von x und y
#define MIN(a,b) ( (a) <= (b) ? (a) : (b))
// -------------------------------------------------------
// Makro MAX
// Aufruf: MAX(x,y)
// Liefert das Maximum von x und y
#define MAX(a,b) ( (a) >= (b) ? (a) : (b))

#ifdef _WIN32
#include "..\..\console\console.h" // Win32
// Konsolenfunktionen
// -------------------------------------------------------
// Makros zur Steuerung des Bildschirms
// -------------------------------------------------------
// Makro CLS
// Aufruf: CLS;
// Löscht den Bildschirm
#define CLS cls() // Bildschirm löschen
// -------------------------------------------------------
// Makro LOCATE
// Aufruf: LOCATE(zeile, spalte);
// Setzt den Cursor auf die Position (zeile,spalte).
// (1,1) ist linke obere Ecke.
#define LOCATE(z,s) setCursor(z-1,s-1)
// -------------------------------------------------------
// Makro FARBE
// Aufruf: FARBE(vordergrund, hintergrund);
// Setzt die Vordergrundfarbe v und Hintergrundfarbe h
// für nachfolgende Ausgaben.
#define FARBE(v,h) setColor(v|(h<<4)|FOREGROUND_INTENSITY)
// Farbwerte für das Makro FARBE
// Beispielaufruf: FARBE( WEISS,BLAU);
#define SCHWARZ 0
#define BLAU 1
#define GRUEN 2
#define ROT 4
#define CYAN 3
#define MAGENTA 5
#define GELB 6
#define WEISS 7
// -------------------------------------------------------
// Makro NORMAL
// Aufruf: NORMAL;
// Setzt die Bildschirmattribute auf die Standardwerte.
#define NORMAL setColor( FOREGROUND_WHITE)
// -------------------------------------------------------
// Makro INVERS
// Aufruf: INVERS;
// Die nachfolgende Ausgabe wird invers dargestellt.
#define INVERS setColor( BACKGROUND_WHITE)
#else // _WIN32 nicht definiert.
#include <iostream>
// -------------------------------------------------------
// Makros zur Steuerung des Bildschirms
// -------------------------------------------------------
// Makro CLS
// Aufruf: CLS;
// Löscht den Bildschirm
#define CLS (std::cout << "\033[2J")
// -------------------------------------------------------
// Makro LOCATE
// Aufruf: LOCATE(zeile, spalte);
// Setzt den Cursor auf die Position (zeile,spalte).
// (1,1) ist linke obere Ecke.
#define LOCATE(z,s) (std::cout <<"\033["<< (z) << ';' \
<< (s) << 'H')
// -------------------------------------------------------
// Makro FARBE
// Aufruf: FARBE(vordergrund, hintergrund);
// Setzt die Vordergrund- und Hintergrundfarbe für
// nachfolgende Ausgaben.
#define FARBE(v,h) (std::cout << "\033[1;3"<< (v) \
<<";4"<< (h) <<'m' << flush)
// 1: Vordergrund hell
// 3x: Vordergrundfarbe x
// 4x: Hintergrundfarbe x
// Farbwerte für das Makro FARBE
// Beispielaufruf: FARBE( WEISS,BLAU);
#define SCHWARZ 0
#define ROT 1
#define GRUEN 2
#define GELB 3
#define BLAU 4
#define MAGENTA 5
#define CYAN 6
#define WEISS 7
// -------------------------------------------------------
// Makro NORMAL
// Aufruf: NORMAL;
// Setzt die Bildschirmattribute auf die Standardwerte.
#define NORMAL (std::cout << "\033[0m")
// -------------------------------------------------------
// Makro INVERS
// Aufruf: INVERS;
// Die nachfolgende Ausgabe wird invers dargestellt.
#define INVERS (cout << "\033[7m")
#endif // _WIN32
#endif // MYMAKROS_H