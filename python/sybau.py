# --- KHAI BÁO THƯ VIỆN ---

# Khai báo thư viện sympy và đặt tên rút gọn là sp (dùng cho tính toán symbolic)
import sympy as sp
# Khai báo thư viện numpy và đặt tên rút gọn là np (dùng cho tính toán số học, mảng)
import numpy as np
# Khai báo thư viện matplotlib.pyplot (dùng để vẽ) và đặt tên là plt
import matplotlib.pyplot as plt
# Khai báo thư viện math (dùng cho các hàm toán cơ bản, như đổi sang radian)
import math

# --- ĐỊNH NGHĨA HÀM CHÍNH ---

# Định nghĩa hàm chính (main) để chứa toàn bộ logic của chương trình
def main():
    # ----- Nhiệm vụ 1: Nhập các giá trị ban đầu -----
    
    # In tiêu đề của chương trình ra màn hình
    print("--- CHƯƠNG TRÌNH XÁC ĐỊNH QUỸ ĐẠO CỦA VẬT ---")
    # In một đường gạch ngang để phân cách
    print("-----------------------------------------------")
    
    # Bắt đầu một khối 'try' để xử lý lỗi nếu người dùng nhập sai
    try:
        # --- Nhập liệu ---
        # Yêu cầu người dùng nhập biên độ x0 và chuyển đổi chuỗi nhập vào thành số thực (float)
        x0_val = float(input("Nhập biên độ x0: "))
        # Yêu cầu người dùng nhập biên độ y0 và chuyển đổi sang số thực
        y0_val = float(input("Nhập biên độ y0: "))
        # Yêu cầu người dùng nhập độ lệch pha (bằng độ) và chuyển sang số thực
        phi_val_deg = float(input("Nhập độ lệch pha phi (tính bằng độ): "))
        
        # --- Chuyển đổi phi sang radian ---
        # Dùng hàm math.radians để đổi giá trị từ độ (degree) sang radian
        phi_val_rad = math.radians(phi_val_deg)
        
    # Khối 'except' sẽ chạy nếu lỗi 'ValueError' xảy ra (ví dụ: nhập chữ thay vì số)
    except ValueError:
        # In thông báo lỗi
        print("Lỗi: Vui lòng nhập số hợp lệ.")
        # Dừng hàm main() và thoát chương trình
        return

    # ----- Nhiệmvụ 2: Thiết lập và giải symbolic -----
    
    # In tiêu đề cho phần 2 (thêm \n để xuống dòng)
    print("\n--- PHÂN TÍCH SYMBOLIC ---")
    
    # --- Khai báo các biến symbolic ---
    # Báo cho thư viện sympy biết 't', 'x', 'y', 'x0', 'y0', 'phi' là các ký hiệu toán học
    t, x, y, x0, y0, phi = sp.symbols('t x y x0 y0 phi')
    
    # --- Phương trình quỹ đạo tổng quát ---
    # Dùng sp.Eq để định nghĩa một phương trình (Vế Trái = Vế Phải)
    general_trajectory_eq = sp.Eq(
        # Vế Trái: (x/x0)**2 + (y/y0)**2 - 2*(x/x0)*(y/y0)*sp.cos(phi)
        (x/x0)**2 + (y/y0)**2 - 2*(x/x0)*(y/y0)*sp.cos(phi), 
        # Vế Phải: sp.sin(phi)**2
        sp.sin(phi)**2
    )
    
    # In thông báo
    print("Phương trình quỹ đạo tổng quát:")
    # Dùng sp.pprint (pretty print) để in phương trình ra dạng công thức dễ đọc
    sp.pprint(general_trajectory_eq, use_unicode=True)
    
    # --- Thay các giá trị số đã nhập vào phương trình ---
    # Dùng hàm .subs() (substitute - thay thế) để gán giá trị số vào ký hiệu
    trajectory_with_values = general_trajectory_eq.subs([
        # Thay ký hiệu x0 bằng giá trị số x0_val
        (x0, x0_val),
        # Thay ký hiệu y0 bằng giá trị số y0_val
        (y0, y0_val),
        # Thay ký hiệu phi bằng giá trị số phi_val_rad
        (phi, phi_val_rad)
    ]).evalf() # .evalf() để tính toán các biểu thức (ví dụ: sp.cos(1.57) -> 0)
    
    # In thông báo, sử dụng f-string để chèn giá trị của biến vào chuỗi
    print(f"\nPhương trình quỹ đạo với x0={x0_val}, y0={y0_val}, phi={phi_val_deg} độ:")
    
    # --- Làm gọn phương trình ---
    # Yêu cầu sympy cố gắng rút gọn biểu thức sau khi đã thay số
    simplified_eq = sp.simplify(trajectory_with_values)
    # In phương trình đã rút gọn ra màn hình
    sp.pprint(simplified_eq, use_unicode=True)

    # --- Kết luận về quỹ đạo ---
    # Kiểm tra nếu phi chia hết cho 180 (ví dụ: 0, 180, 360...)
    if phi_val_deg % 180 == 0:
        # Đây là trường hợp cùng pha hoặc ngược pha
        print("Kết luận: Quỹ đạo là một đường thẳng.")
    # Ngược lại, nếu phi chia hết cho 90 (ví dụ: 90, 270) VÀ hai biên độ bằng nhau
    elif phi_val_deg % 90 == 0 and x0_val == y0_val:
        # Đây là trường hợp vuông pha, biên độ bằng nhau
        print("Kết luận: Quỹ đạo là một đường tròn.")
    # Ngược lại, nếu phi chỉ chia hết cho 90 (biên độ khác nhau)
    elif phi_val_deg % 90 == 0:
        # Đây là trường hợp vuông pha, biên độ khác nhau
        print("Kết luận: Quỹ đạo là một đường elip chuẩn (không xoay).")
    # Tất cả các trường hợp góc phi còn lại
    else:
        # Ví dụ: 30, 45, 60, 120 độ...
        print("Kết luận: Quỹ đạo là một đường elip xoay.")

    # ----- Nhiệm vụ 3: Vẽ hình quỹ đạo -----
    
    # In thông báo
    print("\n--- ĐANG VẼ ĐỒ THỊ ---")
    
    # --- Tạo một dải giá trị thời gian t (1 chu kỳ là T = 2*pi / 5) ---
    # Dùng np.linspace để tạo một mảng gồm 500 điểm, bắt đầu từ 0, kết thúc ở (2*pi/5)
    t_vals = np.linspace(0, 2 * np.pi / 5, 500)
    
    # --- Tính toán các giá trị x(t) và y(t) ---
    # Tính 500 giá trị x_vals, dùng phương trình x(t) = x0*cos(5*t)
    x_vals = x0_val * np.cos(5 * t_vals)
    # Tính 500 giá trị y_vals, dùng phương trình y(t) = y0*cos(5*t + phi)
    y_vals = y0_val * np.cos(5 * t_vals + phi_val_rad)
    
    # --- Bắt đầu vẽ ---
    # Tạo một khung vẽ (figure) với kích thước (rộng 8 inches, cao 6 inches)
    plt.figure(figsize=(8, 6))
    # Lệnh vẽ chính: Vẽ một đường nối 500 điểm (x_vals, y_vals)
    # 'label' dùng để đặt tên cho đường này, sẽ hiển thị trong chú thích
    plt.plot(x_vals, y_vals, label=f'Quỹ đạo (phi = {phi_val_deg} deg)')
    
    # --- Đặt tiêu đề và nhãn ---
    # Đặt tiêu đề cho toàn bộ đồ thị
    plt.title('Quỹ đạo của chất điểm')
    # Đặt nhãn cho trục hoành (trục x)
    plt.xlabel('x(t)')
    # Đặt nhãn cho trục tung (trục y)
    plt.ylabel('y(t)')
    # Rất quan trọng: Đặt tỉ lệ 2 trục bằng nhau (để hình tròn không bị méo thành elip)
    plt.axis('equal')
    # Bật hiển thị lưới (grid) trên đồ thị
    plt.grid(True)
    # Hiển thị hộp chú thích (legend), dựa trên 'label' đã đặt ở lệnh plot
    plt.legend()
    # Hiển thị cửa sổ đồ thị lên màn hình
    plt.show()

# --- ĐIỂM BẮT ĐẦU CỦA CHƯƠNG TRÌNH ---

# Khối 'if' này kiểm tra xem file có đang được chạy trực tiếp hay không
# (thay vì bị import bởi một file khác)
if __name__ == "__main__":
    # Nếu đúng, gọi hàm main() để bắt đầu chạy chương trình
    main()