/**
 *	Encoder.cpp
 *	Created on: 19.06.2013
 *	Author: Sascha Hopp
 *	Version: 1.0
 */
#include "Encoder.h"
/**
 * Fehlermeldungen
 */
const char* Encoder::NICHT_OEFFNEN = "Fehler beim oeffnen der zu lesenden Datei";
const char* Encoder::NICHT_SCHREIBEN = "Fehler beim oeffnen der zu beschreibenden Datei";

/*	\brief	Encoder
 *			Oeffnet die Datei und schreibt kodiert Zeichen fuer Zeichen
 *			in eine Neue Datei
 */
Encoder::Encoder(char* readFileName, char *writeFileName) {
	readFile.open(readFileName, ios::in);	//Oeffen der Lese datei
	if (!readFile)
		throw NICHT_OEFFNEN;

	writeFile.open(writeFileName, ios::out);//Oeffnen/Erstellt die zu beschreibende Datei
	if (!writeFile)
		throw NICHT_SCHREIBEN;

	//Kopiert und Kodiert Zeichen fuer Zeichen
	char c;
	while (readFile.get(c)) {
		c = kodierer(c);
		writeFile.put(c);
	}
	readFile.close();
	writeFile.close();
}
/**
 * Destruktor
 */
Encoder::~Encoder() {
}
/**
 *	\brief	grossbuchstaben
 *			Tauscht die Groﬂbuchstaben aus nach der entsprechende Verschiebung
 *
 *	\param	char c	Das Zeichen das kodiert werden soll
 *	\return	char	Das kodierte Zeichen wird zurueckgegeben
 *
 */
char Encoder::grossbuchstaben(char c) {
	if (c < ASCII_ULB + CUT_UPPER) {//Ueberpruefung ob das Zeichen Links des CUTs befindet
		if (c < (ASCII_ULB + SHIFT_UPPER)) {//Ueberpruefung ob das Zeichen am linken Rand innerhalb des SHIFT ist
			return c + (CUT_UPPER - SHIFT_UPPER);
		} else {
			return c - SHIFT_UPPER;	//Verschiebung um den SHIFT wert nach Links
		}
	} else {
		if (c > (ASCII_ULE - SHIFT_UPPER)) {//Ueberpruefung ob das Zeichen am rechten Rand innerhalb des SHIFT ist
			return c - (26 - CUT_UPPER) + SHIFT_UPPER;
		} else {
			return c + SHIFT_UPPER;	//Verschiebung um den SHIFT wert nach Rechts
		}
	}
}
/**
 *	\brief	kleinbuchstaben
 *			Tauscht die Kleinbuchstaben aus nach der entsprechende Verschiebung
 *
 *	\param char c	Das Zeichen das kodiert werden soll
 *	\return	char	Das kodierte Zeichen wird zurueckgegeben
 */
char Encoder::kleinbuchstaben(char c) {
	if (c < (ASCII_LLB + CUT_LOWER)) {//Ueberpruefung ob das Zeichen Links des CUTs befindet
		if (c >= (ASCII_LLB + (CUT_LOWER - SHIFT_LOWER))) {//Ueberpruefung ob das Zeichen am rechten Rand innerhalb des SHIFT ist
			return c - (CUT_LOWER - SHIFT_LOWER);
		} else
			return c + SHIFT_LOWER;//Verschiebung um den SHIFT wert nach Rechts
	} else {
		if (c < ASCII_LLB + (CUT_LOWER + SHIFT_LOWER))//Ueberpruefung ob das Zeichen am linken Rand innerhalb des SHIFT ist
			return c + ((26 - CUT_LOWER) - SHIFT_LOWER);
		else
			return c - SHIFT_LOWER;//Verschiebung um den SHIFT wert nach Links
	}
}
/**
 *	\breif	kodierer
 *			Tauscht ein Klein oder Gross Buchstaben aus nach der entsprechende Verschiebung
 *	\param char c	Das Zeichen das Kodiert werden soll
 *	\return char	Das Kodierte Zeichen wird zurueckgegeben
 */
char Encoder::kodierer(char c) {
	if (c >= ASCII_LLB && c <= ASCII_LLE) {	//Ueberpruefung nach ASCII ob es das kleine Alphabet ist
		return kleinbuchstaben(c);
	}
	if (c >= ASCII_ULB && c <= ASCII_ULE) {	//Ueberpruefung nach ASCII ob es das grosse Alphabet ist
		return grossbuchstaben(c);
	}
	return c;
}
