#include<cmath>
#include<iomanip>
#include<iostream>
#include<string>
#include<fstream>
#include <map>
using namespace std;
fstream outputfile("test.hack",ios::out | ios::app);


string removeSpaces(string str)
{
    int count = 0;
    for (int i = 0; str[i]; i++) 
    {
        if (str[i] != ' ') 
            str[count++] = str[i]; // here count is 
    }                              // incremented 
    str[count] = '\0'; 
    return str;
}
string calcBinary(string str)
{
    int len = str.length();
    int sum = 0;
    for(int i=0;i<len-1;i++)
    {
        int x = str[i] - '0';
        sum = sum *10  + x;
        
       
    }
    
    int value = sum; 
    int powerof2;

    powerof2 = pow(2, 1) * 32768;
    string res;
    while (powerof2 > 0)
    {
        if (value >= powerof2)
        {    
            res+="1";
            value = value - powerof2;
        }
        else
            res+="0";
        powerof2 = powerof2 / 2;
    }
    return res;
}
string getBeforeEquals(string str)
{
    int i=0;
    string res ;
    while(str[i]!='=')
    {
        res+=str[i];
        i++;
    }
    return res;
}
string getAfterEquals(string str)
{
    int i=0;
    string res ;
    while(str[i]!='=')
    {
        i++;
    }
   i++;
//cout<<"1"<<endl;;
    while(str[i]!='\0')
    {
        res += str[i]; i++;
    }
//    cout<<"res: "<<res<<endl;
    return res;
}
string getAfterEqualsBeforeSemi(string str)
{
    int i=0;
    string res ;
    while(str[i]!=';')
    {
        res += str[i]; i++;
    }
    return res;
}
string getAfterEqualsBeforeSemi2(string str)
{
    int i=0;
    string res ;
    while(str[i]!=';')
    {
        i++;
    }
    i++;
    while(str[i]!='\0')
    {
        res += str[i]; i++;
    }
    return res;
}
string getAfterSemi(string str)
{
    int i=0;
    string res ;
    while(str[i]!='=')
    {
        i++;
    }
   i++;
    while(str[i]!=';')
    {
        i++;
    }
    i++;
    while(str[i]!='\0')
    {
        res += str[i]; i++;
    }
    return res;
}
string isFound(string temp[], string to_find, int size)
{
//    cout<<"1"<<endl;
    for(int i=0;i<size;i++)
    {
  //          cout<<"2"<<endl;
        if(temp[i]==to_find)
        {
    //        cout<<temp[i]<<endl;
            return to_find;
        }
    }
    return "";
}
bool findSemi(string s)
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]==';')
            return true;
        i++;
    }
    return false;
}
int main()
{
    string myText;
    ifstream MyReadFile("test.asm");

    map<string, string> comps;
        map<string, string> comps2;
    map<string, string> jumps;
    map<string, string> dests;

     comps["0"]     = "101010";
     comps["1"]     = "111111";
     comps["-1"]    = "111010";
     comps["D"]     = "001100";
     comps["A"]     = "110000";
     comps["!D"]    = "001101";
     comps["!A"]    = "110001";
     comps["-D"]    = "001111";
     comps["-A"]    = "110011";
     comps["D+1"]   = "011111";
     comps["A+1"]   = "110111";
     comps["D-1"]   = "001110";
     comps["A-1"]   = "110010";
     comps["D+A"]   = "000010";
     comps["D-A"]   = "010011";
     comps["A-D"]   = "000111";
     comps["D&A"]   = "000000";
     comps["D|A"]   = "010101";

     comps["M"]     = "110000";
     comps["!M"]    = "110001";
     comps["-M"]    = "110011";
     comps["M+1"]   = "110111";
     comps["M-1"]   = "110010";
     comps["D+M"]   = "000010";
     comps["D-M"]   = "010011";
     comps["M-D"]   = "000111";
     comps["D&M"]   = "000000";
     comps["D|M"]   = "010101";

     dests["null"]  = "000";
     dests["M"]     = "001";
     dests["D"]     = "010";
     dests["MD"]    = "011";
     dests["A"]     = "100";
     dests["AM"]    = "101";
     dests["AD"]    = "110";
     dests["AMD"]   = "111";

     jumps["null"]  = "000";
     jumps["JGT"]   = "001";
     jumps["JEQ"]   = "010";
     jumps["JGE"]   = "011";
     jumps["JLT"]   = "100";
     jumps["JNE"]   = "101";
     jumps["JLE"]   = "110";
     jumps["JMP"]   = "111";
     
     int i=0;
    string dest[8] = {"null","M", "D", "MD", "A", "AM", "AD", "AMD"}; 
    string com[18] = {"0", "1", "-1", "D", "A", "!D", "!A", "-D", "-A", "D+1", "A+1", "D-1", "A-1", "D+A", "D-A", "A-D", "D&A", "D|A"};
    string com2[10] = {"M", "!M", "-M", "M+1", "M-1", "D+M", "D-M", "M-D", "D&M", "D|M"};//, "A+1", "D-1", "A-1", "D+A", "D-A", "A-D", "D&A", "D|A"};
    while (getline (MyReadFile, myText)) 
    {
        string res = removeSpaces(myText);
        string beforeEquals = getBeforeEquals(myText);
        string after = getAfterEquals(myText);
        string before = getAfterEqualsBeforeSemi(myText);
        if(res[0] == '/' && res[1] == '/')
        {

        }
        else if(res[0] == '@')
        {
            res = res.erase(0,1);
            
            string temp=calcBinary(res);
            outputfile<<temp<<endl;
        }
        else if(findSemi(myText))
        {
            string temp ="111";

            if(isFound(com,before,18)!="")
            {
                temp+="0";
            }
            else if(isFound(com2,before,10)!="")
            {
                temp+="1";
            }
//            string x = getAfterSemi(myText);
            temp+=comps[before];
            temp+="000";
            temp+=jumps[getAfterEqualsBeforeSemi2(myText)];
            outputfile<<temp<<endl;;
        }
        else if(isFound(dest,beforeEquals,8) != "")
        {
            string temp ="111";
            if(isFound(com,after,18)!="")
            {
                temp+="0";
            }
            else if(isFound(com2,after,10)!="")
            {
                temp+="1";
            }
            string x = getAfterEquals(myText);
            temp+=comps[x];
            temp+=dests[beforeEquals];
            temp+="000";
            outputfile<<temp<<endl;
        }
            i++;
    }

    MyReadFile.close();
}
