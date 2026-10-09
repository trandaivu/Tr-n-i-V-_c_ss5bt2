
#include <stdio.h>

int main() {
    int tuoi_benh_nhan[4];
    int co_bao_hiem[4];
    int phi_kham[4];

    int phi_goc = 200000;
    int tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;
    int i;

    printf("========================================\n");
    printf("   MEDCARE CLINIC - TIEP NHAN BENH NHAN\n");
    printf("========================================\n");

    // Nhap thong tin 4 benh nhan
    for (i = 0; i < 4; i++) {
        printf("\nNhap thong tin benh nhan thu %d\n", i + 1);

        printf("Nhap tuoi: ");
        scanf("%d", &tuoi_benh_nhan[i]);

        printf("Co BHYT khong? (1: Co, 0: Khong): ");
        scanf("%d", &co_bao_hiem[i]);

        // Kiem tra trang thai BHYT
        if (co_bao_hiem[i] != 0 && co_bao_hiem[i] != 1) {
            co_bao_hiem[i] = 0;
            printf("BHYT khong hop le, da chuyen ve 0.\n");
        }

        // Kiem tra tuoi va tinh phi kham
        if (tuoi_benh_nhan[i] <= 0 ||
            tuoi_benh_nhan[i] > 120) {
            phi_kham[i] = 0;
        } else {
            if (co_bao_hiem[i] == 1) {
                phi_kham[i] = phi_goc * 20 / 100;
            } else {
                phi_kham[i] = phi_goc;
            }

            // Cong doanh thu cua benh nhan hop le
            tong_doanh_thu += phi_kham[i];

            // Dem benh nhan uu tien
            if (tuoi_benh_nhan[i] > 70) {
                so_ca_uu_tien++;
            }
        }
    }

    // In bao cao tiep nhan
    printf("\n========================================\n");
    printf("       BAO CAO TIEP NHAN BENH NHAN\n");
    printf("========================================\n");

    for (i = 0; i < 4; i++) {
        printf("\nBenh nhan %d (Index %d)\n", i + 1, i);
        printf("Tuoi: %d\n", tuoi_benh_nhan[i]);
        printf("BHYT: %d\n", co_bao_hiem[i]);
        printf("Phi kham: %d VNĐ\n", phi_kham[i]);

        if (tuoi_benh_nhan[i] <= 0 ||
            tuoi_benh_nhan[i] > 120) {
            printf("Luong kham: LOI DU LIEU\n");
        } else if (tuoi_benh_nhan[i] > 70) {
            printf("Luong kham: UU TIEN\n");
        } else {
            printf("Luong kham: THUONG\n");
        }
    }

    // Tong ket ca truc
    printf("\n========================================\n");
    printf("          TONG KET CA TRUC\n");
    printf("========================================\n");
    printf("Tong doanh thu: %d VNĐ\n", tong_doanh_thu);
    printf("So ca uu tien: %d\n", so_ca_uu_tien);
    printf("Ket thuc chuong trinh!\n");

    return 0;
}
