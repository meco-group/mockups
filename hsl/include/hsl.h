extern "C" {
  void ma27id_(int* ICNTL, double* CNTL);
  void ma27ad_(int *N, int *NZ, const int *IRN, const int* ICN,
               int *IW, int* LIW, int* IKEEP, int *IW1,
               int* NSTEPS, int* IFLAG, int* ICNTL,
               double* CNTL, int *INFO, double* OPS);
  void ma27bd_(int *N, int *NZ, const int *IRN, const int* ICN,
               double* A, int* LA, int* IW, int* LIW,
               int* IKEEP, int* NSTEPS, int* MAXFRT,
               int* IW1, int* ICNTL, double* CNTL,
               int* INFO);
  void ma27cd_(int *N, double* A, int* LA, int* IW,
               int* LIW, double* W, int* MAXFRT,
               double* RHS, int* IW1, int* NSTEPS,
               int* ICNTL, double* CNTL);
}
