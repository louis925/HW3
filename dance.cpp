#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;


bool hasCorrectSyntax(string dance){
	// while dance is empty string 
	//if (dance == "")
	//	return true;
	// judge every character in dance
	for (int i = 0; i < dance.size(); i++) {
		if (dance[i] == 'u' || dance[i] == 'U' || dance[i] == 'd' || dance[i] == 'D' || dance[i] == 'l' || dance[i] == 'L' || dance[i] == 'r' || dance[i] == 'R') {
			if ((i + 1) != dance.size()) {
				if (dance[i + 1] != '/')
					return false;
				
			}
			else
				return false;
		}
		else if (isdigit(dance[i])) {
			if ((i + 1) != dance.size()) {
				if (!(isdigit(dance[i + 1])) && !(dance[i+1] == 'u' || dance[i+1] == 'U' || dance[i+1] == 'd' || dance[i+1] == 'D' || dance[i+1] == 'l' || dance[i+1] == 'L' || dance[i+1] == 'r' || dance[i+1] == 'R'))
					return false;
				else if (isdigit(dance[i + 1])) {
					if ((i + 2) == dance.size())
						return false;
					else if (!(dance[i + 2] == 'u' || dance[i + 2] == 'U' || dance[i + 2] == 'd' || dance[i + 2] == 'D' || dance[i + 2] == 'l' || dance[i + 2] == 'L' || dance[i + 2] == 'r' || dance[i + 2] == 'R'))
						return false;
					else {
						if ((i + 3) == dance.size())
							return false;
						else if (dance[i + 3] != '/')
							return false;
					}
				}
				else {
					if ((i + 2) == dance.size())
						return false;
					else if (!(dance[i + 2] == '/'))
						return false;
					
				}
			}
			else
				return false;
		}
		else if (dance[i] == '/') {
			continue;
		}
		else
			return false;
	}
	return true;
}

int convertDance(string dance, string& instructions, int& badBeat) {
	string convert = "";

	// not syntactically correct, return 1
	if (!hasCorrectSyntax(dance))
		return 1;

	// syntatically correct while dance is empty string
	else if (dance == "") {
		instructions = "";
		return 0;
	}
	// sytactically correct
	else {
		for (int i = 0; i < dance.size(); i++) {
			if (isdigit(dance[i])) {
				
				// while freeze of length is two digits
				if (isdigit(dance[i + 1])) {
					
					// n=freeze of length
					int n=0;
					n = (dance[i]-'0') * 10 + dance[i + 1]-'0';


					// freeze of length is less than 2, return 3
					if (n == 0 || n == 1) {
						int slash = 0;
						for (int k = 0; k < i; k++) {
							if (dance[k] == '/')
								slash += 1;
						}
						badBeat = slash + 1;
						return 3;
					}
					// freeze of length is at least 2
					else if ((i + 1 + 1 +1 + n) > dance.size()) {

						// dance ends prematurely, return 2

						int slash = 0;
						for (int k = 0; k < dance.size(); k++) {
							if (dance[k] == '/')
								slash += 1;
						}
						badBeat = slash + 1;
						return 2;
					}
					// while freeze is in effect, a beat not consisting of only a slash, return 4
					else {
						for (int j = 0; j < n; j++) {
							if (dance[i + 1 + 1 +1 + j] != '/') {
								int slash = 0;
								for (int k = 0; k <= i + 1 + 1 +1+ j; k++) {
									if (dance[k] == '/')
										slash += 1;
								}
								badBeat = slash + 1;
								return 4;
							}
						}
						badBeat = -999;
					}
					// return 0;					
					// 锣传//Τbug!!!!!!!
					for (int m = 0; m < n; m++) {
						convert += tolower(dance[i + 1+1]);

					}
					i += (1+1 + n);
					}			
				// ㄢ计
				// 计
				// while freeze of length is one digits
				else {
					// n=freeze of length
					int n = 0;
					n = dance[i]-'0';

					// freeze of length is less than 2, return 3
					if (n == 0 || n == 1) {
						int slash = 0;
						for (int k = 0; k < i; k++) {
							if (dance[k] == '/')
								slash += 1;
 						}
						badBeat = slash + 1;
						return 3;
					}
					// freeze of length is at least 2
					else if ((i + 1 + 1 + n) > dance.size()){
						
							// dance ends prematurely, return 2
							
								int slash = 0;
								for (int k = 0; k < dance.size(); k++) {
									if (dance[k] == '/')
										slash += 1;
								}
								badBeat = slash + 1;
								return 2;													
					}
					// while freeze is in effect, a beat not consisting of only a slash, return 4
					else {
						for (int j = 0; j < n; j++) {
							if (dance[i + 1 + 1 + j] != '/') {
								int slash = 0;
								for (int k = 0; k <= i + 1 + 1 + j; k++) {
									if (dance[k] == '/')
										slash += 1;
								}
								badBeat = slash + 1;
								return 4;
							}
						}
						badBeat = -999;
					}
					// return 0;					
					// 锣传//Τbug!!!!!!!
					for (int m = 0; m < n; m++) {
						convert += tolower(dance[i + 1]);
					
					}
					i += (1 + n);
				}
					
			}		
			else if (dance[i] == '/')
				convert += '.';
			else {
				convert += tolower(dance[i]);
				i += 1;
			}
		}
	}
instructions = convert;
return 0;
}

int main() {

	assert(hasCorrectSyntax(""));
	assert(hasCorrectSyntax(""));
	assert(hasCorrectSyntax("u/"));
	assert(hasCorrectSyntax("0u/"));
	assert(hasCorrectSyntax("1u/"));
	assert(hasCorrectSyntax("01u/"));
	assert(hasCorrectSyntax("/u/"));
	assert(hasCorrectSyntax("3u/"));
	assert(hasCorrectSyntax("03u/"));
	assert(hasCorrectSyntax("3u///"));
	assert(hasCorrectSyntax("3u////"));
	assert(hasCorrectSyntax("u/d/"));
	assert(hasCorrectSyntax("R/L/U/D/"));
	assert(hasCorrectSyntax("3u//d/"));
	assert(hasCorrectSyntax("3u//d//"));
	assert(hasCorrectSyntax("3u//2R/D/"));
	assert(hasCorrectSyntax("3u/////2R//L/"));
	assert(hasCorrectSyntax("10u/"));

	assert(!hasCorrectSyntax(" /"));
	assert(!hasCorrectSyntax("u"));
	assert(!hasCorrectSyntax("0u"));
	assert(!hasCorrectSyntax("01u"));
	assert(!hasCorrectSyntax("3"));
	assert(!hasCorrectSyntax("3u"));
	assert(!hasCorrectSyntax("3 u/"));
	assert(!hasCorrectSyntax("10u"));
	assert(!hasCorrectSyntax("ud/"));
	assert(!hasCorrectSyntax("u/d"));
	assert(!hasCorrectSyntax("/u"));
	assert(!hasCorrectSyntax("///////L"));
	assert(!hasCorrectSyntax("R/L/U/D"));
	
	string ins;
	int bb;
	ins = "WOW";  // so we can detect whether convertDance sets ins
	bb = -999;    // so we can detect whether convertDance sets bb
	////convertDance("10u///", ins, bb);
	//convertDance("3r///", ins, bb);
	//convertDance("3r//", ins, bb);
	//convertDance("3r///2r/", ins, bb);
	//convertDance("3r///2r//", ins, bb);
	//convertDance("3r////2r//", ins, bb);
	//convertDance("3r//u/2r//", ins, bb);
	//convertDance("3r///u///u/2r//", ins, bb);
	//convertDance("02u//", ins, bb);
	//convertDance("10u/////////", ins, bb);
	/*convertDance("10u//////////r/", ins, bb);
	convertDance(" /", ins, bb);
	cout << ins << endl;
	cout << bb << endl;
	cout << convertDance(" /", ins, bb) << endl;*/
	
	assert(convertDance("u/", ins, bb) == 0 && ins == "u"  &&  bb == -999);
	assert(convertDance("2u//", ins, bb) == 0 && ins == "uu"  &&  bb == -999);
	assert(convertDance("2U//", ins, bb) == 0 && ins == "uu"  &&  bb == -999);
	assert(convertDance("2u///", ins, bb) == 0 && ins == "uu."  &&  bb == -999);
	assert(convertDance("/u/", ins, bb) == 0 && ins == ".u"  &&  bb == -999);
	assert(convertDance("u/d/", ins, bb) == 0 && ins == "ud"  &&  bb == -999);
	assert(convertDance("u//d/", ins, bb) == 0 && ins == "u.d"  &&  bb == -999);
	assert(convertDance("/u//d/", ins, bb) == 0 && ins == ".u.d"  &&  bb == -999);
	assert(convertDance("u/d/l/r/", ins, bb) == 0 && ins == "udlr"  &&  bb == -999);
	assert(convertDance("u/3d///l//r/", ins, bb) == 0 && ins == "udddl.r"  &&  bb == -999);

	ins = "WOW";
	bb = -999;
	assert(convertDance(" /", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("u", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("A", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("u/a/", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("0u", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("01u", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("3", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("3u", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("3 u/", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("10u", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("ud/", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("u/d", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("/u", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("///////L", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("R/L/U/D", ins, bb) == 1 && ins == "WOW"  &&  bb == -999);
	ins = "WOW";
	bb = -999;

	assert(convertDance("2u/", ins, bb) == 2 && ins == "WOW"  &&  bb == 2);
	ins = "WOW";
	bb = -999;
	assert(convertDance("2u//3d/", ins, bb) == 2 && ins == "WOW"  &&  bb == 4);
	ins = "WOW";
	bb = -999;
	assert(convertDance("2u//3d//", ins, bb) == 2 && ins == "WOW"  &&  bb == 5);
	ins = "WOW";
	bb = -999;
	assert(convertDance("2u//3d///10L/", ins, bb) == 2 && ins == "WOW"  &&  bb == 7);
	ins = "WOW";
	bb = -999;
	assert(convertDance("03u///2r//5L//", ins, bb) == 2 && ins == "WOW"  &&  bb == 8);
	ins = "WOW";
	bb = -999;

	assert(convertDance("0u/", ins, bb) == 3 && ins == "WOW"  &&  bb == 1);
	ins = "WOW";
	bb = -999;
	assert(convertDance("1u/", ins, bb) == 3 && ins == "WOW"  &&  bb == 1);
	ins = "WOW";
	bb = -999;
	assert(convertDance("/1u/", ins, bb) == 3 && ins == "WOW"  &&  bb == 2);
	ins = "WOW";
	bb = -999;
	assert(convertDance("2u//0D/", ins, bb) == 3 && ins == "WOW"  &&  bb == 3);
	ins = "WOW";
	bb = -999;
	assert(convertDance("2u//1D/", ins, bb) == 3 && ins == "WOW"  &&  bb == 3);
	ins = "WOW";
	bb = -999;
	assert(convertDance("2u//2D///1L/", ins, bb) == 3 && ins == "WOW"  &&  bb == 6);
	ins = "WOW";
	bb = -999;

	assert(convertDance("2u/r/", ins, bb) == 4 && ins == "WOW"  &&  bb == 2);
	ins = "WOW";
	bb = -999;
	assert(convertDance("2u//r/3l//d/", ins, bb) == 4 && ins == "WOW"  &&  bb == 6);
	ins = "WOW";
	bb = -999;
	assert(convertDance("2u//r/3L///2U/R//", ins, bb) == 4 && ins == "WOW"  &&  bb == 8);
	ins = "WOW";
	bb = -999;
	




	assert(convertDance("u//d/r///d/", ins, bb) == 0 && ins == "u.dr..d"  &&  bb == -999);
	ins = "WOW";
	bb = -999;
	assert(convertDance("u//d/3r///d/", ins, bb) == 0 && ins == "u.drrrd"  &&  bb == -999);

	//ins = "WOW";  // so we can detect whether convertDance sets ins
	//bb = -999;    // so we can detect whether convertDance sets bb
	//assert(convertDance("5r//", ins, bb) == 2 && ins == "WOW"  &&  bb == 3);
    
		cout << "All tests succeeded" << endl;
		system("pause");

}