/**
 *	main.cpp
 *	Created on: 19.06.2013
 *	Author: Sascha Hopp
 *	Version: 1.0
 *
 *   Kodiert einen Text mittels Verschiebung und Scheidung des Alphabets.
 */
#include <iostream>
#include "Encoder.h"

using namespace std;
/**
 * \brief main
 *
 *  	  Kodiert mittels der Klasse Encoder.
 *  	  Der Text des ersten Argumente wird Kodiert in die Restliche Argumente
 *  	  erstellt.
 * \param	int argc		Anzahl der Argumente
 * \param	char* argv[]	Array mit dem Inhalt der Argumente
 * \return
 */
int main(int argc, char* argv[]){
	try {
		if(argc <= 2) // Uberpruefung nach anzahl der Argumente
				throw "Es muessen mindestens 2 Argumente mitgegeben werden!\n";
		for(int i=2; i < argc; i++){
			Encoder encoder(argv[1],argv[i]); //Aufrufen der Klasse Encorder
		}
	} catch (const char*e){
		cout << e + '\n';
		return 1;
	}
	return 0;
}


