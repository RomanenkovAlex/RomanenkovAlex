#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_BMPFileHeader {
    unsigned short file_type;  // File type always BM which is 0x4D42
    unsigned int file_size;    // Size of the file (in bytes)
    unsigned short reserved1;  // Reserved, always 0
    unsigned short reserved2;  // Reserved, always 0
    unsigned int offset_data;  // Start position of pixel data (bytes from the beginning of the file)
} BMPFILEHEADER, *LPBMPFILEHEADER;


typedef struct _tag_BMPInfoHeader {
    unsigned int size;              // Size of this header (in bytes)
    int width;                      // width of bitmap in pixels
    int height;                     // width of bitmap in pixels
                                    //       (if positive, bottom-up, with origin in lower left corner)
                                    //       (if negative, top-down, with origin in upper left corner)
    unsigned short planes;          // No. of planes for the target device, this is always 1
    unsigned short bit_count;       // No. of bits per pixel
    unsigned int compression;       // 0 or 3 - uncompressed. THIS PROGRAM CONSIDERS ONLY UNCOMPRESSED BMP images
    unsigned int size_image;        // 0 - for uncompressed images
    int x_pixels_per_meter;
    int y_pixels_per_meter;
    unsigned int colors_used;       // No. color indexes in the color table. Use 0 for the max number of colors allowed by bit_count
    unsigned int colors_important;  // No. of colors used for displaying the bitmap. If 0 all colors are required
} BMPINFOHEADER, *LPBMPINFOHEADER;

void read_hex(const char *fin_name, const char *fout_name)
{
    FILE *f_in = fopen(fin_name, "rb");
    FILE *f_out = fopen(fout_name, "wb");
    unsigned char c = 0;
    int i = 0;

    while (!feof(f_in))
    {
        fread(&c, 1, 1, f_in);
        fprintf(f_out, "0x%02x", c);
        if ((++i) & 0xf) // if (++i % 16)
            fputc(' ', f_out);
        else
            fputc('\n', f_out);
    }

    fclose(f_in);
    fclose(f_out);
}

int main()
{
    int h = 0;
    int w = 0;
    
    // BMPFILEHEADER hdr = {
    //     .file_type = 0x4D42,
    //     .file_size = ,
    //     .reserved1 = 0,
    //     .reserved2 = 0,
    //     .offset_data = 
    // };

    // BMPINFOHEADER inf = {
    //     .
    // };

    BMPFILEHEADER hdr;
    BMPINFOHEADER inf;

    FILE *f = fopen("/home/afleksik/Desktop/prog/src/pic_v1.bmp", "rb");

    fread(&hdr, sizeof(hdr), 1, f);
    fread(&inf, sizeof(inf), 1, f);

    printf("filesize = %u\n%dx%d - %u\n", hdr.file_size, inf.height, inf.width, inf.size);

    hdr.offset_data

    fclose(f);

    return 0;
}
