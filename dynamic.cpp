#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <utility>


using namespace std;

int max(int a, int b) { return (a > b)? a : b; }  
  
// Returns the maximum value that  
// can be put in a knapsack of capacity remain=n 
int knapSack(int W, int wt[], int val[], int n)  
{  
      
// Base Case  
if (n == 0 || W == 0)  
    return 0;  
  
// If weight of the nth item is more  
// than Knapsack capacity W, then  
// this item cannot be included 
// in the optimal solution  
if (wt[n-1] > W)  
    return knapSack(W, wt, val, n-1);  
  
// Return the maximum of two cases:  
// (1) nth item included  
// (2) not included  
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),  
                    knapSack(W, wt, val, n-1) );  
}  




int main(int argc,char *argv[])
{
	int n;
	int v[10],w[10];
	int remain;
	
	
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
     // cout << line << '\n';
       n=stoi(line);
    }
   
    int i;
    string word=" ";
    string word1=" ";
	string word2=" ";
    string word3=" ";
    
	for(i=0;i<=n;i++)
	{
		int counter=0;
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
				  
				  	  
					if (counter==12 or counter==13)
					  word1=word1+x;
					if (counter==8 or counter ==9)
					word2=word2+x;
				    
					   
				}
			//	cout<<"counter "<<counter<<" x "<<x<<endl;
			}
			if (counter>1)
			{
			
			cout<<word1<<endl;
			cout<<word2<<endl;
			
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
  
  
  
  int k=knapSack(remain,w,v,n);
  
  cout<<" Dynamic Programming Solution: "<<k;
  
ofstream fs;
string filename="record2.txt";
ofstream outputFile (filename,ios_base::app);

int count=0,p=0;
for(int i=0;i<n;i++)
{
	
	p=p+v[i];
	count++;
}

outputFile<<"Dynamic Programmic"<<','<<"File Name"<<','<<"Total Weight"<<','<<"Total Value/profit"<<','<<"Total Objects"<<endl;
outputFile<<k<<','<<fileid<<','<<remain<<','<<p<<','<<count<<','<<endl;

outputFile.close();
  
  
  
  
  return 0;
}
