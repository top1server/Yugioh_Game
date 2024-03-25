#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

// Kích thước cửa sổ
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Vị trí đích
const int DEST_X = 200;
const int DEST_Y = 200;

// Hàm chính
int main(int argc, char* args[]) {
    // Khởi tạo SDL và kiểm tra lỗi
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Tạo cửa sổ
    SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Tạo renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Tải hình ảnh lên texture
    SDL_Surface* surface = IMG_Load("images/menu/pvp.png");
    if (surface == NULL) {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == NULL) {
        printf("Texture could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Vị trí ban đầu của texture
    SDL_Rect textureRect = { 200, 0, 100, 100 }; // Vị trí và kích thước texture ban đầu

    // Vòng lặp chính
    int quit = 0;
    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Xóa renderer
        SDL_RenderClear(renderer);

        // Tính toán khoảng cách từ vị trí hiện tại đến vị trí đích
        int dx = DEST_X - textureRect.x;
        int dy = DEST_Y - textureRect.y;
        int distance = sqrt(dx * dx + dy * dy);

        // Nếu chưa đến vị trí đích, di chuyển texture
        if (distance > 1) { // Sử dụng 1 pixel làm ngưỡng dừng lại
            // Tính toán bước di chuyển
            float stepX = dx / (float)distance;
            float stepY = dy / (float)distance;

            // Cập nhật vị trí của texture
            textureRect.x += (int)(stepX * 2); // Điều chỉnh tốc độ di chuyển bằng cách thay đổi hằng số 2
            textureRect.y += (int)(stepY * 2); // Điều chỉnh tốc độ di chuyển bằng cách thay đổi hằng số 2
        }

        // Vẽ texture
        SDL_RenderCopy(renderer, texture, NULL, &textureRect);

        // Cập nhật cửa sổ
        SDL_RenderPresent(renderer);

        // Đợi một chút để giảm tốc độ di chuyển
        SDL_Delay(2);
    }

    // Giải phóng bộ nhớ và thoát SDL
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
