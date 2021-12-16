#include "str.h"
#include <vector>

Str::size_type width(const std::vector<Str>&);

std::vector<Str> frame(const std::vector<Str>&);

std::vector<Str> vcat(const std::vector<Str>&, const std::vector<Str>&);

std::vector<Str> hcat(const std::vector<Str>&, const std::vector<Str>&);

std::vector<Str> center(const std::vector<Str>&);