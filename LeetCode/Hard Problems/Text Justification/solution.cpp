class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        /*
        add words to a line until doing so would exceed max width,
        then construct a line by distributing spaces until max width is reached
        */
        
        vector<string> ans;

        int charcount = 0;

        vector<string> line;

        for (auto s : words) {

            int len = s.size();

            if (charcount + len <= maxWidth) {

                charcount += len + 1;

                line.push_back(s);

            }

            else {

                int numwords = line.size();

                charcount -= numwords;

                int numspaces = maxWidth - charcount;
                
                int i = 0;

                while (numspaces > 0 && numwords > 1) {

                    cout << "i " << i << endl;
                    cout << "n " << numspaces << endl;

                    if (i != numwords - 1) {
                        line[i] += " ";
                        numspaces--;
                        i++;
                    }
                    else { i = 0; }

                }

                string makeline = "";
                for (auto s : line) {
                    
                    makeline += s;

                }

                while (makeline.size() < maxWidth) makeline += " ";

                ans.push_back(makeline);

                line = {s};
                charcount = s.size() + 1;

            }

        }

        string lastline = "";

        for (auto s : line) {
            if(lastline.size() + s.size() + 1 <= maxWidth) lastline += s + " ";
            else lastline += s;
        }

        while (lastline.size() < maxWidth) lastline += " ";

        ans.push_back(lastline);

        return ans;


    }
};
