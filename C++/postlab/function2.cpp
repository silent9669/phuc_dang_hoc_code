int convertToBaseM(int n, int m = 2) {
  int result = 0;
  int place = 1;

  while (n > 0) {
    result += (n % m) * place;
    n /= m;
    place *= 10;
  }

  return result;
}
