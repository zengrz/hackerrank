#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void liss(int *seq, int seqlen, int curIdx, int isslensofar, int prenuminiss, int &lisslengthsofar, int *memo)
{
   // update important info
   if (lisslengthsofar < isslensofar)
      lisslengthsofar = isslensofar;

   // check to return
   if (curIdx == seqlen)
      return;

   // update memo and recurse
   liss(seq, seqlen, curIdx + 1, isslensofar, prenuminiss, lisslengthsofar, memo); // exclude
   if (seq[curIdx] > prenuminiss) {
      if (memo[curIdx] < isslensofar) { // if you want to include this elem and there is not any longer sequence when this elem is included
         memo[curIdx] = isslensofar;
         liss(seq, seqlen, curIdx + 1, isslensofar + 1, seq[curIdx], lisslengthsofar, memo); // include
      }
   }
}

//int main()
//{
//   int seqlen;
//   std::cin >> seqlen;
//   int *seq = new int[seqlen];
//   for (int k = 0; k < seqlen; ++k) {
//      std::cin >> seq[k];
//   }
//
//   int *memo = new int[seqlen];
//   for (int k = 0; k < seqlen; ++k) {
//      memo[k] = 1 << 31;
//   }
//
//   int lisslensofar1 = 0;
//   liss(seq, seqlen, 1, 0, 1 << 31, lisslensofar1, memo); // exclude the first elem
//
//   int lisslensofar = 0;
//   memo[0] = 1;
//   liss(seq, seqlen, 1, 1, seq[0], lisslensofar, memo); // include the first elem
//   
//   std::cout << (lisslensofar > lisslensofar1 ? lisslensofar : lisslensofar1) << std::endl;
//
//   return 0;
//}
