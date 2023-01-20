using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SimpleJSON;
using System;
public class SimpleJsonExample : MonoBehaviour
{
    [Serializable]
    public class Mob
    {
        [SerializeField] public int index;
        [SerializeField] public string name;
    }
    public class Serialization<T>
    {
        [SerializeField] 
        List<T> _t;
        public List<T> ToList() { return _t; }
        public Serialization(List<T> _tmp)
        {
            _t = _tmp;
        }
    }
    void Start()
    {
        TextAsset txtAsset = Resources.Load<TextAsset>("Json/TestData1");
        JSONNode root = JSON.Parse(txtAsset.text);
        int age = root["age"].AsInt;
        Debug.Log(root["age"]);
        JSONNode arr = root["address"];
        for (int i = 0; i < arr.Count; i++)
        {
            Debug.Log(arr[i]);
        }
        //����Ʈ�� ������ ����
        List<Mob> mobList = new List<Mob>();
        for(int i = 0; i < 10; i++)
        {
            Mob p = new Mob();
            p.index = 100;
            p.name = "ȫ�浿_" + i.ToString();
            mobList.Add(p);
        }
        //����Ʈ ������ Json�������� ��ȯ
        string jsonDataList = JsonUtility.ToJson(new Serialization<Mob>(mobList));
        Debug.Log(jsonDataList);
        //Json������ ����Ʈ�������� ��ȯ
        List<Mob> mobListformJson = JsonUtility.FromJson<Serialization<Mob>>(jsonDataList).ToList();
        foreach(Mob one in mobListformJson)
        {
            Debug.Log(one.index + "__" + one.name);
        }        
    }
    void Update()
    {        
    }
}
