Construction:

  std::string: Default constructor to create an empty string.
  std::string(const char*): Construct from a C-style null-terminated string.
  std::string(const char*, size_t): Construct from a character array with a specified length.
  std::string(const std::string&): Copy constructor to create a string from another string.

String Operations:

  size(): Returns the length (number of characters) of the string.
  empty(): Checks if the string is empty.
  clear(): Clears the contents of the string.
  substr(pos, len): Returns a substring starting at position pos with a length of len.
  insert(pos, str): Inserts the string str into the current string at position pos.
  erase(pos, len): Erases len characters from the string, starting at position pos.
  replace(pos, len, str): Replaces len characters in the string, starting at position pos, with str.
  find(str): Finds the first occurrence of str within the string.
  rfind(str): Finds the last occurrence of str within the string.
  find_first_of(str): Finds the first occurrence of any character in str within the string.
  find_last_of(str): Finds the last occurrence of any character in str within the string.
  find_first_not_of(str): Finds the first occurrence of a character not in str within the string.
  find_last_not_of(str): Finds the last occurrence of a character not in str within the string.
  getline(stream, str): Reads a line from an input stream stream into the string str.

String Transformation:

  tolower(): Converts the string to lowercase.
  toupper(): Converts the string to uppercase.
  reverse(): Reverses the characters in the string.

String Conversion:

  stoi(str), stol(str), stoll(str): Converts a string to an integer, long, or long long.
  to_string(value): Converts a value to a string representation.

String Comparison and Sorting:

  compare(str): Compares the string with another string str.
    ==, !=, <, <=, >, >=: Comparison operators to compare strings.
  std::ranges::sort(): Sorts a range of strings in ascending order using default comparison.
  std::ranges::sort(comp): Sorts a range of strings using the provided comparison function or lambda expression.

String Manipulation:

  std::getline(stream, str): Reads a line from an input stream stream into the string str.
  std::stoi(str), std::stol(str), std::stoll(str): Converts a string to an integer, long, or long long.
  std::to_string(value): Converts a value to a string representation.
  std::toupper(str), std::tolower(str): Converts the string to uppercase or lowercase.
  std::reverse(str): Reverses the characters in the string.

String Searching:

  std::find(str.begin(), str.end(), ch): Finds the first occurrence of a character ch in the string.
  std::find(str.begin(), str.end(), substr.begin(), substr.end()): Finds the first occurrence of a substring substr in the string.
  std::count(str.begin(), str.end(), ch): Counts the number of occurrences of a character ch in the string.
  std::count(str.begin(), str.end(), substr.begin(), substr.end()): Counts the number of occurrences of a substring substr in the string.

String Matching and Replacement:

  std::regex_match(str, regex): Checks if the string matches a regular expression.
  std::regex_search(str, match, regex): Searches the string for a regular expression match and stores the matched results in match.
  std::regex_replace(str, regex, replacement): Replaces matches of a regular expression regex in the string with the replacement string.

STRING VIEWS

Construction and Assignment:

  std::string_view(): Default constructor that creates an empty string view.
  std::string_view(const char*): Constructs a string view from a null-terminated C-style string.
  std::string_view(const char*, size_t): Constructs a string view from a character array with a specified length.
  std::string_view(const std::string&): Constructs a string view from a std::string object.
  std::string_view(const std::string&, size_t, size_t): Constructs a string view from a portion of a std::string object.

Access and Operations:

  size(): Returns the length (number of characters) of the string view.
  empty(): Checks if the string view is empty.
  operator[](index): Accesses the character at the specified index.
  front(), back(): Accesses the first and last characters of the string view.
  data(): Returns a pointer to the underlying character array.
  substr(pos, len): Returns a substring starting at position pos with a length of len.

Comparison and Searching:

  compare(str): Compares the string view with another string or string view str.
  ==, !=, <, <=, >, >=: Comparison operators to compare string views.
  find(str): Finds the first occurrence of str within the string view.
  rfind(str): Finds the last occurrence of str within the string view.
  find_first_of(str): Finds the first occurrence of any character in str within the string view.
  find_last_of(str): Finds the last occurrence of any character in str within the string view.
  find_first_not_of(str): Finds the first occurrence of a character not in str within the string view.
  find_last_not_of(str): Finds the last occurrence of a character not in str within the string view.

Range-based Algorithms:

  std::ranges::sort(): Sorts a range of elements using default comparison.
  std::ranges::sort(comp): Sorts a range of elements using the provided comparison function or lambda expression.
  std::ranges::reverse(): Reverses the order of elements in a range.
  std::ranges::unique(): Removes consecutive duplicate elements from a range.
  std::ranges::count(): Counts the occurrences of a value in a range.
  std::ranges::min_element(): Finds the smallest element in a range.
  std::ranges::max_element(): Finds the largest element in a range.
  std::ranges::binary_search(): Determines if a value is present in a sorted range.
  std::ranges::lower_bound(): Finds the first position where a value can be inserted in a sorted range.
  std::ranges::upper_bound(): Finds the last position where a value can be inserted in a sorted range.

Range Adaptors:

  std::views::transform(): Applies a transformation function to each element of a range.
  std::views::filter(): Filters a range based on a predicate function.
  std::views::take(): Returns a range containing the first N elements of a range.
  std::views::drop(): Returns a range without the first N elements of a range.
  std::views::split(): Splits a range into subranges based on a delimiter.
  std::views::join(): Concatenates a range of ranges into a single range.
  std::views::reverse(): Reverses the order of elements in a range.
  std::views::unique(): Removes consecutive duplicate elements from a range.


Split the string based on delimiter:

Approach 1:
  #include <iostream>
  #include <string>
  #include <sstream>
  #include <vector>

  std::vector<std::string> splitString(const std::string& str, char delimiter) {
      std::vector<std::string> tokens;
      std::istringstream iss(str);
      std::string token;

      while (std::getline(iss, token, delimiter)) {
          tokens.push_back(token);
      }

      return tokens;
  }

  int main() {
      std::string input = "apple,banana,cherry,date";
      char delimiter = ',';

      std::vector<std::string> substrings = splitString(input, delimiter);

      // Print the substrings
      for (const auto& substr : substrings) {
          std::cout << substr << std::endl;
      }

      return 0;
  }

Approach 2:

  #include <iostream>
  #include <string>
  #include <vector>
  #include <ranges>
  #include <algorithm>

  int main() {
      std::string input = "apple,banana,cherry,date";
      char delimiter = ',';

      // Split the string into substrings based on the delimiter
      std::vector<std::string> substrings = input
          | std::views::split(delimiter)
          | std::views::transform([](auto&& subrange) {
              return std::string{subrange.begin(), subrange.end()};
          });

      // Print the substrings
      for (const auto& substr : substrings) {
          std::cout << substr << std::endl;
      }

      return 0;
  }
