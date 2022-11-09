#ifndef HANNING_WINDOW_H_
#define HANNING_WINDOW_H_

// This array is generated by the following Python script:
// ```py
// import numpy as np
// N = 1024
// w = np.zeros((N,1))
// for i in range(N):
//     w[i] = 0.5 * (1 - np.cos((2 * np.pi * i) / (N - 1)))
// c_header = "static fract16 w[1024] = {"
// for i in range(N):
//     a = int(float(w[i]) * 2 ** 15)
//     c_header += hex(a) + ","
// c_header += "};"
// print(c_header)
// ```
static fract16 w[1024] = {
    0x0,    0x0,    0x1,    0x2,    0x4,    0x7,    0xb,    0xf,    0x13,
    0x19,   0x1e,   0x25,   0x2c,   0x34,   0x3c,   0x45,   0x4f,   0x59,
    0x64,   0x6f,   0x7b,   0x88,   0x95,   0xa3,   0xb1,   0xc0,   0xd0,
    0xe0,   0xf1,   0x103,  0x115,  0x128,  0x13b,  0x14f,  0x163,  0x179,
    0x18e,  0x1a5,  0x1bc,  0x1d3,  0x1eb,  0x204,  0x21e,  0x238,  0x252,
    0x26d,  0x289,  0x2a5,  0x2c2,  0x2e0,  0x2fe,  0x31d,  0x33c,  0x35c,
    0x37c,  0x39d,  0x3bf,  0x3e1,  0x404,  0x428,  0x44b,  0x470,  0x495,
    0x4bb,  0x4e1,  0x508,  0x52f,  0x557,  0x580,  0x5a9,  0x5d3,  0x5fd,
    0x628,  0x653,  0x67f,  0x6ab,  0x6d8,  0x706,  0x734,  0x763,  0x792,
    0x7c2,  0x7f2,  0x823,  0x854,  0x886,  0x8b8,  0x8eb,  0x91f,  0x953,
    0x988,  0x9bd,  0x9f2,  0xa28,  0xa5f,  0xa96,  0xace,  0xb06,  0xb3f,
    0xb78,  0xbb2,  0xbec,  0xc27,  0xc62,  0xc9e,  0xcda,  0xd17,  0xd54,
    0xd92,  0xdd0,  0xe0f,  0xe4e,  0xe8d,  0xece,  0xf0e,  0xf4f,  0xf91,
    0xfd3,  0x1015, 0x1058, 0x109c, 0x10e0, 0x1124, 0x1169, 0x11ae, 0x11f4,
    0x123a, 0x1280, 0x12c7, 0x130f, 0x1356, 0x139f, 0x13e7, 0x1431, 0x147a,
    0x14c4, 0x150f, 0x1559, 0x15a5, 0x15f0, 0x163c, 0x1689, 0x16d6, 0x1723,
    0x1771, 0x17bf, 0x180d, 0x185c, 0x18ab, 0x18fb, 0x194b, 0x199b, 0x19ec,
    0x1a3d, 0x1a8e, 0x1ae0, 0x1b32, 0x1b85, 0x1bd7, 0x1c2b, 0x1c7e, 0x1cd2,
    0x1d26, 0x1d7b, 0x1dd0, 0x1e25, 0x1e7b, 0x1ed0, 0x1f27, 0x1f7d, 0x1fd4,
    0x202b, 0x2083, 0x20da, 0x2132, 0x218b, 0x21e3, 0x223c, 0x2296, 0x22ef,
    0x2349, 0x23a3, 0x23fd, 0x2458, 0x24b3, 0x250e, 0x2569, 0x25c5, 0x2621,
    0x267d, 0x26d9, 0x2736, 0x2793, 0x27f0, 0x284e, 0x28ab, 0x2909, 0x2967,
    0x29c5, 0x2a24, 0x2a82, 0x2ae1, 0x2b40, 0x2ba0, 0x2bff, 0x2c5f, 0x2cbf,
    0x2d1f, 0x2d7f, 0x2ddf, 0x2e40, 0x2ea1, 0x2f02, 0x2f63, 0x2fc4, 0x3026,
    0x3087, 0x30e9, 0x314b, 0x31ad, 0x320f, 0x3271, 0x32d4, 0x3336, 0x3399,
    0x33fc, 0x345e, 0x34c1, 0x3525, 0x3588, 0x35eb, 0x364f, 0x36b2, 0x3716,
    0x3779, 0x37dd, 0x3841, 0x38a5, 0x3909, 0x396d, 0x39d1, 0x3a35, 0x3a99,
    0x3afe, 0x3b62, 0x3bc7, 0x3c2b, 0x3c8f, 0x3cf4, 0x3d58, 0x3dbd, 0x3e22,
    0x3e86, 0x3eeb, 0x3f4f, 0x3fb4, 0x4019, 0x407d, 0x40e2, 0x4147, 0x41ab,
    0x4210, 0x4274, 0x42d9, 0x433d, 0x43a2, 0x4406, 0x446b, 0x44cf, 0x4533,
    0x4598, 0x45fc, 0x4660, 0x46c4, 0x4728, 0x478c, 0x47f0, 0x4854, 0x48b8,
    0x491b, 0x497f, 0x49e2, 0x4a46, 0x4aa9, 0x4b0c, 0x4b6f, 0x4bd2, 0x4c35,
    0x4c98, 0x4cfa, 0x4d5d, 0x4dbf, 0x4e21, 0x4e83, 0x4ee5, 0x4f47, 0x4fa9,
    0x500a, 0x506c, 0x50cd, 0x512e, 0x518f, 0x51ef, 0x5250, 0x52b0, 0x5310,
    0x5370, 0x53d0, 0x5430, 0x548f, 0x54ee, 0x554d, 0x55ac, 0x560b, 0x5669,
    0x56c7, 0x5725, 0x5783, 0x57e0, 0x583d, 0x589a, 0x58f7, 0x5954, 0x59b0,
    0x5a0c, 0x5a68, 0x5ac3, 0x5b1f, 0x5b7a, 0x5bd4, 0x5c2f, 0x5c89, 0x5ce3,
    0x5d3d, 0x5d96, 0x5def, 0x5e48, 0x5ea0, 0x5ef9, 0x5f51, 0x5fa8, 0x5fff,
    0x6056, 0x60ad, 0x6104, 0x615a, 0x61af, 0x6205, 0x625a, 0x62af, 0x6303,
    0x6357, 0x63ab, 0x63fe, 0x6451, 0x64a4, 0x64f6, 0x6548, 0x659a, 0x65eb,
    0x663c, 0x668c, 0x66dc, 0x672c, 0x677c, 0x67cb, 0x6819, 0x6867, 0x68b5,
    0x6903, 0x6950, 0x699c, 0x69e9, 0x6a35, 0x6a80, 0x6acb, 0x6b16, 0x6b60,
    0x6baa, 0x6bf3, 0x6c3c, 0x6c84, 0x6ccd, 0x6d14, 0x6d5b, 0x6da2, 0x6de8,
    0x6e2e, 0x6e74, 0x6eb9, 0x6efd, 0x6f41, 0x6f85, 0x6fc8, 0x700b, 0x704d,
    0x708f, 0x70d0, 0x7111, 0x7152, 0x7191, 0x71d1, 0x7210, 0x724e, 0x728c,
    0x72ca, 0x7307, 0x7343, 0x737f, 0x73bb, 0x73f6, 0x7430, 0x746a, 0x74a4,
    0x74dd, 0x7515, 0x754d, 0x7584, 0x75bb, 0x75f2, 0x7628, 0x765d, 0x7692,
    0x76c6, 0x76fa, 0x772d, 0x7760, 0x7792, 0x77c4, 0x77f5, 0x7825, 0x7855,
    0x7885, 0x78b4, 0x78e2, 0x7910, 0x793d, 0x796a, 0x7996, 0x79c2, 0x79ed,
    0x7a17, 0x7a41, 0x7a6b, 0x7a94, 0x7abc, 0x7ae3, 0x7b0b, 0x7b31, 0x7b57,
    0x7b7d, 0x7ba1, 0x7bc6, 0x7be9, 0x7c0c, 0x7c2f, 0x7c51, 0x7c72, 0x7c93,
    0x7cb3, 0x7cd3, 0x7cf2, 0x7d10, 0x7d2e, 0x7d4b, 0x7d68, 0x7d84, 0x7d9f,
    0x7dba, 0x7dd4, 0x7dee, 0x7e07, 0x7e20, 0x7e38, 0x7e4f, 0x7e66, 0x7e7c,
    0x7e91, 0x7ea6, 0x7eba, 0x7ece, 0x7ee1, 0x7ef3, 0x7f05, 0x7f16, 0x7f27,
    0x7f37, 0x7f46, 0x7f55, 0x7f63, 0x7f71, 0x7f7e, 0x7f8a, 0x7f96, 0x7fa1,
    0x7fab, 0x7fb5, 0x7fbf, 0x7fc7, 0x7fcf, 0x7fd7, 0x7fdd, 0x7fe4, 0x7fe9,
    0x7fee, 0x7ff2, 0x7ff6, 0x7ff9, 0x7ffc, 0x7ffe, 0x7fff, 0x7fff, 0x7fff,
    0x7fff, 0x7ffe, 0x7ffc, 0x7ff9, 0x7ff6, 0x7ff2, 0x7fee, 0x7fe9, 0x7fe4,
    0x7fdd, 0x7fd7, 0x7fcf, 0x7fc7, 0x7fbf, 0x7fb5, 0x7fab, 0x7fa1, 0x7f96,
    0x7f8a, 0x7f7e, 0x7f71, 0x7f63, 0x7f55, 0x7f46, 0x7f37, 0x7f27, 0x7f16,
    0x7f05, 0x7ef3, 0x7ee1, 0x7ece, 0x7eba, 0x7ea6, 0x7e91, 0x7e7c, 0x7e66,
    0x7e4f, 0x7e38, 0x7e20, 0x7e07, 0x7dee, 0x7dd4, 0x7dba, 0x7d9f, 0x7d84,
    0x7d68, 0x7d4b, 0x7d2e, 0x7d10, 0x7cf2, 0x7cd3, 0x7cb3, 0x7c93, 0x7c72,
    0x7c51, 0x7c2f, 0x7c0c, 0x7be9, 0x7bc6, 0x7ba1, 0x7b7d, 0x7b57, 0x7b31,
    0x7b0b, 0x7ae3, 0x7abc, 0x7a94, 0x7a6b, 0x7a41, 0x7a17, 0x79ed, 0x79c2,
    0x7996, 0x796a, 0x793d, 0x7910, 0x78e2, 0x78b4, 0x7885, 0x7855, 0x7825,
    0x77f5, 0x77c4, 0x7792, 0x7760, 0x772d, 0x76fa, 0x76c6, 0x7692, 0x765d,
    0x7628, 0x75f2, 0x75bb, 0x7584, 0x754d, 0x7515, 0x74dd, 0x74a4, 0x746a,
    0x7430, 0x73f6, 0x73bb, 0x737f, 0x7343, 0x7307, 0x72ca, 0x728c, 0x724e,
    0x7210, 0x71d1, 0x7191, 0x7152, 0x7111, 0x70d0, 0x708f, 0x704d, 0x700b,
    0x6fc8, 0x6f85, 0x6f41, 0x6efd, 0x6eb9, 0x6e74, 0x6e2e, 0x6de8, 0x6da2,
    0x6d5b, 0x6d14, 0x6ccd, 0x6c84, 0x6c3c, 0x6bf3, 0x6baa, 0x6b60, 0x6b16,
    0x6acb, 0x6a80, 0x6a35, 0x69e9, 0x699c, 0x6950, 0x6903, 0x68b5, 0x6867,
    0x6819, 0x67cb, 0x677c, 0x672c, 0x66dc, 0x668c, 0x663c, 0x65eb, 0x659a,
    0x6548, 0x64f6, 0x64a4, 0x6451, 0x63fe, 0x63ab, 0x6357, 0x6303, 0x62af,
    0x625a, 0x6205, 0x61af, 0x615a, 0x6104, 0x60ad, 0x6056, 0x6000, 0x5fa8,
    0x5f51, 0x5ef9, 0x5ea0, 0x5e48, 0x5def, 0x5d96, 0x5d3d, 0x5ce3, 0x5c89,
    0x5c2f, 0x5bd4, 0x5b7a, 0x5b1f, 0x5ac3, 0x5a68, 0x5a0c, 0x59b0, 0x5954,
    0x58f7, 0x589a, 0x583d, 0x57e0, 0x5783, 0x5725, 0x56c7, 0x5669, 0x560b,
    0x55ac, 0x554d, 0x54ee, 0x548f, 0x5430, 0x53d0, 0x5370, 0x5310, 0x52b0,
    0x5250, 0x51ef, 0x518f, 0x512e, 0x50cd, 0x506c, 0x500a, 0x4fa9, 0x4f47,
    0x4ee5, 0x4e83, 0x4e21, 0x4dbf, 0x4d5d, 0x4cfa, 0x4c98, 0x4c35, 0x4bd2,
    0x4b6f, 0x4b0c, 0x4aa9, 0x4a46, 0x49e2, 0x497f, 0x491b, 0x48b8, 0x4854,
    0x47f0, 0x478c, 0x4728, 0x46c4, 0x4660, 0x45fc, 0x4598, 0x4533, 0x44cf,
    0x446b, 0x4406, 0x43a2, 0x433d, 0x42d9, 0x4274, 0x4210, 0x41ab, 0x4147,
    0x40e2, 0x407d, 0x4019, 0x3fb4, 0x3f4f, 0x3eeb, 0x3e86, 0x3e22, 0x3dbd,
    0x3d58, 0x3cf4, 0x3c8f, 0x3c2b, 0x3bc7, 0x3b62, 0x3afe, 0x3a99, 0x3a35,
    0x39d1, 0x396d, 0x3909, 0x38a5, 0x3841, 0x37dd, 0x3779, 0x3716, 0x36b2,
    0x364f, 0x35eb, 0x3588, 0x3525, 0x34c1, 0x345e, 0x33fc, 0x3399, 0x3336,
    0x32d4, 0x3271, 0x320f, 0x31ad, 0x314b, 0x30e9, 0x3087, 0x3026, 0x2fc4,
    0x2f63, 0x2f02, 0x2ea1, 0x2e40, 0x2ddf, 0x2d7f, 0x2d1f, 0x2cbf, 0x2c5f,
    0x2bff, 0x2ba0, 0x2b40, 0x2ae1, 0x2a82, 0x2a24, 0x29c5, 0x2967, 0x2909,
    0x28ab, 0x284e, 0x27f0, 0x2793, 0x2736, 0x26d9, 0x267d, 0x2621, 0x25c5,
    0x2569, 0x250e, 0x24b3, 0x2458, 0x23fd, 0x23a3, 0x2349, 0x22ef, 0x2296,
    0x223c, 0x21e3, 0x218b, 0x2132, 0x20da, 0x2083, 0x202b, 0x1fd4, 0x1f7d,
    0x1f27, 0x1ed0, 0x1e7b, 0x1e25, 0x1dd0, 0x1d7b, 0x1d26, 0x1cd2, 0x1c7e,
    0x1c2b, 0x1bd7, 0x1b85, 0x1b32, 0x1ae0, 0x1a8e, 0x1a3d, 0x19ec, 0x199b,
    0x194b, 0x18fb, 0x18ab, 0x185c, 0x180d, 0x17bf, 0x1771, 0x1723, 0x16d6,
    0x1689, 0x163c, 0x15f0, 0x15a5, 0x1559, 0x150f, 0x14c4, 0x147a, 0x1431,
    0x13e7, 0x139f, 0x1356, 0x130f, 0x12c7, 0x1280, 0x123a, 0x11f4, 0x11ae,
    0x1169, 0x1124, 0x10e0, 0x109c, 0x1058, 0x1015, 0xfd3,  0xf91,  0xf4f,
    0xf0e,  0xece,  0xe8d,  0xe4e,  0xe0f,  0xdd0,  0xd92,  0xd54,  0xd17,
    0xcda,  0xc9e,  0xc62,  0xc27,  0xbec,  0xbb2,  0xb78,  0xb3f,  0xb06,
    0xace,  0xa96,  0xa5f,  0xa28,  0x9f2,  0x9bd,  0x988,  0x953,  0x91f,
    0x8eb,  0x8b8,  0x886,  0x854,  0x823,  0x7f2,  0x7c2,  0x792,  0x763,
    0x734,  0x706,  0x6d8,  0x6ab,  0x67f,  0x653,  0x628,  0x5fd,  0x5d3,
    0x5a9,  0x580,  0x557,  0x52f,  0x508,  0x4e1,  0x4bb,  0x495,  0x470,
    0x44b,  0x428,  0x404,  0x3e1,  0x3bf,  0x39d,  0x37c,  0x35c,  0x33c,
    0x31d,  0x2fe,  0x2e0,  0x2c2,  0x2a5,  0x289,  0x26d,  0x252,  0x238,
    0x21e,  0x204,  0x1eb,  0x1d3,  0x1bc,  0x1a5,  0x18e,  0x179,  0x163,
    0x14f,  0x13b,  0x128,  0x115,  0x103,  0xf1,   0xe0,   0xd0,   0xc0,
    0xb1,   0xa3,   0x95,   0x88,   0x7b,   0x6f,   0x64,   0x59,   0x4f,
    0x45,   0x3c,   0x34,   0x2c,   0x25,   0x1e,   0x19,   0x13,   0xf,
    0xb,    0x7,    0x4,    0x2,    0x1,    0x0,    0x0};

#endif
