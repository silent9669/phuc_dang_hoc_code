import sympy as sp
import numpy as np
import matplotlib.pyplot as plt


# --- PHẦN 1: HÀM SUY LUẬN CÔNG THỨC (SYMBOLIC) ---
def tu_dong_chung_minh_cong_thuc():
    print("\n" + "=" * 60)
    print("PHẦN 1: MAY TINH TU CHUNG MINH CONG THUC")
    print("=" * 60)

    # 1. Khai báo các ký hiệu toán học (bien so)
    t = sp.symbols('t', real=True)  # Thoi gian
    x, y = sp.symbols('x y', real=True)  # Toa do x, y
    x0, y0, phi = sp.symbols('x0 y0 phi', real=True)  # Bien do va goc lech pha

    # 2. Định nghĩa các thành phần cơ bản
    # Tu phuong trinh x = x0 * cos(5t) => cos(5t) = x / x0
    cos_5t = x / x0

    # Day la thanh phan 'sin(5t)' ma chung ta can tim de khu no di
    sin_5t = sp.sin(5 * t)

    print(f"[BUOC 1] Ta co: cos(5t) = {cos_5t}")

    # 3. Ap dung cong thuc cong luong giac cho y
    # y = y0 * cos(5t + phi)
    # y = y0 * [ cos(5t)*cos(phi) - sin(5t)*sin(phi) ]

    # Chung ta tu thay 'cos(5t)' bang 'x/x0' vao cong thuc luon
    y_khai_trien = y0 * (cos_5t * sp.cos(phi) - sin_5t * sp.sin(phi))

    print(f"[BUOC 2] Ap dung cong thuc cong va the x vao y:")
    print(f"  y = {y_khai_trien}")

    # 4. Co lap sin(5t) (Giai phuong trinh tim sin(5t))
    # May tinh se hieu la: Giai phuong trinh "y = ..." de tim "sin(5t)"
    ket_qua_giai = sp.solve(sp.Eq(y, y_khai_trien), sin_5t)

    if not ket_qua_giai:
        print("Loi: Khong tim thay nghiem.")
        return

    # Lay nghiem dau tien tim duoc
    sin_5t_da_rut = ket_qua_giai[0]
    print(f"[BUOC 3] Rut sin(5t) ra duoc: {sin_5t_da_rut}")

    # 5. Binh phuong va khu t (su dung sin^2 + cos^2 = 1)
    # Ve trai: 1 - cos^2(5t)  (tuc la sin^2)
    ve_trai_binh_phuong = 1 - cos_5t ** 2

    # Ve phai: Binh phuong cua cai sin(5t) vua tim duoc o tren
    ve_phai_binh_phuong = sin_5t_da_rut ** 2

    # 6. Tao phuong trinh tong quat
    # Chuyen ve: Ve trai - Ve phai = 0
    bieu_thuc_chua_rut_gon = ve_trai_binh_phuong - ve_phai_binh_phuong

    # Dung ham simplify de may tinh tu dong rut gon bieu thuc dai ngoang
    phuong_trinh_cuoi = sp.simplify(bieu_thuc_chua_rut_gon)

    print("\n[KET QUA CUOI CUNG] Phuong trinh quy dao (dang f(x,y) = 0):")
    sp.pprint(phuong_trinh_cuoi)
    print("-" * 60)


# --- PHẦN 2: HÀM VẼ ĐỒ THỊ ---
def ve_do_thi_quy_dao(bien_do_x, bien_do_y, goc_phi_do):
    print(f"\n>> Dang ve do thi: x0={bien_do_x}, y0={bien_do_y}, phi={goc_phi_do} do")

    # Doi goc tu do sang radian (may tinh chi hieu radian)
    goc_phi_rad = np.radians(goc_phi_do)

    # Tao 1000 diem thoi gian tu 0 den het 1 chu ky
    mang_thoi_gian = np.linspace(0, 2 * np.pi / 5, 1000)

    # Tinh toan toa do x va y cho tung diem thoi gian
    # Cong thuc: x = x0 * cos(5t)
    toa_do_x = bien_do_x * np.cos(5 * mang_thoi_gian)

    # Cong thuc: y = y0 * cos(5t + phi)
    toa_do_y = bien_do_y * np.cos(5 * mang_thoi_gian + goc_phi_rad)

    # Bat dau ve
    plt.figure(figsize=(8, 8))  # Tao khung hinh vuong 8x8

    # Ve duong quy dao mau xanh
    plt.plot(toa_do_x, toa_do_y, label=f'Quy dao (phi={goc_phi_do})', linewidth=2.5)

    # Danh dau diem xuat phat (luc t=0) bang cham do
    plt.plot(toa_do_x[0], toa_do_y[0], 'ro', label='Diem xuat phat (Start)')

    # Trang tri do thi
    plt.title(f"Do thi Quy dao Lissajous\nx0={bien_do_x}, y0={bien_do_y}, phi={goc_phi_do} do")
    plt.xlabel("Bien do x")
    plt.ylabel("Bien do y")

    # Ve truc toa do ngang doc mau den
    plt.axhline(0, color='black')
    plt.axvline(0, color='black')

    # Hien luoi o vuong
    plt.grid(True, linestyle='--')

    # QUAN TRONG: Lenh nay giup hinh tron khong bi meo
    plt.axis('equal')

    # Gioi han khung nhin
    gioi_han = max(bien_do_x, bien_do_y) * 1.2
    plt.xlim(-gioi_han, gioi_han)
    plt.ylim(-gioi_han, gioi_han)

    plt.legend()  # Hien chu thich
    plt.show()  # Hien cua so do thi


# --- CHẠY CHƯƠNG TRÌNH ---
if __name__ == "__main__":
    # Buoc 1: Chay phan chung minh cong thuc
    try:
        tu_dong_chung_minh_cong_thuc()
    except Exception as loi:
        print(f"Co loi he thong: {loi}")

    # Buoc 2: Vong lap nhap so lieu de ve
    while True:
        try:
            print("\n--- NHAP THONG SO (Go 'q' de thoat) ---")
            nhap_lieu = input("Nhap bien do x0: ")

            # Neu nguoi dung go 'q' thi thoat chuong trinh
            if nhap_lieu.lower() == 'q':
                break

            # Chuyen doi du lieu nhap vao thanh so thuc
            gia_tri_x0 = float(nhap_lieu)
            gia_tri_y0 = float(input("Nhap bien do y0: "))
            gia_tri_phi = float(input("Nhap goc phi (do): "))

            # Goi ham ve do thi voi cac gia tri vua nhap
            ve_do_thi_quy_dao(gia_tri_x0, gia_tri_y0, gia_tri_phi)

        except ValueError:
            print("Loi: Vui long chi nhap so hop le!")