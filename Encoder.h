/*
 *	Encoder.h
 *	Created on: 19.06.2013
 *	Author: Sascha Hopp
 *	Version: 0.1
 */
#ifndef ENCORD_H_
#define ENCORD_H_

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
///	Encoder Kodiert den Inhalt einer Text Datei
/**
 *	Kodiert mittels Schneiden und Verschiebung des Alphabets einen Text.
 *	Dabei wird das Alphabet rechts und links der Stelle CUT um den SHIFT
 *	wert verschoben. Die Verschiebung findet aber rechts und links in
 *	entgegengesetzte Richtungen stat. Das Grosse und Kleine Alphabet wird
 *	dabei anders behandelt.
 *
 */
class Encoder {
public:
	///Fehlermeldungen
	static const char* NICHT_OEFFNEN;
	static const char* NICHT_SCHREIBEN;
	///SHIFT_LOWER Verschiebung der Kleinbuchstaben im Alphabet
	static const int SHIFT_LOWER = 2;
	///CUT_LOWER Schnittstelle der Kleinbuchstaben
	static const int CUT_LOWER = 13;
	///SHIFT_UPPER Verschiebung der Grossbuchstaben im Alphabet
	static const int SHIFT_UPPER = 1;
	///CUT_UPPER Schnittstelle der Grossbuchstaben
	static const int CUT_UPPER = 13;
	///ASCII_* Stellen des Alphabets im ASCII Code
	static const int ASCII_LLB = 97;	//ASCII Lower Letter Begin
	static const int ASCII_LLE = 122;	//ASCII Lower Letter End
	static const int ASCII_ULB = 65;	//ASCII Upper Letter Begin
	static const int ASCII_ULE = 90;	//ASCII Upper Letter End

	///Konstruktor
	Encoder(char *readFileName, char *writeFileName);
	///Destruktor
	virtual ~Encoder();
private:
	char grossbuchstaben(char c);	///Kodiert Grossbuchstaben
	char kleinbuchstaben(char c);	///Kodiert Kleinbuchstaben
	char kodierer(char c);			///Endscheidet ob Klein- oder Grossbuchstaben

	//Antribute
	ifstream readFile;
	ofstream writeFile;
};

#endif /* ENCORD_H_ */
