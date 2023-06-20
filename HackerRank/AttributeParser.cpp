#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class tag {
    
    public:
    
    string tagname;

    map<string, string> att;

    map<string, tag> dau;
    
    tag *parent;

    tag(string s) {
        tagname = s;
        parent = this;
    }

    tag(string s, tag &t) {
        tagname = s;
        parent = &t;
    }

    tag(tag *t) {
        tagname = t->tagname;
        parent = t->parent;
    }
    
    void add_daughter(string s, tag t) {
        dau.insert(pair<string, tag>(s, new tag(&t)));
    }
    
    tag& find_daughter(string s) {
        try {
            return dau.at(s);
        }
        catch (const std::out_of_range& oor) {
            return *this;
        }
    }
    
    string att_val(string s) {
        try {
            return att.at(s);
        }
        catch (const std::out_of_range& oor) {
            return "Not Found!";
        }
    }
};

class tag_tree {

    public:

    tag tagroot = tag("root");

    tag *current_tag = &tagroot;

    tag_tree() {

    }

    void add_att(string s1, string s2) {
        current_tag->att.insert(pair<string, string>(s1, s2));
    }

    void add_tag(string s) {
        
        current_tag->add_daughter(s, tag(s, *current_tag));
        current_tag = &current_tag->find_daughter(s);
    }

    void pup() {
        current_tag = current_tag->parent;
    }
    
    void move_to(string s) {
        current_tag = &current_tag->find_daughter(s);
    }
    
    string get_att(string goal, string s) {
        if (current_tag->tagname.compare(goal) == 0)
            return current_tag->att_val(s);
        else return "Not Found!";
    }
    
    void root() {
        current_tag = &tagroot;
    }
};

int main() {
    int n; 
    int q;
    
    string line;
    string white;

    tag_tree tree;

    scanf("%d %d", &n, &q);

    getline(cin, white); //consumes \n
    
    for (int i = 0; i < n; i++) {
        getline(cin, line);

        if (line.at(1) == '/') {
            //cout<<"moved from: "<<tree.current_tag->tagname;
            tree.pup();
            //cout<<" to: "<<tree.current_tag->tagname<<endl;

        }
        else {
            //parse instructions then follow

            string line_tag;

            int space;

            if (line.find(' ', 0) != line.npos)
                space = line.find(' ', 0);

            else space = line.size() - 1;

            line_tag = line.substr(1, space-1);

            tree.add_tag(line_tag);
            //cout<<"added: "<<line_tag<<endl;
            int equals = 0;
            int pec = 0;

            while (pec != line.npos) {
                pec = line.find('=', pec+1);
                if (pec != line.npos) equals++;
            }

            int pos = line.find('=', 0);

            for (int j = 0; j < equals; j++) {
                string att_id = line.substr(space+1, pos-space-2);

                int con_start = line.find('\"', pos);
                int con_end = line.find('\"', con_start+1);
                space = con_end+1;

                pos = line.find('=', con_end);

                string att_con = line.substr(con_start+1, con_end-con_start-1);

                //cout<<"adding a:"<<att_id<<" v:"<<att_con<<endl;
                tree.add_att(att_id, att_con);
            }
        }
    }
    
    
    
    for (int i = 0; i < q; i++) {
        tree.root();
        getline(cin, line);
        
        int tilde = line.find('~', 0);
        
        string queryval = line.substr(tilde+1, line.size()-tilde-1);
        string querytag = line.substr(0, tilde);
        
        int pos = 0;
                
        //cout<<querytag<<endl;
        string goal;

        while (pos != querytag.npos) {
            int dot = querytag.find('.', pos);

            if (dot != querytag.npos) {
                goal = querytag.substr(pos, dot-pos);

                pos = dot+1;
            }

            else {
                goal = querytag.substr(pos, querytag.size()-pos);
                pos = -1;
            }
        
            //cout<<"goal: "<<goal<<endl;

            tree.move_to(goal);
            //cout<<"moved to "<<tree.current_tag->tagname<<endl<<endl;
        }
        
        cout<<tree.get_att(goal, queryval)<<endl;
    }

    return 0;
}
