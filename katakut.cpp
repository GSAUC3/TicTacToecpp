#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int n=3;
// to display the content 
void display(char m[n][n],int n=3){
  
  int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
          if(m[i][j]=='x'|| m[i][j]=='o')
          cout<<m[i][j];
          else
        {
            cout<<m[i][j]-'a';
        }
            if(j<2)
            cout<<" | ";
        
        }
        cout<<endl;
        if(i<2)
        cout<<"---------\n";
    }

}

            //  main function starts right here 
int main(){
  char g[n][n];
  int c=0; 
  int v[12]{0};
  
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
        
            g[i][j]='a'+(++c);
            
        }
    }
int win =0;
int count=0;
  cout<<"WELCOME TO TIC TAC TOE aka Kata Kuti\n";
  cout<<"  *******************************   \n";
  cout<<"Player 1 -> x\n"; 
  cout<<"Player 2 -> o\n";
  cout<<"  *******************************   \n";
  cout<<"   TO START THE GAME PRESS 1\n";
  cout<<"  *******************************   \n";
  int x;
   // the 1 that the user will press to start the game

  cin>>x;cout<<endl;
  display(g);
  while(x){ 
  cout<<"Player "<<(x%2?1:2)<<" your turn. Enter the position:\n";
   int in; cin>>in;
   //check input status
    if(v[in]!=0)
    {cout<<"INVALID CHOICE, CHECK CAREFULLY CHOMPA AND TRY AGAIN\n";
         continue;}
         x%2?v[in]=1 : v[in]=5;
   //update matrix
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
         if(g[i][j]==in+'a' && x%2!=0){
         g[i][j]='x';count++;}
         else if(g[i][j]==in+'a')
         {
           g[i][j]='o';count++;
         }
         
        }
      }
  
 display (g);
 x++;
 //win logic;
 
 if((v[1]+v[5]+v[9] == 3)||(v[7]+v[5]+v[3]==3))
 {//diagonal
   win=1;goto l;
 }
 if((v[1]+v[5]+v[9] == 15)||(v[7]+v[5]+v[3]==15))
 {
   win=2;goto l;
 }
for(int i=0;i<3;i++){
  if(v[1+i]+v[4+i]+v[7+i]==3)
  {win=1;break;}
  if(v[1+i]+v[4+i]+v[7+i]==15)
  {win=2;break;}
  //column logic
}
for(int i=0;i<3;i++){
 if(v[1+i*3]+v[2+i*3]+v[3+i*3]==3)
 {win=1;break;}
 if(v[1+i*3]+v[2+i*3]+v[3+i*3]==15)
 {win=2;break;}
}//row logic
l:
if(win==1){
  cout<<"CONGRATS deadpool YOU AKA PLAYER 1 WON\n";break;
}else if(win==2)
{
  cout<<"CONGRATS batman YOU AKA PLAYER 2 WON\n";break;
}else if(count==9)
{
  cout<<"TIE A TIE KIDDo.O\n";
  
}

  }

  system("PAUSE");
return 0;}