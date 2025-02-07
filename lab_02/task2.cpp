#include <iostream >
using namespace std ;
int **Allocate(int row,int col){
	int **ptr=new int *[row];
	for(int i=0;i<row;i++){
		ptr[i]=new int [col];
	}
	return ptr;
}
void deallocate(int **ptr,int row){
    for (int i = 0; i < row; i++)
    {
        delete[] ptr[i];
    }
    delete ptr;
}
void input(int **ptr,int row,int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"("<<i+1<<","<<j+1<<") :";
            cin>> ptr[i][j];
        }
    }
}
void display(int **ptr,int row ,int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<ptr[i][j]<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void add(int **ptr1,int** ptr2,int** ptr3,int row,int col){
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            ptr3[i][j]=ptr1[i][j]+ptr2[i][j];
        }
    }
}
void sub(int **ptr1,int** ptr2,int** ptr3,int row,int col){
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            ptr3[i][j]=ptr1[i][j]-ptr2[i][j];
        }
    }
}
int main(){
	int rows,cols,choice;
	cout<<"Enter the number of rows of Matrix : ";
	cin>>rows;
	cout<<"Enter the number of coloumn of Matrix : ";
	cin>>cols;	
	int **ptr1=Allocate(rows,cols);
	int **ptr2=Allocate(rows,cols);
	int **ptr3=Allocate(rows,cols);
	cout<<"Values For Matrix 1:\n";
	input(ptr1,rows,cols);
	cout<<"Values For Matrix 2:\n";
	input(ptr2,rows,cols);
	cout<<endl;
	cout<<"Matrix Addition \n";
	add(ptr1,ptr2,ptr3,rows,cols);
	display(ptr3,rows,cols);
	cout<<"Matrix Subtraction \n";
	sub(ptr1,ptr2,ptr3,rows,cols);
	display(ptr3,rows,cols);
	deallocate(ptr1,rows);
	deallocate(ptr3,rows);
	deallocate(ptr2,rows);
}
