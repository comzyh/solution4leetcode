class Solution {
public:
    int nextint(const char* &str) {
        int ans = 0;
        while (*str >= '0' && *str <= '9') {
            ans *= 10;
            ans += *(str ++) - '0';
        }
        return ans;
    }
    string nextstring(const char * &str) {
        const char *e = str;
        for (;*e != ']' && !(*e >= '0' && *e <= '9') && *e != '\0'; e++);
        string ans(str, e - str);
        str = e;
        return ans;
    }
    string decode(const char * &str) {
        string ans;
        while(*str != '\0' && *str != ']') {
            int rep = nextint(str);            
            if (rep == 0) {
                string repstr = nextstring(str);
                ans.append(repstr);                
            } else {
                str ++; // skip [
                string repstr = decode(str);
                str ++; // skip ]
                while(rep --){
                    ans.append(repstr);
                }    
            }    
        }
        return ans;
    }
    string decodeString(string s) {
        const char *str = s.data();
        return decode(str);
    }
};
