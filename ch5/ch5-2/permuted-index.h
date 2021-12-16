#pragma once
#include <string>
#include <vector>

struct Rotation
{
    std::vector<std::string>::size_type first;
    std::vector<std::string> words;
 };

std::vector<std::string> read_line(std::istream&);

std::vector<Rotation> rotate_line(std::string);

std::vector<Rotation> rotate_lines(std::vector<std::string>);

void permuted(const std::vector<Rotation>&);

bool compare(const Rotation&, const Rotation&);
