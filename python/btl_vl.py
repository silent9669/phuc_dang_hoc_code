import sympy as sp
import numpy as np
import matplotlib.pyplot as plt


def suy_luan_cong_thuc():
    # u = cos(5t), v = sin(5t)
    x, y = sp.symbols('x y', real=True)
    x0, y0, phi = sp.symbols('x0 y0 phi', real=True, positive=True)
    u, v = sp.symbols('u v', real=True)

    # x = x0*u
    pt1 = sp.Eq(x, x0 * u)

    # y = y0*cos(5t + phi) = y0*(u*cos(phi) - v*sin(phi))
    pt2 = sp.Eq(y, y0 * (u * sp.cos(phi) - v * sp.sin(phi)))

    # Giai he tim u, v theo x, y
    nghiem = sp.solve([pt1, pt2], (u, v))

    cos_5t = nghiem[u]
    sin_5t = nghiem[v]

    print(f"cos(5t) = {cos_5t}")
    print(f"sin(5t) = {sin_5t}")

    # Khu t: sin^2 + cos^2 = 1
    pt_quy_dao = sp.simplify(sp.Eq(sin_5t**2 + cos_5t**2, 1))

    print("\n--- Phuong trinh quy dao ---")
    sp.pprint(pt_quy_dao)


def ve_do_thi(x0, y0, phi_do):
    phi_rad = np.radians(phi_do)
    t = np.linspace(0, 2*np.pi/5, 100)

    x = x0 * np.cos(5*t)
    y = y0 * np.cos(5*t + phi_rad)

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