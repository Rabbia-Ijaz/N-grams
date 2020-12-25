#include"Ngrams.h"
#include<iostream>

using namespace std;
int main()
{
	readInput("alice.txt");
	getText();
	removePunctucationMarks();
	getText();
	removeSpacing();
	getText();
	insertDots();
	getText();
	generateUnigrams();
	generateBigrams();
	generateTrigrams();
	validateSentance("Sam I am");
	sentenceCreation(11);

}