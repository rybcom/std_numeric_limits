
#include <iostream>
#include <limits>
#include <format>

namespace console
{
	inline void set_header_mode()
	{
		std::cout << "\x1b[94m";
	}

	inline void set_line_mode()
	{
		std::cout << "\x1b[0m";
	}

	template<typename... Args>
	inline void println(std::string_view text, Args&&... args)
	{
		std::cout << std::vformat(text, std::make_format_args(args...)) << '\n';
	}
}

#define NUMERIC_LIMITS(func)																								\
		console::set_header_mode();																							\
		console::println("---------------------------------------------------------");										\
		console::println("| {:^20} | {:^30} |", "Type", #func "()");																\
		console::println("---------------------------------------------------------");										\
		console::set_line_mode();																							\
		console::println("| {:<20} | {:<30} |", typeid(bool).name(), std::numeric_limits<bool>::func());					\
		console::println("| {:<20} | {:<30} |", typeid(char).name(), (int)std::numeric_limits<char>::func());				\
		console::println("| {:<20} | {:<30} |", typeid(signed char).name(), std::numeric_limits<signed char>::func());		\
		console::println("| {:<20} | {:<30} |", typeid(unsigned char).name(), std::numeric_limits<unsigned char>::func());	\
		console::println("| {:<20} | {:<30} |", typeid(char8_t).name(), (int)std::numeric_limits<char8_t>::func());			\
		console::println("| {:<20} | {:<30} |", typeid(char16_t).name(), (int)std::numeric_limits<char16_t>::func());		\
		console::println("| {:<20} | {:<30} |", typeid(char32_t).name(), (int)std::numeric_limits<char32_t>::func());		\
		console::println("| {:<20} | {:<30} |", typeid(short).name(), std::numeric_limits<short>::func());					\
		console::println("| {:<20} | {:<30} |", typeid(unsigned short).name(), std::numeric_limits<unsigned short>::func());\
		console::println("| {:<20} | {:<30} |", typeid(int).name(), std::numeric_limits<int>::func());						\
		console::println("| {:<20} | {:<30} |", typeid(unsigned int).name(), std::numeric_limits<unsigned int>::func());	\
		console::println("| {:<20} | {:<30} |", typeid(long).name(), std::numeric_limits<long>::func());					\
		console::println("| {:<20} | {:<30} |", typeid(unsigned long).name(), std::numeric_limits<unsigned long>::func());	\
		console::println("| {:<20} | {:<30} |", typeid(long long).name(), std::numeric_limits<long long>::func());			\
		console::println("| {:<20} | {:<30} |", typeid(unsigned long long).name(), std::numeric_limits<unsigned long long>::func());	\
		console::println("| {:<20} | {:<30} |", typeid(float).name(), std::numeric_limits<float>::func());					\
		console::println("| {:<20} | {:<30} |", typeid(double).name(), std::numeric_limits<double>::func());				\
		console::println("| {:<20} | {:<30} |", typeid(long double).name(), std::numeric_limits<long double>::func())


int main()
{
	//returns the smallest finite value of the given type
	NUMERIC_LIMITS(min);
	//returns the lowest finite value of the given type
	NUMERIC_LIMITS(lowest);
	//returns the largest finite value of the given type
	NUMERIC_LIMITS(max);
	//returns the difference between 1.0 and the next representable value of the given floating - point type
	NUMERIC_LIMITS(epsilon);
	//returns the maximum rounding error of the given floating - point type
	NUMERIC_LIMITS(round_error);
	//returns the positive infinity value of the given floating - point type
	NUMERIC_LIMITS(infinity);
	//returns a quiet NaN value of the given floating - point type
	NUMERIC_LIMITS(quiet_NaN);
	//returns a signaling NaN value of the given floating - point type
	NUMERIC_LIMITS(signaling_NaN);
	//returns the smallest positive subnormal value of the given floating - point type
	NUMERIC_LIMITS(denorm_min);
	
	return 0;
}