class Solution {
public:

// is approach me ham s se empty string banayenge  

    bool isValid(string s) {
        if(s.size() == 0)
        {
            return true;
        }
        int found = s.find("abc");
        if(found!=string::npos)
        {
            string tleft = s.substr(0,found);
            string tright = s.substr(found+3,s.size());
            return isValid(tleft+tright);
        }
        return false;
    }
};
