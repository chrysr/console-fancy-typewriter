#ifndef FUNC_
#define FUNC_
#include <iostream>
#include <unistd.h>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>

using namespace std;
#define reset "\033[0m"
#define Black "\033[0;30m"         //Black
#define Red "\033[0;31m"           //Red
#define Green "\033[0;32m"         //Green
#define Yellow "\033[0;33m"        //Yellow
#define Blue "\033[0;34m"          //Blue
#define Purple "\033[0;35m"        //Purple
#define Cyan "\033[0;36m"          //Cyan
#define White "\033[0;37m"         //White
#define colorful "colorful"

 //Bold
#define BBlack "\033[1;30m"        //Black
#define BRed "\033[1;31m"          //Red
#define BGreen "\033[1;32m"        //Green
#define BYellow "\033[1;33m"       //Yellow
#define BBlue "\033[1;34m"         //Blue
#define BPurple "\033[1;35m"       //Purple
#define BCyan "\033[1;36m"         //Cyan
#define BWhite "\033[1;37m"        //White

 //Underline
#define UBlack "\033[4;30m"        //Black
#define URed "\033[4;31m"          //Red
#define UGreen "\033[4;32m"        //Green
#define UYellow "\033[4;33m"       //Yellow
#define UBlue "\033[4;34m"         //Blue
#define UPurple "\033[4;35m"       //Purple
#define UCyan "\033[4;36m"         //Cyan
#define UWhite "\033[4;37m"        //White

 //Background
#define On_Black "\033[40m"        //Black
#define On_Red "\033[41m"          //Red
#define On_Green "\033[42m"        //Green
#define On_Yellow "\033[43m"       //Yellow
#define On_Blue "\033[44m"         //Blue
#define On_Purple "\033[45m"       //Purple
#define On_Cyan "\033[46m"         //Cyan
#define On_White "\033[47m"        //White

 //High Intensty
#define IBlack "\033[0;90m"        //Black
#define IRed "\033[0;91m"          //Red
#define IGreen "\033[0;92m"        //Green
#define IYellow "\033[0;93m"       //Yellow
#define IBlue "\033[0;94m"         //Blue
#define IPurple "\033[0;95m"       //Purple
#define ICyan "\033[0;96m"         //Cyan
#define IWhite "\033[0;97m"        //White

 //Bold High Intensty
#define BIBlack "\033[1;90m"       //Black
#define BIRed "\033[1;91m"         //Red
#define BIGreen "\033[1;92m"       //Green
#define BIYellow "\033[1;93m"      //Yellow
#define BIBlue "\033[1;94m"        //Blue
#define BIPurple "\033[1;95m"      //Purple
#define BICyan "\033[1;96m"        //Cyan
#define BIWhite "\033[1;97m"       //White

 //High Intensty backgrounds
#define On_IBlack "\033[0;100m"    //Black
#define On_IRed "\033[0;101m"      //Red
#define On_IGreen "\033[0;102m"    //Green
#define On_IYellow "\033[0;103m"   //Yellow
#define On_IBlue "\033[0;104m"     //Blue
#define On_IPurple "\033[10;95m"   //Purple
#define On_ICyan "\033[0;106m"     //Cyan
#define On_IWhite "\033[0;107m"    //White

class letter{
public:
    string str[8];
};

extern letter a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,gamma,delta,theta,lamda,xi,pi,sigma,fi,psi,omega,space;
extern map<char,letter> table;
extern map<string,string> col;

void init();
void usage(char** argv);
void params(char** argv,int argc,bool& vertical,string& input,string& color,int& speed);
string getnextword(string input,int& place);
string printwordvertically(string str);
void printfit(vector<string> &lines,string tmp,int& remaining);
string addto(string basic,string add);
string refineinput(string input);
void makecolorarray(vector<string> &clrs);





#endif