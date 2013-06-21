#	test.sh
#	Programm zum Testen des encoder Programms
#	Programmaufruf wird ohne ausgefuerft
#
clear;
touch TestIn.txt;
echo "Fehler erzwingen: mit keine Argumenten";
encoder;
echo "Fehler erzwingen: mit einen Argument";
encoder TestIn.txt;
echo "Fehler erzwingen: mit keiner lesbaren Datei";
chmod 220 TestIn.txt;
encoder TestIn.txt TestOut.txt;
chmod 664 TestIn.txt;
echo "Fehler erzwingen: mit keiner beschreibarer Datei";
touch TestOut.txt;
chmod 440 TestOut.txt;
encoder TestIn.txt TestOut.txt;
chmod 664 TestOut.txt;
rm TestIn.txt;
rm TestOut.txt;
encoder input/input1.txt output/newOutput1.txt;
if [ ! 'cmp output/newOutput1.txt output/output1.txt' ] ; then
	echo "newOutPut1.txt stimmt nicht mit output1.txt ueberein";
fi;
encoder input/input2.txt output/newOutput2.txt;
if [ ! 'cmp output/newOutput2.txt output/output2.txt' ] ; then
	echo "newOutPut1.txt stimmt nicht mit output1.txt ueberein";
fi;
encoder input/input2.txt output/newOutput3.txt;
if [ ! 'cmp output/newOutput3.txt output/output3.txt' ] ; then
	echo "newOutPut1.txt stimmt nicht mit output1.txt ueberein";
fi;
