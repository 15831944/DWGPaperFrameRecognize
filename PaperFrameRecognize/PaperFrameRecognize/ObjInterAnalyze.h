#pragma once

struct SFrame
{
    AcGePoint3d ptMax;
	AcGePoint3d ptMin;
	AcDbObjectIdArray arrIds;
};

class CObjInterAnalyze
{
public:
	CObjInterAnalyze(AcDbDatabase *pDb = NULL);
	virtual ~CObjInterAnalyze(void);

protected:
	AcDbDatabase *m_pDb;
	vector < SFrame > m_arrFrame;
protected:
	virtual bool Interfere( SFrame &src, SFrame &dst );    //�ж���ʵ���Ƿ��ཻ���������������ݿ�,���ϲ�ids
	bool Merge ( SFrame &dst );                    //�����ж��������Ƿ���������ܸ��棬����ȡ��������ʵ��

public:
	vector < SFrame > GetArrFrame() const;
	void Analyze();
};

class CObjInterAnalyze2 : public CObjInterAnalyze
{
public:
	CObjInterAnalyze2 ();
	~CObjInterAnalyze2 ();

protected:
	virtual bool Interfere( SFrame &src, SFrame &dst );    //�ж���ʵ���Ƿ��ཻ���������������ݿ�,���ϲ�ids
};

