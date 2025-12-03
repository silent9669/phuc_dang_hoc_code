import sympy as sp
import numpy as np
import matplotlib.pyplot as plt

def suy_luan_cong_thuc():
    t, x, y = sp.symbols('t x y', real=True)
    x0, y0, phi = sp.symbols('x0 y0 phi', real=True)

    # x = x0*cos(5t) => cos(5t) = x/x0
    cos_5t = x / x0

    # BƯỚC 2: Rút gọn sin(5t) từ phương trình y (sau khi khai triển cos(5t + phi))
    # Khai triển: y/y0 = cos(5t)cos(phi) - sin(5t)sin(phi)
    # => sin(5t)sin(phi) = cos(5t)cos(phi) - y/y0
    sin_5t_expr = (cos_5t * sp.cos(phi) - y / y0) / sp.sin(phi)

    # BƯỚC 3: Áp dụng hằng đẳng thức sin^2(5t) + cos^2(5t) = 1
    # sin^2(5t) = 1 - cos^2(5t)
    pt_goc = sp.Eq(sin_5t_expr ** 2, 1 - cos_5t ** 2)

    # BƯỚC 4: Rút gọn để tìm phương trình quỹ đạo
    pt_quy_dao = sp.simplify(pt_goc.lhs - pt_goc.rhs)

    # Rút gọn về dạng ellipse chuẩn
    pt_ellipse = sp.Eq(pt_quy_dao + sp.sin(phi) ** 2, sp.sin(phi) ** 2)

    print("\n[Phương trình Quỹ Đạo (sau khi loại biến t)]")
    # Sử dụng pprint cho output toán học đẹp hơn
    sp.pprint(pt_ellipse)


def ve_do_thi(x0, y0, phi_do):
    phi_rad = np.radians(phi_do)
    t = np.linspace(0, 2 * np.pi / 5, 1000)

    x = x0 * np.cos(5 * t)
    y = y0 * np.cos(5 * t + phi_rad)

    plt.figure(figsize=(8, 8))
    plt.plot(x, y, linewidth=2)
    plt.plot(x[0], y[0], 'ro', label='Start')
    plt.title(f"Quy dao: x0={x0}, y0={y0}, phi={phi_do}")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.axhline(0, color='black')
    plt.axvline(0, color='black')
    plt.grid(True, linestyle='--')
    plt.axis('equal')
    plt.legend()
    plt.show()


if __name__ == "__main__":
    suy_luan_cong_thuc()

    while True:
        nhap = input("\nNhap x0 (q de thoat): ")
        if nhap.lower() == 'q':
            break
        try:
            x0 = float(nhap)
            y0 = float(input("Nhap y0: "))
            phi = float(input("Nhap phi (do): "))
            ve_do_thi(x0, y0, phi)
        except ValueError:
            print("Nhap so khong hop le")