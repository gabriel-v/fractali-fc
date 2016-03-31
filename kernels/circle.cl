#pragma OPENCL EXTENSION cl_khr_fp64 : enable

kernel void circle(global const double *X, global const int *Y,
                       global unsigned int *IMG,
			const int width, const int height) {

	int j = get_global_id(0);
	int i = get_global_id(1);
/*
	if(X[i] * X[i] + Y[j] * Y[j] < 0.5) {
		IMG[i * width + j] = 0xFFFFFFFF;
	} else {
		IMG[i * width + j] = 0;
	}
*/
	IMG[i] = 0xFFFF;
	IMG[j] = 0xFFFF;
	IMG[i + j] = 0xFFFF;
}