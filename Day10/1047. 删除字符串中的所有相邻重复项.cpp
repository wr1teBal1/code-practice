class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> word;
        for(char c : s){
            if(word.empty()){
                word.push(c);
            }
            else if(word.top() == c){
                word.pop();
            }
            else{
                word.push(c);
            }
        }
        string res;
        while(!word.empty()){
            res += word.top(); // 直接拼接字符，自动扩展字符串
            word.pop();
        }
        
        reverse(res.begin(), res.end()); // 反转得到正确顺序
        return res;
    }

};