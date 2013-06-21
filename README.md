|///////////////////////////////////////////////////////////////|
|	Loesung in C++ fuer HTW Connect Programmierwettbewerb		|
|																|
|	Autor: Sascha Hopp											|
|	Datum: 21.06.2013											|
|   URL: https://github.com/LockeSascha/ConsistecWettbewerb		|
|	Email:locke_sascha@web.de									|
|																|
|///////////////////////////////////////////////////////////////|

|///////////////////////////////////////////////////////////////|
|	Makefile		Mit Make kompilieren man das Programm		|
|					mit den schlater clean loescht man alle .o	|
|					und die auszufuehrende Datei				|
|	Testskripte:												|
|	Das Testskript erzwingt durch Falsche eingabe Fehler und 	|
|	vergleicht die vorgegebenen output's mit denen die vom		|
|	Programm erstellt worden sind								|
|	test.sh			Shellskrpit zum test des Encoder Programms	|
|					Bei Shells in dem der Programm aufruf		|
|					mit ./ startet								|
|	test_unix.sh	Shellskrpit zum test des Encoder Programms	|
|					Bei Shells in dem der Programm aufruf		|
|					ohne ./ startet								|
|///////////////////////////////////////////////////////////////|

|///////////////////////////////////////////////////////////////|
|	Quellcode:													|
|	Encoder.cpp		Quellcode der Klasse Encoder				|
|	Encoder.h													|
|	main.cpp													|
|																|
|	Programm um ein Textfile zu Kodieren mittels verschiebung	|
|	im Alphabets												|
|																|
|   Sonstiger Inhalt:											|
|	input/input1.txt			vorgabe von Consistec			|
|	input/input2.txt			vorgabe von Consistec			|
|	input/input3.txt			vorgabe von Consistec			|
|	input/input_test.txt		test mit inhalt des Alphabets	|
|	input/lorem_ipsum.txt		vorgabe von Consistec			|
|	output/output1.txt			vorgabe von Consistec			|
|	output/output2.txt			vorgabe von Consistec			|
|	output/output3.txt			vorgabe von Consistec			|
|	output/output_test.txt		kodoert aus input_test.txt		|
|	output/lorem_output.txt		kodiert aus lorem_ipsum.txt		|
|///////////////////////////////////////////////////////////////|