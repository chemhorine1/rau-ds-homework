
#include <iostream>
#include <stack>
#include <string>
#include<vector>
#include <queue>

bool isBalanced(std::string str) {
    std::stack<char> stk;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stk.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (stk.empty()) {
                return false;
            }

            if ((str[i] == ')' && stk.top() != '(') ||
                (str[i] == ']' && stk.top() != '[') ||
                (str[i] == '}' && stk.top() != '{')) {
                return false;
            }

            stk.pop();
        }
    }

    return stk.empty();
}




int evaluateRPN(std::vector<std::string> expr) {
    std::stack<int> stk;

    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == "+" || expr[i] == "-" || expr[i] == "*" || expr[i] == "/") {

            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();

            int result = 0;

            switch (expr[i][0]) {
                case '+':
                result = b + a; break;
                
                case '-': 
                result = b - a; break;
                
                case '*':
                result = b * a; break;
                
                case '/':
                result = b / a; break;
            }

            stk.push(result);
        } else {
            stk.push(std::stoi(expr[i]));
        }
    }

    return stk.top();
}



void reverseString(std::string& str){
    std::stack<char> stk;
    std::string h = "";
    for (int i = 0; i < str.size(); i++) {
        stk.push(str[i]);
    }
    for (int i = 0; i < str.size(); i++) {
        h+= stk.top();
        stk.pop();
    }
    str = h;
}





////////////////////////////////queue///////////////////////////////


std::string  hotPotato(std::vector<std::string> players, int k) {
    std::queue<std::string> q;

    for (int i = 0; i < players.size(); i++) {
        q.push(players[i]);
    }
    
    while(q.size() != 1){
        for (int i = 0; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    
    return q.front();
    
}



std::vector<std::string> generateBinaryNumbers(int n) {
    std::queue<std::string> q;
    std::vector<std::string> res;

    q.push("1");
    
    for (int i = 0; i < n; i++) {
        
        std::string now = q.front();
        q.pop();
        
        res.push_back(now);
        q.push(now + '0');
        q.push(now + '1');
        
    }

    return res;
}



int main() {
    
    /*
    
    // stak 1
    std::cout << isBalanced("({[]})") << '\n';  // 1
    std::cout << isBalanced("([)]") << '\n';    // 0
    std::cout << isBalanced("{[}]") << '\n';    // 0
    
    */

    /*
    std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
    std::cout << evaluateRPN(expr) << '\n';  //9
    // s2
    */
    
    
    /*
    std::string s = "Hello";
    reverseString(s);
    std::cout << s << '\n';  
    //s3
    
    */
    
    
    ///////////////////////////////////////////queue
    
    
    /*
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    std::cout << hotPotato(players, 7) << '\n';  // победитель
    
   // queue 1
    
    */
    
    
    /*
    
    std::vector<std::string> numbers = generateBinaryNumbers(5);

    for (const std::string& s : numbers) {
        std::cout << s << ' ';
    }
    
    // q2
    */
    
    
    
    

    return 0;
}
