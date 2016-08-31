//
// Created by DynNoil on 23.08.2016.
//
#include <iostream>
#include "../headers/exercises.h"

using namespace std;

void testStrStr() {
    (0 == my_strstr("", "")) ? cout << "OK : 1" << " (" << 0 << " : " << (0 == my_strstr("", "")) << " )" << endl : cout
            << "Failed : 1" << " (" << 0 << " : " << (0 == my_strstr("", "")) << " )" << endl;
    (0 == my_strstr("a", "")) ? cout << "OK : 2" << " (" << 0 << " : " << (0 == my_strstr("a", "")) << " )" << endl : cout
            << "Failed : 2" << " (" << 0 << " : " << (0 == my_strstr("a", "")) << " )" << endl;
    (0 == my_strstr("a", "a")) ? cout << "OK : 3" << " (" << 0 << " : " << (0 == my_strstr("a", "a")) << " )" << endl : cout
            << "Failed : 3" << " (" << 0 << " : " << (0 == my_strstr("a", "a")) << " )" << endl;
    (-1 == my_strstr("a", "b")) ? cout << "OK : 4" << " (" << -1 << " : " << (-1 == my_strstr("a", "b")) << " )" << endl :
    cout << "Failed : 4" << " (" << -1 << " : " << (-1 == my_strstr("a", "b")) << " )" << endl;

    (0 == my_strstr("aa", "")) ? cout << "OK : 5" << " (" << 0 << " : " << (0 == my_strstr("aa", "")) << " )" << endl : cout
            << "Failed : 5" << " (" << 0 << " : " << (0 == my_strstr("aa", "")) << " )" << endl;
    (0 == my_strstr("aa", "a")) ? cout << "OK : 6" << " (" << 0 << " : " << (0 == my_strstr("aa", "a")) << " )" << endl : cout
            << "Failed : 6" << " (" << 0 << " : " << (0 == my_strstr("aa", "a")) << " )" << endl;
    (0 == my_strstr("ab", "a")) ? cout << "OK : 7" << " (" << 0 << " : " << (0 == my_strstr("ab", "a")) << " )" << endl : cout
            << "Failed : 7" << " (" << 0 << " : " << (0 == my_strstr("ab", "a")) << " )" << endl;
    (1 == my_strstr("ba", "a")) ? cout << "OK : 8" << " (" << 1 << " : " << (1 == my_strstr("ba", "a")) << " )" << endl : cout
            << "Failed : 8" << " (" << 1 << " : " << (1 == my_strstr("ba", "a")) << " )" << endl;
    (-1 == my_strstr("bb", "a")) ? cout << "OK : 9" << " (" << -1 << " : " << (-1 == my_strstr("bb", "a")) << " )" << endl :
    cout << "Failed : 9" << " (" << -1 << " : " << (-1 == my_strstr("bb", "a")) << " )" << endl;

    (0 == my_strstr("aaa", "")) ? cout << "OK : 10" << " (" << 0 << " : " << (0 == my_strstr("aaa", "")) << " )" << endl :
    cout << "Failed : 10" << " (" << 0 << " : " << (0 == my_strstr("aaa", "")) << " )" << endl;
    (0 == my_strstr("aaa", "a")) ? cout << "OK : 11" << " (" << 0 << " : " << (0 == my_strstr("aaa", "a")) << " )" << endl :
    cout << "Failed : 11" << " (" << 0 << " : " << (0 == my_strstr("aaa", "a")) << " )" << endl;
    (1 == my_strstr("abc", "b")) ? cout << "OK : 12" << " (" << 1 << " : " << (1 == my_strstr("abc", "b")) << " )" << endl :
    cout << "Failed : 12" << " (" << 1 << " : " << (1 == my_strstr("abc", "b")) << " )" << endl;
    (2 == my_strstr("abc", "c")) ? cout << "OK : 13" << " (" << 2 << " : " << (2 == my_strstr("abc", "c")) << " )" << endl :
    cout << "Failed : 13" << " (" << 2 << " : " << (2 == my_strstr("abc", "c")) << " )" << endl;
    (-1 == my_strstr("abc", "d")) ? cout << "OK : 14" << " (" << -1 << " : " << (-1 == my_strstr("abc", "d")) << " )" << endl
                               : cout << "Failed : 14" << " (" << -1 << " : " << (-1 == my_strstr("abc", "d")) << " )"
                                      << endl;

    (-1 == my_strstr("a", "aa")) ? cout << "OK : 15" << " (" << -1 << " : " << (-1 == my_strstr("a", "aa")) << " )" << endl :
    cout << "Failed : 15" << " (" << -1 << " : " << (-1 == my_strstr("a", "aa")) << " )" << endl;
    (-1 == my_strstr("a", "ba")) ? cout << "OK : 16" << " (" << -1 << " : " << (-1 == my_strstr("a", "ba")) << " )" << endl :
    cout << "Failed : 16" << " (" << -1 << " : " << (-1 == my_strstr("a", "ba")) << " )" << endl;
    (-1 == my_strstr("a", "ab")) ? cout << "OK : 17" << " (" << -1 << " : " << (-1 == my_strstr("a", "ab")) << " )" << endl :
    cout << "Failed : 17" << " (" << -1 << " : " << (-1 == my_strstr("a", "ab")) << " )" << endl;
    (-1 == my_strstr("a", "bb")) ? cout << "OK : 18" << " (" << -1 << " : " << (-1 == my_strstr("a", "bb")) << " )" << endl :
    cout << "Failed : 18" << " (" << -1 << " : " << (-1 == my_strstr("a", "bb")) << " )" << endl;

    (-1 == my_strstr("a", "aaa")) ? cout << "OK : 19" << " (" << -1 << " : " << (-1 == my_strstr("a", "aaa")) << " )" << endl
                               : cout << "Failed : 19" << " (" << -1 << " : " << (-1 == my_strstr("a", "aaa")) << " )"
                                      << endl;
    (-1 == my_strstr("aa", "aaa")) ? cout << "OK : 20" << " (" << -1 << " : " << (-1 == my_strstr("aa", "aaa")) << " )"
                                       << endl : cout << "Failed : 20" << " (" << -1 << " : "
                                                      << (-1 == my_strstr("aa", "aaa")) << " )" << endl;
    (0 == my_strstr("aaa", "aaa")) ? cout << "OK : 21" << " (" << 0 << " : " << (0 == my_strstr("aaa", "aaa")) << " )" << endl
                                : cout << "Failed : 21" << " (" << 0 << " : " << (0 == my_strstr("aaa", "aaa")) << " )"
                                       << endl;
    (0 == my_strstr("aaab", "aaa")) ? cout << "OK : 22" << " (" << 0 << " : " << (0 == my_strstr("aaab", "aaa")) << " )"
                                        << endl : cout << "Failed : 22" << " (" << 0 << " : "
                                                       << (0 == my_strstr("aaab", "aaa")) << " )" << endl;
    (1 == my_strstr("baaa", "aaa")) ? cout << "OK : 23" << " (" << 1 << " : " << (1 == my_strstr("baaa", "aaa")) << " )"
                                        << endl : cout << "Failed : 23" << " (" << 1 << " : "
                                                       << (1 == my_strstr("baaa", "aaa")) << " )" << endl;
    (1 == my_strstr("baaaa", "aaa")) ? cout << "OK : 24" << " (" << 1 << " : " << (1 == my_strstr("baaaa", "aaa")) << " )"
                                         << endl : cout << "Failed : 24" << " (" << 1 << " : "
                                                        << (1 == my_strstr("baaaa", "aaa")) << " )" << endl;
    (1 == my_strstr("baaab", "aaa")) ? cout << "OK : 25" << " (" << 1 << " : " << (1 == my_strstr("baaab", "aaa")) << " )"
                                         << endl : cout << "Failed : 25" << " (" << 1 << " : "
                                                        << (1 == my_strstr("baaab", "aaa")) << " )" << endl;
    (-1 == my_strstr("abd", "abc")) ? cout << "OK : 26" << " (" << -1 << " : " << (-1 == my_strstr("abd", "abc")) << " )"
                                        << endl : cout << "Failed : 26" << " (" << -1 << " : "
                                                       << (-1 == my_strstr("abd", "abc")) << " )" << endl;

    (2 == my_strstr("ababc", "abc")) ? cout << "OK : 27" << " (" << 2 << " : " << (2 == my_strstr("ababc", "abc")) << " )"
                                         << endl : cout << "Failed : 27" << " (" << 2 << " : "
                                                        << (2 == my_strstr("ababc", "abc")) << " )" << endl;
    (3 == my_strstr("abdabc", "abc")) ? cout << "OK : 28" << " (" << 3 << " : " << (3 == my_strstr("abdabc", "abc")) << " )"
                                          << endl : cout << "Failed : 28" << " (" << 3 << " : "
                                                         << (3 == my_strstr("abdabc", "abc")) << " )" << endl;

}
