#include <stdio.h>
#include <stdlib.h>

unsigned char S[256] = {                   // SBOX
	0x63,0x7C,0x77,0x7B,0xF2,0x6B,0x6F,0xC5,0x30,0x01,0x67,0x2B,0xFE,0xD7,0xAB,0x76,
	0xCA,0x82,0xC9,0x7D,0xFA,0x59,0x47,0xF0,0xAD,0xD4,0xA2,0xAF,0x9C,0xA4,0x72,0xC0,    
	0xB7,0xFD,0x93,0x26,0x36,0x3F,0xF7,0xCC,0x34,0xA5,0xE5,0xF1,0x71,0xD8,0x31,0x15,    
	0x04,0xC7,0x23,0xC3,0x18,0x96,0x05,0x9A,0x07,0x12,0x80,0xE2,0xEB,0x27,0xB2,0x75,    
	0x09,0x83,0x2C,0x1A,0x1B,0x6E,0x5A,0xA0,0x52,0x3B,0xD6,0xB3,0x29,0xE3,0x2F,0x84,    
	0x53,0xD1,0x00,0xED,0x20,0xFC,0xB1,0x5B,0x6A,0xCB,0xBE,0x39,0x4A,0x4C,0x58,0xCF,    
	0xD0,0xEF,0xAA,0xFB,0x43,0x4D,0x33,0x85,0x45,0xF9,0x02,0x7F,0x50,0x3C,0x9F,0xA8,    
	0x51,0xA3,0x40,0x8F,0x92,0x9D,0x38,0xF5,0xBC,0xB6,0xDA,0x21,0x10,0xFF,0xF3,0xD2,    
	0xCD,0x0C,0x13,0xEC,0x5F,0x97,0x44,0x17,0xC4,0xA7,0x7E,0x3D,0x64,0x5D,0x19,0x73,    
	0x60,0x81,0x4F,0xDC,0x22,0x2A,0x90,0x88,0x46,0xEE,0xB8,0x14,0xDE,0x5E,0x0B,0xDB,    
	0xE0,0x32,0x3A,0x0A,0x49,0x06,0x24,0x5C,0xC2,0xD3,0xAC,0x62,0x91,0x95,0xE4,0x79,    
	0xE7,0xC8,0x37,0x6D,0x8D,0xD5,0x4E,0xA9,0x6C,0x56,0xF4,0xEA,0x65,0x7A,0xAE,0x08,    
	0xBA,0x78,0x25,0x2E,0x1C,0xA6,0xB4,0xC6,0xE8,0xDD,0x74,0x1F,0x4B,0xBD,0x8B,0x8A,    
	0x70,0x3E,0xB5,0x66,0x48,0x03,0xF6,0x0E,0x61,0x35,0x57,0xB9,0x86,0xC1,0x1D,0x9E,    
	0xE1,0xF8,0x98,0x11,0x69,0xD9,0x8E,0x94,0x9B,0x1E,0x87,0xE9,0xCE,0x55,0x28,0xDF,   
	0x8C,0xA1,0x89,0x0D,0xBF,0xE6,0x42,0x68,0x41,0x99,0x2D,0x0F,0xB0,0x54,0xBB,0x16
	};
unsigned char IS[256] =  {                 // Inverse SBOX
	0x52,0x09,0x6a,0xd5,0x30,0x36,0xa5,0x38,0xbf,0x40,0xa3,0x9e,0x81,0xf3,0xd7,0xfb,
	0x7c,0xe3,0x39,0x82,0x9b,0x2f,0xff,0x87,0x34,0x8e,0x43,0x44,0xc4,0xde,0xe9,0xcb,
	0x54,0x7b,0x94,0x32,0xa6,0xc2,0x23,0x3d,0xee,0x4c,0x95,0x0b,0x42,0xfa,0xc3,0x4e,
	0x08,0x2e,0xa1,0x66,0x28,0xd9,0x24,0xb2,0x76,0x5b,0xa2,0x49,0x6d,0x8b,0xd1,0x25,
	0x72,0xf8,0xf6,0x64,0x86,0x68,0x98,0x16,0xd4,0xa4,0x5c,0xcc,0x5d,0x65,0xb6,0x92,
	0x6c,0x70,0x48,0x50,0xfd,0xed,0xb9,0xda,0x5e,0x15,0x46,0x57,0xa7,0x8d,0x9d,0x84,
	0x90,0xd8,0xab,0x00,0x8c,0xbc,0xd3,0x0a,0xf7,0xe4,0x58,0x05,0xb8,0xb3,0x45,0x06,
	0xd0,0x2c,0x1e,0x8f,0xca,0x3f,0x0f,0x02,0xc1,0xaf,0xbd,0x03,0x01,0x13,0x8a,0x6b,
	0x3a,0x91,0x11,0x41,0x4f,0x67,0xdc,0xea,0x97,0xf2,0xcf,0xce,0xf0,0xb4,0xe6,0x73,
	0x96,0xac,0x74,0x22,0xe7,0xad,0x35,0x85,0xe2,0xf9,0x37,0xe8,0x1c,0x75,0xdf,0x6e,
	0x47,0xf1,0x1a,0x71,0x1d,0x29,0xc5,0x89,0x6f,0xb7,0x62,0x0e,0xaa,0x18,0xbe,0x1b,
	0xfc,0x56,0x3e,0x4b,0xc6,0xd2,0x79,0x20,0x9a,0xdb,0xc0,0xfe,0x78,0xcd,0x5a,0xf4,
	0x1f,0xdd,0xa8,0x33,0x88,0x07,0xc7,0x31,0xb1,0x12,0x10,0x59,0x27,0x80,0xec,0x5f,
	0x60,0x51,0x7f,0xa9,0x19,0xb5,0x4a,0x0d,0x2d,0xe5,0x7a,0x9f,0x93,0xc9,0x9c,0xef,
	0xa0,0xe0,0x3b,0x4d,0xae,0x2a,0xf5,0xb0,0xc8,0xeb,0xbb,0x3c,0x83,0x53,0x99,0x61,
	0x17,0x2b,0x04,0x7e,0xba,0x77,0xd6,0x26,0xe1,0x69,0x14,0x63,0x55,0x21,0x0c,0x7d
	};	 
static const int RC[10] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};
void KeyExpansion(unsigned char K[16],unsigned char k[11][16]){
	int i,j;
	for(i = 0; i < 16; i++)
		k[0][i] = K[i];
	for(i = 1; i < 11; i++)
	{
	    k[i][0] = k[i-1][0] ^ S[k[i-1][13]] ^ RC[i-1];
		k[i][1] = k[i-1][1] ^ S[k[i-1][14]];
		k[i][2] = k[i-1][2] ^ S[k[i-1][15]];
		k[i][3] = k[i-1][3] ^ S[k[i-1][12]];
		for(j = 0; j < 12; j++){
			k[i][4+j] = k[i-1][4+j] ^ k[i][j];
		}
	}
}
void AddRoundKey(unsigned char *state, unsigned char *RoundKey){
	int i;
    for (i = 0;i < 16;i++)
   		state[i] ^= RoundKey[i] ; 
}
void SubBytes(unsigned char *input){  // SBOX�N�� 
	int i ;     
	for(i = 0; i < 16; i++)
		input[i] = S[input[i]] ;
}
void InvSubBytes(unsigned char *input){    //SBOX�f�N�� 
	int i;
	for(i = 0; i < 16; i++)
		input[i] = IS[input[i]] ;
}
void ShiftRows(unsigned char *a){  
	unsigned char b[16] ;
	int i;
	b[0] = a[0] ;	b[4] = a[4] ;	b[8] = a[8]  ;	b[12] = a[12];
	b[1] = a[5] ;	b[5] = a[9] ;	b[9] = a[13] ;	b[13] = a[1] ;
	b[2] = a[10];	b[6] = a[14];	b[10] = a[2] ;	b[14] = a[6] ;
	b[3] = a[15];	b[7] = a[3] ;	b[11] = a[7] ;	b[15] = a[11];
	for(i = 0; i < 16; i++)
		a[i] = b[i];
} 
void InvShiftRows(unsigned char *a){   
	unsigned char b[16] ;
	int i;
	b[0] = a[0] ;	b[4] = a[4] ;	b[8] = a[8]  ;	b[12] = a[12];
	b[1] = a[13];	b[5] = a[1] ;	b[9] = a[5]  ;	b[13] = a[9] ;
	b[2] = a[10];	b[6] = a[14];	b[10] = a[2] ;	b[14] = a[6] ;
	b[3] = a[7] ;	b[7] = a[11];	b[11] = a[15];	b[15] = a[3] ;
	for(i = 0 ; i < 16 ; i ++ )
		a[i] = b[i] ;
} 
unsigned char Mul(unsigned char a, unsigned char b){
    unsigned char p = 0;
    unsigned char counter;
    unsigned char hi_bit_set;
    for (counter = 0; counter < 8; counter++)
    {
        if ((b & 1) == 1)
            p ^= a;
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set == 0x80)
            a ^= 0x1b;
        b >>= 1;
    }
    return p;
}
void MixColumns( unsigned char *a ){       //MixColumns
	unsigned char b[16] ;
	b[0] = Mul(0x02,a[0]) ^ Mul(0x03,a[1]) ^ a[2] ^ a[3];
	b[1] = Mul(0x02,a[1]) ^ Mul(0x03,a[2]) ^ a[3] ^ a[0];
	b[2] = Mul(0x02,a[2]) ^ Mul(0x03,a[3]) ^ a[0] ^ a[1];
	b[3] = Mul(0x02,a[3]) ^ Mul(0x03,a[0]) ^ a[1] ^ a[2];
	b[4] = Mul(0x02,a[4]) ^ Mul(0x03,a[5]) ^ a[6] ^ a[7];
	b[5] = Mul(0x02,a[5]) ^ Mul(0x03,a[6]) ^ a[7] ^ a[4];
	b[6] = Mul(0x02,a[6]) ^ Mul(0x03,a[7]) ^ a[4] ^ a[5];
	b[7] = Mul(0x02,a[7]) ^ Mul(0x03,a[4]) ^ a[5] ^ a[6];
	b[8] = Mul(0x02,a[8]) ^ Mul(0x03,a[9]) ^ a[10] ^ a[11];
	b[9] = Mul(0x02,a[9]) ^ Mul(0x03,a[10]) ^ a[11] ^ a[8];
	b[10] = Mul(0x02,a[10]) ^ Mul(0x03,a[11]) ^ a[8] ^ a[9];
	b[11] = Mul(0x02,a[11]) ^ Mul(0x03,a[8]) ^ a[9] ^ a[10];
	b[12] = Mul(0x02,a[12]) ^ Mul(0x03,a[13]) ^ a[14] ^ a[15];
	b[13] = Mul(0x02,a[13]) ^ Mul(0x03,a[14]) ^ a[15] ^ a[12];
	b[14] = Mul(0x02,a[14]) ^ Mul(0x03,a[15]) ^ a[12] ^ a[13];
	b[15] = Mul(0x02,a[15]) ^ Mul(0x03,a[12]) ^ a[13] ^ a[14];
	int i;
	for(i = 0 ; i < 16 ; i ++ )
		a[i] = b[i] ;
}
void InvMixColumns(unsigned char *a){      //Inverse MixColumns
	unsigned char b[16];
	b[0] = Mul(0x0E, a[0]) ^ Mul(0x0B, a[1]) ^ Mul(0x0D, a[2]) ^ Mul(0x09, a[3]);
	b[1] = Mul(0x0E, a[1]) ^ Mul(0x0B, a[2]) ^ Mul(0x0D, a[3]) ^ Mul(0x09, a[0]);
	b[2] = Mul(0x0E, a[2]) ^ Mul(0x0B, a[3]) ^ Mul(0x0D, a[0]) ^ Mul(0x09, a[1]);
	b[3] = Mul(0x0E, a[3]) ^ Mul(0x0B, a[0]) ^ Mul(0x0D, a[1]) ^ Mul(0x09, a[2]);
	b[4] = Mul(0x0E, a[4]) ^ Mul(0x0B, a[5]) ^ Mul(0x0D, a[6]) ^ Mul(0x09, a[7]);
	b[5] = Mul(0x0E, a[5]) ^ Mul(0x0B, a[6]) ^ Mul(0x0D, a[7]) ^ Mul(0x09, a[4]);
	b[6] = Mul(0x0E, a[6]) ^ Mul(0x0B, a[7]) ^ Mul(0x0D, a[4]) ^ Mul(0x09, a[5]);
	b[7] = Mul(0x0E, a[7]) ^ Mul(0x0B, a[4]) ^ Mul(0x0D, a[5]) ^ Mul(0x09, a[6]);
	b[8] = Mul(0x0E, a[8]) ^ Mul(0x0B, a[9]) ^ Mul(0x0D, a[10]) ^ Mul(0x09, a[11]);
	b[9] = Mul(0x0E, a[9]) ^ Mul(0x0B, a[10]) ^ Mul(0x0D, a[11]) ^ Mul(0x09, a[8]);
	b[10] = Mul(0x0E, a[10]) ^ Mul(0x0B, a[11]) ^ Mul(0x0D, a[8]) ^ Mul(0x09, a[9]);
	b[11] = Mul(0x0E, a[11]) ^ Mul(0x0B, a[8]) ^ Mul(0x0D, a[9]) ^ Mul(0x09, a[10]);
	b[12] = Mul(0x0E, a[12]) ^ Mul(0x0B, a[13]) ^ Mul(0x0D, a[14]) ^ Mul(0x09, a[15]);
	b[13] = Mul(0x0E, a[13]) ^ Mul(0x0B, a[14]) ^ Mul(0x0D, a[15]) ^ Mul(0x09, a[12]);
	b[14] = Mul(0x0E, a[14]) ^ Mul(0x0B, a[15]) ^ Mul(0x0D, a[12]) ^ Mul(0x09, a[13]);
	b[15] = Mul(0x0E, a[15]) ^ Mul(0x0B, a[12]) ^ Mul(0x0D, a[13]) ^ Mul(0x09, a[14]);
	int i;
	for (i = 0; i < 16; i++)
		a[i] = b[i];
}
//AES�[�K 
void AES(unsigned char plaintext[16], unsigned char ciphertext[16], unsigned char k[11][16],int Round) {
	int i, round;
	for(i = 0; i < 16; i++)
		ciphertext[i] = plaintext[i];
	AddRoundKey(ciphertext,k[0]);
	for(round = 1; round < Round; round++){
		SubBytes(ciphertext);
		ShiftRows(ciphertext);
		MixColumns(ciphertext);
		AddRoundKey(ciphertext, k[round]);
	}
	SubBytes(ciphertext);
	ShiftRows(ciphertext);
	AddRoundKey(ciphertext, k[Round]);
}
//Aes�ѱK 
void RAES(unsigned char plaintext[16], unsigned char ciphertext[16], unsigned char k[11][16], int Round){
	int i, round;
	for(i = 0; i < 16; i++){ 
		plaintext[i] = ciphertext[i];}    
	AddRoundKey(plaintext, k[Round]);       
	InvShiftRows(plaintext);               
	InvSubBytes(plaintext);
	for(round = 9; round > 0; round--){
		AddRoundKey(plaintext, k[round]);
		InvMixColumns(plaintext);
		InvShiftRows(plaintext);
		InvSubBytes(plaintext);
	}
	AddRoundKey(plaintext,k[0]);
}

int main(int argc, char *argv[]) {
	FILE *out = fopen("out.txt", "w+");
	int i;
	unsigned char k[11][16];
	unsigned char ciphertext1[16] = {0x5a ,0x3d ,0xd1, 0x41 ,0x31 ,0x97 ,0x5a ,0xf2 ,0x1e ,0x22 ,0xee ,0x67 ,0x12 ,0xdd ,0xaa ,0x62};
	unsigned char ciphertext2[16] = {0xe6, 0x1b, 0x1d, 0x18, 0x68, 0x36, 0xd2, 0x5a, 0xc2, 0x4d, 0x3b, 0x47, 0x4a, 0x19, 0x5a, 0x72};  //�K��
	unsigned char plaintext[32]={};
	unsigned char Key[16]={0x48, 0x6A, 0x00, 0x4E, 0x29, 0x00, 0x74, 0x67, 0x5A , 0x00 ,0x39 ,0x77 ,0x72 ,0x63, 0x00 ,0x6D};
	//2 5 9 14
	Key[2] = 0x25;
	Key[5] = 0x36;
	Key[9] = 0x7D;
	Key[14] = 0x2A;
	KeyExpansion(Key, k);
	RAES(plaintext, ciphertext1, k, 10);
	RAES(plaintext+16, ciphertext2, k, 10);
	fprintf(out, "%s     \n%c %c %c %c", plaintext, Key[2], Key[5], Key[9], Key[14]);
	/*The code How I Find the correct plaintext
	unsigned char a, b, c, d;
	for(a = 0x00; a < 0x7E; a++){
		for(b = 0x00;b < 0x7E; b++){
			for(c = 0x00; c < 0x7E; c++){
				for(d = 0x00; d < 0x7E; d++){
					Key[2] = a;
					Key[5] = b;
					Key[9] = c;
					Key[14] = d;
					KeyExpansion(Key, k);
					RAES(plaintext, ciphertext1, k, 10);
					if(plaintext[0] == 0x4E && plaintext[1] == 0x61 ){
						RAES(plaintext+16, ciphertext2, k, 10);
						if(plaintext[2] < 0x7e && plaintext[3] < 0x7e && plaintext[4] < 0x7e && plaintext[5] < 0x7e && plaintext[6] < 0x7e && plaintext[7] < 0x7e && plaintext[8] < 0x7e){
							printf("%s     \n%c %c %c %c \n",plaintext, a, b, c, d);	
						}
					}
				}
			}
		}
	}
	*/
	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    	
}

/*	reference:
	https://cryptii.com/pipes/base64-to-hex
	https://blog.csdn.net/weixin_56375405/article/details/123896872
	https://cboard.cprogramming.com/c-programming/87805-[tutorial]-implementing-advanced-encryption-standard.html
*/