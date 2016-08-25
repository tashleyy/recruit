#pragma once
#include <exception>

class NoSuchElementException : public std::exception {};
class EmptyLinkedListException : public std::exception {};
class EmptyQueueException : public std::exception {};
class EmptyStackException : public std::exception {};
