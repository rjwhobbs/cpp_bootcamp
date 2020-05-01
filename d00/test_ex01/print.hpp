#ifndef PRINT_HPP
# define PRINT_HPP
# include <string>

void print_str(std::string &str);
void print_str_nl(std::string &str);
void print_cstr(const char *str);
void print_cstr_nl(const char *str);
void print_str_pad(std::string str, int pad);
void print_str_pad_nl(std::string str, int pad);
void print_cstr_pad(const char *str, int pad);
void print_cstr_pad_nl(const char *str, int pad);

#endif