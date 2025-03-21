#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

// Function to process file and create word frequency map
map<string, int> getWordFrequencies(const string &filename) {
    ifstream file(filename);
    map<string, int> freq;
    string word;
    
    if (!file) {
        cerr << "Error: Cannot open file " << filename << endl;
        exit(1);
    }

    while (file >> word) {
        freq[word]++;
    }
    
    return freq;
}

// Function to compute cosine similarity
float cosineSimilarity(map<string, int> &freq1, map<string, int> &freq2) {
    float dotProduct = 0.0, sum1 = 0.0, sum2 = 0.0;

    // Explicit iterator for compatibility
    for (map<string, int>::iterator it = freq1.begin(); it != freq1.end(); ++it) {
        string word = it->first;
        int count = it->second;
        dotProduct += count * freq2[word]; // Dot product
        sum1 += count * count; // Squared sum of freq1
    }

    for (map<string, int>::iterator it = freq2.begin(); it != freq2.end(); ++it) {
        int count = it->second;
        sum2 += count * count; // Squared sum of freq2
    }

    if (sum1 == 0 || sum2 == 0) return 0.0; // Avoid division by zero

    return dotProduct / (sqrt(sum1) * sqrt(sum2));
}

// Main function
int main() {
    string file1 = "file1.txt";
    string file2 = "file2.txt";

    map<string, int> freq1 = getWordFrequencies(file1);
    map<string, int> freq2 = getWordFrequencies(file2);

    float similarity = cosineSimilarity(freq1, freq2);

    cout << "Cosine Similarity: " << similarity << endl;
    return 0;
}
