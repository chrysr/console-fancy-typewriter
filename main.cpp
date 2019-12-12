#include <iostream>
#include <unistd.h>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <sys/ioctl.h>
#include <unistd.h>

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

int main(int argc,char** argv)
{
    map<string,string> col;
    col["red"]=Red;
    col["black"]=Black;
    col["green"]=Green;
    col["yellow"]=Yellow;
    col["blue"]=Blue;
    col["purple"]=Purple;
    col["cyan"]=Cyan;
    col["white"]=White;
    int maxperline=0;
    bool wordaline=false;
    bool oneline=false;
    bool fit=true;
    string input="";
    string color=Red;
    letter a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,gamma,delta,theta,lamda,xi,pi,sigma,fi,psi,omega,space;
    
    if(argc==1)
    {
        std::cout<<"Typewriter style console printer"<<std::endl;
        std::cout<<"Usage: "<<argv[0]<<" [OPTION] -txt <your text here>"<<std::endl;
        std::cout<<"   -oneline              Prints everything in one line *(Note this might mess up the output depending on your screen size"<<std::endl;
        std::cout<<"   -wline                Prints one word in each line"<<std::endl;
        std::cout<<"   -maxln <num>          Prints maximum <num> letter in each row"<<std::endl;
        std::cout<<"   -color <colorname>    Prints output (letters) with color"<<std::endl;
        std::cout<<"      "<<Red<<"red"<<std::endl; 
        std::cout<<"      "<<Black<<"black"<<std::endl;
        std::cout<<"      "<<Green<<"green"<<std::endl;
        std::cout<<"      "<<Yellow<<"yellow"<<std::endl;
        std::cout<<"      "<<Blue<<"blue"<<std::endl;
        std::cout<<"      "<<Purple<<"purple"<<std::endl;
        std::cout<<"      "<<Cyan<<"cyan"<<std::endl;
        std::cout<<"      "<<White<<"white"<<std::endl<<reset; 
        std::cout<<"Default is: "<<argv[0]<<" -color red (will fit max number of letters in each line)"<<std::endl;
        return 0;
    }
    for(int i=1;i<argc;i++)
    {
        if(strcmp(argv[i],"-oneline")==0)
        {    
            oneline=true;
            fit=false;
        }
        else if(strcmp(argv[i],"-wline")==0)
        {
            wordaline=true;
            fit=false;
        }
        else if(strcmp(argv[i],"-maxln")==0)
        {    
            maxperline=atoi(argv[i+1]);
            fit=false;
        }
        else if(strcmp(argv[i],"-txt")==0)
            input=argv[i+1];
        else if(strcmp(argv[i],"-color")==0)
            color=col[argv[i+1]];
    }
    
    if(input=="")
    {
        std::cout<<"No input text was provided! Bye!"<<std::endl;
        return 0;
    }
    if(wordaline&&!oneline&&!maxperline)
        std::cout<<"Running in (one word in every line) mode"<<std::endl;
    else if(oneline&&!wordaline&&!maxperline)
        std::cout<<"Running in (all text in one line) mode *(Note this might mess up the output)*"<<std::endl;
    else if(maxperline&&!wordaline&&!oneline)
        std::cout<<"Running in (max words in a line="<<maxperline<<") mode"<<std::endl;
    else if(!maxperline&&!wordaline&&!oneline&&fit)
    { 
        std::cout<<"Running in (fit most letter in a line) mode"<<std::endl;
    }
    else
    {
        std::cout<<"Please only select one of the following parameters when runnig the program\n\t-oneline\n\t-wline\n\t-maxln <num>"<<std::endl;
        return 0;
    }
    std::cout<<std::endl<<"Will be using the following input text:"<<std::endl<<color<<input<<reset<<std::endl<<std::endl;

    a.str[0]="        ***        ";
    a.str[1]="       ** **       ";
    a.str[2]="      **   **      ";
    a.str[3]="     **     **     ";
    a.str[4]="    ***********    ";
    a.str[5]="   **         **   ";
    a.str[6]="  **           **  ";
    a.str[7]=" **             ** ";

    b.str[0]=" **********  ";
    b.str[1]=" **      *** ";
    b.str[2]=" **      *** ";
    b.str[3]=" **********  ";
    b.str[4]=" **********  ";
    b.str[5]=" **      *** ";
    b.str[6]=" **      *** ";
    b.str[7]=" **********  ";

    c.str[0]="    ******* ";
    c.str[1]="  **        ";
    c.str[2]=" **         ";
    c.str[3]=" **         ";
    c.str[4]=" **         ";
    c.str[5]=" **         ";
    c.str[6]="  **        ";
    c.str[7]="    ******* ";

    d.str[0]=" *********    ";
    d.str[1]=" **       **  ";
    d.str[2]=" **        ** ";
    d.str[3]=" **        ** ";
    d.str[4]=" **        ** ";
    d.str[5]=" **        ** ";
    d.str[6]=" **       **  ";
    d.str[7]=" *********    ";

    e.str[0]=" *********** ";
    e.str[1]=" *********** ";
    e.str[2]=" ***         ";
    e.str[3]=" *********** ";
    e.str[4]=" *********** ";
    e.str[5]=" ***         ";
    e.str[6]=" *********** ";
    e.str[7]=" *********** ";

    f.str[0]=" *********** ";
    f.str[1]=" *********** ";
    f.str[2]=" ***         ";
    f.str[3]=" *********** ";
    f.str[4]=" ***         ";
    f.str[5]=" ***         ";
    f.str[6]=" ***         ";
    f.str[7]=" ***         ";

    g.str[0]="    *******    ";
    g.str[1]="  **      ***  ";
    g.str[2]=" **            ";
    g.str[3]=" **            ";
    g.str[4]=" **            ";
    g.str[5]=" **        *** ";
    g.str[6]="  **       *** ";
    g.str[7]="    ********   ";

    h.str[0]=" **        ** ";
    h.str[1]=" **        ** ";
    h.str[2]=" **        ** ";
    h.str[3]=" ************ ";
    h.str[4]=" ************ ";
    h.str[5]=" **        ** ";
    h.str[6]=" **        ** ";
    h.str[7]=" **        ** ";
    
    i.str[0]=" ******** "; 
    i.str[1]="    **    ";  
    i.str[2]="    **    ";  
    i.str[3]="    **    ";  
    i.str[4]="    **    ";  
    i.str[5]="    **    "; 
    i.str[6]="    **    ";
    i.str[7]=" ******** "; 

    j.str[0]=" ********** "; 
    j.str[1]="       **   ";  
    j.str[2]="       **   ";  
    j.str[3]="       **   ";  
    j.str[4]="       **   ";  
    j.str[5]="       **   "; 
    j.str[6]="      **    ";
    j.str[7]="  ****      "; 

    k.str[0]=" **      ** ";
    k.str[1]=" **    **   ";
    k.str[2]=" **  **     ";
    k.str[3]=" ****       ";
    k.str[4]=" ****       ";
    k.str[5]=" **  **     ";
    k.str[6]=" **    **   ";
    k.str[7]=" **      ** ";

    l.str[0]=" **           ";
    l.str[1]=" **           ";
    l.str[2]=" **           ";
    l.str[3]=" **           ";
    l.str[4]=" **           ";
    l.str[5]=" **           ";
    l.str[6]=" **           ";
    l.str[7]=" ************ ";

    m.str[0]=" **           ** ";     
    m.str[1]=" ****       **** ";    
    m.str[2]=" ** **     ** ** ";    
    m.str[3]=" **   ** **   ** ";    
    m.str[4]=" **     *     ** ";
    m.str[5]=" **           ** ";
    m.str[6]=" **           ** ";
    m.str[7]=" **           ** ";

    n.str[0]=" ****       ** ";
    n.str[1]=" ** **      ** "; 
    n.str[2]=" **  **     ** "; 
    n.str[3]=" **   **    ** "; 
    n.str[4]=" **    **   ** "; 
    n.str[5]=" **     **  ** ";  
    n.str[6]=" **      ** ** ";  
    n.str[7]=" **       **** ";    

    o.str[0]="      *******      ";
    o.str[1]="    **       **    "; 
    o.str[2]="  **           **  "; 
    o.str[3]=" ***           *** ";
    o.str[4]=" ***           *** "; 
    o.str[5]="  **           **  "; 
    o.str[6]="    **       **    ";
    o.str[7]="      *******      "; 

    p.str[0]=" ************ ";
    p.str[1]=" **        ** ";   
    p.str[2]=" **        ** ";   
    p.str[3]=" ************ ";   
    p.str[4]=" **           ";   
    p.str[5]=" **           ";   
    p.str[6]=" **           ";  
    p.str[7]=" **           ";    

    q.str[0]="      *******      ";
    q.str[1]="    **       **    "; 
    q.str[2]="  **           **  "; 
    q.str[3]=" ***           *** ";
    q.str[4]=" ***           *** "; 
    q.str[5]="  **           **  "; 
    q.str[6]="    ***      ***   ";
    q.str[7]="      ************ ";  

    r.str[0]=" ************  ";
    r.str[1]=" **        **  ";   
    r.str[2]=" **        **  ";   
    r.str[3]=" ************  ";   
    r.str[4]=" **  ***       ";   
    r.str[5]=" **    ***     ";   
    r.str[6]=" **      ***   ";  
    r.str[7]=" **        *** ";   

    s.str[0]="  ***********  ";
    s.str[1]=" ***********   ";   
    s.str[2]="  ****         ";   
    s.str[3]="   ******      ";   
    s.str[4]="     ******    ";   
    s.str[5]="        ****   ";   
    s.str[6]="  ***********  ";  
    s.str[7]=" ***********   ";   

    t.str[0]=" ************ ";
    t.str[1]="      **      ";   
    t.str[2]="      **      ";   
    t.str[3]="      **      ";   
    t.str[4]="      **      ";   
    t.str[5]="      **      ";   
    t.str[6]="      **      ";  
    t.str[7]="      **      ";  

    u.str[0]=" **        ** ";
    u.str[1]=" **        ** ";
    u.str[2]=" **        ** ";
    u.str[3]=" **        ** ";
    u.str[4]=" **        ** ";
    u.str[5]=" **        ** ";
    u.str[6]=" ***      *** ";
    u.str[7]="   ********   ";

    v.str[0]=" **        ** ";
    v.str[1]=" **        ** ";
    v.str[2]=" **        ** ";
    v.str[3]=" **        ** ";
    v.str[4]=" **        ** ";
    v.str[5]="  **      **  ";
    v.str[6]="   **    **   ";
    v.str[7]="    ******    ";

    w.str[0]=" **            ** ";     
    w.str[1]=" **            ** ";    
    w.str[2]=" **            ** ";    
    w.str[3]=" **     **     ** ";    
    w.str[4]=" **   **  **   ** ";
    w.str[5]=" ** **      ** ** ";
    w.str[6]=" ***          *** ";
    w.str[7]=" **            ** ";

    x.str[0]=" **        ** ";     
    x.str[1]="   **    **   ";    
    x.str[2]="    **  **    ";    
    x.str[3]="      **      ";    
    x.str[4]="      **      ";
    x.str[5]="    **  **    ";
    x.str[6]="   **    **   ";
    x.str[7]=" **        ** ";

    y.str[0]=" **        ** ";     
    y.str[1]="   **    **   ";    
    y.str[2]="    **  **    ";    
    y.str[3]="     ****     ";    
    y.str[4]="      **      ";
    y.str[5]="      **      ";
    y.str[6]="      **      ";
    y.str[7]="      **      ";

    z.str[0]=" ************ ";
    z.str[1]="          **  ";   
    z.str[2]="        **    ";   
    z.str[3]="       **     ";   
    z.str[4]="     **       ";   
    z.str[5]="   **         ";   
    z.str[6]="  **          ";  
    z.str[7]=" ************ ";   

    gamma.str[0]=" ************ ";
    gamma.str[1]=" ************ ";
    gamma.str[2]=" ***          ";
    gamma.str[3]=" ***          ";
    gamma.str[4]=" ***          ";
    gamma.str[5]=" ***          ";
    gamma.str[6]=" ***          ";
    gamma.str[7]=" ***          ";

    theta.str[0]="    ***********    ";
    theta.str[1]="   **         **   "; 
    theta.str[2]="  **           **  "; 
    theta.str[3]=" ***************** ";
    theta.str[4]=" ***************** "; 
    theta.str[5]="  **           **  "; 
    theta.str[6]="   **         **   ";
    theta.str[7]="    ***********    "; 

    sigma.str[0]=" ************ ";
    sigma.str[1]=" ************ ";
    sigma.str[2]="  **          ";
    sigma.str[3]="   **         ";
    sigma.str[4]="   **         ";
    sigma.str[5]="  **          ";
    sigma.str[6]=" ************ ";
    sigma.str[7]=" ************ ";

    lamda.str[0]="        ***        ";
    lamda.str[1]="       ** **       ";
    lamda.str[2]="      **   **      ";
    lamda.str[3]="     **     **     ";
    lamda.str[4]="    **       **    ";
    lamda.str[5]="   **         **   ";
    lamda.str[6]="  **           **  ";
    lamda.str[7]=" **             ** ";

    xi.str[0]=" ************** ";     
    xi.str[1]=" ************** ";    
    xi.str[2]="                ";    
    xi.str[3]="    ********    ";    
    xi.str[4]="    ********    ";
    xi.str[5]="                ";
    xi.str[6]=" ************** ";
    xi.str[7]=" ************** ";

    delta.str[0]="        ***        ";
    delta.str[1]="       ** **       ";
    delta.str[2]="      **   **      ";
    delta.str[3]="     **     **     ";
    delta.str[4]="    **       **    ";
    delta.str[5]="   **         **   ";
    delta.str[6]="  **           **  ";
    delta.str[7]=" ***************** ";

    fi.str[0]="    ***********    ";
    fi.str[1]="  ***   **    ***  "; 
    fi.str[2]=" ***    **     *** "; 
    fi.str[3]=" ***    **     *** ";
    fi.str[4]="  ***   **    ***  "; 
    fi.str[5]="    ***********    "; 
    fi.str[6]="        **         ";
    fi.str[7]="        **         "; 

    psi.str[0]=" ***    **    *** ";
    psi.str[1]=" ***    **    *** "; 
    psi.str[2]=" ***    **    *** "; 
    psi.str[3]=" ***    **    *** ";
    psi.str[4]="  ***   **   ***  "; 
    psi.str[5]="    ***********   "; 
    psi.str[6]="        **        ";
    psi.str[7]="        **        "; 

    omega.str[0]="    ***********    ";
    omega.str[1]="  ***         ***  "; 
    omega.str[2]=" ***           *** "; 
    omega.str[3]=" ***           *** ";
    omega.str[4]=" ***           *** "; 
    omega.str[5]="  ***         ***  "; 
    omega.str[6]="    ***     ***    ";
    omega.str[7]=" *******   ******* "; 

    space.str[0]="               ";
    space.str[1]="               "; 
    space.str[2]="               "; 
    space.str[3]="               ";
    space.str[4]="               "; 
    space.str[5]="               "; 
    space.str[6]="               ";
    space.str[7]="               "; 

    map<char,letter> table;
    table['a']=a;
    table['b']=b;
    table['c']=c;
    table['d']=d;
    table['e']=e;
    table['f']=f;
    table['g']=g;
    table['h']=h;
    table['i']=i;
    table['j']=j;
    table['k']=k;
    table['l']=l;
    table['m']=m;
    table['n']=n;
    table['o']=o;
    table['p']=p;
    table['q']=q;
    table['r']=r;
    table['s']=s;
    table['t']=t;
    table['u']=u;
    table['v']=v;
    table['w']=w;
    table['x']=x;
    table['y']=y;
    table['z']=z;
    table['α']=a;
    table['β']=b;
    table['γ']=gamma;
    table['δ']=delta;
    table['ε']=e;
    table['ζ']=z;
    table['η']=h;
    table['θ']=theta;
    table['ι']=i;
    table['κ']=k;
    table['λ']=lamda;
    table['μ']=m;
    table['ν']=n;
    table['ξ']=xi;
    table['ο']=o;
    table['π']=pi;
    table['ρ']=p;
    table['σ']=sigma;
    table['τ']=t;
    table['υ']=y;
    table['φ']=fi;
    table['χ']=x;
    table['ψ']=psi;
    table['ω']=omega;
    table['A']=a;
    table['B']=b;
    table['C']=c;
    table['D']=d;
    table['E']=e;
    table['F']=f;
    table['G']=g;
    table['H']=h;
    table['I']=i;
    table['J']=j;
    table['K']=k;
    table['L']=l;
    table['M']=m;
    table['N']=n;
    table['O']=o;
    table['P']=p;
    table['Q']=q;
    table['R']=r;
    table['S']=s;
    table['T']=t;
    table['U']=u;
    table['V']=v;
    table['W']=w;
    table['X']=x;
    table['Y']=y;
    table['Z']=z;
    table['Α']=a;
    table['Β']=b;
    table['Γ']=gamma;
    table['Δ']=delta;
    table['Ε']=e;
    table['Ζ']=z;
    table['Η']=h;
    table['Θ']=theta;
    table['Ι']=i;
    table['Κ']=k;
    table['Λ']=lamda;
    table['Μ']=m;
    table['Ν']=n;
    table['Ξ']=xi;
    table['Ο']=o;
    table['Π']=pi;
    table['Ρ']=p;
    table['Σ']=sigma;
    table['Τ']=t;
    table['Υ']=y;
    table['Φ']=fi;
    table['Χ']=x;
    table['Ψ']=psi;
    table['Ω']=omega;
    table['ς']=sigma;
    table[' ']=space;

    string str="";
    string refined="";
    for(int i=0;i<input.length();i++)
    {
        if(table.find(input[i])==table.end())
        {
            //std::cout<<input[i]<<std::endl;;
            continue;
        }
        refined+=input[i];
    }
    input=refined;
    refined="";
    if(fit)
    {
        vector <int> linepoints;
        vector <int> lineletters;
        linepoints.push_back(0);
        lineletters.push_back(0);
        struct winsize size;
        ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
        //std::cout<<size.ws_col<<" "<<size.ws_row<<std::endl;
        int flag=0;
        for(int i=0;i<input.length();i++)
        {
            // if(lines.size()==0)//||lines.back()+table[input[i]].str[0].length()>size.ws_row)
            //     lines.push_back(0);

            int sum=0;
            int letters=0;
            int j=i;
            for(;j<input.length();j++)
            {
                sum+=table[input[i]].str[0].length();
                letters++;
                if(input[j]==' ')
                    break;
            }
            //std::cout<<sum<<std::endl;
            if(sum>size.ws_col)
            {
                //cout<<"this case"<<std::endl;
                flag=1;
                break;
            }
            //fit by letter
            //lines.back()+=table[input[i]].str[0].length();
            if(linepoints.back()+sum>size.ws_col-10)
            {
                linepoints.push_back(sum);
                lineletters.push_back(letters);
            }
            else
            { 
                linepoints.back()+=sum;
                lineletters.back()+=letters;
            }
            i=j;
        }
        maxperline=0;
        //std::cout<<std::endl<<std::endl;
        // for(int i=0;i<lineletters.size();i++)
        //     std::cout<<lineletters[i]<<std::endl;
        if(!flag)
        {
            for(int i=0;i<lineletters.size();i++)
            {
                if(lineletters.at(i)<lineletters.at(maxperline))
                    maxperline=i;
            }
            //std::cout<<"maxpline: "<<lineletters.at(maxperline)<<std::endl;
            //std::cout<<"the other: "<<linepoints.at(maxperline)<<std::endl;
            //maxperline=lineletters.at(maxperline);
            for(int i=0,sum=0;i<lineletters.size();i++)
            {
                for(int k=0;k<8;k++)
                {
                    for(int j=0;j<lineletters.at(i);j++)
                    {
                        str+=table[input[sum+j]].str[k];
                    }
                    str+="\n";
                }
                sum+=lineletters.at(i);
                str+="\n\n";
            }
            maxperline=0;
        }
        else
        {
            
            int sum=0;
            for(int i=0;i<input.length();i++)
            {
                sum+=table[input[i]].str[0].length();
            }
            std::cout<<sum<<" "<<size.ws_col<<std::endl;
            maxperline=sum/size.ws_col;
            maxperline++;
            maxperline=input.length()/maxperline;
            
            std::cout<<maxperline<<" "<<input.length()<<std::endl;
        }
    }
    if(oneline)
    {
        for(int j=0;j<8;j++)
        {
            for(int i=0;i<input.length();i++)
                str+=table[input[i]].str[j];

            str+="\n";

        }
    }
    else if(maxperline)
    {
        if(maxperline!=1)
        {
            for(int i=0;i<input.length();i++)
            {
                if(i%maxperline==0&&input[i]==' ')
                    continue;
                refined+=input[i];
            }
            input=refined;

        }
        for(int line=0;line<(input.length()/maxperline)+1;line++)
        {
            for(int j=0;j<8;j++)
            {
                for(int i=line*maxperline;i<(line+1)*maxperline;i++)                    
                    str+=table[input[i]].str[j];
                
                str+="\n";
            }
            str+="\n\n";
        }
    }
    else if(wordaline)
    {
        for(int start=0;start<input.length();)
        {
            int nextspace=input.length()+1;
            for(int i=start;i<input.length();i++)
            {
                if(input[i]==' ')
                {
                    nextspace=i;
                    break;
                }
            }
            for(int j=0;j<8;j++)
            {
                for(int i=start;i<nextspace;i++)
                    str+=table[input[i]].str[j];
                
                str+="\n";
            }
            start=nextspace+1;
            str+="\n\n";
        }
    }
    

    cout<<color<<endl;  
    
    
    for(int i=0;i<str.length();i++)
    {
        cout<<str[i];
        fflush(stdout);
        //usleep(5000);
        //usleep(20000/input.length());
        usleep(str.length()/input.length()*50);

    }
    cout<<reset;
}