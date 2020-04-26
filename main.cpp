#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

#include "ContentTxtAnalyser.hpp"

int main() {

	std::shared_ptr<Content> c = std::make_shared<ContentTxt>();

	bool load_result = c->Load("D://git/Project1/test.txt");
	if (load_result) {
		std::cout << "Content was sucessfuly loaded" << std::endl;
	}
	else {
		std::cout << "Cannot load content" << std::endl;
		return -1;
	}
	c->PrintContent();

	return 0;
}