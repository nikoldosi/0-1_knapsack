#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <time.h>


using namespace std;


int main(int argc,char *argv[])
{
	int n;
	int *v,*w;
	int remain;
	clock_t t;
	
	
  string fileid;
	//read the name of our file
if (argc!=1)	
   cout<<"You entered the name of file"<< argv[0];
   
else
{
  cout<<" Give the name of your file ";
  cin>>fileid;
  cout<<" Your file is "<<fileid<<endl;
}

//reading file and finding N and Weights and Values


  string line;
  ifstream myfile (fileid);
  if (myfile.is_open())
  {
    if (getline (myfile,line) )
    {
      //cout << "items "<<line << '\n';
       n=stoi(line);
       v=new int[n];
       w=new int[n];
    }
   
    int i;
    string word=" ";
    string word1=" ";
	string word2=" ";
    string word3=" ";
    
	for(i=0;i<=n;i++)
	{
		int counter=0;
		int in=1;
		string word1;
		string word2;
		string word3;
		
	   
	   
		if(getline(myfile,line))
		{
			
			for (auto x:line)
			{
				if (x==' ')
				{
					counter++;
				}
				else
				{
				  
				  	  
				if 	((in==0  ) && (counter==9))
				  word1=word1+x;
				else	if (counter>=6 && counter<=9){					
					  word2=word2+x;
				      in=0;
				}
				else if  (counter>=10 && counter<=14)  
					  word1=word1+x;
					   
				}
			//	cout<<"counter "<<counter<<" x "<<x<<endl;
			}
			if (counter>1)
		_	{
		//	cout<<word2<<endl;
		//	cout<<word1<<endl;
			
			
			v[i]=stoi(word2);
			w[i]=stoi(word1);
			}
		}
	
	 remain=stoi(line);
	 
	}  
	
     
           
  }
  else cout << "Unable to open file"; 
  myfile.close();
  /*cout<<"remain "<<remain<<endl;
  for(int i=0;i<n;i++)
  {
  	cout<<"value "<<v[i];
  	cout<<" " <<" Weight "<<w[i]<<endl;
  }*/
  
  



//Greddy algorithm
t=clock();
int v_t_w_r[10];
int p=0;

/*for( int i=0;i<n;i++){
 v_t_w_r[i]=v[i]/w[i];
 cout<<" "<<v_t_w_r[i];
}*/
 
sort(v_t_w_r,v_t_w_r+n,greater<int>());

/*for(int i=0;i<n;i++)
  cout<<" "<<v_t_w_r[i]*/
int count=0;
for(int i=0;i<n;i++)
{
	if (remain>0 && w[i]<=remain)
	{
			remain=remain-w[i];
			p=p+v[i];
			count++;
	}
	else
	 break;

t = clock() - t;
		if ((((float)t)/CLOCKS_PER_SEC) > 10){
			cout<<"break"<<endl;
			break;
		}	
}

//writing to a file the name, sum_weight,sum_value or profit and count and total executable time


ofstream fs;
string filename="record.txt";
ofstream outputFile (filename,ios_base::app);



outputFile<<"File Name"<<','<<"Total Weight"<<','<<"Total Value/profit"<<','<<"Total Objects"<<"Exec TIme"<<endl;
outputFile<<fileid<<','<<remain<<','<<p<<','<<count<<','<<t<<endl;

outputFile.close();


  
return 0;

	
}

