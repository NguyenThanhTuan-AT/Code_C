#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*int find(int a[], int n)
{
    int max = INT_MIN;
    int MAX = INT_MIN;
    for(int i = 0; i<n ; i++)
    {
        if(a[i]> MAX)
        {
            max = MAX;
            MAX = a[i];
        }
        else if (max<a[i] && a[i]<MAX)
        {
            max=a[i];
        }

    }
        return (max == INT_MIN) ? MAX : max;
}
int main()
{
    int T;
    scanf("%d", &T);
    int n;
    for(int t = 1; t<=T ; t++)
    {
        scanf("%d", &n);
        int a[n];
        for(int i = 0; i<n; i++)
            scanf("%d",&a[i]);
        printf("Case #%d: %d\n", t, find(a, n));
    }
    return 0;
}*/
void doi_cho(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int Partition(int a[], int t, int p)
{
    int chot = a[t];
    int i = t+1;
    int j = p;
    do
    {
        while(i<=j && a[i]< chot) i++;
        while(i<=j && a[j]> chot) j--;
        if(i< j)
            doi_cho(a, i, j);
    }
    while(i<=j);
    doi_cho(a, j, t);
    return j;
}


// Hàm Quick Sort (sắp xếp tăng dần)
void Quick_sort(int a[], int t, int p)
{
    if (t < p)
    {
        // j là chỉ số phân vùng
        int j = Partition(a, t, p);
        // Sắp xếp đệ quy các mảng con
        Quick_sort(a, t, j - 1);
        Quick_sort(a, j + 1, p);
    }
}

// Hàm tìm giá trị nhỏ nhất (min)
int min(int a, int b)
{
    return (a < b) ? a : b;
}

/*
 * @brief Hàm kiểm tra xem có thể phân công tất cả các bài tập (trong một tập hợp con bất kỳ)
 * cho K người sao cho không người nào làm quá max_time hay không.
 * Sử dụng Bitmask Dynamic Programming.
 * @param a Mảng chứa thời gian hoàn thành của từng bài tập.
 * @param N Số lượng bài tập.
 * @param K Số lượng người trong nhóm.
 * @param max_time Thời gian tối đa cho phép một người hoàn thành.
 * @return 1 (true) nếu có thể phân công, 0 (false) nếu không.
 */
int can_complete_bitmask(int a[], int N, int K, long long max_time)
{
    int max_mask = 1 << N; // Tính toán 2^N một lần

    // Cấp phát động cho mảng sums trên heap
    long long *sums = (long long *)malloc(max_mask * sizeof(long long));
    if (sums == NULL)
    {
        fprintf(stderr, "Loi cap phat bo nho cho sums.\n");
        return 0; // Trả về false nếu không cấp phát được
    }

    for (int mask = 0; mask < max_mask; mask++)
    {
        sums[mask] = 0;
        for (int i = 0; i < N; i++)
        {
            if ((mask >> i) & 1)   // Nếu bit thứ i được bật trong mask
            {
                sums[mask] += a[i];
            }
        }
    }

    // Cấp phát động cho mảng dp trên heap
    int *dp = (int *)malloc(max_mask * sizeof(int));
    if (dp == NULL)
    {
        fprintf(stderr, "Loi cap phat bo nho cho dp.\n");
        free(sums); // Giải phóng sums nếu dp cấp phát lỗi
        return 0; // Trả về false nếu không cấp phát được
    }

    // Khởi tạo dp với giá trị lớn hơn K (coi như vô cùng), ngoại trừ dp[0]
    for (int mask = 0; mask < max_mask; mask++)
    {
        dp[mask] = K + 1;
    }
    dp[0] = 0; // 0 bài tập cần 0 người

    // Duyệt qua tất cả các mask (tập hợp con của các bài tập)
    for (int mask = 1; mask < max_mask; mask++)   // Bắt đầu từ mask 1 (tập hợp không rỗng)
    {
        // Duyệt qua tất cả các tập hợp con `submask` của `mask` (bao gồm cả `mask` chính nó)
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask)
        {
            // Nếu tổng thời gian của `submask` này không vượt quá `max_time`
            if (sums[submask] <= max_time)
            {
                // `prev_mask` là các bài tập còn lại sau khi `submask` đã được phân công
                int prev_mask = mask ^ submask;
                // Nếu `prev_mask` đã có thể được phân công với số người hợp lệ (<= K)
                if (dp[prev_mask] != K + 1)
                {
                    // Cập nhật dp[mask]: số người cần cho `mask` = số người cho `prev_mask` + 1 (cho nhóm `submask`)
                    dp[mask] = min(dp[mask], dp[prev_mask] + 1);
                }
            }
        }
    }

    // Kiểm tra kết quả cuối cùng
    int result = dp[max_mask - 1] <= K;

    // Giải phóng bộ nhớ đã cấp phát trên heap
    free(sums);
    free(dp);

    return result;
}

/*
 * @brief Hàm chính giải quyết bài toán phân công bài tập.
 * Sử dụng tìm kiếm nhị phân trên kết quả với hàm kiểm tra là Bitmask DP.
 * @param a Mảng chứa thời gian hoàn thành của từng bài tập.
 * @param n Số lượng bài tập.
 * @param k Số lượng người trong nhóm.
 * @return Thời gian tối đa nhỏ nhất mà người lâu nhất phải làm.
 */
int baiTap(int a[], int n, int k)
{
    // Sắp xếp mảng các bài tập tăng dần.
    Quick_sort(a, 0, n - 1);

    // Tính tổng thời gian của tất cả các bài tập và tìm bài tập lâu nhất.
    long long sum_time = 0;
    long long max_single_time = 0;

    for (int i = 0; i < n; i++)
    {
        sum_time += a[i];
        if (a[i] > max_single_time)
        {
            max_single_time = a[i];
        }
    }

    // Thiết lập phạm vi tìm kiếm nhị phân
    long long low = max_single_time;
    long long high = sum_time;
    long long result = high; // Biến lưu kết quả cuối cùng

    // Thực hiện tìm kiếm nhị phân trên kết quả
    while (low <= high)
    {
        long long mid = low + (high - low) / 2; // Tránh tràn số

        // Gọi hàm can_complete_bitmask để kiểm tra tính khả thi
        if (can_complete_bitmask(a, n, k, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return (int)result;
}

int main()
{
    int T;
    scanf("%d", &T); // Đọc số lượng test case

    for (int t = 1; t <= T; t++)
    {
        int N, K;
        scanf("%d %d", &N, &K); // Đọc N và K

        // Cấp phát động bộ nhớ cho mảng input
        int *a = (int *)malloc(N * sizeof(int));
        if (a == NULL)
        {
            fprintf(stderr, "Loi cap phat bo nho cho mang input.\n");
            return 1; // Thoát chương trình với mã lỗi
        }

        // Đọc các phần tử của mảng
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &a[i]);
        }

        // Gọi hàm baiTap và in kết quả theo định dạng yêu cầu
        printf("#%d %d\n", t, baiTap(a, N, K));

        free(a); // Giải phóng bộ nhớ đã cấp phát cho mảng input
    }

    return 0; // Kết thúc chương trình
}
