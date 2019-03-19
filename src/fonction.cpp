#include "fonction.h"

std::vector<std::string> split(const std::string & s , const char & c ){
	std::vector<std::string> v ; 
	if(s != ""){
		
		int pos = 0 , len = 0 ,t;
		unsigned int last = s.find_last_of(c);
		while (pos <= last){
			t= s.find(c , pos);
			len = t-pos;
			v.push_back(s.substr(pos,len));
			pos = t+1 ;
		}
		if(last < s.size()) v.push_back(s.substr(pos));
		return v;
	}
	else {
		v.push_back("");
		return  v;

	}
}