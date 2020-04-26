#include "ContentTxtAnalyser.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

bool ContentTxt::Load(const std::string& path) {
	std::ifstream t(path);

	t.seekg(0, std::ios::end);
	content.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	content.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	
	return true;
}

void ContentTxt::PrintContent() {
	std::cout << "CONTENT: <" << content << ">" << std::endl;
}