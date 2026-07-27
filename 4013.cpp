#include<iostream>

int N;
int magnets[4][8];
int curTarget[4];
int rotates[4];

using namespace std;

int getLeft(int magnet) {
	int cur = curTarget[magnet];
	return magnets[magnet][(cur - 2 + 8) % 8];
}

int getRight(int magnet) {
	int cur = curTarget[magnet];
	return magnets[magnet][(cur + 2) % 8];
}

void rotateRightMagnet(int curMagnet, int direction) {
	rotates[curMagnet] = direction;

	if (curMagnet == 3)
		return;

	if (getRight(curMagnet) != getLeft(curMagnet + 1))
		rotateRightMagnet(curMagnet + 1, -direction);
}

void rotateLeftMagnet(int curMagnet, int direction) {
	rotates[curMagnet] = direction;

	if (curMagnet == 0)
		return;

	if (getLeft(curMagnet) != getRight(curMagnet - 1))
		rotateLeftMagnet(curMagnet - 1, -direction);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		
		cin >> N;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnets[i][j];
			}
			curTarget[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++)
				rotates[j] = 0;

			int inputMagnet, direction;

			cin >> inputMagnet >> direction;
			inputMagnet--;

			rotateLeftMagnet(inputMagnet, direction);
			rotateRightMagnet(inputMagnet, direction);
			rotates[inputMagnet] = direction;

			for (int j = 0; j < 4; j++)
				curTarget[j] = (curTarget[j] - rotates[j] + 8) % 8;
		}

		int score = 0;

		for (int i = 0; i < 4; i++) {
			if (magnets[i][curTarget[i]] == 1)
				score += (1 << i);
		}

		printf("#%d %d\n", test_case, score);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}