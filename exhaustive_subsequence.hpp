///////////////////////////////////////////////////////////////////////////////
// exhaustive_subsequence.hpp
//
// Exhaustive search algorithms for the longest substring, and longest
// subsequence, problems.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cstdint>
#include <random>
#include <string>
#include <vector>
#include <cmath>
std::string random_letter_string(int seed, int size, int distinct_letters) {

  assert(size >= 0);
  assert(distinct_letters > 0);
  assert(distinct_letters <= 26);

  std::string s;

  std::mt19937 gen(seed);
  std::uniform_int_distribution<> dist('a', 'a' + distinct_letters - 1);

  for (int i = 0; i < size; ++i) {
    char ch;
    do {
      ch = dist(gen);
    } while (!isprint(ch));

    s.push_back(ch);
  }

  return s;
}

std::string exhaustive_longest_substring(const std::string& a,
                                         const std::string& b) {
    std::string best = "";
    std::string substring = "";
    size_t found;
    for(int i = 0; i<a.length();i++){
        for(int k = 0; k<=a.length()-i; k++){
            substring = a.substr(i,k);
            found = b.find(substring);
            if(found!= std::string::npos && substring.length()>best.length()){
              best = substring;
            }
        }
   }
   return best;
}

bool detect_subsequence(const std::string& candidate_subsequence,
                        const std::string& candidate_supersequence) {
    int i = 0;
    int k = 0;
    while(i<candidate_supersequence.length() && k<candidate_subsequence.length()){
        if(candidate_subsequence[k] == candidate_supersequence[i]){
            k++;
        }
        i++;
    }

    if(k==candidate_subsequence.length()){
       return true;
    }
    return false;
}

std::string exhaustive_longest_subsequence(const std::string& a,
                                           const std::string& b) {
    std::string shorter;
    std::string longer;
    if(a.length()<=b.length()){
       shorter = a;
       longer = b;
    }
    else{
        shorter = b;
        longer = a;
    }
    std::string best = "";
    std::string subset;

    int pow_size = pow(2,shorter.length());
    std::vector <std::string> power_set;

    for (int i = 0; i< pow_size; i++){
         subset = "";
          for (int j = 0 ;j < shorter.length(); j++){
              if((i>>j) & 1){
                 subset+=shorter[j];
              }
          }
          power_set.push_back(subset);
    }
    for (std::string sub: power_set){
        if(detect_subsequence(sub,longer) == true && sub.length()>best.length()){
           best = sub;
        }
    }
    return best;
}
