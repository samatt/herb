#ifndef HERBIVORE_UTILS_H
#define HERBIVORE_UTILS_H
#include <sstream>
#include <string>
#include <map>
#include "tins/tins.h"

std::string to_json(std::map <std::string, std::string> data);
void send_packet(std::string s);
std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
#endif