#ifndef CONTENTANALYSER_HPP
#define CONTENTANALYSER_HPP
#include <string>
#include <memory>

class Content {
public:
	virtual bool Load(const std::string& path) = 0;
	virtual void PrintContent() = 0;
};

class AnalyseResult {
public:
	virtual bool IsValid() = 0;

	virtual void printResult() = 0; // TODO [Pedus] : need to think about export results
};

class ContentAnalyser {
public:
	virtual bool LoadContent(const std::shared_ptr<Content>& content) = 0;
	virtual bool Analyse() = 0;
	virtual std::shared_ptr<AnalyseResult> GetAnalyseResult() = 0;
};

#endif  // CONTENTANALYSER_HPP
