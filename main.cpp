#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using std::vector;

typedef std::string Word;

vector<Word> read_words(std::istream&);
vector<Word> sort_words(vector<Word>);
vector<Word> merge(vector<Word>, vector<Word>);

int main(void) {
  vector<Word> words = read_words(std::cin);
  vector<Word> sorted = sort_words(words);
  for (Word w : sorted) std:: cout << w << std::endl;
  return EXIT_SUCCESS;
}

vector<Word> read_words(std::istream& stream) {
  vector<Word> words;
  for (Word w; stream >> w;) words.push_back(w);
  return words;
}

vector<Word> sort_words(vector<Word> words) {
  size_t num_words = words.size();
  if (num_words == 1) {
    return words;
  } else {
    size_t middle = ceil(num_words / 2.0);
    vector<Word> left(words.begin(), words.begin() + middle);
    vector<Word> right(words.begin() + middle, words.end());
    vector<Word> sorted = merge(sort_words(left), sort_words(right));
    return sorted;
  }
}

vector<Word> merge(vector<Word> words1, vector<Word> words2) {
  size_t num_words = words1.size() + words2.size();
  vector<Word> merged(num_words);
  vector<Word>::iterator w1 = words1.begin();
  vector<Word>::iterator w2 = words2.begin();
  for (size_t i = 0; i < num_words; ++i) {
    if (w1 == words1.end()) {
      merged[i] = *w2;
      w2 += 1;
    } else if (w2 == words2.end()) {
      merged[i] = *w1;
      w1 += 1;
    } else {
      if (*w1 <= *w2) {
	merged[i] = *w1;
	w1 += 1;
      } else {
	merged[i] = *w2;
	w2 += 1;
      }
    }
  }
  return merged;
}
