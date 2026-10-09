#include<iostream>
using namespace std;
enum enlevel
{
  easy=1,
  mid=2,
  hard=3,
  mix=4
};
enum enoperation
{
  add=1,
  sub=2,
  mul=3,
  div1=4,
  mix1=5
};
struct stquestioninfo
{
  int number1=0;
  int number2=0;
  string levelofquestion;
  string oprationofquestion;
  int rightanswer=0;
  int wronganswer=0;
  enoperation operationtype;
  enlevel questionlevel;
  string type="";
};

struct stresult
{
stquestioninfo questionlist[100];
    int numberofquestion=0;
  int numberofrightanswer=0;
  int numberofwronganswer=0;
   enoperation operationtype;
  enlevel questionlevel;
  
};
string returnchar(enoperation op)
{
    switch(op)
    {
       case enoperation::add:
          return "+";
       case enoperation::sub:
          return "-";
       case enoperation::mul:
          return "*";
       case enoperation::div1:
          return "/";

       defualt:  
       return "mix"; 
    }
}
int randomnumber(int n1,int n2) 
{
    return rand()%(n2-n1+1)+n1;
}
enoperation getoptype()
{
    return (enoperation)randomnumber(1,4);
}

string levelname(enlevel level)
{
    string arrlevel[4]={"easy","medium","hard","mix"};
    return arrlevel[level-1];
}
//void colors
string opertionname(enoperation op)
{
    string arrop[5]={"addition","subtraction","multiplication","division","mix"};
    return arrop[op-1];
}
int calculater(int n1,int n2,enoperation op)

{
    switch(op)
    {
        case enoperation::add:
            return n1+n2;
        case enoperation::sub:
            return n1-n2;
        case enoperation::mul:
            return n1*n2;
        case enoperation::div1:
            return n1/n2;
        default:
            return 0;
    }
}
stquestioninfo knowinglevel(enlevel level,enoperation op)//i dont understand why we put stquestioninfo
{
    stquestioninfo question;
   if(level==enlevel::mix)
   {
      level= (enlevel)randomnumber(1,3);
   }   
   if(op==enoperation::mix1)
   {
      op=getoptype();

   }
      question.operationtype=op;
       switch(level)
       {
          case enlevel::easy:
          {
               question.number1=randomnumber(1,10);
               question.number2=randomnumber(1,10);
               break;
        }
          case enlevel::mid:
          {
               question.number1=randomnumber(10,100);
               question.number2=randomnumber(10,100);
               break;
          }
          case enlevel::hard:
          {
               question.number1=randomnumber(100,1000);
               question.number2=randomnumber(100,1000);
               break;
          }
          case enlevel::mix:
          {
               question.number1=randomnumber(1,30);
               question.number2=randomnumber(1,30);
               break;
          }
       }
       
     question.rightanswer=calculater(question.number1,question.number2,question.operationtype);
     question.questionlevel=level;
     
     return question;
}


void  howmanyquestion(stresult& result)
{
   int howmanyquestion;
   stquestioninfo question;

  
   for(int i=1;i<=result.numberofquestion;i++)
   {
       
       cout<<"Question :  ["<<i<<"/"<<result.numberofquestion<<"] "<<endl;
       cout<<result.questionlist[i].number1<<" "<<returnchar(result.questionlist[i].operationtype)<<" "<<result.questionlist[i].number2<<" = ?"<<endl;
       int answer;
       cin>>answer;
       int rightanswer=calculater(result.questionlist[i].number1,result.questionlist[i].number2,result.questionlist[i].operationtype);
       if(answer==rightanswer)
       {
           cout<<"right answer"<<endl;
           result.numberofrightanswer++;
            system("color 2F"); 
       }
       else
       {
           cout<<"wrong answer"<<endl;
           result.numberofwronganswer++;
                   system("color 4F");
                    cout << "\a";
       }
   }
}
 void print( stresult& result,stquestioninfo& question)
 {   
 cout<<endl;
 cout<<"__________FINAL RESULT_______"<<endl;
 int numberofquestion;
 
 cout<<"THE NUMBER OF QUESTION IS: "<<result.numberofquestion<<endl;
 cout<<"THE LEVEL OF QUESTION IS: "<<levelname(result.questionlevel)<<endl;
 cout<<"THE OPERATION OF QUESTION IS: "<<opertionname(result.operationtype)<<endl; 
 cout<<"THE RIGHT ANSWERS IS: "<<result.numberofrightanswer<<endl ;
 cout<<"THE WRONG ANSWERS IS: "<<result.numberofwronganswer<<endl;
 }  
void playgame(stresult& result)
{
  
  stquestioninfo question;
  int numberofquestion1 ;
   cout<<"the number of question is: ";
   cin>>numberofquestion1;
   
   cout<<endl;
   cout<<"what level do you want [1]easy,[2]mid,[3]hard,[4]mix: ";
   int level1;
   cin>>level1;
   cout<<endl;
   cout<<"what operation do you want [1]addition,[2]subtraction,[3]multiplication,[4]division,[5]mix: ";
   int op1;
   cin>>op1;
  
  
   result.operationtype=(enoperation)op1;
   result.questionlevel=(enlevel)level1;
   result.numberofquestion=numberofquestion1;
  for(int i=1;i<=numberofquestion1;i++)
  {
    result.questionlist[i]=knowinglevel(result.questionlevel,result.operationtype);
  }
  howmanyquestion(result);
  print(result,question);


 
}   
int main()
{
    stresult result;
    stquestioninfo question;
srand((unsigned)time(NULL));
playgame(result);


return 0;
}
