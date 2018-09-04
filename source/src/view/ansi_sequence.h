
#pragma once

namespace ansi
{
namespace ansi_impl
{
constexpr auto csi_start = "\033[";    //!< Control Sequence Introducer, ESC [
constexpr auto end       = 'm';
}
//! \brief Select Graphic Rendition
namespace sgr
{
enum class style {
    reset         = 0,
    bold          = 1,
    faint         = 2,
    italic        = 3,
    underline     = 4,
    slow_blink    = 5,
    fast_blink    = 6,
    reverse_video = 7,
    conceal       = 8,
    crossed_out   = 9,
    primary       = 10,    //!< Primary/default font
    bold_off      = 21,
    normal_color  = 22,
    italic_off    = 23,
    underline_off = 24,
    blink_off     = 25,
    inverse_off   = 27,
};

enum class fg {
    black   = 30,
    red     = 31,
    green   = 32,
    yellow  = 33,
    blue    = 34,
    magenta = 35,
    cyan    = 36,
    white   = 37,
    set     = 38,    //!< Next arguments are 5;n or 2;r;g;b,
    def     = 39,    //!< default foreground color
};

enum class bg {
    black   = 40,
    red     = 41,
    green   = 42,
    yellow  = 43,
    blue    = 44,
    magenta = 45,
    cyan    = 46,
    white   = 47,
    set     = 48,    //!< Next arguments are 5;n or 2;r;g;b,
    def     = 49,    //!< default background color
};

template<typename T>
inline std::ostream& operator<<(std::ostream& oss, const T value)
{
    return oss << ansi_impl::csi_start + static_cast<int>(value) + ansi_impl::end;
}

// inline std::string csi(const std::string& sgr) { return csi_start + sgr + end; }
//
// inline std::string csi(const std::string& sgr1, const std::string& sgr2)
//{
//    return csi_start + sgr1 + ";" + sgr2 + ";" + end;
//}
//
// inline std::string csi(const std::string& sgr1, const std::string& sgr2, const std::string& sgr3)
//{
//    return csi_start + sgr1 + ";" + sgr2 + ";" + sgr3 + end;
//}

// inline std::ostream& operator<<(std::ostream& oss, sgr c) { return oss << static_cast<char>(c); }
//
// inline std::ostream& operator<<(std::ostream& oss, f_color c)
//{
//    return oss << static_cast<char>(c);
//}
//
// inline std::ostream& operator<<(std::ostream& oss, b_color c)
//{
//    return oss << static_cast<char>(c);
//}
}
