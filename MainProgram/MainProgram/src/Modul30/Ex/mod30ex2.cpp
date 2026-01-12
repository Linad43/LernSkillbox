#include "header_modul30.h"
#include "cpr/cpr.h"

void mod30ex2() {
	std::cout << "2. Реализовать захват заголовка HTML-страницы.\n";
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
		cpr::Header{{"body", "text/html"}});

	int beg, end;
	beg = r.text.find("<h1>")+lengthString("<h1>");
	end = r.text.find("</h1>");
	std::string header = r.text.substr(beg, end-beg);
	std::cout<<header<<std::endl;
}
