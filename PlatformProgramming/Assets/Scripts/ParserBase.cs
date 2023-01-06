using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

public struct NpcData
{
    public int index;
    public string name;
    public byte jobType;
}
public struct MonsterData
{
    public int index;
    public string name;
    public byte jobType;
}
public class ParserBase<T, Q> where T : class, new() where Q : struct
{
    //���̺� ������ ������ ����Ʈ �ʿ�
    //����ü�� ���̺�
    protected List<Q> list;
    private static T Instance;
    public static T instance
    {
        get
        {
            if (null == Instance)
            {
                return null;
            }
            return Instance;
        }
    }
    public ParserBase()
    {

    }
    public void LoadData(string _fileName)
    {
        list = new List<Q>();
        using (StreamReader sr = new StreamReader(_fileName))
        {
            string line = string.Empty;
            line = sr.ReadLine();
            while ((line = sr.ReadLine()) != null)
            {
                string[] datas = line.Split(',');
                ReadData(datas);
            }
            sr.Close();
        }
    }
    public virtual void ReadData(string[] _datas)
    {

    }
    public void AddData(Q _data)
    {
        list.Add(_data);
    }
}
