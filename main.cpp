#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* build(vector<int> &inorder, int inorderBegin, int inorderEnd,
                    vector<int> &postorder, int postorderBegin, int postorderEnd) {
            if (postorderBegin > postorderEnd) return nullptr;
            TreeNode *root = new TreeNode(postorder[postorderEnd]);
            if (postorderBegin == postorderEnd) return root;
            int index;
            for (index = 0; index <= inorderEnd; index++) {
                if (inorder[index] == postorder[postorderEnd]) break;
            }
            // 缁熶竴閲囩敤宸﹂棴鍙抽棴鐨勬柟寮�
            int leftinorderBegin = inorderBegin;
            int leftinorderEnd = index - 1;
            int rightinorderBegin = index + 1;
            int rightinorderEnd = inorderEnd;

            int leftpostorderBegin = postorderBegin;
            int leftpostorderEnd = postorderBegin + index - inorderBegin - 1;
            int rightpostorderBegin = postorderBegin + index - inorderBegin;
            int rightpostorderEnd = postorderEnd - 1;//鎺掗櫎鏈€鍚庝竴涓厓绱�
            root->left = build(inorder, leftinorderBegin, leftinorderEnd, postorder, leftpostorderBegin, 
                            leftpostorderEnd);
            root->right = build(inorder, rightinorderBegin, rightinorderEnd, postorder, rightpostorderBegin, 
                            rightpostorderEnd);
            return root;
            
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
           TreeNode *root = build(inorder, 0, inorder.size() - 1, 
                                 postorder, 0, postorder.size() -1);
            return root;
            
    }
};
void preorder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);

}

int main() {
    Solution solution;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode *root = solution.buildTree(inorder, postorder);
    preorder(root);
    return 0;
}

   

 
// void creat(TreeNode* &p) {
//     int a;
//     cin >> a;
//     if (a == 0) {
//         p = nullptr;
//     }
//     else {
//         p = new TreeNode(a);
//         creat(p->left);
//         creat(p->right);
//     }
// }
// int treeDepth(TreeNode *root) {
//         if (root == nullptr) {
//             return 0;
//         }
//         else {
//             int m = treeDepth(root->left);
//             int n = treeDepth(root->right);
//             return m >= n ? (m + 1) : (n + 1);
//         }
// }
// void preorder(TreeNode *root) {
//     if (root == nullptr) {
//         return;
//     }
//     cout << root->val << " ";
//     preorder(root->left);
//     preorder(root->right);
// }
// void level(TreeNode *root, int l, vector<vector<int>> &result) {
//     if (root == nullptr) {
//         return;
//     }
//     //cout << root->val << " ";
//     result[l].push_back(root->val);
//     level(root->left, l + 1, result);
//     level(root->right, l + 1, result);
// }
// int main() {
//     TreeNode *root = nullptr;
//     creat(root);
//     preorder(root);
//     cout << endl;
//     int l = treeDepth(root);
//     cout << l << endl;
//     vector<vector<int>> result(l);
//     level(root, 0, result);
//     for (auto &a : result) {
//         for (auto & b : a) {
//             cout << b << " ";
//         }
//         cout << endl;
//     }
//     return 0;

// }

// void reverse(string &s, int i, int j) {
//     while (i < j) {
//         swap(s[i], s[j]);
//         i++;
//         j--;
//     }
// }
// void removeSpace (string &s) {
//     int fast = 0;
//     int slow = 0;
//     int size = (int)s.size();
//     //绉婚櫎鏈€鍓嶉潰鐨勭┖鏍�
//     while (fast < size && s[fast] == ' ') {
//         fast++;
//     }
//     //绉婚櫎杩炵画鐨勭┖鏍�
//     for (; fast < size; fast++) {
//         if (fast - 1 > 0 && s[fast] == ' ' && s[fast - 1] == ' ') {
//             continue;
//         }
//         else {
//             s[slow++] = s[fast];
//         }
//     }
//     //绉婚櫎鏈€鍚庣殑绌烘牸
//     if (slow - 1 > 0 && s[slow - 1] == ' ') {
//         s.resize(slow - 1);
//     }
//     else {
//         s.resize(slow);
//     }
// }


// string& reverseString(string &s) {
//     //瀹屽叏鍙嶈浆
//     reverse(s.begin(), s.end());
//     removeSpace(s);
//     for (int i = 0; i < s.size(); i++) {
//         int j = i;
//         while (j < s.size() && s[j] != ' ') {
//             j++;
//         }
//         reverse(s, i, j - 1);
//         i = j;
//     }
//     return s;
// }

// int main() {
//     string s = "     hello     world      ";
//     // string s1 = reverseString(s);
//     //cout << s1 << endl;
//     reverseString(s);

//     cout << s << endl;

    
//     return 0;
// }








// struct TreeNode {
//     int val;
//     TreeNode *root;
//     TreeNode *left;
//     TreeNode *right;
// };

// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode *root) {
//     vector<int> result;
//     TreeNode tree;
//     stack<TreeNode*> st;
//     if (root == nullptr) 
//         return result;
   
//     st.push(root);
//     while (!st.empty()) {
//         TreeNode *node = st.top();
//         if (node != nullptr) {
//         st.pop();
//         if (node->right)  st.push(node->right);
//         if (node->left)   st.push(node->left);
//         st.push(node);
//         st.push(nullptr);
//         } else {
//             st.pop();//绌烘寚閽堝嚭鏍�
//             node = st.top();
//             st.pop();
//             result.push_back(node->val);   
//     }   

//     }
//     return result;
//     }
    
// };
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode *root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         if (root != nullptr) {
//             st.push(root);
//         }
//         while (!st.empty()) {
//             TreeNode *node = st.top();
//             if (node != nullptr) {
//                 st.pop();
//                 st.push(node);
//                 st.push(nullptr);
//                 if (node->right) st.push(node->right);
//                 if (node->left) st.push(node->left);
//             } else {
//                 st.pop();
//                 node = st.top();
//                 st.pop();
//                 result.push_back(node->val);
//             }
//         }                                                                
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode *root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         TreeNode *cur = root, *pre = nullptr;
//         while (cur || !st.empty()) {
//             if (cur) {
//                 st.push(cur);
//                 cur = cur->left;
//             }
//             else {
//                 cur = st.top();
//                 if (cur->right != nullptr && cur->right != pre) {
//                     cur = cur->right;
//                 }
//                 else {
//                     cur = st.top();
//                     st.pop();
//                     result.push_back(cur->val);
//                     pre = cur;
//                     cur = nullptr;
//                 }
//             }

//         }
//         return result;
//     }
// };
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode *root) {

//         vector<int> result;
//         stack<TreeNode*> st;
//         TreeNode *cur = root;
//         if (cur != nullptr) {
//             st.push(cur);
//         }
//         while (!st.empty()) {
//             cur = st.top();
//             result.push_back(cur->val);
//             st.pop();
//             if (cur->right) {
//                 st.push(cur->right);
//             }
//             if (cur->left) {
//                 st.push(cur->left);
//             }
//         }
//         return result;
//     }
// };
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode *root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         TreeNode *cur = root;
//         while (cur || !st.empty()) {
//             if (cur) {
//                 st.push(cur);
//                 cur = cur->left;
//             }
//             else {
//                 cur = st.top();
//                 result.push_back(cur->val);
//                 st.pop();
//                 cur = cur->right;
//             }
//         }
//         return result;
//     }
// };



// //KMP绠楁硶
// void getNext(vector<int> &next, string &needle) {
//     int j = 0;
//     next[0] = 0;
//     for (int i = 1; i < needle.size(); i++) {
//         while (j > 0 && needle[i] != needle[j]) {
//             j = next[j - 1];
//         }
//         if (needle[i] == needle[j]) {
//             j++;
//         }
//         next[i] = j;
//     }
// }

// int strStr(string &haystack, string &needle) {
//     if (needle.size() == 0) {
//         return 0;
//     }
//     int j = 0;
//     vector<int> next(needle.size());
//     getNext(next, needle);
//     for (int i = 0; i < haystack.size(); i++) {
//         while (j > 0 && haystack[i] != needle[j]) {
//             j = next[j - 1];
//         }
//         if (haystack[i] == needle[j]) {
//             j++;
//         }
//         if (j == needle.size()) {
//             return i - needle.size() + 1;
//         }
//     }
//     return -1;
// }
        
   
// int main() {
//     string haystack = "abacabfg";
//     string needle = "cabf";
//     int result = strStr(haystack, needle);
//     cout << result << endl;
//     return 0;
// }



// int main()
// {
//     char a = 'a';
//     string s;
//     vector<string> ss;
//     s.push_back('a' + 1);
//     ss.emplace_back(s);
//     cout << s << endl;
//     for(auto &s : ss)
//         cout << s << ' ';
//     cout << endl;
// }



// typedef int(*Func)(int, int);

// int func(int m, int n)
// {
//     return m + n;
// }
// // void test(int m, int n, Func func)//鍑芥暟鎸囬拡
// // {
// //     int result = func(m, n);
// //     cout << result << endl;
// // }
// template<typename T, typename F>
// void test(const T &a, const T &b, F func)
// {
//     cout << func(a, b) << endl;
// }
// class A {
// public:
//     A() {
//         cout << "鏋勯€犲嚱鏁拌皟鐢�" << endl;
//     };
//     A(const A &a) {
//         cout << "鎷疯礉鏋勯€犲嚱鏁拌皟鐢�" << endl;
//     }
//     int operator()(int n, int m) { //瀵硅薄閫氳繃閲嶈浇锛堬級鍙樹负鍙皟鐢ㄥ璞★紝鍙互鍍忓嚱鏁颁竴鏍蜂娇鐢�
//        return n + m;
//     }
// };

// int main()
// {
//     //A a;
//     test(20, 20, A());
//     return 0;
// }