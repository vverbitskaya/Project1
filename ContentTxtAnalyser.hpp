#ifndef CONTENT_TXT_ANALYSER_HPP
#define CONTENT_TXT_ANALYSER_HPP

#include "ContentAnalyser.hpp"

#include <memory>

class ContentTxt : public Content {
public:
	virtual bool Load(const std::string& path) override;
	void PrintContent() override;
private:
	std::string content;
};

class AnalyseResultTxt : public AnalyseResult {
	virtual bool IsValid() override;
	virtual void printResult() override;
};

class ContentAnalyserTxt : public ContentAnalyser {
private:
	virtual bool LoadContent(const std::shared_ptr<Content>& content) override;
	virtual bool Analyse() override;
	virtual std::shared_ptr<AnalyseResult> GetAnalyseResult() override;
};

#endif  // CONTENT_TXT_ANALYSER_HPP