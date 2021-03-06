/*
Lillian Saeger
ITSE 1307 Spring 2019
20190219
This program displays business card infomation in vCard format to an output file named businessCard.
*/


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	//naming output filestream variable
	ofstream fileVCard;

	//opening file
	fileVCard.open("businessCard.vcf");

	//output using file named businessCard.vcf
	fileVCard << "BEGIN:VCARD" << endl;
	fileVCard << "N:Saeger; Lili;;" << endl;
	fileVCard << "FN: Lili Saeger" << endl;
	fileVCard << "ORG:Jewelry Asundries" << endl;
	fileVCard << "Title: Making Goods For You"<< endl;
	fileVCard << "ADR;TYPE=WORK;PREF=1;LABEL=\"111 Triad Way\\nAnywhere\\, TX 88888\\nUnited States of America\":;;111 Triad Way;Anywhere TX;88888;United States of America"
			  << endl;
	fileVCard << "EMAIL:LSJewelry@example.com " << endl;
	fileVCard << "END:VCARD" << endl;

	//closing file
	fileVCard.close();

    return 0;
}

