# 🎬 Hệ thống Đặt Vé Rạp Chiếu Phim (Movie Ticket Booking System)

## Giới thiệu

Đây là chương trình quản lý đặt vé rạp chiếu phim được xây dựng bằng **C++ (Console Application)** nhằm áp dụng các kiến thức về **Cấu trúc dữ liệu và Giải thuật (DSA)**.

Chương trình cho phép người dùng:

* Xem sơ đồ ghế của rạp.
* Đặt vé theo vị trí ghế.
* Hủy vé.
* Quản lý danh sách chờ khi rạp hết chỗ.
* Tìm kiếm khách hàng.
* Thống kê số ghế còn trống và doanh thu.

---

# Cấu trúc dữ liệu sử dụng

## 1. Binary Search Tree (BST)

**Mục đích**

* Lưu thông tin khách hàng đã đặt vé.
* Tìm kiếm khách hàng theo mã nhanh chóng.

**Lý do lựa chọn**

BST hỗ trợ tìm kiếm, thêm và duyệt dữ liệu hiệu quả với độ phức tạp trung bình **O(log n)**.

---

## 2. Priority Queue

**Mục đích**

Quản lý danh sách chờ khi toàn bộ ghế đã được đặt.

**Lý do lựa chọn**

Khách hàng VIP sẽ được ưu tiên nhận ghế trước khi có người hủy vé.

Độ phức tạp:

* Thêm vào hàng chờ: **O(log n)**
* Lấy khách ưu tiên cao nhất: **O(log n)**

---

## 3. Stack

**Mục đích**

Lưu lịch sử các giao dịch đặt vé.

**Lý do lựa chọn**

Stack hoạt động theo nguyên tắc **LIFO**, thuận tiện cho việc theo dõi hoặc mở rộng chức năng hoàn tác (Undo).

---

## 4. Mảng hai chiều (2D Array)

**Mục đích**

Quản lý sơ đồ ghế của rạp chiếu phim.

Mỗi phần tử của mảng là một ghế:

* Trống
* Đã đặt

Việc truy cập một ghế có độ phức tạp **O(1)**.

---

# Chức năng

Chương trình hỗ trợ các chức năng sau:

1. Hiển thị sơ đồ ghế bằng ký tự ASCII.
2. Đặt vé.
3. Tự động đưa khách vào Priority Queue nếu rạp hết ghế.
4. Hủy vé.
5. Cấp ghế cho khách đang chờ theo mức ưu tiên.
6. Tìm kiếm khách hàng theo mã.
7. Xuất danh sách khách hàng đã đặt vé.
8. Thống kê:

   * Số ghế còn trống.
   * Doanh thu.

---

# Cấu trúc thư mục

```
MovieTicketBooking/

│── src/
│   │── main.cpp
│   │── TicketSystem.h
│   │── TicketSystem.cpp
│
│── tests/
│   │── test_cases.cpp
│
│── docs/
│
└── README.md
```

---

# Biên dịch chương trình

Sử dụng trình biên dịch hỗ trợ C++17.

Ví dụ với g++:

```bash
g++ -std=c++17 src/main.cpp src/TicketSystem.cpp -o MovieTicket
```

Chạy chương trình:

```bash
./MovieTicket
```

---

# Menu chương trình

```
========== MENU ==========

1. Hiển thị sơ đồ ghế
2. Đặt vé
3. Hủy vé
4. Tìm khách hàng
5. Danh sách khách đã đặt
6. Thống kê
0. Thoát
```

---

# Độ phức tạp các chức năng

| Chức năng       | Cấu trúc dữ liệu | Độ phức tạp |
| --------------- | ---------------- | ----------- |
| Hiển thị ghế    | Mảng 2 chiều     | O(R × C)    |
| Đặt vé          | BST + Array      | O(log n)    |
| Hủy vé          | BST              | O(log n)    |
| Khách chờ       | Priority Queue   | O(log n)    |
| Tìm khách       | BST              | O(log n)    |
| Danh sách khách | BST (Inorder)    | O(n)        |
| Thống kê        | Mảng             | O(R × C)    |

---

# Test Cases

## Test 1

Đặt vé thành công.

Kết quả mong đợi:

* Ghế chuyển sang trạng thái đã đặt.
* Doanh thu tăng.

---

## Test 2

Đặt vé vào ghế đã có người.

Kết quả mong đợi:

* Thông báo ghế đã được đặt.
* Không thay đổi dữ liệu.

---

## Test 3

Rạp hết ghế.

Kết quả mong đợi:

* Khách được đưa vào Priority Queue.

---

## Test 4

Hủy vé.

Kết quả mong đợi:

* Ghế được giải phóng.
* Nếu có khách chờ thì cấp ghế ngay.

---

## Test 5

Tìm kiếm khách hàng.

Kết quả mong đợi:

* Hiển thị đúng thông tin khách hàng nếu tồn tại.
* Thông báo không tìm thấy nếu không tồn tại.

---

# Hướng phát triển

* Lưu và đọc dữ liệu từ file.
* Tìm kiếm theo tên khách hàng.
* Xóa khách hàng khỏi BST khi hủy vé.
* Hỗ trợ nhiều phòng chiếu.
* Quản lý nhiều suất chiếu.
* Thêm đăng nhập quản trị viên.
* Giao diện đồ họa (Qt hoặc WinAPI).

---

# Thành viên thực hiện

* Họ và tên: ....................................
* MSSV: .........................................
* Lớp: ..........................................

---

# Kết luận

Dự án giúp vận dụng nhiều cấu trúc dữ liệu quan trọng như **Binary Search Tree**, **Priority Queue**, **Stack** và **Mảng hai chiều** vào một bài toán thực tế. Qua đó rèn luyện kỹ năng thiết kế chương trình, quản lý dữ liệu và phân tích độ phức tạp của thuật toán trong C++.
