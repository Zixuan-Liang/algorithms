/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:

    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] == b[i])
                matches ++;
        return matches;
    }

// Generally, we will get 0 matches from the master.guess.
// As a result, the size of wordlist reduces slowly.

// Recall some math here, the possiblity that get 0 matched is:
// (25/26) ^ 6 = 79.03%

// That is to say, if we make a blind guess,
// we have about 80% chance to get 0 matched with the secret word.

// To simplify the model,
// we're going to assume that,
// we will always run into the worst case (get 0 matched).

// In this case,
// we have 80% chance to eliminate the candidate word
// as well as its close words which have at least 1 match.

// Additionally, in order to delete a max part of words,
// we select a candidate who has a big "family",
// (that is, the fewest 0 matched with other words.)
// We want to guess a word that can minimum our worst outcome.

// So we compare each two words and count their matches.
// For each word, we note how many word of 0 matches it gets.
// Then we guess the word with minimum words of 0 matches.

// In this solution, we apply a minimax idea.
// We minimize our worst case,
// The worst case is max(the number of words with x matches),
// and we assume it equal to "the number of words with 0 matches"

// Time complexity O(N^2)
// Space complexity O(N)

    // Minimax
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
            unordered_map<string, int> count;
            for (string w1 : wordlist)
                for (string w2 : wordlist)
                    if (match(w1, w2) == 0)
                        count[w1]++;
            pair<string, int> minimax = {wordlist[0], 1000};
            for (string w : wordlist)
                if (count[w] <= minimax.second)
                    minimax = make_pair(w, count[w]);
            x = master.guess(minimax.first);
            vector<string> wordlist2;
            for (string w : wordlist)
                if (match(minimax.first, w) == x)
                    wordlist2.push_back(w);
            wordlist = wordlist2;
        }
    }
    
// In the previous solution, we compaired each two words.
// This make the complexity O(N^2) for each turn.

// But actually we don't have to do that.
// We just need to count the occurrence for each character on each position.

// If we can guess the word that not in the wordlist,
// we can guess the word based on the most frequent character on the position.

// Here we have to guess a word from the list,
// we still can calculate a score of similarity for each word,
// and guess the word with highest score.

// Time complexity O(N)
// Space complexity O(N)

    void findSecretWord(vector<string>& wordlist, Master& master) {
        int count[6][26], x = 0, best;
        for (int t = 0; t < 10 && x < 6; ++t) {
            memset(count, 0, 156 * sizeof(int));
            for (string w : wordlist)
                for (int i = 0; i < 6; ++i)
                    count[i][w[i] - 'a']++;
            best = 0;
            string guess = wordlist[0];
            for (string w: wordlist) {
                int score = 0;
                for (int i = 0; i < 6; ++i)
                    score += count[i][w[i] - 'a'];
                if (score > best) {
                    guess = w;
                    best = score;
                }
            }
            x = master.guess(guess);
            vector<string> wordlist2;
            for (string w : wordlist)
                if (match(guess, w) == x)
                    wordlist2.push_back(w);
            wordlist = wordlist2;
        }
    }

};