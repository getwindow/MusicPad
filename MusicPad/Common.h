#pragma once

//�����ṹ��
struct Note
{
	int note;		//������1~7�ֱ�Ϊ�����е�1~7��0����ֹ��
	int octave;		//����8�ȡ����� 0������C���ڵ�8�ȣ�1:��8�ȣ�2:������8�ȣ�-1:��8��
	int type;		//�������ͣ�1��ȫ������2��2��������4��4����������������
	DWORD extend_half;	//����ʱֵ�ӳ���bit0:�ӳ�1/2; bit1:�ӳ�1/4; bit2:�ӳ�1/8, �������ƣ�
	int signature;		//�����Ǻţ�0���ޱ仯��-1����������1��������
};


class CCommon
{
public:
	CCommon();
	~CCommon();

	static CString IntToString(int n);
};

