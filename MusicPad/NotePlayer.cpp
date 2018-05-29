#include "stdafx.h"
#include "NotePlayer.h"


CNotePlayer::CNotePlayer()
{
}


CNotePlayer::~CNotePlayer()
{
}

void CNotePlayer::PlayNote(const Note& note)
{
	int index;		//����������CΪ�ο�����ţ��԰���Ϊ��λ��
	int index_in_octave{};	//������һ���˶��е���ţ��԰���Ϊ��λ��
	switch (note.note)
	{
	case 1: index_in_octave = 0; break;
	case 2: index_in_octave = 2; break;
	case 3: index_in_octave = 4; break;
	case 4: index_in_octave = 5; break;
	case 5: index_in_octave = 7; break;
	case 6: index_in_octave = 9; break;
	case 7: index_in_octave = 11; break;
	case 0: break;
	default: return;
	}
	index_in_octave += note.signature;	//���������Ǻ�����ָ�������İ���
	index = m_mode + index_in_octave + note.octave * 12;
	DWORD time;		//�����ĳ���ʱ��
	time = m_full_note_time / note.type;
	//����ʱֵ�ӳ�
	for (int i = 0; i <= 31; i++)
	{
		if ((note.extend_half >> i) % 2 != 0)
			time += (m_full_note_time / note.type * (1 / std::pow(2, i + 1)));
	}
	if (note.note == 0)	//Ϊ��ֹ��ʱ
		Sleep(time);
	else
		PlayNoteRaw(index, time);
}

void CNotePlayer::PlayMusicSource(const vector<Note>& music_source)
{
	for (const auto& note : music_source)
	{
		PlayNote(note);
	}
}

void CNotePlayer::PlayNoteRaw(int index, DWORD dwDuration)
{
	double freq;
	freq = 261.626 * std::pow(2, (static_cast<double>(index) / 12));	//����C��Ƶ����261.626Hz������ÿ���һ��������Ƶ�����2��1/12�η���
	Beep(static_cast<int>(freq), dwDuration);
}
