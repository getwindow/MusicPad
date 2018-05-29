#pragma once
#include "Common.h"

class CMusicSource
{
public:
	CMusicSource();
	~CMusicSource();
	vector<Note>& GetNoteList() { return m_note_list; }

	int m_mode{};				//��ʽ
	int m_full_note_time{ 2000 };	//һ��ȫ������ʱ��

	//���һ������
	void AddNote(int note, int octave, int type, int extend_half = 0, int signature = 0);
	void AddNote(const Note& note);

	void ClearList();

	void LoadFromFile(LPCTSTR file_path);
	bool SaveToFile(LPCTSTR file_path);
protected:
	vector<Note> m_note_list;
};

