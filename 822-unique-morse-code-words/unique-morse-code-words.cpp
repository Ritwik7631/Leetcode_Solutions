class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> transformations;

        vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        for(auto word : words)
        {
            string temp = "";

            for(auto ch : word)
            {
                temp += dict[ch - 'a'];
            }

            transformations.insert(temp);
        }

        return transformations.size();
    }
};