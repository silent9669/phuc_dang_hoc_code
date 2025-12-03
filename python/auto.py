import sympy as sp
from sympy import cos, sin, groebner, simplify, Eq
import numpy as np
import matplotlib.pyplot as plt


def suy_luan_cong_thuc():
    x, y = sp.symbols('x y', real=True)
    x0, y0, phi = sp.symbols('x0 y0 phi', real=True, positive=True)
    u, v = sp.symbols('u v', real=True)  # u = cos(5t), v = sin(5t)

    # He phuong trinh:
    # x = x0*u
    # y = y0*(u*cos(phi) - v*sin(phi))  [khai trien cos(5t + phi)]
    # u^2 + v^2 = 1
    eq1 = x - x0 * u
    eq2 = y - y0 * (u * cos(phi) - v * sin(phi))
    eq3 = u ** 2 + v ** 2 - 1

    # Groebner basis de khu u, v
    G = groebner([eq1, eq2, eq3], u, v, x, y, order='lex')

    # Lay phuong trinh chi chua x, y
    print("Phuong trinh quy dao:")
    for poly in G:
        if not poly.has(u) and not poly.has(v):
            sp.pprint(Eq(simplify(poly), 0))


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