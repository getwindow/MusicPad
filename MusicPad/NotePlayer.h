//����������
#pragma once
#include "Common.h"

class CNotePlayer
{
public:
	CNotePlayer();
	~CNotePlayer();
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

