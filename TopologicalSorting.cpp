- #include <iostream> 
#include <list> 
#include <stack> 
using namespace std; 

class Graph {
	int v;
	list<int>* adj;
	void topologicalSortUtil(int v, bool visited[], 
                             stack<int>& Stack); 
                             
public: 
    Graph(int v);
	void addedge(int v,int w);
	void topologicalsort();                             
};
Graph::Graph(int v){
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addedge(int v, int w){
	adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], 
                             stack<int>& Stack)
                             
{
    visited[v]=true;	
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
            
            
    Stack.push(v);         
}

void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool* visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to store Topological 
    // Sort starting from all 
    // vertices one by one 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack); 
  
    // Print contents of stack 
    while (Stack.empty() == false) { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
} 
  
// Driver Code 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given "
            "graph \n"; 
    
    // Function Call 
    g.topologicalSort(); 
  
    return 0; 
}
							 
