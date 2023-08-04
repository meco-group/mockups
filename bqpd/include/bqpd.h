extern "C" {
    extern struct {
       int kk, ll, kkk, lll, mxws, mxlws;
    } wsc_;

    extern struct {
       double alpha;
    } kktalphac_;

    extern void
    bqpd_(const int*, const int*, int*, int*, double*, int*, double*, double*, double*, double*, double*, double*,
          double*, double*, double*, int* , double*, int* , int*, int* , double* , int* , const int*, int*,
          int*, int*, int*);
}
