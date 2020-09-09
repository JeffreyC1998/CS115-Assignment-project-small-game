//
//  TestTemplates.cpp
//
//  A program to test the templates functions for Assignment 6.
//

#include <cassert>
#include <string>
#include <iostream>
#include <iomanip>

#include "Templates.h"

using namespace std;



int main ()
{
	const unsigned int ARRAY_SIZE = 56;
	const int ARRAY_0[ARRAY_SIZE] =
	{	-7, -51, 4, -2, -5, 110, 15, -3, 3, 5,
		-7, -3, 19, 4, 5, -3, 430, 141, 4, 4,
		-2, 574, 3, 7, 1518, -3, 62, 84, -2, -10,
		11, -7, -13, -4, 4, -3, 45551, -5, 3, 3,
		2, -33, 4494, -8, -5, -6, 3, -2, 7, 2,
		9, -3, -4, -4, 3, -17, };  // https://oeis.org/A056581

	const short ARRAY_1[ARRAY_SIZE] =
	{	1, 2, 0, 3, 1, 2, 4, 3, 5, 2,
		4, 1, 3, 5, 2, 4, 7, 5, 6, 4,
		7, 2, 6, 8, 7, 9, 1, 6, 5, 7,
		4, 2, 5, 9, 4, 2, 7, 3, 12, 4,
		2, 1, 3, 8, 2, 1, 4, 8, 12, 9,
		10, 2, 11, 3, 1, 2, };	// https://oeis.org/A125940

	const unsigned int ARRAY_2[ARRAY_SIZE] =
	{	1u, 2u, 3u, 1u, 4u, 4u, 5u, 10u, 1u, 6u,
		20u, 6u, 7u, 35u, 21u, 1u, 8u, 56u, 56u, 8u,
		9u, 84u, 126u, 36u, 1u, 10u, 120u, 252u, 120u, 10u,
		11u, 165u, 462u, 330u, 55u, 1u, 12u, 220u, 792u, 792u,
		220u, 12u, 13u, 286u, 1287u, 1716u, 715u, 78u, 1u, 14u,
		364u, 2002u, 3432u, 2002u, 364u, 14u, };  // https://oeis.org/A034867

	const float ARRAY_3[ARRAY_SIZE] =
	{	793.78f, 986.43f, 261.11f, -24.71f, 28.26f,
		-725.64f, 879.62f, 57.37f, -250.36f, -173.96f,
		-635.61f, -562.16f, -836.40f, 266.00f, -574.77f,
		-874.22f, 247.96f, -269.73f, -159.71f, 169.75f,
		-724.28f, 346.21f, 200.21f, 571.59f, 999.80f,
		-141.60f, 184.95f, -136.01f, -176.31f, -156.12f,
		885.78f, -902.95f, 48.28f, -139.74f, -39.82f,
		-630.59f, 378.06f, -212.70f, -387.88f, -956.56f,
		-835.34f, 927.54f, -868.11f, -39.98f, -257.28f,
		465.77f, 501.29f, -613.47f, 295.61f, -140.13f,
		-884.01f, 692.68f, -286.43f, 373.94f, 975.21f,
		51.45f, };  // random

	const char ARRAY_4[ARRAY_SIZE] =
	{	'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
		'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
		'z', 'x', 'c', 'v', 'b', 'n', 'm',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		'1', '2', '3', '4', };  // keyboard order

	const string ARRAY_5[ARRAY_SIZE] =
	{	"We ", "hold ", "these ", "truths ", "to ",
		"be ", "self-evident, ", "that ", "all ", "men ",
		"are ", "created ", "equal, ", "that ", "they ",
		"are ", "endowed ", "by ", "their ", "Creator ",
		"with ", "certain ", "unalienable ", "Rights, ", "that ",
		"among ", "these ", "are ", "Life, ", "Liberty ",
		"and ", "the ", "Pursuit ", "of ", "Happiness.  ",
		"That ", "to ", "secure ", "these ", "rights, ",
		"Governments ", "are ", "instituted ", "among ", "Men, ",
		"deriving ", "their ", "just ", "powers ", "from ",
		"from ", "the ", "consent ", "of ", "the ",
		"governed; ",	};  // U.S. Declaration of Independence

	const string DECLARATION =
		"We hold these truths to be self-evident, that all men "
		"are created equal, that they are endowed by their Creator "
		"with certain unalienable Rights, that among these are Life, Liberty "
		"and the Pursuit of Happiness.  That to secure these rights, "
		"Governments are instituted among Men, deriving their just powers from "
		"from the consent of the governed; ";

	cout << boolalpha;  // print true and false as "true" and "false"
	cout << left;



	cout << "Testing max(a, b, c):" << endl;
	cout << "---------------------" << endl;

	int max0 = max(-2, 0, 2);
	cout << setw(40) << "max(-2, 0, 2):"
	     << max0 << "\t" << (max0 == 2) << endl;

	short max1 = max(short(-400), short(-900), short(-100));
	cout << setw(40) << "max(-400, -900, -100):"
	     << max1 << "\t" << (max1 == -100) << endl;

	unsigned int max2 = max(20u, 4000000000u, 5000u);
	cout << setw(40) << "max(20u, 4000000000u, 5000u):"
	     << max2 << "u\t" << (max2 == 4000000000u) << endl;

	float max3 = max(2.71828f, 3.14159f, 1.61803f);
	cout << setw(40) << "max(2.71828f, 3.14159f, 1.61803f):"
	     << max3 << "f\t" << (max3 == 3.14159f) << endl;

	char max4 = max('Z', 'X', 'Y');
	cout << setw(40) << "max(\'Z\', \'X', \'Y\'):"
	     << "\'" << max4 << "\' (" << int(max4) << ")\t" << (max4 == 'Z') << endl;

	string max5 = max(string("brawn"), string("bravado"), string("brain"));
	cout << setw(40) << "max(\"brawn\", \"bravado\", \"brain\"):"
	     << "\"" << max5 << "\"\t" << (max5 == "brawn") << endl;

	cout << endl;



	cout << "Testing median(a, b, c):" << endl;
	cout << "------------------------" << endl;

	int median0 = median(-2, 0, 2);
	cout << setw(40) << "median(-2, 0, 2):"
	     << median0 << "\t" << (median0 == 0) << endl;

	short median1 = median(short(-400), short(-900), short(-100));
	cout << setw(40) << "median(-400, -900, -100):"
	     << median1 << "\t" << (median1 == -400) << endl;

	unsigned int median2 = median(20u, 4000000000u, 5000u);
	cout << setw(40) << "median(20u, 4000000000u, 5000u):"
	     << median2 << "u\t" << (median2 == 5000u) << endl;

	float median3 = median(2.71828f, 3.14159f, 1.61803f);
	cout << setw(40) << "median(2.71828f, 3.14159f, 1.61803f):"
	     << median3 << "f\t" << (median3 == 2.71828f) << endl;

	char median4 = median('Z', 'X', 'Y');
	cout << setw(40) << "median(\'Z\', \'X', \'Y\'):"
	     << "\'" << median4 << "\' (" << int(median4) << ")\t" << (median4 == 'Y') << endl;

	string median5 = median(string("brawn"), string("bravado"), string("brain"));
	cout << setw(40) << "median(\"brawn\", \"bravado\", \"brain\"):"
	     << "\"" << median5 << "\"\t" << (median5 == "bravado") << endl;

	cout << endl;



	cout << "Testing sum(a, b, c):" << endl;
	cout << "---------------------" << endl;

	int sum0 = sum(-2, 0, 2);
	cout << setw(40) << "sum(-2, 0, 2):"
	     << sum0 << "\t" << (sum0 == 0) << endl;

	short sum1 = sum(short(-400), short(-900), short(-100));
	cout << setw(40) << "sum(-400, -900, -100):"
	     << sum1 << "\t" << (sum1 == -1400) << endl;

	unsigned int sum2 = sum(20u, 4000000000u, 5000u);
	cout << setw(40) << "sum(20u, 4000000000u, 5000u):"
	     << sum2 << "u\t" << (sum2 == 4000005020u) << endl;

	float sum3 = sum(2.71828f, 3.14159f, 1.61803f);
	cout << setw(40) << "sum(2.71828f, 3.14159f, 1.61803f):"
	     << sum3 << "f\t" << (sum3 == 7.47790f) << endl;

	char sum4 = sum('Z', 'X', 'Y');
	cout << setw(40) << "sum(\'Z\', \'X', \'Y\'):"
	     << "\'" << sum4 << "\' (" << int(sum4) << ")\t" << (sum4 == char(11)) << " (wraparound)" << endl;

	string sum5 = sum(string("brawn"), string("bravado"), string("brain"));
	cout << setw(40) << "sum(\"brawn\", \"bravado\", \"brain\"):"
	     << "\"" << sum5 << "\"\t" << (sum5 == "brawnbravadobrain") << endl;

	cout << endl;



	cout << "Testing max(array, count):" << endl;
	cout << "--------------------------" << endl;

	int maxa0 = max(ARRAY_0, ARRAY_SIZE);
	cout << setw(16) << "max of ARRAY_0:"
	     << maxa0 << "\t" << (maxa0 == 45551) << endl;

	short maxa1 = max(ARRAY_1, ARRAY_SIZE);
	cout << setw(16) << "max of ARRAY_1:"
	     << maxa1 << "\t" << (maxa1 == 12) << endl;

	unsigned int maxa2 = max(ARRAY_2, ARRAY_SIZE);
	cout << setw(16) << "max of ARRAY_2:"
	     << maxa2 << "u\t" << (maxa2 == 3432u) << endl;

	float maxa3 = max(ARRAY_3, ARRAY_SIZE);
	cout << setw(16) << "max of ARRAY_3:"
	     << maxa3 << "f\t" << (maxa3 == 999.80f) << endl;

	char maxa4 = max(ARRAY_4, ARRAY_SIZE);
	cout << setw(16) << "max of ARRAY_4:"
	     << "\'" << maxa4 << "\' (" << int(maxa4) << ")\t" << (maxa4 == 'z') << endl;

	string maxa5 = max(ARRAY_5, ARRAY_SIZE);
	cout << setw(16) << "max of ARRAY_5:"
	     << "\"" << maxa5 << "\"\t" << (maxa5 == "with ") << endl;

	cout << endl;



	cout << "Testing sum(array, count):" << endl;
	cout << "--------------------------" << endl;

	int suma0 = sum(ARRAY_0, ARRAY_SIZE);
	cout << setw(16) << "sum of ARRAY_0:"
	     << suma0 << "\t" << (suma0 == 52872) << endl;

	short suma1 = sum(ARRAY_1, ARRAY_SIZE);
	cout << setw(16) << "sum of ARRAY_1:"
	     << suma1 << "\t" << (suma1 == 253) << endl;

	unsigned int suma2 = sum(ARRAY_2, ARRAY_SIZE);
	cout << setw(16) << "sum of ARRAY_2:"
	     << suma2 << "u\t" << (suma2 == 16383u) << endl;

	float suma3 = sum(ARRAY_3, ARRAY_SIZE);
	cout << setw(16) << "sum of ARRAY_3:"
	     << suma3 << "f\t" << (fabs(suma3 - -2027.93f) < 0.01f)
	     << " (allowing for rounding errors)" << endl;

	char suma4 = sum(ARRAY_4, ARRAY_SIZE);
	cout << setw(16) << "sum of ARRAY_4:"
	     << "\'" << suma4 << "\' (" << int(suma4) << ")\t" << (suma4 == char(-56)) << " (wraparound)" << endl;

	string suma5 = sum(ARRAY_5, ARRAY_SIZE);
	cout << setw(16) << "sum of ARRAY_5:"
	     << "\"" << suma5 << "\"\t" << (suma5 == DECLARATION) << endl;

	cout << endl;



	return 0;
}
