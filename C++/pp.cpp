
void process(const char str[], char outstr[]) {
    int i = 0; // Chi so duyet chuoi dau vao
    int j = 0; // Chi so ghi vao chuoi dau ra

    // 1. Bo qua cac khoang trang o dau chuoi
    while (str[i] == ' ') {
        i++;
    }

    // Neu chuoi chi toan khoang trang hoac rong, ket thuc som
    if (str[i] == '\0') {
        outstr[0] = '\0';
        return;
    }

    // 2. Duyet qua cac ky tu con lai cua chuoi dau vao
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            // Neu la ky tu khong phai khoang trang, copy vao outstr
            outstr[j++] = str[i];
        } else {
            // Neu la khoang trang, chi them vao neu truoc do khong co khoang trang
            // Viec nay giup loai bo cac khoang trang lien ke
            if (j > 0 && outstr[j - 1] != ' ') {
                outstr[j++] = ' ';
            }
        }
        i++;
    }

    // 3. Loai bo khoang trang o cuoi chuoi neu co
    // Neu ky tu cuoi cung vua ghi vao la khoang trang, ta xoa no di
    if (j > 0 && outstr[j - 1] == ' ') {
        j--;
    }

    // Ket thuc chuoi dau ra bang ky tu ket thuc '\0'
    outstr[j] = '\0';
}
