#include "functions.h"
letter a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,gamma,delta,theta,lamda,xi,pi,sigma,fi,psi,omega,space;
map<char,letter> table;
map<string,string> col;
struct winsize size;
        

void init(){
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    col["red"]=Red;
    col["black"]=Black;
    col["green"]=Green;
    col["yellow"]=Yellow;
    col["blue"]=Blue;
    col["purple"]=Purple;
    col["cyan"]=Cyan;
    col["white"]=White;
    col["colorful"]=colorful;

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
    table['ά']=a;
    table['έ']=e;
    table['ή']=h;
    table['ί']=i;
    table['ό']=o;
    table['ύ']=y;
    table['ώ']=omega;
}

void usage(char** argv)
{
    std::cout<<"Typewriter style console printer"<<std::endl;
    std::cout<<"Usage: "<<argv[0]<<" [OPTIONS] "<<std::endl;
    std::cout<<"   -vertical             Prints everything in one line *(Note this might mess up the output depending on your screen size"<<std::endl;
    std::cout<<"   -txt <your text here> The text you want to print with the program"<<std::endl;
    std::cout<<"   -color <colorname>    Prints output (letters) with color"<<std::endl;
    std::cout<<"   -s0                   Instant Print"<<std::endl;
    std::cout<<"   -s1                   Slower than s0 print"<<std::endl;
    std::cout<<"   -s2                   Slower than s1 print"<<std::endl;
    std::cout<<"   -s3                   Slower than s2 print"<<std::endl;
    std::cout<<"   -s4                   Slower than s3 print"<<std::endl;
    std::cout<<"      "<<Red<<"red"<<std::endl; 
    std::cout<<"      "<<Black<<"black"<<std::endl;
    std::cout<<"      "<<Green<<"green"<<std::endl;
    std::cout<<"      "<<Yellow<<"yellow"<<std::endl;
    std::cout<<"      "<<Blue<<"blue"<<std::endl;
    std::cout<<"      "<<Purple<<"purple"<<std::endl;
    std::cout<<"      "<<Cyan<<"cyan"<<std::endl;
    std::cout<<"      "<<White<<"white"<<std::endl<<reset; 
    std::cout<<"Default is: "<<argv[0]<<" -s2 -color red (will fit max number of letters in each line)"<<std::endl;
    return;
}
void params(char** argv,int argc,bool& vertical,string& input,string& color,int& speed)
{
    for(int i=1;i<argc;i++)
    {
        if(strcmp(argv[i],"-vertical")==0)
            vertical=true;
        else if(strcmp(argv[i],"-txt")==0)
            input=argv[i+1];
        else if(strcmp(argv[i],"-color")==0)
            color=col[argv[i+1]];
        else if(strcmp(argv[i],"-s0")==0)
            speed=0;
        else if(strcmp(argv[i],"-s1")==0)
            speed=5;
        else if(strcmp(argv[i],"-s2")==0)
            speed=15;
        else if(strcmp(argv[i],"-s3")==0)
            speed=35;
        else if(strcmp(argv[i],"-s4")==0)
            speed=60;
    }
}

string getnextword(string input,int& place)
{
    string rslt="";
    int i=place;
    for(;i<input.length();i++)
    {
        if(input[i]==' ')            
            break;
        rslt+=input[i];
    }
    place=i+1;
    return rslt;
}
string printwordvertically(string str)
{
    string rslt="";
    for(int i=0;i<str.length();i++)
    {
        for(int j=0;j<8;j++)
        {
            rslt+=table[str[i]].str[j]+"\n";
        }
        rslt+="\n\n";
    }
    return rslt;
}
int sumup(string str)
{
    int sum=0;
    for(int i=0;i<str.length();i++)
    {
        sum+=table[str[i]].str[0].length();
    }
    return sum;
}
void printfit(vector<string> &lines,string str,int& remaining)
{
    int sum=sumup(str);
    if(sum>remaining)
    {
        //does not fit in this line
        //either cut or new line
        if(sum<=size.ws_col)
        {
            remaining=size.ws_col;
            lines.push_back("");
            printfit(lines,str,remaining);
            //fit in a different line if i wanna
        }
        else
        {
            int used=0;
            if((double)remaining/(double)size.ws_col<=0.6)
            {
                for(int i=0;i<str.length();i++)
                {
                    int sum=sumup(str.substr(0,str.length()-i));
                    if(sum<=remaining)
                    {
                        printfit(lines,str.substr(0,str.length()-i),remaining);
                        used=str.length()-i;
                        break;
                    }
                }
            }
            while(used<str.length())
            {
                for(int i=0;i<str.length();i++)
                {
                    int sum=sumup(str.substr(used,(str.length()-used-i)));
                    remaining=size.ws_col;
                    if(sum<=remaining)
                    {
                        lines.push_back("");
                        printfit(lines,str.substr(used,(str.length()-used-i)),remaining);
                        used=str.length()-i;
                        break;
                    }
                }
            }
                //split current + next 
        
            
            //does not fit in line...def split
        }
    }
    else
    {
        lines.back()=addto(lines.back(),str);
        remaining-=sum;
        if(str!=" ")
        {
            int sum=sumup(" ");
            if(sum<=remaining)
            {
                lines.back()=addto(lines.back()," ");
                remaining-=sum;
            }
        }
        //fits in this line
    }
}

string addto(string basic,string add)
{
    string rslt="";
    for(int i=0,start=0;i<8;i++)
    {
        if(basic!="")
        {
            for(int j=start;j<basic.length();j++)
            {
                if(basic[j]=='\n')
                {
                    rslt+=basic.substr(start,j-1-start);
                    start=j+1;
                    break;
                }
            }
        }
        for(int j=0;j<add.length();j++)
        {
            rslt+=table[add[j]].str[i];
        }
        rslt+="\n";
    }
    return rslt;
}