#include "stdafx.h"
#include "MusicSource.h"


CMusicSource::CMusicSource()
{
}


CMusicSource::~CMusicSource()
{
}

void CMusicSource::AddNote(int note, int octave, int type, int extend_half, int signature)
{
	Note music_note;
	music_note.note = note;
	music_note.octave = octave;
	music_note.type = type;
	music_note.extend_half = extend_half;
	music_note.signature = signature;
	m_note_list.push_back(music_note);
}

void CMusicSource::AddNote(const Note & note)
{
	m_note_list.push_back(note);
}

void CMusicSource::ClearList()
{
	m_note_list.clear();
}

void CMusicSource::LoadFromFile(LPCTSTR file_path)
{
	// ���ļ�
	CFile file;
	BOOL bRet = file.Open(file_path, CFile::modeRead);
	if (!bRet) return;
	// ����CArchive����
	CArchive ar(&file, CArchive::load);
	// ������
	m_note_list.clear();
	size_t size{};
	Note note;
	CString temp;
	int no_use;
	try
	{
		ar >> temp;
		ar >> m_mode;
		ar >> m_full_note_time;
		ar >> size;		//��ȡӳ�������ĳ���
		for (size_t i{}; i < size; i++)
		{
			ar >> note.note;
			ar >> note.octave;
			ar >> note.type;
			ar >> note.extend_half;
			ar >> note.signature;
			ar >> no_use;
			ar >> no_use;
			m_note_list.push_back(note);
		}
	}
	catch (CArchiveException* exception)
	{
		CString info;
		info.Format(_T("�����ļ�ʱ���������л��쳣���쳣���ͣ�CArchiveException��m_cause = %d��"), exception->m_cause);
		AfxMessageBox(info, MB_ICONWARNING | MB_OK);
	}
	// �رն���
	ar.Close();
	// �ر��ļ�
	file.Close();
}

bool CMusicSource::SaveToFile(LPCTSTR file_path)
{
	// �򿪻����½��ļ�
	CFile file;
	BOOL bRet = file.Open(file_path, CFile::modeCreate | CFile::modeWrite);
	if (!bRet)		//���ļ�ʧ��
	{
		return false;
	}
	// ����CArchive����
	CArchive ar(&file, CArchive::store);
	// д����
	ar << CString("MPDSC");				//�ļ�����д��̶����ַ�
	ar << m_mode;
	ar << m_full_note_time;
	ar << m_note_list.size();		//д��ӳ�������Ĵ�С
	for (auto& note : m_note_list)
	{
		ar << note.note
			<< note.octave
			<< note.type
			<< note.extend_half
			<< note.signature
			<< 0		//Ԥ��
			<< 0;		//Ԥ��
	}
	// �ر�CArchive����
	ar.Close();
	// �ر��ļ�
	file.Close();
	return true;
}
