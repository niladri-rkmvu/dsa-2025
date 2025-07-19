/*---------------------------------------------------------------
Matrices
----------------------------------------------------------------*/

/* -------------------------------
1.a. Diagonal matrix | C approach
----------------------------------*/

#include <stdio.h>

struct Matrix
{
	int A[10];
	int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
	if(i==j)
		m->A[i-1]=x;
}

int get(struct Matrix m, int i, int j)
{
	if(i==j)
		return m.A[i-1];
	else
		return 0;
}

void display(struct Matrix m)
{
	for(int i=0; i<m.n; i++){
		for(int j=0; j<m.n; j++){
			if(i==j){
				printf("%d ",m.A[i]);
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int main()
{
	struct Matrix m;

	// 4x4 matrix
	m.n=4;

	set(&m,1,1,5); 
	set(&m,2,2,8); 
	set(&m,3,3,9); 
	set(&m,4,4,12);

	display(m);

	printf("%d",get(m,2,2));

	return 0;
}

/* -------------------------------
1.b. Diagonal matrix | C++ approach
----------------------------------*/
#include <iostream>
using namespace std;

class Diagonal
{
	private:
		int *A;
		int n; // order
	public:
		Diagonal(){
			n = 2;
			A = new int[2];
		}

		Diagonal(int n){
			this->n = n;
			A = new int[n];
		}

		~Diagonal(){
			delete[] A;
		}

		void set(int i, int j, int x);

		int get(int i, int j);

		void display();
};

void Diagonal::set(int i, int j, int x){
	if (i == j && i >= 1 && i <= n)
		A[i-1]=x;
}

int Diagonal::get(int i, int j){
	if (i == j && i >= 1 && i <= n)
		return A[i-1];
	return 0;
}

void Diagonal::display(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j)
				cout << A[i] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

int main()
{
	Diagonal d(4);

	d.set(1,1,5); 
	d.set(2,2,8);
	d.set(3,3,9);
	d.set(4,4,12);

	d.display();

	cout << "M[2,2] = " << d.get(2,2) << endl;
	return 0;
}

/* -------------------------------
2.a. Lower Triangular matrix - RMO and CMO | C
----------------------------------*/

#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int *A;
    int n;
    char mode;  // 'R' for Row-Major, 'C' for Column-Major
};

// Row-Major Order set with validation
void rmo_set(struct Matrix *m, int i, int j, int x) {
    if (i >= j) {
        int index = (i * (i - 1) / 2) + (j - 1);
        m->A[index] = x;
    } else if (x != 0) {
        printf("Error: Invalid entry at A[%d][%d] = %d. Upper triangle must be zero.\n", i, j, x);
        exit(1);
    }
}

// Column-Major Order set with validation
void cmo_set(struct Matrix *m, int i, int j, int x) {
    if (i >= j) {
        int index = (m->n * (j - 1)) - ((j - 2) * (j - 1) / 2) + (i - j);
        m->A[index] = x;
    } else if (x != 0) {
        printf("Error: Invalid entry at A[%d][%d] = %d. Upper triangle must be zero.\n", i, j, x);
        exit(1);
    }
}

// Row-Major Order get
int rmo_get(struct Matrix m, int i, int j) {
    if (i >= j)
        return m.A[(i * (i - 1) / 2) + (j - 1)];
    else
        return 0;
}

// Column-Major Order get
int cmo_get(struct Matrix m, int i, int j) {
    if (i >= j)
        return m.A[(m.n * (j - 1)) - ((j - 2) * (j - 1) / 2) + (i - j)];
    else
        return 0;
}

// Display matrix
void display(struct Matrix m) {
    int val;
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
        	if (m.mode == 'R')
        	    val = rmo_get(m, i, j);
        	else
        		val = cmo_get(m, i, j);
            printf("%d ", val);
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    int value;

    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    printf("Choose storage mode (R for Row-Major, C for Column-Major): ");
    scanf(" %c", &m.mode);

    // Allocate memory for lower triangular matrix
    m.A = (int *)malloc((m.n * (m.n + 1) / 2) * sizeof(int));

    printf("\nEnter the matrix row by row (upper triangle must be zero):\n");
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            scanf("%d", &value);
            if (m.mode == 'R')
                rmo_set(&m, i, j, value);
            else if (m.mode == 'C')
                cmo_set(&m, i, j, value);
            else {
                printf("Invalid mode selected.\n");
                free(m.A);
                return 1;
            }
        }
    }

    printf("\nLower Triangular Matrix (%s-Major Order):\n", (m.mode == 'R') ? "Row" : "Column");
    display(m);

    // Free allocated memory
    free(m.A);

    return 0;
}

/*
Note - in the above program - I am not checking the valid non-zero elements are indeed != 0
modfied that in the next C++ program - which is more accurate implementation
*/

/* -------------------------------
2.b. Lower Triangular matrix - RMO and CMO
----------------------------------*/

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class LowerTriangularMatrix {
private:
    vector<int> A;
    int n;
    char mode;  // 'R' for Row-Major, 'C' for Column-Major

    int rmo_index(int i, int j) const {
        return (i * (i - 1)) / 2 + (j - 1);
    }

    int cmo_index(int i, int j) const {
        return (n * (j - 1)) - ((j - 2) * (j - 1)) / 2 + (i - j);
    }

public:
    LowerTriangularMatrix(int size, char storage_mode) : n(size), mode(storage_mode) {
        if (mode != 'R' && mode != 'C')
            throw invalid_argument("Invalid storage mode. Use 'R' or 'C'.");
        A.resize(n * (n + 1) / 2);
    }

    void set(int i, int j, int x) {
        if (i < 1 || j < 1 || i > n || j > n)
            throw out_of_range("Index out of bounds.");

        if (i >= j) {
            if (x == 0)
                throw invalid_argument("Lower triangle entries must be non-zero.");
            int index = (mode == 'R') ? rmo_index(i, j) : cmo_index(i, j);
            A[index] = x;
        } else if (x != 0) {
            throw invalid_argument("Upper triangle must be zero.");
        }
    }

    int get(int i, int j) const {
        if (i < 1 || j < 1 || i > n || j > n)
            throw out_of_range("Index out of bounds.");

        if (i >= j) {
            int index = (mode == 'R') ? rmo_index(i, j) : cmo_index(i, j);
            return A[index];
        } else {
            return 0;
        }
    }

    void display() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    void displayIndexMapping() const {
        cout << "\nIndex Mapping (" << ((mode == 'R') ? "Row" : "Column") << "-Major Order):\n";

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {  // j should go from 1 to i
                int index = (mode == 'R') ? rmo_index(i, j) : cmo_index(i, j);
                cout << "A[" << index << "] = M(" << i << "," << j << ") = " << A[index] << endl;
            }
        }
    }

    // Displays the contents of the linear array A directly.
    void displayLinearArray() const {
        cout << "\nLinear Array (A) Contents:\n[";
        for (size_t k = 0; k < A.size(); ++k) {
            cout << A[k];
            if (k < A.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }
};

int main() {
    int n, value;
    char mode;

    cout << "Enter Dimension: ";
    cin >> n;

    cout << "Choose storage mode (R for Row-Major, C for Column-Major): ";
    cin >> mode;

    try {
        LowerTriangularMatrix matrix(n, mode);

        cout << "\nEnter the matrix row by row (upper triangle must be zero):\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> value;
                matrix.set(i, j, value);
            }
        }

        cout << "\nLower Triangular Matrix (" << ((mode == 'R') ? "Row" : "Column") << "-Major Order):\n";
        matrix.display();

        matrix.displayIndexMapping();
        matrix.displayLinearArray();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

/* -------------------------------
3. Upper Triangular matrix - RMO and CMO
----------------------------------*/

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class UpperTriangularMatrix {
private:
    vector<int> A;
    int n;
    char mode;  // 'R' for Row-Major, 'C' for Column-Major

    int rmo_index(int i, int j) const {
        return (n * (i - 1)) - ((i - 2) * (i - 1)) / 2 + (j - i);
    }

    int cmo_index(int i, int j) const {
        return (j * (j - 1)) / 2 + (i - 1);
    }

public:
    UpperTriangularMatrix(int size, char storage_mode) : n(size), mode(storage_mode) {
        if (mode != 'R' && mode != 'C')
            throw invalid_argument("Invalid storage mode. Use 'R' or 'C'.");
        A.resize(n * (n + 1) / 2);
    }

    void set(int i, int j, int x) {
        if (i < 1 || j < 1 || i > n || j > n)
            throw out_of_range("Index out of bounds.");

        if (i <= j) {
            if (x == 0)
                throw invalid_argument("Upper triangle entries must be non-zero.");
            int index = (mode == 'R') ? rmo_index(i, j) : cmo_index(i, j);
            A[index] = x;
        } else if (x != 0) {
            throw invalid_argument("Upper triangle must be zero.");
        }
    }

    int get(int i, int j) const {
        if (i < 1 || j < 1 || i > n || j > n)
            throw out_of_range("Index out of bounds.");

        if (i <= j) {
            int index = (mode == 'R') ? rmo_index(i, j) : cmo_index(i, j);
            return A[index];
        } else {
            return 0;
        }
    }

    void display() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    void displayIndexMapping() const {
        cout << "\nIndex Mapping (" << ((mode == 'R') ? "Row" : "Column") << "-Major Order):\n";

        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {  // j should go from i to n
                int index = (mode == 'R') ? rmo_index(i, j) : cmo_index(i, j);
                cout << "A[" << index << "] = M(" << i << "," << j << ") = " << A[index] << endl;
            }
        }
    }

    // Displays the contents of the linear array A directly.
    void displayLinearArray() const {
        cout << "\nLinear Array (A) Contents:\n[";
        for (size_t k = 0; k < A.size(); ++k) {
            cout << A[k];
            if (k < A.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }

};

int main() {
    int n, value;
    char mode;

    cout << "Enter Dimension: ";
    cin >> n;

    cout << "Choose storage mode (R for Row-Major, C for Column-Major): ";
    cin >> mode;

    try {
        UpperTriangularMatrix matrix(n, mode);

        cout << "\nEnter the matrix row by row (upper triangle must be zero):\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> value;
                matrix.set(i, j, value);
            }
        }

        cout << "\nUpper Triangular Matrix (" << ((mode == 'R') ? "Row" : "Column") << "-Major Order):\n";
        matrix.display();

        matrix.displayIndexMapping();
        matrix.displayLinearArray();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

/* -------------------------------
4. Symmetric matrix
----------------------------------*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

class LowerTriangularMatrix {
private:
    vector<int> A;
    int n;
    char mode;  // 'R' for Row-Major, 'C' for Column-Major

    int rmo_index(int i, int j) const {
        // Ensure i >= j for lower triangle access
        if (i < j) {
            swap(i, j);
        }
        return (i * (i - 1) / 2) + (j - 1);
    }

    int cmo_index(int i, int j) const {
        // Ensure i >= j for lower triangle access
        if (i < j) {
            swap(i, j);
        }
        return (n * (j - 1) - ((j - 2) * (j - 1) / 2)) + (i - j);
    }

public:
    LowerTriangularMatrix(int size, char storage_mode) : n(size), mode(storage_mode) {
        if (mode != 'R' && mode != 'C')
            throw invalid_argument("Invalid storage mode. Use 'R' or 'C'.");
        A.resize(n * (n + 1) / 2);
    }
    
    void set(int i, int j, int x) {
        if (i < 1 || j < 1 || i > n || j > n)
            throw out_of_range("Index out of bounds.");

        int row_idx = i;
        int col_idx = j;

        if (mode == 'R') {
            //cout << "row_idx = " << row_idx << " | " << "col_idx = " << col_idx << " | " << "rmo_index = " << rmo_index(row_idx, col_idx) << endl;
            A[rmo_index(row_idx, col_idx)] = x;
        } else { // mode == 'C'
            //cout << "row_idx = " << row_idx << " | " << "col_idx = " << col_idx << " | " << "cmo_index = " << cmo_index(row_idx, col_idx) << endl;
            A[cmo_index(row_idx, col_idx)] = x;
        }
    }
    
    int get(int i, int j) const {
        if (i < 1 || j < 1 || i > n || j > n)
            throw out_of_range("Index out of bounds.");
        int row_idx = i;
        int col_idx = j;

        if (mode == 'R') {
            return A[rmo_index(row_idx, col_idx)];
        } else { // mode == 'C'
            return A[cmo_index(row_idx, col_idx)];
        }
    }

    // Displays the full n x n matrix.
    // It retrieves values using the get method, which handles symmetry.
    void display() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    // Displays the mapping of matrix elements (specifically the lower triangle and diagonal)
    void displayIndexMapping() const {
        cout << "\nIndex Mapping (" << ((mode == 'R') ? "Row" : "Column") << "-Major Order):\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) { // Only iterate through lower triangle
                int computed_index = (mode == 'R') ? rmo_index(i, j) : cmo_index(i, j);
                cout << "A[" << computed_index << "] = M(" << i << "," << j << ") = " << A[computed_index] << endl;
            }
        }
    }

    // Displays the contents of the linear array A directly.
    void displayLinearArray() const {
        cout << "\nLinear Array (A) Contents:\n[";
        for (size_t k = 0; k < A.size(); ++k) {
            cout << A[k];
            if (k < A.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }
};

int main() {
    int n, value;
    char mode;

    cout << "Enter Dimension (n): ";
    cin >> n;

    cout << "Choose storage mode (R for Row-Major, C for Column-Major): ";
    cin >> mode;

    try {
        LowerTriangularMatrix matrix(n, mode);

        // Modified input loop to only ask for lower triangular elements
        cout << "\nEnter the " << n * (n + 1) / 2 << " unique elements of the symmetric matrix (lower triangle including diagonal):\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) { // Iterate only for lower triangle (i >= j)
                cout << "Enter M[" << i << "][" << j << "]: ";
                cin >> value;
                matrix.set(i, j, value);
            }
        }

        cout << "\n--- Displaying the Symmetric Matrix ---\n";
        cout << "Matrix (" << ((mode == 'R') ? "Row" : "Column") << "-Major Order):\n";
        matrix.display();

        matrix.displayIndexMapping();
        matrix.displayLinearArray();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
