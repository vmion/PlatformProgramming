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
        //리스트에 데이터 저장
        List<Mob> mobList = new List<Mob>();
        for(int i = 0; i < 10; i++)
        {
            Mob p = new Mob();
            p.index = 100;
            p.name = "홍길동_" + i.ToString();
            mobList.Add(p);
        }
        //리스트 형식을 Json형식으로 변환
        string jsonDataList = JsonUtility.ToJson(new Serialization<Mob>(mobList));
        Debug.Log(jsonDataList);
        //Json형식을 리스트형식으로 변환
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
