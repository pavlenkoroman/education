#include <iostream>
#include <string>

using namespace std;

bool is_sequention_right(string sequention) {
    std::stack<char> brackets;

    for (char ch : sequence) {
        if (ch == '(' || ch == '[' || ch == '<' || ch == '{') {
            brackets.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '>' || ch == '}') {
            if (brackets.empty()) {
                return false;
            }

            char top = brackets.top();
            brackets.pop();

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') ||
                (ch == '>' && top != '<') || (ch == '}' && top != '{')) {
                return false;
            }
        } else if (ch == '@') {
            break;
        }
    }

    return brackets.empty();
		&& openingSquareBracesCount == closingSquareBracesCount
		&& openingCurlyBracesCount == closingCurlyBracesCount
		&& openingTriangularBracesCount == closingTriangularBracesCount;
}