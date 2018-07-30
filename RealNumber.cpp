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
	//�����^�̕\���͈́i��Βl�j
	//�@float�^�ŕ\�����Ƃ̂ł���ő�l��ϐ�max�ɑ������
	float max = 0.0f;

	printf("float�^�ŕ\�����Ƃ̂ł���ő�l��%e\n", 3.40282346e+38f);	//�w���`���ŕ\��

	printf( "float�^�ŕ\�����Ƃ̂ł���ő�l��%e\n", FLT_MAX );	//�w���`���ŕ\��

	//�Afloat�^�ŕ\�����Ƃ̂ł���ŏ���Βl�i�[���ɍł��߂����j��ϐ�min�ɑ������
	float min = 0.0f;

	printf("float�^�ŕ\�����Ƃ̂ł���ŏ���Βl�i�[���ɍł��߂����j��%e\n", 1.175494351e-38f);	//�w���`���ŕ\��

	printf( "float�^�ŕ\�����Ƃ̂ł���ŏ���Βl�i�[���ɍł��߂����j��%e\n", FLT_MIN );	//�w���`���ŕ\��

	//�����^�̎w���\�L
	//�B�������k���ău���b�N�z�[���ɂȂ锼�a���V�����@���c�V���g���a�iSchwarzschild radius�j�ƌ����A�����ŗ^������B
	// r = 2GM/c^2
	//�����ŁAr�̓V�����@���c�V���g���a�AM�͎��ʁAG�͖��L���͒萔�Ac�͌��̑��x�ł���B
	//�n���̃V�����@���c�V���g���a�����߂�B�iMKS�P�ʌn��p���邱�Ɓj
	/*�@MKS�P�ʌn
	�@�@�����@M�@���[�g��
	  �@�d���@K�@�L���O����
	  �@���ԁ@S�@�b	*/

	float r = 0.0f;	//�V�����@���c�V���g���a
	float g = 6.67408e-11; //���L���͒萔
	float m = 5.972e+24; //����
	float c = 3.00e+8f; //���̑��x

	r = 2.0*g*m / (c*c);

	printf( "�n���̃V�����@���c�V���g���a��%f���[�g��\n", r );

	//�����^�i���������_���^�j�̌덷
	//�C���L�̓��l����͈ꌩ���������A���Ғʂ�̓�������Ȃ��B�덷���l���������莮�ɕύX����B
	//�D����ɁA�ߎ��I�ɓ��l���������֐�����������B
	float a = 0.1f;
	float b = 0.2f;
	if( a + b < 0.3+FLT_EPSILON && a+b > 0.3-FLT_EPSILON )
	{
		printf( "0.1��0.2�̘a��0.3�ł���I\n" );
	}
	else
	{
		printf( "0.1��0.2�̘a��0.3�ɂȂ�Ȃ��E�E�E�H\n" );
	}

	if (approx_equal(a+b, 0.3f))
	{
		printf("0.1��0.2�̘a��0.3�ł���I");
	}
	else
	{
		printf("0.1��0.2�̘a��0.3�ɂȂ�Ȃ��E�E�E�H");
	}

	printf( "\n" );
	/* FLT_EPSILON �덷*/

	//�E���L�̓��l������ꌩ���������A���Ғʂ�̓�������Ȃ��B�B�Ŏ��������֐����g���ċߎ��I�ɓ��l���������B
	float n = 0.0f;
	for( int i = 0; i < 100; i++ )
	{
		n += 0.01f;
	}
	if( approx_equal(n,1.0f, 1.119e-5f))
	{
		printf( "�����l0.01��100����Z�����1�ɂȂ�I" );
	}
	else
	{
		printf( "�����l0.01��100����Z�����1�ɂȂ�Ȃ��E�E�E�H" );
	}
	printf( "\n" );

	//�����^����
	srand( ( unsigned int )time( 0 ) );
	//�F0�ȏ�1�ȉ��̎����^�����𐶐����A�ϐ�r�ɑ������B
	//�y�q���g�zrand�֐��̐������闐���̍ő�l��stdlib.h�Ŏ��̂悤�ɒ�`����Ă���
	//	#define RAND_MAX 0x7fff
	for( int i = 0; i < 5; i++ )
	{
		float r = 0.0f;
		r = (float)rand() / RAND_MAX;

		printf( "0�ȏ�1�ȉ��̎��������F%f\n", r );
	}
	//�G10�ȏ�15�ȉ��̎����^�����𐶐����A�ϐ�r�ɑ������B
	for( int i = 0; i < 5; i++ )
	{
		float r = 0.0f;
		r = (float)rand() / RAND_MAX * 5 + 10;

		printf( "10�ȏ�15�ȉ��̎��������F%f\n", r );
	}	
	//�H2�ȏ�5�ȉ��̎����^�����𐶐����A�ϐ�r�ɑ������B����ɁA���̗����̏����_�ȉ���3�ʂ��l�̌ܓ����A�ϐ�s�ɑ������B
	for( int i = 0; i < 5; i++ )
	{
		float r = 0.0f;
		r = (float)rand() / RAND_MAX * 3 + 2;
		float s = 0.0f;
		s = (int)(r * 100 + 0.5);
		s = s / 100;
		printf( "%f�������_�ȉ���3�ʂ��l�̌ܓ������%f�ɂȂ�\n", r, s );
	}
}

