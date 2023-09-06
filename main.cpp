#include <iostream>
#include <cstdlib>

template <size_t size>
struct Matrix
{
	int array[size][size];
};

int generateRandomNumber(int min, int max)
{
	int dif = max - min;
	return (rand() % dif) + min;
}

template <size_t size>
void fillMatrix(Matrix<size>& resultMatrix)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			resultMatrix.array[i][j] = generateRandomNumber(0, 20);
		}
	}
}

template <size_t size>
void printMatrix(const Matrix<size>& matrix)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << matrix.array[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

template <size_t size>
Matrix<size> multiplyMatrix(const Matrix<size>& left, const Matrix<size>& right)
{
	Matrix<size> resultMatrix{};
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				resultMatrix.array[i][j] += left.array[i][k] * right.array[k][j];
			}
		}
	}
	return resultMatrix;
}

template <size_t size>
static Matrix<size> operator*(const Matrix<size>& left, const Matrix<size>& right)
{
	return multiplyMatrix(left, right);
}

int main()
{
	srand(time(0));

	const int num = 3;
	Matrix<num> matrix1;
	Matrix<num> matrix2;

	fillMatrix(matrix1);
	fillMatrix(matrix2);

	std::cout << "First matrix: \n";
	printMatrix(matrix1);
	std::cout << "\n";

	std::cout << "Second matrix: \n";
	printMatrix(matrix2);
	std::cout << "\n";

	Matrix<num> resultMatrix = matrix1 * matrix2;
	std::cout << "Result matrix: \n";
	printMatrix(resultMatrix);
}