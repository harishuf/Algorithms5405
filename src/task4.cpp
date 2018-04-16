#include "task4.hpp"
#include<iostream>
#include<stdio.h>
#include <cstring>
#include <vector>

int abs(int t){
    return t<0? -t : t;
}

int max(int a, int b){
    return a<b? b : a;
}

int min(int a, int b){
    return a<b? a : b;
}

void fill(int* arr, int len){
    for(int t = 0; t<len; t++){
        arr[t] = -1;
    }
}

void arrcopy(int* src, int* dst, int len){
    for(int t = 0; t<len; t++){
        dst[t] = src[t];
    }
}

void task4(int num_row, int num_column, std::vector<std::vector<int> >& height, int C) 
{
        int S[num_column][C+1];
        int start_idx[num_column];
	int upper_limit[num_column];

        int max_area = 0;
        int x1 = 1;
        int y1 = 1;
        int x2 = 1;
        int y2 = 1;

        for(int i=0; i <=C; i++){
            upper_limit[i] = -1;
            for(int l=0;l<num_column;l++){
               	  upper_limit[l] = -1;
		 start_idx[l] =0 ;
		 S[l][i] = -1;
            }
        }

		for (int i = 0; i < num_row; i++) {
            int ip_row[num_column];
			for (int l = 0; l < num_column; l++) {
				ip_row[l] = height[i][l];
				//scanf("%d", &ip_row[l]);
				if (ip_row[l] <= upper_limit[l]) {
					if (abs(ip_row[l] - upper_limit[l]) <= C) {
						S[l][abs(ip_row[l] - upper_limit[l])] = i;
					} else {
						int current_upper_limit = upper_limit[l];
						int new_upper_limit = ip_row[l];
						int first_idx = C + 100;
						for (int c = 0; c <= C; c++) {
							if (abs((current_upper_limit - c) - ip_row[l]) <= C && S[l][c] != -1 && first_idx==C+100) {
								new_upper_limit = current_upper_limit - c;
								first_idx = c;
							}
						}

						start_idx[l] = i;
						upper_limit[l] = new_upper_limit;
						start_idx[l] = i;
      
                        int final_idx = -1;
                        for (int c = 0; first_idx <= C && c <= C; c++) {
                            if (c < first_idx) {
                                if (S[l][c] > final_idx) {
                                    final_idx = S[l][c];
                                    start_idx[l] = S[l][c] + 1;
                                }
                            }
                        }
                        
                        for (int c = 0; first_idx <= C && c <= C; c++) {
                            if (c >= first_idx) {
                                if (S[l][c] > final_idx) {
                                    S[l][c - first_idx] = S[l][c];
                                } else {
                                    S[l][c - first_idx] = -1;
                                }
                                S[l][c] = -1;
                            }
                        }

						if(first_idx == C+100) {
                            fill(S[l], C+1);
							start_idx[l] = i;
						}
						S[l][new_upper_limit - ip_row[l]] = i;
					}
                } else {
					int current_upper_limit = upper_limit[l];
					upper_limit[l] = ip_row[l];
					if (abs(ip_row[l] - upper_limit[l]) > C) {
						for(int t = 0; t<=C; t++){
                            S[l][t] = -1;
                        }
						S[l][0] = i;
						start_idx[l] = i;
					} else {
                        int final_idx = -1;
						int new_upper_limit = start_idx[l];
						for (int c = C; c >= 0; c--) {
							if (abs(ip_row[l] - (current_upper_limit - c)) <= C)
								continue;
							if (S[l][c] > final_idx) {
								final_idx = S[l][c];
								new_upper_limit = max(new_upper_limit, S[l][c] + 1);
							}
							S[l][c] = -1;
						}

						for (int c = C; c >= 0; c--) {
							if (abs(ip_row[l] - (current_upper_limit - c)) > C)
								continue;
							if (S[l][c] <= final_idx) {
								S[l][c] = -1;
							}
						}

                        for (int c = C; c >= 0; c--) {
							if (abs(ip_row[l] - (current_upper_limit - c)) > C)
								continue;
							if (S[l][c] > final_idx) {
								S[l][ip_row[l] - (current_upper_limit - c)] = S[l][c];
								S[l][c] = -1;
							}
						}
						start_idx[l] = new_upper_limit;
						S[l][0] = i;
					}
				}
			}

			for (int j = 0; j < num_column; j++) {
                int temp_col[C + 1];
				int new_upper_limit = ip_row[j];
                int running_max = upper_limit[j];
                int minimum_value = ip_row[j];
				int height = start_idx[j];

                arrcopy(S[j], temp_col, C + 1);

				for (int l = j; l >= 0; l--) {
					height = max(height, start_idx[l]);

					if (abs(new_upper_limit - ip_row[l]) > C || abs(ip_row[l] - minimum_value) > C) {
						break;
					}
					
					new_upper_limit = max(new_upper_limit, ip_row[l]);
					minimum_value = min(minimum_value, ip_row[l]);

					for (int c1 = C; c1 >=0; c1--) {
						if (S[l][c1] != -1 && S[l][c1] >= height) {
							for (int c = 0; c < C + 1; c++) {
								if (temp_col[c] != -1 && temp_col[c] >= height) {
									if (abs((running_max - c) - (upper_limit[l] - c1)) > C) {
										height = max(height, temp_col[c] + 1);
										height = max(height, S[l][c1] + 1);
									}
								}
							}
						}
					}

					int tmp_upper = new_upper_limit;

					for (int c = 0; c <= C; c++) {
						if (S[l][c] >= height){
							tmp_upper = max(tmp_upper, upper_limit[l] - c);
                        }
					}
                    
                    for (int c = C; c >= 0; c--) {
						if (temp_col[c] >= height){
							tmp_upper = max(tmp_upper, running_max - c);
                        }
					}

					for (int c = C; c >= 0; c--) {
						if (running_max - c <= tmp_upper && tmp_upper - running_max - c <= C) {
							if (temp_col[c] >= height) {
								temp_col[tmp_upper - (running_max - c)] = temp_col[c];
							}
						} else {
							temp_col[c] = -1;
						}
					}

                    for (int c = C; c >= 0; c--) {
                        if (S[l][c] >= height) {
							if (upper_limit[l] - c <= tmp_upper && tmp_upper - (upper_limit[l] - c) <= C) {
								temp_col[tmp_upper - (upper_limit[l] - c)] = max(temp_col[tmp_upper - (upper_limit[l] - c)], S[l][c]);
							}
						}
                    }
					running_max = tmp_upper;
					int area = (i + 1 - height) * (j - l + 1);

					if (area > max_area) {
						max_area = area;
						x2 = i + 1;
						y2 = j + 1;
						x1 = height + 1;
						y1 = y2 - (j - l + 1) + 1;
					}
				}
			}
		}
		std::cout << x1 << " "  << y1 << " " <<  x2 << " " <<  y2;
		//printf("%d %d %d %d", x1, y1, x2, y2);
}
