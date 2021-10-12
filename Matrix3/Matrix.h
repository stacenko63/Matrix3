#pragma once
#include <iostream> 
#include <vector>
using namespace std;
template <class T>
class Matrix
{
private:
	vector<vector<T>> arr;  
	template <typename T1>
	bool CheckDivisionByZero(T1)
	{
		//if (number == 0) return true;
		return false;
	}
	template<>
	bool CheckDivisionByZero(int number)
	{
		if (number == 0) return true;
		return false;
	}
	template<>
	bool CheckDivisionByZero(float number)
	{
		if (number == 0) return true;
		return false;
	}
	template<>
	bool CheckDivisionByZero(double number)
	{
		if (number == 0) return true; 
		return false;
	}

public:
	int GetN() const
	{
		return arr.size(); 
	}
	int GetM() const
	{
		return arr[0].size(); 
	}
	Matrix(int n, int m, T value)
	{
		if (n > 0 && m > 0)
		{
			arr.resize(n);  
			for (int i = 0; i < n; i++)
			{
				arr[i].resize(m); 
				for (int j = 0; j < m; j++)
				{
					arr[i][j] = value; 
				}
			}
		}
		else throw "Incorrect matrix sizes are specified!"; 
	}
	T MatrixTrace() const
	{
		T trace = 0;
		for (int i = 0, j = 0; i < (int)arr.size() && j < (int)arr[i].size(); i++, j++) 
		{
			trace += arr[i][j];
		}
		return trace;
	}
	Matrix<T> operator*(T number)
	{
		Matrix<T> temp(arr.size(), arr[0].size(), 0);
		for (int i = 0; i < (int)arr.size(); i++)
		{
			for (int j = 0; j < (int)arr[i].size(); j++)
			{
				temp.arr[i][j] = arr[i][j] * number;
			}
		}
		return temp;
	}

	template <typename AT1>
	Matrix<T> operator*(AT1)
	{
		throw "Matrix type and number type must be the same!";
	}


	/*
	for (auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		for (auto it = iter->begin(); it != iter->end(); it++)
		{
			*it = *it - 6;
			cout «* it;
		}
		cout « endl;
	}
	*/

	Matrix<T> operator/(T number)
	{
		if (CheckDivisionByZero(number)) throw "Division by 0"; 
		Matrix<T> temp(arr.size(), arr[0].size(), 0);
		for (int i = 0; i < (int)arr.size(); i++)
		{
			for (int j = 0; j < (int)arr[0].size(); j++)
			{
				temp.arr[i][j] = arr[i][j] / number;
				if (temp.arr[i][j] != temp.arr[i][j]) throw "Division by 0";
			}
		}
		return temp;
	}


	template <typename T1>
	Matrix<T> operator/(T1)
	{
		throw "Matrix type and number type must be the same!";
	}


	Matrix<T> operator*(const Matrix<T>& other)
	{
		if (this->arr[0].size() == other.arr.size()) 
		{
			Matrix<T> temp(this->arr.size(), other.arr[0].size(), 0); 
			for (int i = 0; i < (int)this->arr.size(); i++)
			{
				for (int k = 0; k < (int)other.arr[0].size(); k++) 
				{
					for (int j = 0; j < (int)this->arr[0].size(); j++)
					{
						temp.arr[i][k] += this->arr[i][j] * other.arr[j][k];
					}
				}
			}
			return temp;
		}
		throw "The number of columns of the first matrix must be equal to the number of rows of the second matrix!";
	}
	template <typename T1>
	Matrix<T> operator*(const Matrix<T1>&)
	{
		throw "The matrices must be of the same type!";
	}
	template <typename T2>
	Matrix<T> operator+(const Matrix<T2>&)
	{
		throw "The matrices must be of the same type!";
	}
	bool operator==(const Matrix<T>& other)
	{
		if (this->arr.size() != other.arr.size() || this->arr[0].size() != other.arr[0].size()) return false;
		for (int i = 0; i < (int)arr.size(); i++)
		{
			for (int j = 0; j < (int)this->arr[0].size(); j++)
			{
				if (this->arr[i][j] != other.arr[i][j]) return false;
			}
		}
		return true;
	}
	template <typename T4>
	bool operator==(const Matrix<T4>&)
	{
		return false;
	}
	template <typename T5>
	bool operator!=(const Matrix<T5>&)
	{
		return true;
	}
	bool operator!=(const Matrix<T>& other)
	{
		return (!(*this == other));
	}
	Matrix<T> operator+(const Matrix<T>& other)
	{
		if (other.arr.size() == this->arr.size() && other.arr[0].size() == this->arr[0].size())
		{
			Matrix<T> temp(arr.size(), other.arr[0].size(), 0); 
			for (int i = 0; i < (int)arr.size(); i++)
			{
				for (int j = 0; j < (int)other.arr[0].size(); j++) 
				{
					temp.arr[i][j] = this->arr[i][j] + other.arr[i][j];
				}
			}
			return temp;
		}
		throw "The matrices must be of the same dimension!\n";
	}
	Matrix<T> operator-(const Matrix<T>& other)
	{
		if (other.arr.size() == this->arr.size() && other.arr[0].size() == this->arr[0].size())
		{
			Matrix<T> temp(other.arr.size(), other.arr[0].size(), 0);
			for (int i = 0; i < (int)arr.size(); i++)
			{
				for (int j = 0; j < (int)arr[0].size(); j++) 
				{
					temp.arr[i][j] = this->arr[i][j] - other.arr[i][j]; 
				}
			}
			return temp;
		}
		throw "The matrices must be of the same dimension!";
	}
	template <typename T1>
	Matrix<T> operator-(const Matrix<T1>&)
	{
		throw "The matrices must be of the same type!";
	}
	T& operator()(const int row, const int col)
	{
		if (row >= 0 && col >= 0 && row < (int)arr.size() && col < (int)arr[0].size()) 
		{
			return arr[row][col];
		}
		throw "The indexes are set incorrectly!";
	}
	T operator()(const int row, const int col) const
	{
		if (row >= 0 && col >= 0 && row < (int)arr.size() && col < (int)arr[0].size())
		{
			return arr[row][col];
		}
		throw "The indexes are set incorrectly!";
	}

	template <typename T1>
	Matrix<T>& operator=(const Matrix<T1> other)
	{
		throw "The matrices must be of the same type!";

	}
};


template <typename T>
ostream& operator <<(ostream& out, const Matrix<T>& matrix)
{
	for (int i = 0; i < matrix.GetN(); i++)
	{
		for (int j = 0; j < matrix.GetM(); j++)
		{
			out << matrix(i, j) << " ";
		}
		out << endl;
	}
	return out;

}