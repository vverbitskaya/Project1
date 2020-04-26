#ifndef CONTENT_TXT_ANALYSER_HPP
#define CONTENT_TXT_ANALYSER_HPP

#include "ContentAnalyser.hpp"

#include <vector>
#include <memory>
#include <utility>

class ContentTxt : public Content {
public:
	bool Load(const std::string& path) override;
	void PrintContent() override;
	void Clear() override;

	std::string& GetRawContent();
private:
	std::string content;
};

class AnalyseResultTxt : public AnalyseResult {
public:
	AnalyseResultTxt(const std::vector<std::pair<std::string, int>>& data);
	virtual bool IsValid() override;
	virtual void printResult(size_t min_frequency, size_t max_frequency) override;
private:
	std::vector<std::pair<std::string, int>> _data;
};

class ContentAnalyserTxt : public ContentAnalyser {
public:
	virtual bool LoadContent(const std::shared_ptr<Content>& content) override;
	virtual bool Analyse() override;
	virtual std::shared_ptr<AnalyseResult> GetAnalyseResult() override;

private:
	bool IsEndOfWord(char s);

	std::shared_ptr<Content> _content;
	std::vector<std::pair<std::string, int>> storage;
};

#endif  // CONTENT_TXT_ANALYSER_HPP