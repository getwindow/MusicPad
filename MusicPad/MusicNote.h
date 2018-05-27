//����������
#pragma once

//�����ṹ��
struct Note
{
	int note;		//������1~7�ֱ�Ϊ�����е�1~7��0����ֹ��
	int octave;		//����8�ȡ����� 0������C���ڵ�8�ȣ�1:��8�ȣ�2:������8�ȣ�-1:��8��
	int type;		//�������ͣ�1��ȫ������2��2��������4��4����������������
	int extend_half;	//����ʱֵ�ӳ�һ�루���Ϊ2�����ӳ�1/2 + 1/4��Ϊ3���ӳ� 1/2 + 1/4 + 1/8���������ƣ�
	int signature;		//�����Ǻţ�0���ޱ仯��-1����������1��������
};

class CMusicNote
{
public:
	CMusicNote();
	~CMusicNote();
	void SetMode(int mode) { m_mode = mode; }	//���õ�ʽ
	void SetFullNoteTime(int full_note_time) { m_full_note_time = full_note_time; }		//����ȫ������ʱ��

	//����һ������
	void PlayNote(const Note& note);

	//����һϵ������
	void PlayMusicSource(const vector<Note>& music_source);

private:
	//����һ��������indexΪ������CΪ�ο�����ţ�index���1�������һ��������dwDurationΪ����ʱ��
	void PlayNoteRaw(int index, DWORD dwDuration);

	int m_mode{};		//��ʽ��0~11��C C#/Db D D#/Eb E F F#/Gb G G#/Ab A A#/Bb B
	int m_full_note_time{ 2000 };	//һ��ȫ������ʱ�䣬��λΪ����
};

