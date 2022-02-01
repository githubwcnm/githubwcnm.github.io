#ifndef NS4_H
#define NS4_H

#include <string>

namespace ns4 {
std::wstring encode(const std::string &data);

std::string decode(const std::wstring &m);
}

#endif //NS4_H
