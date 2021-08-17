#include<iostream>
#include<string.h>
#include<fstream>
#include"fine.cpp"
using namespace std;

class student
{

  char *name;
  char *branch;
  int roll;
  public:
  void getstudet(char *name,char *branch,int roll)
  {
    strcpy(this->name,name);
    strcpy(this->name,name);
    this->roll=roll;
  };

  void prints()
  {
    cout<<"student details are:";
    cout<<name<<endl<<branch<<endl<<roll<<endl;
  }
};

class fine1
{
  protected:
  
      int d1,d2;
      int m1,m2;
      int y1,y2;
  public:
      int fine;
      int finedetails(void)
      {
          cout<<endl<<"enter the date of issue"<<endl;
          cin>>d1;
          cout<<"enter the month of issue"<<endl;
          cin>>m1;
          cout<<"enter the year of issue"<<endl;
          cin>>y1;
          cout<<"enter the date of return"<<endl;
          cin>>d2;
          cout<<"enter the month of return"<<endl;
          cin>>m2;
          cout<<"enter the year of return"<<endl;
          cin>>y2;
          Date dt1={d1,m1,y1};
          Date dt2={d2,m2,y2};
          int f;
          f=getDifference(dt1,dt2);
      }
};

/*void getdiff(int d1,int d2,int m1,int m2,int y1,int y2)
{

  this->d1=d1;
this->d2=d2;
this->m1=m1;
this->m2=m2;
this->y1=y1;
this->y2=y2;
int c;
c=d2-d1;
int fine;
if(y1==y2&&m1==m2&&c>15)
{
  fine=c-15;
 
}
else if(y1==y2&&m1!=m2&&c>15)
{
fine=c-

}*/

 
class item:public student
{
   
  protected:
      char *n;
      char *aut;
      int cd;
  public:
      void getdetails(char *s,char *r,int l)
      {
          n=new char[strlen(s)];
          n=s;
          aut=new char[strlen (r)];
          aut=r;
          cd=l;
      }

      virtual void display() {}
};


class journal:virtual public item,virtual public fine1
{
    protected:
        int issn;
    public:
        void getjdetail(int e)
        {
            issn=e;
        }
        virtual void jdisplay() {}
};

class book: virtual public item,virtual public fine1
{
    protected:
        int isbn;
    public:
        void getbdetail(int p)
        {
            isbn=p;
        }
    virtual void bdisplay() {}
};

class international:virtual public journal,virtual public book
{
public:
void func1()
{
cout<<"entered details r:";
cout<<"book name:"<<n;
cout<<"author:"<<aut;
cout<<"lib code:"<<cd;
cout<<"issn no:"<<issn;
}

void func2()
{
cout<<"book name:"<<n;
cout<<"author:"<<aut;
cout<<"lib code:"<<cd;
cout<<"isbn:"<<isbn;
}
};

class national:virtual public journal,virtual public book
{
public:
void func1()
{
  cout<<"entered details r:";
cout<<"book name:"<<n;
cout<<"author:"<<aut;
cout<<"lib code:"<<cd;
cout<<"issn no:"<<issn;
}

void func2()
{
cout<<"book name:"<<n;
cout<<"author:"<<aut;
cout<<"lib code:"<<cd;
cout<<"isbn:"<<isbn;
}
};


int main()
{
   char *h,*j;
int o,w,num;
char nm[25],br[5];
int r;
international in;
national n;
fstream f;
f.open("library.bin",ios::binary);
do
{
cout<<"enter student details of order name,branch,rollno";
cin>>nm;
cin>>br;
cin>>r;
cout<<"enter item details"<<endl;
h= new char[50];
j=new char[20];
cin>>h;
cin>>j;
cin>>o;
cin>>w;//issn or isbn
int c;
cout<<"choose a no from 1,2,3,4"<<endl;
cin>>c;
cout<<"enter number of students";
cin>>num;
int fine;


switch(c)
{
  case 1:   cout<<"u have selected an international journal:";
                     in.getdetails(h,j,o);
                     in.getjdetail(w);
                     int f1;
                    f1=in.finedetails();       
                    if(f1<=15)
                    {
                      fine=0;
                     cout<<endl<<"no fine"<<endl;
                
                    }
                    else
                    {
                     fine=f1-15;
                    cout<<"fine is"<<fine;
                    }
                      f.write((char *) & in ,sizeof(in));
                      f.read((char *) & in ,sizeof(in));
                      in.func1();
                      break;
                     
    case 2:  cout<<"u have selected an national journal:";
                     n.getdetails(h,j,o);
                     n.getjdetail(w);
                     int f2;
                     f2=n.finedetails();       
                    if(f2<=15)
                    {
                      fine=0;
                    cout<<endl<<"no fine"<<endl;
                
                    }
                    else
                    {
                     fine=f2-15;
                     cout<<"fine is"<<fine;
              
                    }
                      f.write((char *) & n ,sizeof(n));
                      f.read((char *) & n ,sizeof(n));
                      n.func1();
                      break;
                                      
    case 3:  cout<<"u have selected an international book:";
                    
                     in.getdetails(h,j,o);
                     in.getbdetail(w);
                       int f3;
                     f3=in.finedetails();       
                    if(f3<=15)
                    {
                      fine=0;
                     cout<<endl<<"no fine"<<endl;
                
                    }
                    else
                    {
                     fine=f3-15;
                     cout<<"fine is"<<fine;
              
                    }
                      f.write((char *) & in ,sizeof(in));
                      f.read((char *) & in ,sizeof(in));
                      in.func2();
                      break;
                                  
   case 4:  cout<<"u have selected an national book:";
                     n.getdetails(h,j,o);     
                     n.getbdetail(w);
                       int f4;
                     f4=n.finedetails();       
                    if(f4<=15)
                    {
                      fine=0;
                     cout<<endl<<"no fine"<<endl;
                
                    }
                    else
                    {
                     fine=f4-15;
                     cout<<"fine is"<<fine;
              
                    }
                      f.write((char *) & n ,sizeof(n));
                      f.read((char *) & n ,sizeof(n));
                      n.func2();
                      break;

   default : cout<<"no item is available";
             break;
}

}while(num!=0);
f.close();
int value,fine;
cout<<"enter 1 for renewal and 0 for return:";
cin>>value;
if(value==1)
{
      fstream f2;
  f2.open("library.bin",ios::binary|ios::in|ios::out|ios::ate);
  int rec;
  cin>>rec;
f2.seekp((rec-1)*sizeof(in),ios::beg);
             cout<<"student and item details";
             in.getdetails(h,j,o);
             in.getjdetail(w);
              int f5;
            f5=in.finedetails();       
             if(f5<=15)
                 {
                 fine=0;
                 cout<<endl<<"no fine"<<endl;
                // f<<fine;
                  }
              else
                {
                 fine=f5-15;
                 cout<<"fine is"<<fine;
          
           }
            
            f2.write((char*)&in,sizeof(in));
            cout<<"the updated record details are"<<endl;
            f2.read((char *) & in ,sizeof(in));
                      in.func1();
           
     f2.close();
   

   
   
}
return 0;
}