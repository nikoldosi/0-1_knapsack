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
			{
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
  
  
  
  KnapsackSolver solver(
    KnapsackSolver::KNAPSACK_MULTIDIMENSION_BRANCH_AND_BOUND_SOLVER,
    "KnapsackExample");
    
solver.Init(v, w, remain);
solver.Init(values, weights, capacities);
int64 computed_value = solver.Solve();
vector<int> packed_items;
for (size_t i = 0; i < values.size(); ++i) {
  if (solver.BestSolutionContains(i)) packed_items.push_back(i);
}
ostringstream packed_items_ss;
copy(packed_items.begin(), packed_items.end() - 1,
          std::ostream_iterator<int>(packed_items_ss, ", "));
packed_items_ss << packed_items.back();

vector<int64> packed_weights;
packed_weights.reserve(packed_items.size());
for (const auto &it : packed_items) {
  packed_weights.push_back(weights[0][it]);
}
ostringstream packed_weights_ss;
copy(packed_weights.begin(), packed_weights.end() - 1,
          std::ostream_iterator<int>(packed_weights_ss, ", "));
packed_weights_ss << packed_weights.back();

int64 total_weights =
    std::accumulate(packed_weights.begin(), packed_weights.end(), 0LL);

LOG(INFO) << "Total value: " << computed_value;
LOG(INFO) << "Packed items: {" << packed_items_ss.str() << "}";
LOG(INFO) << "Total weight: " << total_weights;
LOG(INFO) << "Packed weights: {" << packed_weights_ss.str() << "}";

}
