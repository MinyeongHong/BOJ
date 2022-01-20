#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<char,char> tree[100];
vector<char> result;

void pre(pair<char, char> tree[],int idx) {
    result.push_back(idx + 'A');

    if (tree[idx].first == '.' && tree[idx].second == '.') {
        return;
    }
    else if (tree[idx].first == '.') {
        pre(tree, tree[idx].second - 'A');

    }
    else if (tree[idx].second == '.') {
        pre(tree, tree[idx].first - 'A');
    }
    else {
        pre(tree, tree[idx].first - 'A');
        pre(tree, tree[idx].second - 'A');
    }
    return;
}

void in(pair<char, char> tree[], int idx) {

    if (tree[idx].first == '.' && tree[idx].second == '.') {
        result.push_back(idx + 'A');
        return;
    }
    else if (tree[idx].first == '.') {
        result.push_back(idx + 'A');
        in(tree, tree[idx].second - 'A');

    }
    else if (tree[idx].second == '.') {
        in(tree, tree[idx].first - 'A');
        result.push_back(idx + 'A');
        return;
    }
    else {
        in(tree, tree[idx].first - 'A');
        result.push_back(idx + 'A');
        in(tree, tree[idx].second - 'A');
    }
    return;
}

void post(pair<char, char> tree[], int idx) {
    if (tree[idx].first == '.' && tree[idx].second == '.') {
        result.push_back(idx + 'A');
        return;
    }
    else if (tree[idx].first == '.') {
        post(tree, tree[idx].second - 'A');
        result.push_back(idx + 'A');
        return;

    }
    else if (tree[idx].second == '.') {
        post(tree, tree[idx].first - 'A');
        result.push_back(idx + 'A');
        return;
    }
    else {
        post(tree, tree[idx].first - 'A');
        post(tree, tree[idx].second - 'A');
        result.push_back(idx + 'A');
    }
    return;
}

int main(void) {
    int n,index;
    char a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        index = a - 'A';
        tree[index] = { b,c };
    }
    pre(tree, 0);
    for (auto itr = result.begin(); itr < result.end(); itr++) printf("%c", *itr);    printf("\n");
    result.clear();
    in(tree, 0);
    for (auto itr = result.begin(); itr < result.end(); itr++) printf("%c", *itr);    printf("\n");
    result.clear();
    post(tree, 0);
    for (auto itr = result.begin(); itr < result.end(); itr++) printf("%c", *itr);    printf("\n");

    return 0;
}
