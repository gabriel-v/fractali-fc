/* constant int x = -50; */
kernel void simple_add(global const int *A, global const int *B,
                       global unsigned int *C) {
	int i = get_global_id(0);
	C[i] = (int) (180 * carg((complex) (A[i], B[i]))) << 1;
}

