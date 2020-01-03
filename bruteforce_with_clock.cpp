#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <utility>

using namespace std;
clock_t t;

void bruteForce(int *serialNo, int *weights, int *values, int *fill, int n, int maxW);

int main(int argc,char *argv[]){
	
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
     // cout << line << '\n';
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
			//cout<<word2<<endl;
			
			v[i]=stoi(word2);
			w[i]=stoi(word1);
			}
		}
	
	 remain=stoi(line);
	 
	}  
	
     
           
    else cout << "Unable to open file"; 
  myfile.close();
  /*cout<<"remain "<<remain<<endl;
  for(int i=0;i<n;i++)
  {
  	cout<<"value "<<v[i];
  	cout<<" " <<" Weight "<<w[i]<<endl;
  }*/
	
	int serialNo[10],fill[10];
	
	for(int i;i<n;i++)
	{
		serialNo[i]=1;
		fill[i]=0;
	}
	
	
	
	

bruteForce(serialNo, w, v, fill, n , remain);
	
ofstream fs;
string filename="record4.txt";
ofstream outputFile (filename,ios_base::app);

int count=0,p=0;
for(int i=0;i<n;i++)
{
	
	p=p+v[i];
	count++;
}

outputFile<<"File Name"<<','<<"Total Weight"<<','<<"Total Value"<<','<<"Total Objects"<<"Exec Time"<<endl;
outputFile<<fileid<<','<<remain<<','<<p<<','<<count<<t<<endl;

outputFile.close();  
	
	
return 0;	
	
 
}
void bruteForce(int *serialNo, int *weights, int *values, int *fill, int n, int maxW){ //eksantlitiki aparithmisi syndyasmwn
// fill einai o pinakas pou exei 0 sta antikeimena pou den exoun epilexthei kai 1 sta epilegmena
	int i, j, y;
	int tempWeight;
	int tempValue;
	int bestValue = 0, bestWeight = 0;
	int sakidio[3];// o sakos me to teliko apotelesma
	clock_t t;
	
	t = clock();
	for(i = 1; i <= exp2(n); i++){ // tha treksei 2 eis tin n fores gia na parei oles tis periptwseis
		j = n - 1;
		tempWeight = 0; // metraei to varos pou exei to sakidio me tin epilogi sygkekrimenwn antikeimenwn
		tempValue = 0;// antistoixa i proswrini aksia. midenizei kathe fora gia na metrisei ek neou me tin epomeni epilogi antikeimenwn
		while(fill[j] != 0 && j >= 0){ 
			fill[j] = 0;
			j--;
		}
		fill[j] = 1;
	
		for(y = 0; y < n; y++){
			if(fill[y] == 1){
				tempWeight += weights[y];
				tempValue += values[y];
			}
		}
		if((tempValue > bestValue) && (tempWeight <= maxW)){
			bestValue = tempValue;
			bestWeight = tempWeight;
			for(y = 0; y < n; y++)
				sakidio[y] = fill[y];
			
			
		}
		t = clock() - t;
		if ((((float)t)/CLOCKS_PER_SEC) > 10){
			cout<<"break"<<endl;
			break;
		}
 
	}
	//cout<<"It took me "<<t<<" clicks and "<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;
	
	/*cout<<"knapsack contents"<<endl;
	for(y = 0; y < n; y++)
		cout<<sakidio[y]<<endl;*/
		
 
	       
}
