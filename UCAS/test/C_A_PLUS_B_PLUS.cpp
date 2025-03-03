#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

// Used to record the base of the number.
enum base_flag {
  DECIMAL,
  HEXADECIMAL,
  OCTAL
};

base_flag check_base_type (string a) {
  if (a[0] == '0' && a[1] == 'x') {
    return HEXADECIMAL;
  } else if (a[0] == '0') {
    return OCTAL;
  } else {
    return DECIMAL;
  }
}

// Used to add two decimal number string.
string add_decimal_string(string num1, string num2) {
  string result = "";
  int carry = 0; 
  int i = num1.size() - 1, j = num2.size() - 1;

  while (i >= 0 || j >= 0 || carry) {
      int n1 = (i >= 0) ? num1[i] - '0' : 0;
      int n2 = (j >= 0) ? num2[j] - '0' : 0;
      int sum = n1 + n2 + carry;
      carry = sum / 10;
      result += (sum % 10) + '0';
      i--; j--;
  }

  reverse(result.begin(), result.end());
  return result;
}

// Convert the hexadecimal number string to decimal number string
string convert_hex_to_dec(string hex_num) {
  string num = hex_num.substr(2);

  string result = "0";
  for (char c : num) {
    int digit = (c >= '0' && c <= '9') ?
                c - '0' : toupper(c) - 'A' + 10;

    // result*16
    for (int i = 0 ; i < 4; i++) {
      result = add_decimal_string(result, result);
    }
    result = add_decimal_string(result, to_string(digit));
    // cout<< "after input:" << c << " result: " << result << endl;
  }
  return result;
}

// Convert the octal number string to decimal number string
string convert_oct_to_dec(string oct_num) {
  string num = oct_num.substr(1);

  string result = "0";
  for (char c : num) {
    int digit = c - '0';

    // result*16
    for (int i = 0 ; i < 3; i++) {
      result = add_decimal_string(result, result);
    }
    result = add_decimal_string(result, to_string(digit));
  }
  return result;
}

// Convert the string to the number in decimal and put it into string
string convert_to_decimal(string num, base_flag base) {
  string result;
  switch (base) {
    case HEXADECIMAL:
      return convert_hex_to_dec(num);
      break;
    case OCTAL:
      return convert_oct_to_dec(num);
      break;
    case DECIMAL:
      break;
  }
  return num;
}



int main() {
  string a, b;
  cin >> a >> b;
  base_flag base_a = check_base_type(a);
  base_flag base_b = check_base_type(b);
  // First, convert a & b to decimal string.
  string dec_a = convert_to_decimal(a, base_a);
  string dec_b = convert_to_decimal(b, base_b);
  // Add these two decimal string.
  string sum = add_decimal_string(dec_a, dec_b);
  std::cout << sum << std::endl;
  return 0; 
}