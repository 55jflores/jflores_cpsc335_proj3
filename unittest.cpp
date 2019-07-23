
///////////////////////////////////////////////////////////////////////////////
// unittest.cpp
//
// Unit tests for the functionality declared in exhaustive_subsequence.hpp .
///////////////////////////////////////////////////////////////////////////////

#include <string>

#include "gtest/gtest.h"

#include "exhaustive_subsequence.hpp"

TEST(exhaustive_longest_substring_TrivialCases, exhaustive_longest_substring_TrivialCases) {
  EXPECT_EQ("", exhaustive_longest_substring("", ""));
  EXPECT_EQ("", exhaustive_longest_substring("", "abc"));
  EXPECT_EQ("", exhaustive_longest_substring("abc", ""));
  EXPECT_EQ("abc", exhaustive_longest_substring("abc", "abc"));
}

TEST(exhaustive_longest_substring_NonTrivialCases, exhaustive_longest_substring_NonTrivialCases) {
  EXPECT_EQ("babc", exhaustive_longest_substring("ababc", "babca"));
  EXPECT_EQ("a", exhaustive_longest_substring("hakuna", "matata"));
  EXPECT_EQ("ain", exhaustive_longest_substring("the rain", "in spain"));
  EXPECT_EQ("ott", exhaustive_longest_substring("bottle", "otter"));
}

TEST(detect_subsequence_TrivialCases, detect_subsequence_TrivialCases) {
  EXPECT_TRUE(detect_subsequence("", ""));
  EXPECT_TRUE(detect_subsequence("", "abc"));
  EXPECT_FALSE(detect_subsequence("abc", ""));
  EXPECT_TRUE(detect_subsequence("abc", "abc"));
}

TEST(detect_subsequence_NonTrivialCases, detect_subsequence_NonTrivialCases) {
  EXPECT_TRUE(detect_subsequence("", "abcd"));
  EXPECT_TRUE(detect_subsequence("a", "abcd"));
  EXPECT_TRUE(detect_subsequence("ab", "abcd"));
  EXPECT_TRUE(detect_subsequence("ab", "abcd"));
  EXPECT_TRUE(detect_subsequence("c", "abcd"));
  EXPECT_TRUE(detect_subsequence("ac", "abcd"));
  EXPECT_TRUE(detect_subsequence("bc", "abcd"));
  EXPECT_TRUE(detect_subsequence("abc", "abcd"));
  EXPECT_TRUE(detect_subsequence("d", "abcd"));
  EXPECT_TRUE(detect_subsequence("ad", "abcd"));
  EXPECT_TRUE(detect_subsequence("bc", "abcd"));
  EXPECT_TRUE(detect_subsequence("abd", "abcd"));
  EXPECT_TRUE(detect_subsequence("cd", "abcd"));
  EXPECT_TRUE(detect_subsequence("acd", "abcd"));
  EXPECT_TRUE(detect_subsequence("bcd", "abcd"));
  EXPECT_TRUE(detect_subsequence("abcd", "abcd"));

  EXPECT_FALSE(detect_subsequence("aaaa", "aaab"));
  EXPECT_FALSE(detect_subsequence("aaaa", "aaa"));
}

TEST(exhaustive_longest_subsequence, exhaustive_longest_subsequence) {
  EXPECT_EQ("aana", exhaustive_longest_subsequence("banana", "atana"));
  EXPECT_EQ("aana", exhaustive_longest_subsequence("atana", "banana"));

  EXPECT_EQ("ga", exhaustive_longest_subsequence("agcat", "gac"));
  EXPECT_EQ("ga", exhaustive_longest_subsequence("gac", "agcat"));

  EXPECT_EQ("adh", exhaustive_longest_subsequence("abcdgh", "aedfhr"));
  EXPECT_EQ("adh", exhaustive_longest_subsequence("aedfhr", "abcdgh"));

  EXPECT_EQ("gtab", exhaustive_longest_subsequence("aggtab", "gxtxayb"));
  EXPECT_EQ("gtab", exhaustive_longest_subsequence("gxtxayb", "aggtab"));
}
