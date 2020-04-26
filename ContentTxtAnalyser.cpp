#include "ContentTxtAnalyser.hpp"

#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

bool ContentTxt::Load(const std::string& path) {
	// TODO : check file extention is *.txt

	std::ifstream t(path);

	t.seekg(0, std::ios::end);
	content.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	content.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	
	return true;
}

void ContentTxt::Clear() {
	content.clear();
}

void ContentTxt::PrintContent() {
	std::cout << "CONTENT: <" << content << ">" << std::endl;
}

std::string& ContentTxt::GetRawContent() {
	return content;
}
//

AnalyseResultTxt::AnalyseResultTxt(const std::vector<std::pair<std::string, int>>& data) : _data(data) {}

bool AnalyseResultTxt::IsValid() {
	return true;
}
void AnalyseResultTxt::printResult(size_t min_frequency, size_t max_frequency) {
	int count_all_words = 0;
	for (size_t i = 0; i < _data.size(); ++i) {
		count_all_words += _data[i].second;
	}
	int pos = 0;
	int account_words = 0;
	int rare_words_count = 0;
	for (auto i = _data.begin(); i != _data.end(); ++i) {
		if (i->second > min_frequency && i->second < max_frequency) {
			account_words += i->second;
			std::cout << ++pos << " : " << i->first << " : " << i->second << ". " 
				<< double(account_words) / double(count_all_words) * 100. << "%" << std::endl;
		}
		else {
			rare_words_count++;
		}
	}
	std::cout << "Rare words count:" << rare_words_count << std::endl;
}

//

bool ContentAnalyserTxt::LoadContent(const std::shared_ptr<Content>& content) {
	// TODO check that Content has type ContentTXT only!!
	_content = content;
	return true;
}
bool ContentAnalyserTxt::Analyse() {
	
	ContentTxt* content_txt_ptr = reinterpret_cast<ContentTxt*>(_content.get());
	
	std::string raw_data = content_txt_ptr->GetRawContent();

	std::string word;
	for (size_t i = 0; i < raw_data.size(); ++i) {
		if (IsEndOfWord(raw_data[i])) {
			if (word.size() != 0) {
				auto iter = std::find_if(storage.begin(), storage.end(), 
					[&word](const std::pair<std::string, int> w) {
					return w.first == word;
				});
				if (iter != storage.end()) {
					iter->second++;
				}
				else {
					storage.push_back(std::make_pair(word, 1));
				}
			}
			word.clear();
		}
		else {
			word += tolower(raw_data[i]);
		}
	}

	std::sort(storage.begin(), storage.end(), 
		[](std::pair<std::string, int> f, std::pair<std::string, int> s) {
		return f.second > s.second;
	});

	return true;
}
std::shared_ptr<AnalyseResult> ContentAnalyserTxt::GetAnalyseResult() {
	return std::make_shared<AnalyseResultTxt>(storage);
}

bool ContentAnalyserTxt::IsEndOfWord(char s) {
	// TODO think about better realization
	if (s == ' ' || s == ',' || s == '.' || s == '-' || s == ';' || s == ':' ||
		s == '!' || s == '?' || s == '\n' || s == '"') {
		return true;
	}
	return false;
}