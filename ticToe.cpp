#include<iostream>
#include<string>
#include<vector>
using namespace std;
//requirements board,players
//1.construction of board
class board{
    public:
    int size;
    vector<vector<char>>matrix;
    board(){
        this->size=3;
        this->matrix=vector<vector<char>>(3,vector<char>(3,'-'));
    }
    board(int n){
        this->size=n;
        this->matrix=vector<vector<char>>(n,vector<char>(n,'-'));
    }
    void displayBoard(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
//player details
//1.constructor 2.fn set 3.get fn
class player{
    private:
    string name;
    string number;
    char sym;
    public:
    player(){
        this->name="navya";
        this->sym='o';
    }
    player(string name,char sym){
        this->name=name;
        this->sym=sym;
    }
    player(string name,string number,char sym){
        this->name=name;
        this->number=number;
        this->sym=sym;
    }
    string getName() const{
        return name;
    }
    string getNumber() const{
        return number;
    }
    char getSym() const{
        return sym;
    }
    void displayPlayerDetails(){
        cout<<"Player name: "<<this->name<<endl;
        cout<<"player number"<<this->number<<endl;
        cout<<"player symbol"<<this->sym<<endl;
    }
};
    class game{
        player pl;
        player p2;
        board b1;
        int turn;
        int noOfMoves;
        //bool gameOver;
        string zero;
        string cross;
        public:
        string symbol;
        game(player p1,player p2,board b1){
            this->pl=p1;
            this->p2=p2;
            p1.displayPlayerDetails();
            p2.displayPlayerDetails();
            this->b1=b1;
            this->turn=0;
            this->noOfMoves=0;
            //this->gameOv1`er=false;
            string z="";
            string s="";
            this->symbol = string(1, p1.getSym()) + string(1, p2.getSym());
            for(int i=0;i<b1.size;i++){
                z+=p1.getSym();
                s+=p2.getSym();
            }  
            this->zero=z;
            this->cross=s;
        }
        int position(){
            int p;
            cout<<"enter the index"<<endl;
            cin>>p;
            if(p>=b1.size*b1.size ){
                return -1;
            }
            return p;
        } 
        bool checkCombinations(){
            int sz=b1.size;
            string check="";
            for(int i=0;i<sz;i++){
                check="";
                for(int j=0;j<sz;j++){
                    check+=b1.matrix[i][j];
                }
                if(check==this->zero || check==this->cross){
                    return true;
                }
            }
            for(int i=0;i<sz;i++){
                check="";
                for(int j=0;j<sz;j++){
                    check+=b1.matrix[j][i];
                }
                if(check==this->zero || check==this->cross){
                    return true;
                }
            }
            int i=0,j=0;
            check="";
            while(i<sz){
                check+=b1.matrix[i][j];
                i++;
                j++;
            }
            if(check==this->zero||check==this->cross)
            return true;
            i=0,j=sz-1;
            check="";
            while(i<sz){
                check+=b1.matrix[i][j];
                i++;
                j--;
            }
            if(check==this->zero||check==this->cross){
                return true;
            }
            return false;
        }
        int play(){
            int sz=b1.size;
            for(int i=0;i<sz*sz;i++){
                if((i>=2*sz-1&&checkCombinations()) ){
                     break;
                }
                else{
                    int index=position();
                    if(index!=-1){
                        int row=index/sz;
                        int col=index%sz;
                        b1.matrix[row][col]=symbol[turn];
                    }
                }
                turn=(turn+1)%2;
                noOfMoves++;
                b1.displayBoard();
            }
            if(noOfMoves>=sz*sz){
                return -1;
            }
            else{
                return turn;
            }
        } 
    };

int main(){
    string name1,name2;
    cout<<"Enter the 1st player name"<<endl;
    cin>>name1;
    string number1,number2;
    cout<<"Enter the 1st player contact"<<endl;
    cin>>number1;
    char sym1,sym2;
    cout<<"Enter the 1st player symbol"<<endl;
    cin>>sym1;
    cout<<"Enter the 2nd player name"<<endl;
    cin>>name2;
    cout<<"Enter the 2nd player contact"<<endl;
    cin>>number2;
    cout<<"Enter the 2nd player symbol"<<endl;
    cin>>sym2;
    class player p1(name1,number1,sym1);
    class player p2(name2,number2,sym2);
    int size;
    cout<<"enter the size of the board"<<endl;
    cin>>size;
    board b1(size);
    game g1(p1,p2,b1);
    int result=g1.play();
    if(result==0){
        cout<<p1.getName()<<"is winner"<<endl;
    }
    else if(result==1){
        cout<<p2.getName()<<"is winner"<<endl;
    }
    else{
        cout<<"Draw"<<endl;
    }
    return 0;
}
