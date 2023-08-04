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
  
void ma57id_(double cntl[], int icntl[]);
void ma57ad_(const int* n, const int* ne, const int irn[], const int jcn[], const int* lkeep, int keep[], int iwork[], int icntl[], int info[], double rinfo[]);
void ma57bd_(const int* n, int* ne, const double a[], double fact[], const int* lfact, int ifact[], const int* lifact, const int* lkeep, const int keep[], int iwork[], int icntl[], double cntl[], int info[], double rinfo[]);
void ma57cd_(const int* job, const int* n, double fact[], int* lfact, int ifact[], int* lifact, const int* nrhs, double rhs[], const int* lrhs, double work[], int* lwork, int iwork[], int icntl[], int info[]);
void ma57dd_(const int* job, const int* n, int* ne, const double a[], const int irn[], const int jcn[], double fact[], int* lfact, int ifact[], int* lifact, const double rhs[], double x[], double resid[], double work[], int iwork[], int icntl[], double cntl[], int info[], double rinfo[]);
}
