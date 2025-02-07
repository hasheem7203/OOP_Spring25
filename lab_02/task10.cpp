#include <iostream>
using namespace std;

int ***allocate(int x,int y,int z){
	int ***ptr=new int **[x];
	for(int i=0;i<x;i++){
		ptr[i]=new int*[y];
		for(int j=0;j<y;j++){
			ptr[i][j]=new int[z];
		}
	}
	return ptr;
}
void deallocate(int ***ptr,int x,int y){
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            delete[] ptr[i][j];
        }
        delete[] ptr[i];
    }
    delete[] ptr;
}
void display(int*** ptr, int x, int y, int z) {
    cout << "\n========= 3D Array Elements =========\n";
    for (int i=0;i<x;i++) {
        cout << "Layer " <<i + 1<<":\n";
        for(int j=0;j<y;j++) {
            for(int k=0;k<z;k++) {
                cout<<ptr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << "--------------------------------\n";
    }
}
void input(int ***ptr, int x, int y, int z){
    for(int i=0;i<x;i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                cout <<"("<<i+1<<","<<j+1<<","<<k+1<<")";
                cin>>ptr[i][j][k];
            }
        }
    }
}
int main(){
	int x,y,z;
    cout<< "Enter 1D size:";
    cin>>x;
    cout<< "Enter 2D size:";
    cin>>y;
    cout<< "Enter 3D size:";
    cin >>z;
    int ***ptr=allocate(x,y,z);
    input(ptr,x,y,z);
    display(ptr,x,y,z);
    deallocate(ptr,x,y);
}

