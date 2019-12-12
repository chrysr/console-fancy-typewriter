#include "functions.h"

int main(int argc,char** argv)
{
    bool vertical=false;
    string input="";
    string color=Red;
    
    if(argc==1)
    {
        usage(argv);
        return 0;
    }

    params(argv,argc,vertical,input,color);
    
    if(input=="")
    {
        std::cout<<"No input text was provided! Bye!"<<std::endl;
        return 0;
    }
    if(vertical)
        std::cout<<"Running in Vertical Mode"<<std::endl;
    else 
        std::cout<<"Running in Horizontal Mode (Best Fit)"<<std::endl;
    
    
    std::cout<<std::endl<<"Will be using the following input text:"<<std::endl<<color<<input<<reset<<std::endl<<std::endl;

    init();
    
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

    string tmp="";
    vector<string> lines;
    for(int i=0,remaining=0;;i++)
    {
        tmp=getnextword(input,tmp);
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