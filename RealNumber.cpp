#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//bool approx_equal(float x, float y)
//{
//	if (x < y + FLT_EPSILON && x > y - FLT_EPSILON)
//	{
//		return true;
//	}
//	else {
//		return false;
//	}
//}

bool approx_equal(float x, float y, const float epsilon = FLT_EPSILON)
{
	if (x == 0) return fabsf(y) < epsilon;
	if (x == 0) return fabsf(y) < epsilon;
	//return fabsf(x-y) / max ( fabsf(x), fabsf(y)) <= epsilon;
	return fabsf(x / y - 1.0f) < epsilon;
}

void main()
{
	//実数型の表現範囲（絶対値）
	//①float型で表すことのできる最大値を変数maxに代入する
	float max = 0.0f;

	printf("float型で表すことのできる最大値は%e\n", 3.40282346e+38f);	//指数形式で表示

	printf( "float型で表すことのできる最大値は%e\n", FLT_MAX );	//指数形式で表示

	//②float型で表すことのできる最小絶対値（ゼロに最も近い数）を変数minに代入する
	float min = 0.0f;

	printf("float型で表すことのできる最小絶対値（ゼロに最も近い数）は%e\n", 1.175494351e-38f);	//指数形式で表示

	printf( "float型で表すことのできる最小絶対値（ゼロに最も近い数）は%e\n", FLT_MIN );	//指数形式で表示

	//実数型の指数表記
	//③星が収縮してブラックホールになる半径をシュヴァルツシルト半径（Schwarzschild radius）と言い、次式で与えられる。
	// r = 2GM/c^2
	//ここで、rはシュヴァルツシルト半径、Mは質量、Gは万有引力定数、cは光の速度である。
	//地球のシュヴァルツシルト半径を求める。（MKS単位系を用いること）
	/*　MKS単位系
	　　距離　M　メートル
	  　重さ　K　キログラム
	  　時間　S　秒	*/

	float r = 0.0f;	//シュヴァルツシルト半径
	float g = 6.67408e-11; //万有引力定数
	float m = 5.972e+24; //質量
	float c = 3.00e+8f; //光の速度

	r = 2.0*g*m / (c*c);

	printf( "地球のシュヴァルツシルト半径は%fメートル\n", r );

	//実数型（浮動小数点数型）の誤差
	//④下記の等値判定は一見正しいが、期待通りの動作をしない。誤差を考慮した判定式に変更する。
	//⑤さらに、近似的に等値判定をする関数を実装する。
	float a = 0.1f;
	float b = 0.2f;
	if( a + b < 0.3+FLT_EPSILON && a+b > 0.3-FLT_EPSILON )
	{
		printf( "0.1と0.2の和は0.3である！\n" );
	}
	else
	{
		printf( "0.1と0.2の和は0.3にならない・・・？\n" );
	}

	if (approx_equal(a+b, 0.3f))
	{
		printf("0.1と0.2の和は0.3である！");
	}
	else
	{
		printf("0.1と0.2の和は0.3にならない・・・？");
	}

	printf( "\n" );
	/* FLT_EPSILON 誤差*/

	//⑥下記の等値判定も一見正しいが、期待通りの動作をしない。③で実装した関数を使って近似的に等値判定をする。
	float n = 0.0f;
	for( int i = 0; i < 100; i++ )
	{
		n += 0.01f;
	}
	if( approx_equal(n,1.0f, 1.119e-5f))
	{
		printf( "実数値0.01を100回加算すると1になる！" );
	}
	else
	{
		printf( "実数値0.01を100回加算すると1にならない・・・？" );
	}
	printf( "\n" );

	//実数型乱数
	srand( ( unsigned int )time( 0 ) );
	//⑦0以上1以下の実数型乱数を生成し、変数rに代入する。
	//【ヒント】rand関数の生成する乱数の最大値はstdlib.hで次のように定義されている
	//	#define RAND_MAX 0x7fff
	for( int i = 0; i < 5; i++ )
	{
		float r = 0.0f;
		r = (float)rand() / RAND_MAX;

		printf( "0以上1以下の実数乱数：%f\n", r );
	}
	//⑧10以上15以下の実数型乱数を生成し、変数rに代入する。
	for( int i = 0; i < 5; i++ )
	{
		float r = 0.0f;
		r = (float)rand() / RAND_MAX * 5 + 10;

		printf( "10以上15以下の実数乱数：%f\n", r );
	}	
	//⑨2以上5以下の実数型乱数を生成し、変数rに代入する。さらに、その乱数の小数点以下第3位を四捨五入し、変数sに代入する。
	for( int i = 0; i < 5; i++ )
	{
		float r = 0.0f;
		r = (float)rand() / RAND_MAX * 3 + 2;
		float s = 0.0f;
		s = (int)(r * 100 + 0.5);
		s = s / 100;
		printf( "%fを小数点以下第3位を四捨五入すると%fになる\n", r, s );
	}
}

