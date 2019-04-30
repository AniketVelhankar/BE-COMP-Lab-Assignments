/*
 * MatrixOP.cpp
 *
 *  Created on: Aug 25, 2018
 *      Author: student
 */


#include <iostream>
using namespace std;

class MatrixOpera
{
	int mat1[10][10], r, c;

public :

	void getmatrix()
	{
	    cout << "Enter rows and columns of matrix: ";
	    cin >> r >> c;

	    cout << endl << "Enter elements of matrix: " << endl;

	    for(int i = 0; i < r; ++i)
	    {
			for(int j = 0; j < c; ++j)
			{
				cout << "Enter element - " << i + 1 <<" "<< j + 1 << ": ";
				cin >> mat1[i][j];
			}
	    }

	    cout << endl << "Entered Matrix: " << endl;
	    for(int i = 0; i < r; ++i)
	    {
	        for(int j = 0; j < c; ++j)
	        {
	            cout << " " << mat1[i][j];
	        }
	        cout<<endl<<endl;
	    }
	}

	void transpose()
	{
		int trans[10][10];
	    for(int i = 0; i < r; ++i)
	    {
	        for(int j = 0; j < c; ++j)
	        {
	            trans[j][i]=mat1[i][j];
	        }
	    }

	    cout << endl << "Transpose of Matrix: " << endl;
	    for(int i = 0; i < c; ++i)
	    {
	        for(int j = 0; j < r; ++j)
	        {
	            cout << " " << trans[i][j];
	        }
	        cout<<endl<<endl;
	    }
	}

	void upperTriang()
	{
	    bool isUpperTriangular;

	    for(int i = 0; i < r; ++i)
	    {
	    	for(int j = 0; j < c; ++j)
	    	{
	    		if(j<=i && mat1[i][j]==0 )
	    		{
	    			isUpperTriangular = true;
	    		}
	    	}
	    }

	    if(isUpperTriangular)
	    	cout<<"Matrix is upper triangular";
	    else
	    	cout<<"Matrix is not upper triangular";
	}

	void diagsum()
	{
	    int sum=0;

	    for(int i = 0; i < r; ++i)
	    {
	    	for(int j = 0; j < c; ++j)
	    	{
	    		if(j==i)
	    		{
	    			sum = sum + mat1[i][j];
	    		}
	    	}
	    }

	    cout<<endl<<"Sum of diagonal elements is "<<sum<<endl;
	}

	void addition()
	{
		int mat2[10][10], add[10][10], p, q;

	    cout << "Enter rows and columns of matrix 2: ";
	    cin >> p >> q;

	    cout << endl << "Enter elements of matrix: " << endl;

	    for(int i = 0; i < p; ++i)
	    {
	    	for(int j = 0; j < q; ++j)
	    	{
	    		cout << "Enter elements - " << i + 1 <<" "<< j + 1 << ": ";
	    		cin >> mat2[i][j];
	    	}
	     }

	    // Displaying the matrix mat2[][]
	     cout << endl << "Entered Matrix: " << endl;
	     for(int i = 0; i < p; ++i)
	     {
	        for(int j = 0; j < q; ++j)
	        {
	             cout << " " << mat2[i][j];
	        }
	        cout<<endl<<endl;
	     }

	    //add two matrices
	     for(int i = 0; i < r; ++i)
	     {
	        for(int j = 0; j < c; ++j)
	        {
	              add[i][j] = mat1[i][j] + mat2[i][j];
	        }
	      }

	     // Displaying the matrix add[][]
	      cout << endl << "Addition Matrix: " << endl;
	      for(int i = 0; i < r; ++i)
	      {
	         for(int j = 0; j < c; ++j)
	         {
	              cout << " " << add[i][j];
	         }
	         cout<<endl<<endl;
	      }
	}

	void subtract()
	{
		int mat2[10][10], sub[10][10], p, q;

	    cout << "Enter rows and columns of matrix 2: ";
	    cin >> p >> q;

	    cout << endl << "Enter elements of matrix: " << endl;

	    for(int i = 0; i < p; ++i)
	    {
	    	for(int j = 0; j < q; ++j)
	    	{
	    		cout << "Enter elements - " << i + 1 <<" "<< j + 1 << ": ";
	    		cin >> mat2[i][j];
	    	}
	     }

	    // Displaying the matrix mat2[][]
	     cout << endl << "Entered Matrix: " << endl;
	     for(int i = 0; i < p; ++i)
	     {
	        for(int j = 0; j < q; ++j)
	        {
	             cout << " " << mat2[i][j];
	        }
	        cout<<endl<<endl;
	     }

	    //add two matrices
	     for(int i = 0; i < r; ++i)
	     {
	        for(int j = 0; j < c; ++j)
	        {
	              sub[i][j] = mat1[i][j] - mat2[i][j];
	        }
	      }

	     // Displaying the matrix sub[][]
	      cout << endl << "Subtraction Matrix: " << endl;
	      for(int i = 0; i < r; ++i)
	      {
	         for(int j = 0; j < c; ++j)
	         {
	              cout << " " << sub[i][j];
	         }
	         cout<<endl<<endl;
	      }

	}

	void mult()
	{
		int mul[10][10], mat2[10][10], p, q;

	    cout << "Enter rows and columns of matrix 2: ";
	    cin >> p >> q;

	    cout << endl << "Enter elements of matrix: " << endl;

	    for(int i = 0; i < p; ++i)
	    {
	    	for(int j = 0; j < q; ++j)
	    	{
	    		cout << "Enter elements - " << i + 1 <<" "<< j + 1 << ": ";
	    		cin >> mat2[i][j];
	    	}
	     }

	    // Displaying the matrix mat2[][]
	     cout << endl << "Entered Matrix: " << endl;
	     for(int i = 0; i < p; ++i)
	     {
	        for(int j = 0; j < q; ++j)
	        {
	             cout << " " << mat2[i][j];
	        }
	        cout<<endl<<endl;
	     }

	    //multiplication of two matrices

	     if(c == p)
	     {
	    	 for(int i=0;i<r;i++)
	    	 {
	    		 for(int j=0;j<q;j++)
	    		 {
	    			 mul[i][j]=0;

	    			 for(int k=0;k<q;k++)
	    			 {
	    				 mul[i][j] = mul[i][j] + mat1[i][k] * mat2[k][j];
	    			 }
	    		 }
	    	 }
	     }
	     else
	     {
	    	 cout<<"Matrix multiplication could not be done\n";
	     }

	     cout << endl << "Multiplication Matrix: " << endl;
	     for(int i = 0; i < r; ++i)
	     {
	    	   for(int j = 0; j < c; ++j)
	    	   {
	               cout << " " << mul[i][j];
	           }
	           cout<<endl<<endl;
	      }
	}

	void isSaddle()
	{
		bool pass=1;

		for(int i=0;i<r;i++)
		{
			int smallest_in_row=mat1[i][0];
			int col_ind = 0;

			for(int j=0;j<c;j++)
			{
				if(smallest_in_row > mat1[i][j])
				{
					smallest_in_row = mat1[i][j];
					col_ind = j;
				}
			}

			int largest_in_col = 0;

			for(int j=0;j<c;j++)
			{
				if(largest_in_col < mat1[j][col_ind])
				{
					largest_in_col =  mat1[j][col_ind];
				}
			}

			if(smallest_in_row == largest_in_col)
			{
				cout<<"Saddle point is "<<smallest_in_row;
				pass=0;
			}
		}

		if(pass !=0)
		{
			cout<<"Sorry, no saddle point";
		}
	}
};

int main()
{
	MatrixOpera obj;
	int choice;
	char ch;

	obj.getmatrix();

	do
	{
			cout<<"Enter the operation you want to perform -\n\n";
			cout<<"1. Transpose\n2. Find whether matrix is upper triangular\n3. Addition of diagonal elements\n4. Addition\n5. Subtraction\n6. Multiplication\n7. Find whether matrix has saddle point\n\n";
			cin>>choice;

			switch(choice)
			{
				case 1:
					obj.transpose();
					break;
				case 2:
					obj.upperTriang();
					break;
				case 3:
					obj.diagsum();
					break;
				case 4:
					obj.addition();
					break;
				case 5:
					obj.subtract();
					break;
				case 6:
					obj.mult();
					break;
				case 7:
					obj.isSaddle();
					break;
			}
		cout<<"\n\nContinue ? (y/n)";
		cin>>ch;
	}while(ch=='y' || ch=='Y');

	cout<<"Thanks - Program terminated successfully";

    return 0;
}


