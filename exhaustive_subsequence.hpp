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

  // TODO: replace this comment, and bogus return statement, with an actual
  // implementation of the function. Then delete this comment.
  return "";
}

bool detect_subsequence(const std::string& candidate_subsequence,
                        const std::string& candidate_supersequence) {

  // TODO: replace this comment, and bogus return statement, with an actual
  // implementation of the function. Then delete this comment.
  return false;
}

std::string exhaustive_longest_subsequence(const std::string& a,
                                           const std::string& b) {

  // TODO: replace this comment, and bogus return statement, with an actual
  // implementation of the function. Then delete this comment.
  return "";
}
