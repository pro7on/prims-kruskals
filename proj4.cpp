#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 

struct triplet 									//enables to use 3 values that is weight/cost, vertice 1 and vertice 2 for krushals
{ 
   int x, y, z; 
}; 
std::vector< std::vector<int> > vec;
int inf = std::numeric_limits<int>::max();								//infinity value

vector<int> set1;
vector<int>	height;
int root;
int parent;
int node;

 
bool repetetiveSorter(triplet xval, triplet yval)     //Custom boolean sorter
{ 
    return (xval.x < yval.x); 
} 


int find3(int x) 													//find3 function
    { 
		root = x;
        while (root != set1[root]) {
            root = set1[root]; 
		}	
			
			
		node = x;
		while(node!= root){
		parent = set1[node];
		set1[node] = root;
		node = parent;
		}
     return root; 
    } 
	
	
 void union3(int repx, int repy) 								//union3 function
    { 
        
       if (height[repx] == height[repy])
	   {	height[repx]++;
			set1[repy] = repx; 	
	   }
	   else if (height[repx] > height [repy])
			set1[repy] = repx; 								
       else
			set1[repx] = repy;
   } 

  

void kruskalAL()								// Gets N and Vector array 
{ 

		srand(time(NULL));			//Makes sure random digit doesn't repeat

	const int n = 5 + rand() % (10 - 5 + 1);		// gets values for N between 5 to 10
	
	cout <<"Selected N Value: " << n << endl; 	
    cout << "\n"; 
	int V = n; 
	srand (time(NULL));									//Againt to make sure random do not repeat
	vec.resize(n, std::vector<int>(n << n, 0));			//resizes Matrix
  
	
	for (int i = 0; i <n; i++) { 
        for (int j = 0; j < n; j++){ 
           if(i == j){
		   vec[i][j] = 0;						//inserts 0 initially in all the elements
		   vec[j][i] = 0;
		   }
			else 
			{
				int r = (rand() % 10 + 1);			//generates random to be put in the Matrix Created
				vec[i][j] = r;					//insert random values
				vec[j][i] = r; 					//inverse has the same value
			}

		}
	
	}
	
	
	for (int i = 0; i <V; i++) 
	{ 
		for (int j = 0; j < V; j++)
		{ 
			cout<< "	"<< vec[i][j]; 				//Displaying Random Weighted Matrix
			
		} 
			cout<< "\n"; 							
	}	
	cout<< "\n"; 								
	cout<< "\n";

  vector<triplet> vec1; 							// Initializing our triple value vector
  
  
  for (int i = 0; i <V; i++) 
	{ 
		for (int j = 0; j < V; j++)
		{ 
		 if(j>i){
			vec1.push_back({vec[i][j], i, j});					//inserting weights and vertice in our vector array
			}
		}
	}	
  

	sort(vec1.begin(), vec1.end(), repetetiveSorter);  		//sorting all the edges E in non decreasing order
  
    
	
	

	set1.resize(V);												//resizing our global elements
	height.resize(V);
	
  for (int i = 0; i <V; i++) 
	{ 
			set1[i] = i;										//making its own set meaning root value is same for initialization
			height[i] = 0;										//height initialization		
	}
	
	
	
	
	int ver1[V] = {};												//holds vertice 1 element
	int ver2[V] = {};												//holds vertice 2 element
	int o = 0;
	int s = vec1.size(); 										
    for (int i=0;i<s;i++) 
    { 
	
	int u = vec1[i].y;
	int v = vec1[i].z;
	
    int ucomp = find3(u);										//get the find values for u &
	int vcomp = find3(v);										//                            v
	
	
	if (ucomp!= vcomp){
	
	ver1[o] = u;
	ver2[o] = v;
	o++;
	union3(ucomp,vcomp);										//union3 function

	}
	
} 


		int bi[n][n] = {};									//used for displaying the new matrix for prim
	
	 
		for (int j = 0; j < V-1; j++)
		{

			int a1 = ver1[j];
			int b1= ver2[j];
			if(a1==b1){
				break;
			}
			bi[a1][b1] = vec[a1][b1];
			bi[b1][a1] = vec[a1][b1];				// gets all the kruskals matrix
			
			
		} 
	
							
		
	
	
	
		cout << "Kruskals Matrix: "<<" \n" <<endl; 
	for (int i = 0; i <V; i++) 
	{ 	
		for (int j = 0; j <V; j++)
		{ 
			
			cout<< "	"<< bi[i][j]; 				//Displaying kruskals Matrix 
			
		} 
	
			cout<< "\n"; 				
	}	
	cout<< "\n"; 								
	cout<< "\n";
	cout<<"Kruskal's MST:"<<endl;
	for(int i=0;i<V;i++){
		int a1 = ver1[i];
		int b1= ver2[i];
		if(a1==b1){
			break;
		}
		cout <<  a1+1 << " - " << b1+1  << " : "<< vec[a1][b1]<<endl;			//displaying values from krushals
		
			
	}
	cout<< "\n"; 								
	cout<< "\n";
	 
}		
 
 
 
void procedure_prim()	// Gets N and Vector array 
{ 
	std::vector< std::vector<int> > vec2;			//vector array
	srand(time(NULL));			//Makes sure random digit doesn't repeat

	const int n = 5 + rand() % (10 - 5 + 1);		// gets values for N between 5 to 10
	
	cout <<"Selected N Value: " << n << endl; 	
    cout << "\n"; 
	int V = n; 
	
	
	
	srand (time(NULL));									//Againt to make sure random do not repeat
	vec2.resize(n, std::vector<int>(n << n, 0));			//resizes Matrix
	
	
	for (int i = 0; i <n; i++) { 
        for (int j = 0; j < n; j++){ 
           if(i == j){
		   vec2[i][j] = 0;						//inserts 0 initially in all the elements
		   vec2[j][i] = 0;
		   }
			else 
			{
				int r = (rand() % 10 + 1);			//generates random to be put in the Matrix Created
				vec2[i][j] = r;					//insert random values
				vec2[j][i] = r; 					//inverse has the same value
			}

		}
	
	}
	
	cout << "Random Generated Matrix: "<<" \n" <<endl; 
	for (int i = 0; i <V; i++) 
	{ 
		for (int j = 0; j < V; j++)
		{ 
			cout<< "	"<< vec2[i][j]; 						//Displays intitial matrix with random weights
			
		} 
			cout<< "\n"; 							
	}	
	cout<< "\n"; 								
	cout<< "\n";

	
	
	priority_queue<pair<int,int>> H;					//Priority queue using pair<>
    
	
	
	
	int cost[V],prev[V];
	bool visited[V];
	
	for(int i =0;i< V;i++){								//initiallizing cost and prev
		cost[i] = inf;
		prev[i] = 0;
		visited[i] = false;
	}
	
	
    H.push(make_pair(0,0)); 
	int u_0 = 0; 
    cost[u_0] = 0; 
  
    int i = 0;
	int a = 0;
	int b = 1;
    while (!H.empty()) 
    { 
	
			
		pair<int, int> qu = H.top();							//helps split the queue elements that is vertice and weights
        int v = qu.second; 										// gets v value which is minimum of all explored vertices till now
        H.pop(); 
        visited[v] = true;   
		a = v;															//a holds where the exploration should start from initially it is 0													
		b  = a+1;													
        
        for (i = a; i < b; i++) 											// here a now which has v value will be used to put the elements in priority_queue
        { 
	
			for (int j=0;j<V;j++){
			
			int v1 = j; 												//getting the particular vertice that is being explored currently
            int w = vec2[i][j]; 											// getting the cost/weight of vertice being explored currently
			
			
			
            if (visited[v1] == false && cost[v1] > w && i!=j) 
            { 
			    cost[v1] = w; 											//replacing infinity with the cost 
                prev[v1] = v; 											// vertice to be put in the queue
				int ins = -1 * cost[v1];								// converting pq to negative so as to get a min heap
				H.push(make_pair(ins, v1)); 							//loading into queue only when the vertice is not visited and has infinity
                
				}
			} 
        } 
		
		 
		if(a==V){												//breaks after all the edges are visited done to avoid seg fault
			break;
		}
	} 

	
		
	int bi[n][n] = {};									//used for displaying the new matrix for prim
	

		for (int j = 0; j < V; j++)
		{ 
			
			a = prev[j];
			bi[a][j] = cost[j];
			bi[j][a] = cost[j];				// gets all the Prims matrix

		} 
		
	
	
		cout << "Prims Matrix: "<<" \n" <<endl; 
	for (int i = 0; i <V; i++) 
	{ 	
		for (int j = 0; j <V; j++)
		{ 
			cout<< "	"<< bi[i][j]; 				//Displaying Prims Matrix 
			
		} 
	
			cout<< "\n"; 				
	}	
	cout<< "\n"; 								
	cout<< "\n";								
		
	
	
	
	
	
	cout << "Prims MST: "<<" \n" <<endl; 
	for (int i = 0; i <1; i++) 
	{ 	
		for (int j = 1; j <V; j++)
		{ 
			cout<< prev[j]+1 << "-"<< j+1 <<"cost: "<<cost[j]<<endl; 				//Displaying selected node with weights
			
		} 
	
							
	}	
	cout<< "\n"; 								
	cout<< "\n";								
		
		
		
	
}		
 
 
 


 
int main(int argc, char** argv) 
{ 

	int c;
	do
  {
    cout << "1.Prims\n";
    cout << "2.Kruskals\n";
    cout << "3.Exit\n";
    cout << "Enter your choice : ";
    cin >> c;
    switch (c)
	   {
    case 1:
	  procedure_prim(); 
	  break;
    case 2:
      kruskalAL();
      break;
    case 3:
      break;
    default:
      cout << "Wrong choice\n";
    }
  } while (c != 3);
	return 0; 
}
