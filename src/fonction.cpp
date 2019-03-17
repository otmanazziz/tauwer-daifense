#include "fonction.h"

std::vector<std::string> split(const std::string & s , const char & c ){
	std::vector<std::string> v ; 
	int pos = 0 , len = 0 ,t , last = s.find_last_of(c);
	while (pos <= last){
		t= s.find(c , pos);
		len = t-pos;
		v.push_back(s.substr(pos,len));
		pos = t+1 ;
		
		
	}
	return v;
}