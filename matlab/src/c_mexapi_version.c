void mexfilerequiredMATLAB_API_VERSION(unsigned int* built_by_rel, unsigned int* target_api_ver)
{
#if MATLAB_API_VERSION==700
  *built_by_rel = 0x2017b;
  *target_api_ver = 0x07000000;
#endif
#if MATLAB_API_VERSION==730
  *built_by_rel = 0x2018a;
  *target_api_ver = 0x07300000;
#endif
#if MATLAB_API_VERSION==800
  *built_by_rel = 0x2018b;
  *target_api_ver = 0x08000000;
#endif
} 

