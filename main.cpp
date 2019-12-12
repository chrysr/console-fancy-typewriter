#include "functions.h"

int main(int argc,char** argv)
{
    init();
    std::cout<<"\n\n";

    string input="";
    string color=Red;
    string tmp="";
    string str="";
    int speed=15;
    int place=0;
    bool vertical=false;
    vector<string> lines;

    if(argc==1)
    {
        usage(argv);
        return 0;
    }

    params(argv,argc,vertical,input,color,speed);
    
    if(input=="")
    {
        std::cout<<"No input text was provided! Bye!"<<std::endl;
        return 0;
    }   
    input=refineinput(input);

    
    for(int i=0,remaining=0;;i++)
    {
        tmp=getnextword(input,place);
        if(tmp=="") 
            break;
        if(vertical)
        {
            if(i>0)
                lines.push_back(printwordvertically(" "));

           lines.push_back(printwordvertically(tmp));
        }
        else
        {
            printfit(lines,tmp,remaining);
        
        }        
    }

    for(int i=0;i<lines.size();i++)
        str+=lines.at(i)+"\n\n";
    

    if(color!=colorful)
        std::cout<<color<<endl;  
    
    vector<string> clrs;
    if(color==colorful)
        makecolorarray(clrs);

    for(int i=0;i<str.length();i++)
    {
        if(color==colorful)
            std::cout<<col[clrs.at(rand()%clrs.size())];
        
        std::cout<<str[i];
        fflush(stdout);
        usleep(str.length()/input.length()*speed);
    }

    std::cout<<reset;
    return 0;
}