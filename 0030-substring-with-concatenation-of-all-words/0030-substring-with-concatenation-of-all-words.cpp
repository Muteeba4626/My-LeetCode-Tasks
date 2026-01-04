// LeetCode 30 - Substring with Concatenation of All Words
// https://leetcode.com/problems/substring-with-concatenation-all-words/
// Author: muteeba4266

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int n = s.length();
        int wordCount = words.size();
        int wordLen = words[0].length();
        int totalLen = wordCount * wordLen;

        unordered_map<string, int> wordFreq;
        for (const string& w : words) {
            wordFreq[w]++;
        }

        // We only need to check starting offsets from 0 to wordLen - 1
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> currentFreq;

            for (int j = i; j <= n - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (wordFreq.count(word)) {
                    currentFreq[word]++;
                    count++;

                    // If a word appears more times than expected, shrink from the left
                    while (currentFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentFreq[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Found a complete concatenation
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Word not in list: reset the window
                    currentFreq.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};