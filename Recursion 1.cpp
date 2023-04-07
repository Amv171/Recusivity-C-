#include <iostream>
using namespace std;    
int sumarTodos(int n);
int gridPaths(int n, int m);
int partitions(int n, int m);
int factorial(int n);
int exponent(int n, int m);
void cambio_array(int nums[3], char op[3], int *sol, int obj);
int main()
{
	int pow = exponent(2, 5);
	int facto = factorial(5);
	int sumar = sumarTodos(2);
	int grid = gridPaths(3, 3);
	int parts = partitions(9,5);
 //   cout << "La suma de los 5 primeros numeros  "<<sumar<<endl<<"Grid de 3x3  "<<grid<<endl<<"Partitions de 9 con max de 5  "<<parts<<endl<<"El factorial de 5 es "<<facto<<endl;
	//cout << "2 elevado a 5 es " << pow;
	int nums[] = { 5,2,3 };
	char op[] = { false,false,false };
	int sol = 0;
	cambio_array(nums, op, &sol, 5);
}
int sumarTodos(int n) {
	if (n== 0)
	{
		return 0;
	}
	else
	{
		return n + sumarTodos(n - 1);
	}
}
int gridPaths(int n, int m) {
	if (n == 1 || m == 1)
	{
		return 1;
	}
	else
	{
		return gridPaths(n - 1, m) + gridPaths(n, m - 1);
	}
}
int partitions(int n, int m){
	if (m == 0 || n<0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return partitions(n - m, m) + partitions(n, m - 1);
	}
}
int factorial(int n){
	if (n == 0 )
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}

}
int exponent(int n, int m) {
	if (m == 0)
	{
		return 1;
	}
	else
	{
		return n * exponent(n, m - 1);
	}


}
void cambio_array(int nums[3], char op[3], int* sol, int obj){
	for (int i = 0; i < 3; i++)
	{
		if (op[i] == true)
		{
			*sol += nums[i];
		}
	}
	if (*sol == obj)
	{
		cout << "Success";
		for (int i = 0; i < 3; i++)
		{
			if (op[i] == true)
			{
				cout << " True ";
			}
			if (op[i] == false)
			{
				cout << " False ";
			}
		}
		exit(0);
	}
	else
	{
		*sol = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		if (op[i] == false)
		{
			op[i] = true;
			cambio_array(nums,op, sol, obj);
			op[i] = false;
		}
	}
}