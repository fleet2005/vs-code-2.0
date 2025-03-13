#pragma once
#include <string>
#include <vector>
#include <stack>
#include <queue>

enum class DataStructureType {
    ARRAY,
    STACK,
    QUEUE
};

class DataStructures {
private:
    std::vector<std::string> array;
    std::stack<std::string> stack;
    std::queue<std::string> queue;
    DataStructureType currentType;
    size_t maxArraySize;
    size_t currentArrayIndex;

public:
    DataStructures(size_t maxSize = 3) 
        : maxArraySize(maxSize), currentArrayIndex(0), currentType(DataStructureType::ARRAY) {}

    void setDataStructureType(DataStructureType type) {
        currentType = type;
    }

    void copy(const std::string& text) {
        switch (currentType) {
            case DataStructureType::ARRAY:
                if (currentArrayIndex < maxArraySize) {
                    array.resize(maxArraySize);
                    array[currentArrayIndex] = text;
                    currentArrayIndex = (currentArrayIndex + 1) % maxArraySize;
                }
                break;
            case DataStructureType::STACK:
                stack.push(text);
                break;
            case DataStructureType::QUEUE:
                queue.push(text);
                break;
        }
    }

    std::string paste() {
        switch (currentType) {
            case DataStructureType::ARRAY:
                if (!array.empty()) {
                    currentArrayIndex = (currentArrayIndex - 1 + maxArraySize) % maxArraySize;
                    return array[currentArrayIndex];
                }
                return "";
            case DataStructureType::STACK:
                if (!stack.empty()) {
                    std::string text = stack.top();
                    stack.pop();
                    return text;
                }
                return "";
            case DataStructureType::QUEUE:
                if (!queue.empty()) {
                    std::string text = queue.front();
                    queue.pop();
                    return text;
                }
                return "";
            default:
                return "";
        }
    }

    std::string getContentAtIndex(size_t index) {
        if (currentType == DataStructureType::ARRAY && index < array.size()) {
            return array[index];
        }
        return "";
    }

    void clear() {
        switch (currentType) {
            case DataStructureType::ARRAY:
                array.clear();
                currentArrayIndex = 0;
                break;
            case DataStructureType::STACK:
                while (!stack.empty()) stack.pop();
                break;
            case DataStructureType::QUEUE:
                while (!queue.empty()) queue.pop();
                break;
        }
    }

    DataStructureType getCurrentType() const {
        return currentType;
    }
}; 