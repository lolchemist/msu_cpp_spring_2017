#include "stdafx.h"
#include <string>
#include <iostream>

using namespase std;

// don't want to use headers, begin of sorry
string chartonum(char r) {
	
	// 
	switch (r)
	{
		// for error&space
	default: return '104'; break;

	case: ' ' return '0'; break;
		break;
		// for abc
	case 'a': return '2'; break;
	case 'b': return '22'; break;
	case 'c': return '222'; break;
		// for def
	case 'd': return '3'; break;
	case 'e': return '33'; break;
	case 'f': return '333'; break;
		// for ghi
	case 'g': return '4'; break;
	case 'h': return '44'; break;
	case 'i': return '444'; break;
		// for jkl
	case 'j': return '5'; break;
	case 'k': return '55'; break;
	case 'l': return '555'; break;
		// for mno
	case 'm': return '6'; break;
	case 'n': return '66'; break;
	case 'o': return '666'; break; // kumamon is glad
		// for pqrs
	case 'p': return '7'; break;
	case 'q': return '77'; break;
	case 'r': return '777'; break;
	case 's': return '7777'; break;
		// for tuv
	case 't': return '8'; break;
	case 'u': return '88'; break;
	case 'v': return '888'; break;
		// for wxyz
	case 'w': return '9'; break;
	case 'x': return '99'; break;
	case 'y': return '999'; break;
	case 'z': return '9999'; break;
	}
	
}

string transform(string str) 
{
	string(result);
	result += chartonu(str[0]);
	for (int i = 1; i < str.size(); i++) {
		if(chartonum(str[i])[0] == chartonum(str[i - 1])[0]) result += " ";
		result += chartonum(str[i]);
	}
	return result;
}
// end of sorry

int main(int argc, char* argv[])
{
	string str;
	getline(cin, str);
	cout << transform(str) << endl;
	return 0;
}