#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>

#define NUM_BITS_PER_BYTE 8

void lcs(int *seq1, int seqlen1, int curIdx1, int *seq2, int seqlen2, int curIdx2, int curlcslen, int &lcslen, std::string lcssofar, std::string &lcsstr, int **memo)
{
   // update important output
   if (lcslen < curlcslen) {
      lcslen = curlcslen;
      lcsstr = lcssofar;
   }

   // check if reached end of array; reutrn if so
   if (curIdx1 == seqlen1)
      return;
   if (curIdx2 == seqlen2)
      return;

   // update memo or return
   if (memo[curIdx1][curIdx2] < curlcslen)
      memo[curIdx1][curIdx2] = curlcslen;
   else
      return;

   // recurse
   int num1 = seq1[curIdx1];
   int num2 = seq2[curIdx2];

   if (num1 == num2) {
      std::string num = std::to_string(num1);
      lcs(seq1, seqlen1, curIdx1 + 1, seq2, seqlen2, curIdx2 + 1, curlcslen + 1, lcslen, lcssofar + num + " ", lcsstr, memo);
   }
   else {
      lcs(seq1, seqlen1, curIdx1, seq2, seqlen2, curIdx2 + 1, curlcslen, lcslen, lcssofar, lcsstr, memo);
      lcs(seq1, seqlen1, curIdx1 + 1, seq2, seqlen2, curIdx2, curlcslen, lcslen, lcssofar, lcsstr, memo);
   }
}

//int main()
//{
//   int seqlen1, seqlen2;
//   std::cin >> seqlen1;
//   std::cin >> seqlen2;
//   int *seq1 = new int[seqlen1];
//   for (int k = 0; k < seqlen1; ++k) {
//      std::cin >> seq1[k];
//   }
//   int *seq2 = new int[seqlen2];
//   for (int k = 0; k < seqlen2; ++k) {
//      std::cin >> seq2[k];
//   }
//
//   int lcslen = 1 << sizeof(int) * NUM_BITS_PER_BYTE - 1;
//   std::string lcstr;
//
//   int **memo = new int*[seqlen1];
//   for (int k = 0; k < seqlen1; ++k) {
//      memo[k] = new int[seqlen2];
//   }
//   for (int k = 0; k < seqlen1; ++k) {
//      for (int l = 0; l < seqlen2; ++l) {
//         memo[k][l] = 1 << sizeof(int) * NUM_BITS_PER_BYTE - 1;
//      }
//   }
//
//   lcs(seq1, seqlen1, 0, seq2, seqlen2, 0, 0, lcslen, "", lcstr, memo);
//
//   std::cout << lcstr << std::endl;
//
//   delete[] seq1;
//   delete[] seq2;
//
//   for (int k = 0; k < seqlen1; ++k) {
//      delete[] memo[k];
//   }
//   delete[] memo;
//
//   return 0;
//}
