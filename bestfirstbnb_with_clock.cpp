#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <queue>

















using namespace std;

struct node
{
	int level;
	int cumValue;
	int cumWeight;
	int nodebound;
	int profit;
	
	
};

struct item_in
{
	int weight;
	int value;
};

//calculating upperbound

int upper_bound(node u,int n,int maxW, int w[],int v[])
{
	if (u.cumWeight>=maxW)
	 return 0;
	int profit_upper_bound=u.profit;
	
	int j=u.level+1;
	
	int totalweight=u.cumWeight;
	
	while ((j<=n) && (totalweight + w[j]<=maxW)) 
	{
		totalweight=totalweight+w[j];
		profit_upper_bound=profit_upper_bound+v[j];
		j++;
		
	}
	
	 if (j < n) 
        profit_upper_bound += (maxW - totalweight) * v[j]/w[j];
  
    return profit_upper_bound; 
	
	
	
}






int main(int argc,char *argv[])
{
	int n;
	int *v,*w;
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
      //cout << line << '\n';
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
		string word1;
		string word2;
		string word3;
		int in=1;
		
	   
	   
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
					   
				}
			//	cout<<"counter "<<counter<<" x "<<x<<endl;
			}
			if (counter>1)
			{
			
			//cout<<word1<<endl;
		//	cout<<word2<<endl;
			
			v[i]=stoi(word2);
			w[i]=stoi(word1);
			}
		}
	
	 remain=stoi(line);
	 
	}  
	
     
           
  
  else cout << "Unable to open file"; 
  myfile.close();
 /* cout<<"remain "<<remain<<endl;
  for(int i=0;i<n;i++)
  {
  	cout<<"value "<<v[i];
  	cout<<" " <<" Weight "<<w[i]<<endl;
  }*/
  
  
  //value-to-weight ratios
  int v_t_w_r[10];
int p=0;

/*for( int i=0;i<n;i++){
 v_t_w_r[i]=v[i]/w[i];
 cout<<" "<<v_t_w_r[i];
}*/
  
  //BestFirstBranchAndBound Algorithm
  
  sort(v_t_w_r,v_t_w_r+n,greater<int>());
  
  queue<node> Q;
  node current,temp;
  
  current.level=-1;
  current.cumValue=0;
  current.cumWeight=0;
  current.nodebound=-1;
  
  
  int MaxValue=0;
  
  Q.push(current);
  int count=0;
  while(!Q.empty())
  {
  	current=Q.front();
  	Q.pop();
  	
  	if (current.level==-1)
  	   temp.level=0;
  	if (current.level==n-1)
	  continue;
	temp.level=current.level+1;
	temp.cumWeight = current.cumWeight + w[temp.level];
	temp.profit= current.profit + v[temp.level];
	count++;
	if (temp.cumWeight <=remain && temp.profit >MaxValue)
	   MaxValue=temp.profit;
	temp.nodebound=upper_bound(temp,n,remain,w,v);    
	
	if (temp.nodebound >MaxValue)
	   Q.push(temp);
	temp.cumWeight=current.cumWeight;
	temp.cumValue=current.cumValue;
	temp.nodebound=upper_bound(temp,n,remain,w,v);
	if (temp.nodebound >MaxValue)
	   Q.push(temp);
}
	   
	cout<<" MaxProfit "<<MaxValue<<endl;  
	   
//writing to a file
ofstream fs;
string filename="record3.txt";
ofstream outputFile (filename,ios_base::app);



outputFile<<"Best first BNB Programmic"<<','<<"File Name"<<','<<"Total Weight"<<','<<"Total Value"<<','<<"Total profit"<<','<<"Total Objects"<<endl;
outputFile<<'BFSBNB'<<','<<fileid<<','<<temp.cumWeight<<','<<temp.cumValue<<','<<temp.profit<<','<<count<<endl;

outputFile.close();  
  	
 
  
 return 0; 
}
