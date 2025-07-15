
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = nullptr ;
    }
};

class Solution {
  public:
    int distance(int x, int y) {
          int cnt=0;
          while(x!=y){
              if(x>y){
                  x/=2;
              }
              else{
                  y/=2;
              }
              cnt++;
          }
          return cnt;
          
    }
};