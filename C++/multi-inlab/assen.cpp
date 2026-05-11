int ascendingRows(int arr[][1000], int row, int col) {
  int count = 0;
  for (int i = 0; i < row; i++) {
    bool isHN1 = true;
    for (int j = 0; j < col - 1; j++) {
      if (arr[i][j] > arr[i][j + 1]) {
        isHN1 = false;
        break;
      }
    }
    if (isHN1)
      count++;
  }
  return count;
}
