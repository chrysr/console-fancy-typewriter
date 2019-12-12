#include "functions.h"

int main(int argc,char** argv)
{
    init();
    std::cout<<"\n\n";
    bool vertical=false;
    string input="";
    string color=Red;
    int speed=50;
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
    if(vertical)
        std::cout<<"Running in Vertical Mode"<<std::endl;
    else 
        std::cout<<"Running in Horizontal Mode (Best Fit)"<<std::endl;
    
    


    string str="";
    string refined="";
    for(int i=0;i<input.length();i++)
    {
        //std::cout<<input[i]<<" "<<(int)input[i]<<std::endl;
        if(input[i]=='\n'||(int)input[i]==32)
        {
            refined+=' ';
            continue;
        }
        if(!table.count(input[i]))
        {
            continue;
        }
        refined+=input[i];
    }

    input=refined;
    refined="";
    
    std::cout<<std::endl<<"Will be using the following input text:"<<std::endl<<color<<input<<reset<<std::endl<<std::endl;

    string tmp="";
    int place=0;
    vector<string> lines;
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
        cout<<color<<endl;  
    
    vector<string> clrs;
    if(color==colorful)
    {
        for(map<string,string>::iterator it=col.begin();it!=col.end();++it)
        {
            if(it->first!="colorful")
                clrs.push_back(it->first);
        }
        srand(time(NULL));

    }
    for(int i=0;i<str.length();i++)
    {
        if(color==colorful)
        {
            cout<<col[clrs.at(rand()%clrs.size())];
        }
        cout<<str[i];
        fflush(stdout);
        //usleep(5000);
        //usleep(20000/input.length());
        usleep(str.length()/input.length()*speed);

    }
    cout<<reset;
}