#include "fonction.h"

std::vector<std::string> split(const std::string & s , const char & c ){
	std::vector<std::string> v ; 
	if(s != ""){
		int pos = 0 , len = 0 ,t;
		int last = s.find_last_of(c);
		while (pos <= last){
			t= s.find(c , pos);
			len = t-pos;
			v.push_back(s.substr(pos,len));
			pos = t+1 ;
		}
		if(last < int(s.length())) v.push_back(s.substr(pos));
		return v;
	}
	else {
		v.push_back("");
		return  v;
	}
}

bool avancerVers(float f ,Vect & m, const Vect & e){
	Vect v(m-e);
	v = Vect(0,0) - v;
	float mod = v.module();
	if (f<mod){
		m = m + Vect((v.getX()/mod) * f , (v.getY()/mod) * f);
		return false;
	}else {
		m = e ;
		return true;
	}
	
}