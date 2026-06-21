class Solution {
public:

    bool ans=false;
    string str="";
    vector<vector<char>> board;
    string word;
    void findword(int k,int i,int j)//passing k, i and j 
    //k is index of the word till where we have found the word 
    // i and j are the curr i and j.
    {
        if(str==word){ans=true;return;}//if word is currently stored in str, then set ans to true and break
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){return;}//if index out of bounds, then return
        if((char)board[i][j]=='#'){return;}//if cell already explored, return.
        if(ans==true){return;}//if the ans is already found, then break from loop
        if(str.size()>=word.size()){return;}//if strlen is more than wordlen then quit 
        if((char)board[i][j]==(char)word[k])//if the match happens, then continue search for the next letter in all directions
        {
            char a=board[i][j];
            board[i][j]='#';
            str.push_back(a);
            findword(k+1, i+1, j);
            findword(k+1, i-1, j);
            findword(k+1, i, j+1);
            findword(k+1, i, j-1);
            str.pop_back();//backtracktracking
            board[i][j]=a;
        }
    }
    bool exist(vector<vector<char>>& board_in, string word_in) {
        board=board_in;
        word=word_in;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                findword(0,i,j);
            }
        }
        return ans;
    }

};
