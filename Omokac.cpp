#include<iostream>
#define GAMEBOARD 19

using namespace std;

struct OMOK {
	char style;
	bool check;
};
struct Count {
	int ccount;
	int b_x[GAMEBOARD];
	int b_y[GAMEBOARD];
	int w_x[GAMEBOARD];
	int w_y[GAMEBOARD];
	char R;
};


void Garocheck(OMOK arr[][GAMEBOARD], Count* Rowdol);
void Serocheck(OMOK arr[][GAMEBOARD], Count* Coldol);
void Crosscheck(OMOK arr[][GAMEBOARD], Count* Crossdol);

int main()
{
	OMOK arr[GAMEBOARD][GAMEBOARD];
	Count garorock;
	Count serorock;
	Count crossrock;

	int inputx = -1, inputy = -1;
	bool turn = true;

	for (int i = 0; i < GAMEBOARD; i++)
	{
		for (int j = 0; j < GAMEBOARD; j++)
		{
			arr[i][j].style = '*';
			cout << arr[i][j].style << " ";
			arr[i][j].check = false;

		}
		cout << endl;
	}

	while (true)
	{
		cout << " 좌표를 입력해주세요. : " << endl;
		cin >> inputy >> inputx;

		if ((inputx > 18 || inputx < 0) || (inputy > 18 || inputy < 0))
		{
			cout << " 범위를 넘었습니다. 좌표를 다시 입력해 주세요." << endl;
			continue;
		}

		if (arr[inputy][inputx].check == true)
		{
			cout << " 이미 돌이 놓여져 있습니다. " << endl;
			continue;
		}
		else
		{
			if (turn == true)
			{
				arr[inputy][inputx].style = '@';
				arr[inputy][inputx].check = true;
				turn = false;
			}

			else
			{
				arr[inputy][inputx].style = '#';
				arr[inputy][inputx].check = true;
				turn = true;
			}
		}

		for (int i = 0; i < GAMEBOARD; i++)
		{
			for (int j = 0; j < GAMEBOARD; j++)
			{
				cout << arr[i][j].style << " ";

			}
			cout << endl;
		}

		Garocheck(arr, &garorock);
		Serocheck(arr, &serorock);
		Crosscheck(arr, &crossrock);

		if (garorock.ccount > serorock.ccount)
		{
			if (garorock.ccount > crossrock.ccount)
			{
				if (garorock.R == '@')
				{
					for (int i = 0; i < garorock.ccount; i++)
					{
						cout << " 좌표 : " << garorock.b_y[i] << " , " << garorock.b_x[i] << endl;

					}


					if (garorock.ccount == 3)
					{
						cout << "위에 표시된 좌표에서 3 공격을 합니다." << endl;
					}
					else if (garorock.ccount == 4)
					{

						cout << "위에 표시된 좌표에서 4 공격을 합니다." << endl;
					}
				}
				else
				{
					for (int i = 0; i < garorock.ccount; i++)
					{
						cout << "좌표 : " << garorock.w_y[i] << " , " << garorock.w_x[i] << endl;

					}
					cout << " 연속된 돌의 개수 : " << garorock.R << " 돌 " << garorock.ccount << " 개" << endl;


					if (garorock.ccount == 3)
					{
						cout << "위에 표시된 좌표에서 3 공격을 합니다." << endl;
					}
					else if (garorock.ccount == 4)
					{
						cout << "위에 표시된 좌표에서 4 공격을 합니다." << endl;
					}
				}
			}
			else if (garorock.ccount < crossrock.ccount)
			{
				if (crossrock.R == '@')
				{
					for (int i = 0; i < crossrock.ccount; i++)
					{
						cout << " 좌표 : " << crossrock.b_y[i] << " , " << crossrock.b_x[i] << endl;

					}
					cout << "연속된 돌의 개수 : " << crossrock.R << " 돌 " << crossrock.ccount << " 개" << endl;


					if (crossrock.ccount == 3)
					{
						cout << "위에 표시된 좌표에서 3 공격을 합니다." << endl;
					}
					else if (crossrock.ccount == 4)
					{
						cout << "위에 표시된 좌표에서 4공격을 합니다." << endl;
					}
				}
				else
				{
					for (int i = 0; i < crossrock.ccount; i++)
					{
						cout << " 좌표 : " << crossrock.w_y[i] << " , " << crossrock.w_x[i] << endl;

					}
					cout << " 연속된 돌의 개수 : " << crossrock.R << "  " << crossrock.ccount << " 개" << endl;


					if (crossrock.ccount == 3)
					{
						cout << "위에 표시된 좌표에서 3 공격을 합니다." << endl;
					}
					else if (crossrock.ccount == 4)
					{
						cout << "위에 표시된 좌표에서 4 공격을 합니다." << endl;
					}
				}
			}
		}
		else if (serorock.ccount > garorock.ccount)
		{
			if (serorock.ccount > crossrock.ccount)
			{
				if (serorock.R == '@')
				{
					for (int i = 0; i < serorock.ccount; i++)
					{
						cout << " 좌표 : " << serorock.b_y[i] << " , " << serorock.b_x[i] << endl;

					}
					cout << "연속된 돌의 개수 " << serorock.R << " " << serorock.ccount << " 개" << endl;


					if (serorock.ccount == 3)
					{
						cout << "위에 표시된 좌표에서 3 공격을 합니다." << endl;
					}
					else if (serorock.ccount == 4)
					{
						cout << "위에 표시된 좌표에서 4 공격을 합니다." << endl;
					}
				}
				else
				{
					for (int i = 0; i < serorock.ccount; i++)
					{
						cout << " 좌표 : " << serorock.w_y[i] << " , " << serorock.w_x[i] << endl;

					}
					cout << "연속된 돌의 개수 : " << serorock.R << " " << serorock.ccount << " 개 " << endl;


					if (serorock.ccount == 3)
					{
						cout << "위에 표시된 좌표에서 3 공격을 합니다." << endl;
					}
					else if (serorock.ccount == 4)
					{
						cout << "위에 표시된 좌표에서 4 공격을 합니다." << endl;
					}
				}
			}
			else
			{
				if (crossrock.R == '@')
				{
					for (int i = 0; i < crossrock.ccount; i++)
					{
						cout << " 좌표 : " << crossrock.b_y[i] << " , " << crossrock.b_x[i] << endl;

					}
					cout << "연속된 돌의 개수 : " << crossrock.R << " " << crossrock.ccount << " 개 " << endl;


					if (crossrock.ccount == 3)
					{
						cout << "위에 표시된 좌표에서 3 공격을 합니다." << endl;
					}
					else if (crossrock.ccount == 4)
					{
						cout << "위에 표시된 좌표에서 4 공격을 합니다." << endl;
					}
				}
				else
				{
					for (int i = 0; i < crossrock.ccount; i++)
					{
						cout << "좌표 : " << crossrock.w_y[i] << " , " << crossrock.w_x[i] << endl;

					}
					cout << " 연속된 돌의 개수  : " << crossrock.R << " " << crossrock.ccount << " 개" << endl;


					if (crossrock.ccount == 3)
					{
						cout << "위에 표시된 좌표에서 3 공격을 합니다." << endl;
					}
					else if (crossrock.ccount == 4)
					{
						cout << "위에 표시된 좌표에서 4 공격을 합니다." << endl;
					}
				}
			}
		}
		else if (garorock.ccount == serorock.ccount && garorock.ccount == crossrock.ccount)
		{
			cout << " 가로 세로 대각선으로 연속된 돌의 개수가 같습니다. - " << garorock.ccount << " 개" << endl;

		}
	}

}

void Garocheck(OMOK arr[][GAMEBOARD], Count* Rowdol)
{
	int p_count = 0;
	int x[GAMEBOARD];
	int y[GAMEBOARD];
	int xindex = 0;
	int yindex = 0;

	for (int i = 0; i < GAMEBOARD; i++)
	{
		for (int j = 0; j < GAMEBOARD; j++)
		{
			if (arr[i][j].style == '@')
			{
				for (int k = j; arr[i][k].style == '@'; k++)
				{
					p_count++;
					x[xindex] = k;
					y[yindex] = i;
					xindex++;
					yindex++;
					if (arr[i][k + 1].style == '*' && arr[i][k + 2].style == '@')
					{
						k++;
						j++;
					}
					j++;
				}
				if (p_count > Rowdol->ccount)
				{
					Rowdol->ccount = p_count;

					for (int u = 0; u < p_count; u++)
					{
						Rowdol->b_x[u] = x[u];
						Rowdol->b_y[u] = y[u];
					}
					Rowdol->R = '@';
				}
			}
			p_count = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD; j++)
		{
			if (arr[i][j].style == '#')
			{
				for (int k = j; arr[i][k].style == '#'; k++)
				{
					p_count++;
					x[xindex] = j;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[i][k + 1].style == '*' && arr[i][k + 2].style == '#')
					{
						k++;
						j++;
					}
					j++;
				}
				if (p_count > Rowdol->ccount)
				{
					Rowdol->ccount = p_count;
					for (int u = 0; u < p_count; u++)
					{
						Rowdol->w_x[u] = x[u];
						Rowdol->w_y[u] = y[u];
					}
					Rowdol->R = '#';
				}
			}
			p_count = 0;
		}
	}
}
void Serocheck(OMOK arr[][GAMEBOARD], Count* Coldol)
{
	int nowcount = 0;
	int x[GAMEBOARD];
	int y[GAMEBOARD];
	int xindex = 0;
	int yindex = 0;


	for (int i = 0; i < GAMEBOARD; i++)
	{
		for (int j = 0; j < GAMEBOARD; j++)
		{
			if (arr[j][i].style == '@')
			{
				for (int k = j; arr[k][i].style == '@'; k++)
				{
					nowcount++;
					x[xindex] = i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][i].style == '*' && arr[k + 2][i].style == '@')
					{
						k++;
						j++;
					}
					j++;

					if (nowcount > Coldol->ccount)
					{
						Coldol->ccount = nowcount;
						for (int u = 0; u < nowcount; u++)
						{
							Coldol->b_x[u] = x[u];
							Coldol->b_y[u] = y[u];
						}
						Coldol->R = '@';
					}
				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD; j++)
		{
			if (arr[j][i].style == '#')
			{
				for (int k = j; arr[k][i].style == '#'; k++)
				{
					nowcount++;
					x[xindex] = i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][i].style == '*' && arr[k + 2][i].style == '#')
					{
						k++;
						j++;
					}
					j++;
					if (nowcount > Coldol->ccount)
					{
						Coldol->ccount = nowcount;
						for (int u = 0; u < nowcount; u++)
						{
							Coldol->w_x[u] = x[u];
							Coldol->w_y[u] = y[u];
						}
						Coldol->R = '#';
					}
				}
			}
			nowcount = 0;
		}
	}
}
void Crosscheck(OMOK arr[][GAMEBOARD], Count* Crossdol)
{
	int nowcount = 0;
	int x[GAMEBOARD];
	int y[GAMEBOARD];
	int xindex = 0;
	int yindex = 0;

	for (int i = 0; i < GAMEBOARD; i++)
	{
		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[j][j + i].style == '@')
			{
				for (int k = j; arr[k][k + i].style == '@'; k++)
				{
					nowcount++;
					x[xindex] = k + i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][k + i + 1].style == '*' && arr[k + 2][k + i + 2].style == '@')
					{
						k++;
						j++;
					}
					j++;
					if (nowcount > Crossdol->ccount)
					{
						Crossdol->ccount = nowcount;
						for (int u = 0; u < nowcount; u++)
						{
							Crossdol->b_x[u] = x[u];
							Crossdol->b_y[u] = y[u];
						}
						Crossdol->R = '@';
					}
				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[j][j + i].style == '#')
			{
				for (int k = j; arr[k][k + i].style == '#'; k++)
				{
					nowcount++;
					x[xindex] = k + i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][k + i + 1].style == '*' && arr[k + 2][k + i + 2].style == '#')
					{
						k++;
						j++;
					}
					j++;
					if (nowcount > Crossdol->ccount)
					{
						Crossdol->ccount = nowcount;
						for (int u = 0; u < nowcount; u++)
						{
							Crossdol->w_x[u] = x[u];
							Crossdol->w_y[u] = y[u];
						}
						Crossdol->R = '#';
					}
				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}
	}

	for (int i = 1; i < GAMEBOARD; i++)
	{
		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[i + j][j].style == '@')
			{
				for (int k = j; arr[i + k][k].style == '@'; k++)
				{
					nowcount++;
					x[xindex] = k;
					y[yindex] = k + i;
					xindex++;
					yindex++;
					if (arr[i + k + 1][k + 1].style == '*' && arr[i + k + 2][k + 2].style == '@')
					{
						k++;
						j++;
					}
					j++;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->b_x[u] = x[u];
						Crossdol->b_y[u] = y[u];
					}
					Crossdol->R = '@';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[i + j][j].style == '#')
			{
				for (int k = j; arr[i + k][k].style == '#'; k++)
				{
					nowcount++;
					x[xindex] = k;
					y[yindex] = k + i;
					xindex++;
					yindex++;
					if (arr[i + k + 1][k + 1].style == '*' && arr[i + k + 2][k + 2].style == '#')
					{
						k++;
						j++;
					}
					j++;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->w_x[u] = x[u];
						Crossdol->w_y[u] = y[u];
					}
					Crossdol->R = '#';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}
	}

	for (int i = GAMEBOARD - 1; i >= 0; i--)
	{
		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[j][i - j].style == '@')
			{
				for (int k = j; arr[k][i - k].style == '@'; k++)
				{
					nowcount++;
					x[xindex] = k - i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][i - k - 1].style == '*' && arr[k + 2][i - k - 2].style == '@')
					{
						k++;
						j++;
					}
					j++;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->b_x[u] = x[u];
						Crossdol->b_y[u] = y[u];
					}
					Crossdol->R = '@';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[j][i - j].style == '#')
			{
				for (int k = j; arr[k][i - k].style == '#'; k++)
				{
					nowcount++;
					x[xindex] = k - i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][i - k - 1].style == '*' && arr[k + 2][i - k - 2].style == '#')
					{
						k++;
						j++;
					}
					j++;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->w_x[u] = x[u];
						Crossdol->w_y[u] = y[u];
					}
					Crossdol->R = '#';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}
	}
	for (int i = 1; i < GAMEBOARD; i++)
	{
		for (int j = GAMEBOARD - 1; j >= i; j--)
		{
			if (arr[i + 18 - j][j].style)
			{
				for (int k = j; arr[i + 18 - k][k].style == '@'; k--)
				{
					nowcount++;
					x[xindex] = k;
					y[yindex] = i + 18 - k;
					xindex++;
					yindex++;
					if (arr[i + 18 - k + 1][k - 1].style == '*' && arr[i + 18 - k + 2][k - 2].style == '@')
					{
						k--;
						j--;
					}
					j--;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->b_x[u] = x[u];
						Crossdol->b_y[u] = y[u];
					}
					Crossdol->R = '@';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = GAMEBOARD - 1; j >= i; j--)
		{
			if (arr[i + 18 - j][j].style)
			{
				for (int k = j; arr[i + 18 - k][k].style == '#'; k--)
				{
					nowcount++;
					x[xindex] = k;
					y[yindex] = i + 18 - k;
					xindex++;
					yindex++;
					if (arr[i + 18 - k + 1][k - 1].style == '*' && arr[i + 18 - k + 2][k - 2].style == '#')
					{
						k--;
						j--;
					}
					j--;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->w_x[u] = x[u];
						Crossdol->w_y[u] = y[u];
					}
					Crossdol->R = '#';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

	}
}