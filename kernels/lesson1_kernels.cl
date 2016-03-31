#pragma OPENCL EXTENSION cl_khr_byte_addressable_store : enable
__constant char hw[] = "Hello World\n";
__kernel void helloKernel ( __global int * out ) {
   size_t tid = get_global_id(0);
   out[tid] = hw[tid];
}
