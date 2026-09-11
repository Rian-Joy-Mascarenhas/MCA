#include <iostream>
using namespace std;
class Matrix{
    int rows,cols;
    int mat[10][10];
public:
    Matrix() : rows(0), cols(0){
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                mat[i][j]=0;
    }
    Matrix(int r,int c){
        rows=r;
        cols=c;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                mat[i][j]=0;
    }
    void accept() {
        cout <<"Enter elements for "<<rows<<"x"<<cols<<" matrix:\n";
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>mat[i][j];
            }
        }
    }
    void display() const{
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<mat[i][j]<<"\t";
            }
            cout << "\n";
        }
    }
    bool operator == (const Matrix &m){
        return (this->rows == m.rows && this->cols == m.cols);
    }
    Matrix operator + (const Matrix &m){
        Matrix temp(rows,cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++) {
                temp.mat[i][j]=this->mat[i][j] + m.mat[i][j];
            }
        }
        return temp;
    }
    Matrix operator - (const Matrix &m){
        Matrix temp(rows,cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                temp.mat[i][j] = this->mat[i][j] - m.mat[i][j];
            }
        }
        return temp;
    }
};
int main(){
    int r1,c1,r2,c2;
    cout<<"Enter rows and columns for Matrix 1:";
    cin>>r1>>c1;
    Matrix m1(r1,c1);
    m1.accept();
    cout<<"Enter rows and columns for Matrix 2:";
    cin>>r2>>c2;
    Matrix m2(r2,c2);
    m2.accept();
    if (m1 == m2) {
        cout << "\nMatrices are compatible! Performing addition and subtraction...\n";
        Matrix m3 = m1 + m2;
        Matrix m4 = m1 - m2;
        cout << "\nMatrix Addition (m3 = m1 + m2):\n";
        m3.display();
        cout << "\nMatrix Subtraction (m4 = m1 - m2):\n";
        m4.display();
    }else{
        cout <<"\nError: Matrices are NOT compatible for addition and subtraction! Dimensions must match.\n";
    }
    return 0;
}
