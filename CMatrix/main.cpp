#include "matrix.h"

using namespace std;

int main()
{
	// matrix<Columns, Rows>
	matrix<2, 3> A; // 2 Columns, 3 Rows
	matrix<4, 2> B; // 4 Columns, 2 Rows

	// 2x3 * 4x2 = 4x3
	matrix<4, 3> C = A * B;
	// matrix<2, 2> D = B * A; // Columns of B does not match rows of A!

	return 0;
}
