#pragma once

using std::vector;
using std::ostream;
using std::ostream_iterator;

// vector 类型格式化输出
template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    if (!v.empty()) {
        out << '{';
        std::copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
        out << "\b\b}";
    } else {
        out << "(empty)";
    }

    return out;
}
