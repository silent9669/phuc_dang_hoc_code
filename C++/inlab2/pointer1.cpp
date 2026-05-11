int calcSum(int *ptr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += *(ptr + i);
  }
  return sum;
}

void add(int *ptr, int n, int k) { *(ptr + n) = k; }

int **readArray() {
  int **matrix = new int *[10];
  for (int i = 0; i < 10; i++) {
    matrix[i] = new int[10];
  }

  for (int i = 0; i < 10; i++) {
    bool zeroDetected = 1;

    for (int j = 0; j < 10; j++) {
      if (!zeroDetected) {
        int val;
        cin >> val;

        matrix[i][j] = val;

        if (matrix[i][j] == 0)
          zeroDetected = 0;
      } else {
        matrix[i][j] = 0;
      }
    }
  }

  return matrix;
}

void addElement(int *&arr, int n, int val, int index) {
  int *newArr = new int[n + 1];

  for (int i = 0; i < n + 1; i++) {
    if (i < index) {
      *(newArr + i) = *(arr + i);
    } else if (i == index) {
      *(newArr + i) = val;
    } else {
      *(newArr + i) = *(arr + i - 1);
    }
  }

  delete[] arr;
  arr = newArr;
  n++;
}

int *flatten(int **matrix, int r, int c) {
  int total = r * c;
  int *flat = new int[total];

  int k = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      flat[k++] = matrix[i][j];
    }
  }

  return flat;
}
