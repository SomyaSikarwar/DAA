#include<iostream>
using namespace std;

void bellmanFord(int src ,int v, int mat[][10]){
     int dist[v];
     for(int i=0 ;i<v ;i++){
         dist[i] = 99;
     }
     
     dist[src-1] = 0;
     
     for(int i =0 ; i< v-1 ;i++){
         
         for(int j = 0 ; j < v ; j++){
             for(int k = 0 ; k< v ;k++){
                 
                 if(mat[j][k]!=0){
                     
	 		if(dist[j]+mat[j][k]<dist[k]){
	 					    
	 		ist[k]=dist[j]+mat[j][k];
						 
			 }
		 }
             }
         }
         for(int b=0;b<v;b++){
		cout<<dist[b]<<" ";
	}
	 cout<<endl;
     }
     
     for(int i=0;i<v;i++){
		cout<<dist [i]<<" ";
	}
	cout<<endl;
    //negative cycle 
    int prev[v];
    for(int i=0 ;i < v ;i++){
        prev[i]= dist[i];
    }
    
    for(int j = 0 ; j < v ; j++){
             for(int k = 0 ; k< v ;k++){
                 if(mat[j][k]!=0){
	 		if(dist[j]+mat[j][k]<dist[k]){
	 					    
	 		dist[k]=dist[j]+mat[j][k];
						 
			 }
		 }
             }
    }
    for(int i=0 ;i < v ;i++){
      if(prev[i] != dist[i]){
          cout<<"NEGATIVE CYCLE IS FOUND!!!";
      }
    }
    
    cout<<"NO NEGATIVE CYCLE IS FOUND!!";
}

int main(){
    int v , e ;
    
    cout<<"Enter the number of vertices: ";
    cin>>v;
    
    cout<<"Enter the number of edges: ";
    cin>>e;
    
    cout<<"-----Enter Edge Details-----";
    int start ,end ,cost;
    int mat[10][10];
    for(int i =0; i< e ;i++){
        cout<<"Source Destination Cost : ";
        cin>> start >> end >> cost;
        
        mat[start-1][end-1] = cost ;
    }
    
    int src;
    cout<<"Enter source vertex: ";
    cin>>src;
    
    for(int i =0 ; i< v ;i++){
        cout<<"\n";
        for(int j = 0 ; j < v ; j++){
            cout<<mat[i][j]<<"\t";
        }
    }
    
    bellmanFord(src,v,mat);
    
    
    
    return 0;
}
