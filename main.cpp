#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

#include "ContentTxtAnalyser.hpp"

int main() {

	std::shared_ptr<Content> c = std::make_shared<ContentTxt>();

	bool load_result = c->Load("D://git/Project1/Twilight.txt");
	if (load_result) {
		std::cout << "Content was sucessfuly loaded" << std::endl;
	}
	else {
		std::cout << "Cannot load content" << std::endl;
		return -1;
	}

	std::shared_ptr<ContentAnalyser> ca = std::make_shared<ContentAnalyserTxt>();

	ca->LoadContent(c);
	ca->Analyse();
	auto analyse_result = ca->GetAnalyseResult();
	
	if (analyse_result->IsValid()) {
		analyse_result->printResult(2, 5);
	} else {
		std::cout << "Analyse result is invalid" << std::endl;
	}

	return 0;
}